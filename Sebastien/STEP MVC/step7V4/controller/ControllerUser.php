<?php

class ControllerUser
{
    private $userManager;

    /*===================================
            Constructeur
    ===================================*/
    public function __construct($url=null)
    {
        $this->userManager=new UserManager;

        //===============================================
        //Si URL est du style http://monsite/user/login
        //===============================================
        if (isset($url) && count($url)==2 && $url[1]=="login")
        {
            $titre="Connexion";

            require_once 'view/viewLogin.php';
            return;        
        }

        //=====================================================
        //Si URL est du style http://monsite/user/loginAnswer
        //=====================================================
        else if (isset($url) && count($url)==2 && $url[1]=="loginAnswer")
        {
            $retour=$this->userManager->login($_POST['pseudo'],$_POST['password'],$_POST['password']);
            //var_dump($retour);die();
            if (! $retour)
            {
                $_SESSION["connexion"]=false;
                $errorMsg="Erreur de connexion";

                require_once 'view/viewError.php';
                return;
            }
            //login OK
            //var_dump('connexion OK");var_dump($retour);die();
            $_SESSION["connexion"]=true;
            $_SESSION["connectedUser"]=$retour;
            require_once 'view/viewAccueil.php';
            return;
        }
        //=====================================================
        //Si URL est du style http://monsite/user/logout
        //=====================================================
        else if (isset($url) && count($url)==2 && $url[1]=="logout")
        {
            $_SESSION["connexion"]=false;
           
            $titre="Déconnexion réussie";
         

            require_once 'view/viewLogout.php';
            return;
        }


        //=============================================================
        //      Si URL http://monsite/user
        //      Si on est admin
        //      on affiche la liste des users, si on clique
        //      sur l'un d'entre eux, on va pouvoir changer le statut
        //      le mot de passe, le supprimer, ect...
        //==============================================================
        else if(isset($url) && count($url)==1)
        {
            //si pas connecté
            if(UserManager::level()==0)
            {
                throw new Exception ("Accès interdit, veuillez vous connecter");
                return;
            }
            
            if(UserManager::level()!=2)
            {
                throw new Exception("Vous n'êtes pas administrateur, vous ne pouvez pas avoir accès à ceci");
                return;
            }
            $this->allUsers();
            return;
        }

        //===============================================
        //Si URL est du style http://monsite/user/new
        //on crée un nouvel utilisateur
        //===============================================

        else if (isset($url) && count($url)==2 && $url[1]=="new")
        {
            $titre="Nouvel utlisateur ";
            require_once 'view/viewNewUser.php';
            return;
        }
        
        else if (isset($url) && count($url)==2 && $url[1]=="newAnswer")
        {
            $this->newUser();
            return;
        }

        //===============================================
        //Si URL est du style http://monsite/user/delete/pseudo
        //on supprime l'utilisateur
        //===============================================
        else if (isset($url) && count($url)==3 && $url[1]=="delete")
        {
            $this->userManager->deleteUser($url[2]);
            $this->allUsers();
            return;
        }

    }

    //===============================================
    //          Nouvel Utilisateur
    //===============================================

    private function newUser()
    {
        //var_dump($_POST);die();
        $validator=new Validator($_POST);
        $db=$this->userManager->getBdd();

        //==========On vérifie les caractères du pseudo===========
        if (!$validator->isAlpha('pseudo','Pseudo invalide'))
        {
            throw new Exception($validator->getErrors());
            return;
        }

        //==========On vérifie si le pseudo à déja été utilisé===========
        if(!$validator->isUnique('pseudo',$db,'tb_user','Pseudo déjà utilisé'))
        { 
            throw new Exception($validator->getErrors());
            return;
        }

        //==========On vérifie que la confirmation du mot de passe est correcte===========
        if(!$validator->isConfirmed('password',"Vous devez saisir un mot de passe valide"))
        {
            throw new Exception($validator->getErrors());
            return;
        }
        //si on arrive ici, tout est OK
        //on peut donc stocker le new user dans la basse de données

        $this->userManager->registerNewUser($_POST);
        $this->allUsers();
    }

    /*================================================================================
                        Affichage de tous les utilisateurs
    ================================================================================*/
    private function allUsers()
    {
        $data=$this->userManager->getAllUsers();
        $titre="Liste des utilisateurs";
        $sousTitre="Voici tous les utilisateur";
        require_once 'view/viewAllUsers.php';
        return;
    }
}
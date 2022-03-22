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

        //=============================================================
        //      Si URL http://monsite/user
        //      Si on est admin
        //      on affiche la liste des users, si on clique
        //      sur l'un d'entre eux, on va pouvoir changer le statut
        //      le mot de passe, le supprimer, ect...
        //==============================================================
        else if(isset($url) && count($url)==1)
        {
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
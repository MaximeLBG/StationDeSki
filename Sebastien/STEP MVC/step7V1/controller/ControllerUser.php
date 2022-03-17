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
        //$this->allUsers();
    }
}
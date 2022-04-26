<?php

class ControllerParam 
{
    private $paramManager;

     /*==========================================================
                    Constructeur
    ===========================================================*/
    public function __construct($url)
    {
        $this->paramManager=new ParamManager;

        if ($url=='')
        {
            throw new Exception('Page introuvable');
        }

        if(isset($url) && count($url)==2)
        {
            if ($url[1]=="Acquitte")
            {
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

                if(UserManager::level()==2)
                {
                    $this->paramManager->clearAlarmes();
                    //require_once 'view/viewAllVent.php';
                    header('Location:'.Router::makeURL("/vent"));
                    return;
                }
            $this->allUsers();
            return;
            }
        }

    }
}
<?php
class ControllerVent
{
    public function __construct($url)
    {
        if ($url=='')
            throw new Exception('Page introuvable');

        //si juste 1 argument, on récupère toutes les températures
        else if (isset($url) && count($url)==1)
        {
            $this->VentManager=new VentManager;
            $data=$this->VentManager->getAllVent();
            $title="vents mesurés";
            require_once 'view/viewAllVent.php';
        }
        else if (isset($url) && count($url)==2)
        {  
           
            $this->VentManager=new VentManager;
            $data=$this->VentManager->getVent($url[1]);

            //var_dump($data);die();

            require_once 'view/viewAllVent.php';
        }    
        else
        {
            throw new Exception("Erreur d'URL");
        }
    }
}
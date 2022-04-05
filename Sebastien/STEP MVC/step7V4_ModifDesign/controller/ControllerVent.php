<?php
class ControllerVent
{
    public function __construct($url)
    {
        if ($url=='')
            throw new Exception('Page introuvable');

        //si juste 1 argument, on récupère toutes les données
        else if (isset($url) && count($url)==1)
        {
            $this->VentManager=new VentManager;
            $data=$this->VentManager->getAllVent();
            $title="vents mesurés";
            require_once 'view/viewAllVent.php';
        }
        else if (isset($url) && count($url)==2)
        {  
           // Test du POST
            if ($url[1]=="new") // nouvelle valeur postée 
            {
                $json=file_get_contents('php://input');
                $data=json_decode($json);
               // var_dump($data);
                //die();
                $this->VentManager=new VentManager;
                $data=$this->VentManager->saveVent($data);
		return;
            }


            $this->VentManager=new VentManager;
            $data=$this->VentManager->getVent($url[1]);

            //var_dump($data);die();
            $lesDates=$this->VentManager->getDate($url[1]);
            $lesMesures=$this->VentManager->getValues($url[1]);
            require_once 'view/viewAllVent.php';
        }    
        else
        {
            throw new Exception("Erreur d'URL");
        }
    }
}

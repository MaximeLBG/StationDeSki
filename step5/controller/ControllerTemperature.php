<?php
class ControllerTemperature
{
    public function __construct($url)
    {
        if ($url=='')
            throw new Exception('Page introuvable');

        //si juste 1 argument, on récupère toutes les températures
        else if (isset($url) && count($url)==1)
        {
            $this->temperatureManager=new TemperatureManager;
            $data=$this->temperatureManager->getAllTemp();
            $title="Températures mesurées";
            require_once 'view/viewAllTemperatures.php';
        }
        else if (isset($url) && count($url)==2)
        {  
           
            $this->temperatureManager=new TemperatureManager;
            $data=$this->temperatureManager->getTemp($url[1]);

            //var_dump($data);die();

            require_once 'view/viewAllTemperatures.php';
        }    
        else
        {
            throw new Exception("Erreur d'URL");
        }
    }
}
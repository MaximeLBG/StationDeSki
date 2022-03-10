<?php
class TemperatureManager extends Model //extends pour la notion d'héritage en PHP
{
    public function __construct()
    {
        $this->setBdd('db_capteur');
    }

    public function getAllTemp()
    {
        //simulation des températures renvoyées par la base de données
        $var=[];

        //cherchons les températures dans la base de données
        $var=$this->getAll("tb_capteur_temp","Temperature");

        //var_dump($var);die();

        return $var;
    }
    /*===========================================================
                RECUP DES TEMP D'UN CAPTEUR PRECIS
    ============================================================*/
    public function getTemp($idCapteur)
    {
        $var=[];
        $var=$this->GetPartial("tb_capteur_temp","TEMPERATURE","idCapteur=".$idCapteur);

        return $var;
    }                    
}
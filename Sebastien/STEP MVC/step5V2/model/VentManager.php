<?php
class VentManager extends Model //extends pour la notion d'héritage en PHP
{
    public function __construct()
    {
        $this->setBdd('db_capteur');
    }
    
    public function getAllVent()
    {
        //simulation des températures renvoyées par la base de données
        $var=[];

        //cherchons les températures dans la base de données
        $var=$this->getAll("tb_capteur_vent","Vent");

        //var_dump($var);die();

        return $var;
    }
    /*===========================================================
                RECUP DES TEMP D'UN CAPTEUR PRECIS
    ============================================================*/
    public function getVent($idCapteur)
    {
        $var=[];
        $var=$this->GetPartial("tb_capteur_vent","Vent","idCapteur=".$idCapteur);
        //var_dump($var);die();
        return $var;
    }                    
}
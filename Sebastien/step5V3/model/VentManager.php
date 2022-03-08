<?php
class VentManager extends Model //extends pour la notion d'héritage en PHP
{
    public function __construct()
    {
        $this->setBdd('db_capteur');
    }

    public function saveVent($data)
    {
        //var_dump("Save VENT");
      
        $sql = " INSERT INTO tb_capteur_vent (idCapteur,dateTme,vitesse,dirvent,temp) VALUES(";  
        $sql=$sql."'".$data->idCapteur."'";
        $sql=$sql.",NOW(),";
        $sql=$sql."'".$data->vitesse."'";
        $sql=$sql.",'".$data->dirvent."'";
        $sql=$sql.",'".$data->temp."')";   //début de parenthèse dans le VALUES
        
        //var_dump($sql);die();

        $req=$this->getBdd()->prepare($sql);
        $req->execute();
        
        
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
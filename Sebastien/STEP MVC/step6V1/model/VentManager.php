<?php
class VentManager extends Model //extends pour la notion d'héritage en PHP
{
    public function __construct()
    {
        $this->setBdd('db_capteur');
    }

    public function saveVent($data)
    {
              
        $sql = "INSERT INTO tb_capteur_vent (idCapteur,dateTme,vitesse,dirvent,temp) VALUES(";  
        $sql=$sql."'".$data->idCapteur."'";
        $sql=$sql.",NOW(),";
        $sql=$sql."'".$data->vitesse."'";
        $sql=$sql.",'".$data->dirvent."'";
        $sql=$sql.",'".$data->temp."')";   //début de parenthèse dans le VALUES
        
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
    
    /*===============================================================
                RECUP DE TOUTES LES VALEURS
                MESUREES SUR UN CAPTEUR PRECIS
    =================================================================*/
    public function getValues($idCapteur)
    {
        $var=[];
        $sql="SELECT vitesse from tb_capteur_vent WHERE idCapteur=".$idCapteur." ORDER BY dateTme";
        //var_dump($sql);die();
        $req=$this->getBdd()->prepare($sql);
        $req->execute();
        while($data=$req->fetch(PDO::FETCH_NUM))
        {
            $var[]=$data[0];
        }
        //var_dump($var);die();
        return $var;
    }

    /*===============================================================
                RECUP DE TOUTES LES VALEURS
                MESUREES SUR UN CAPTEUR PRECIS
    =================================================================*/
    public function getDate($idCapteur)
    {
        $var=[];
        $formatDate_us="Y-m-d H:i:s";
        $formatDate_fr="d/m/Y H:i:s";

        $sql="SELECT dateTme from tb_capteur_vent WHERE idCapteur=".$idCapteur." ORDER by dateTme";

        $req=$this->getBdd()->prepare($sql);
        $req->execute();
        while($data=$req->fetch(PDO::FETCH_NUM))
        {
            $date = DateTime::createFromFormat($formatDate_us,$data[0]);

            $var[]=$date->format($formatDate_fr);
        }
        //var_dump($var);die();
        return $var;

    }

}

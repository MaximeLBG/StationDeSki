<?php

class Temperature
{
    //définition en private de tout les champs de la table température
    //qui sera créée en base de données
    private $id;             //clé primaire
    private $idCapteur;      //id du capteur
    private $dateTime;       //date et heure de l'acquisition
    private $value;          //Valeur de la température

    public function __construct(array $data)
    {
        $this->hydrate($data);
    }

    public function hydrate(array $data)
    {
        foreach($data as $key => $value)
        {
            $method = 'set'.ucfirst($key);
            if(method_exists($this,$method))
                $this->$method($value);
        }
    }



    //GETTERS
    public function getId()
    {
        return $this->id;
    }
    public function getIdCapteur()
    {
        return $this->idCapteur;
    }
    public function getDateTime()
    {
        return $this->dateTime;
    }
    public function getValue()
    {
        return $this->value;
    }

    //SETTTERS
    public function setId($id)
    {
        $id=(int) $id;
        if($id>0)
            $this->id=$id;
    }
    public function setIdCapteur($idCapteur)
    {
        $idCapteur=(int) $idCapteur;
        if($idCapteur>0)
            $this->idCapteur=$idCapteur;
    }
    public function setDateTime($dateTime)
    {
        $this->dateTime=$dateTime;
    }
    public function setValue($value)
    {
        $this->value=$value;
    }

}
<?php

class parametre
{
    private $Vmax;     //vitesse max norme
    private $Email;    //mail commun aux admins


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
    public function getVmax()
    {
        return $this->Vmax;
    }
    public function getEmail()
    {
        return $this->Email;
    }
        
    //SETTERS
    public function setEmail($Email)
    {
        $this->Email=$Email;
    }
    public function setVmax($Vmax)
    {
        $this->Email=$Email;
    }
}

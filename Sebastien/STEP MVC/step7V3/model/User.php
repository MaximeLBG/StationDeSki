<?php

class User
{
    //définition en private de tout les champs de la table température
    //qui sera créée en base de données
    private $id;             //clé primaire
    private $pseudo;      
    private $password;   
    private $priorite;          //1 pour admin et 2 pour consultant


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

    //SETTERS
    public function setId($id)
    {
        $id = (int) $id;
        if($id > 0)
            $this->id=$id;
    }
    public function setPseudo($pseudo)
    {
        $this->pseudo=$pseudo;
    }
    public function setPassword($password)
    {
        $this->password=$password;
    }
    public function setPriorite($priorite)
    {
        $this->priorite=$priorite;
    }

    //GETTERS
    public function getId()
    {
        return $this->id;
    }
    public function getPseudo()
    {
        return $this->pseudo;
    }
    public function getPassword()
    {
        return $this->password;
    }
    public function getPriorite()
    {
        return $this->priorite;
    }
}
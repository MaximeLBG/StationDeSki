<?php
//================================================
//  Classe qui gère les validations des saisies
//================================================

class validator
{
    private $data;
    private $errors;

    //======================================================
    //  Constructeur
    //======================================================

    public function __construct($data)
    {
        $this->data=$data;
    }

    //======================================================
    //  Récup d'un champ donné
    //======================================================

    private function getField($field)
    {
        if(!isset($this->data[$field]))
        {
            return null;
        }
        return $this->data[$field];
    }

    //===================================================================
    //  Renvoie TRUE si les caractères saisis sont des lettres, chiffres
    //  ou UNDERSCORE
    //===================================================================

    public function isAlpha($field, $errorMsg="Seuls les caractères alphanumériques et le underscore sont valides")
    {
        if(!preg_match('/^[a-zA-Z0-9_]+$/',$this->getField($field))) //preg match pour les expressions regulieres
        {                                                            //comparation du début, milieu et fin a notre $field
            $this->errors=$errorMsg;
            return false;
        }
        return true;
    }

    //===================================================================
    //  Renvoie TRUE si la valeur saisie n'existe pas 
    //  déja dans la base de donéees
    //===================================================================

    public function isUnique($field, $db, $table, $errorMsg="Le champ n'est pas unique")
    {
        $sql="SELECT id FROM $table WHERE $field =". '"'.$this->getField($field).'"';
        //var_dump($sql);die();
        $record=$db->query($sql)->fetch();
        //var_dump($record);die();
        if($record)
        {
            $this->errors=$errorMsg;
            return false;
        }
        return true;
    }

    //===================================================================
    //  Renvoie TRUE si le champs de confimation contient la même
    //  chose que le champ saisi
    //===================================================================

    public function isConfirmed($field, $errorMsg="Erreur de confirmation")
    {
        if(empty($this->getField($field)) || $this->getField($field) !=$this->getField($field.'_confirm'))
        {
            $this->errors=$errorMsg;
            return false;
        }
        return true;
    }

    public function getErrors()
    {
        return $this->errors;
    }
}
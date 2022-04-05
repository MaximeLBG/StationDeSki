<?php
class paramManager extends Model
{
    public function __construct()
    {
        $this->setBdd('db_capteur');
    }

    public function getVmax($idCapteur)
    {
        $var=[];
        $var=$this->GetPartial("tb_capteur_vent","Vent","idCapteur=".$idCapteur);
        $varVmax=$this->GetPartial("param_capteur","Vent","idCapteur=".$Vmax);
        
        //var_dump($var);die();
        if($var>$varVmax)
            return $var;
        else
            exit;
    }   










}
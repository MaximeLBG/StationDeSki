<?php

class ControllerParam
{
    public function __construct($url)
    {
        if ($url=='')
            throw new Exception('Page introuvable');


        else if (isset($url) && count($url)==1)
        {
            $this->ParamManager=new ParamManager;
            $data=$this->ParamManager->getVmax();
            $title="Vents Maximum";
            //require_once 'view/viewParam.php';





}
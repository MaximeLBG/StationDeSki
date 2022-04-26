<?php
class paramManager extends Model
{
    public function __construct()
    {
        $this->setBdd('db_capteur');
    }

    public function clearAlarmes()
    {
        $sql="UPDATE tb_capteur_vent SET SeuilDepasse=2 WHERE SeuilDepasse=1";
        $req=$this->getBdd()->query($sql);
        $req->execute();
        return;
    }
}
<?php
class Model
{
    private $_bdd;

    /*================================
             DEFINITION BDD
    =================================*/

    public function setBdd($dataBase,$host='localhost',$login='root',$password='')
    {
        $this->_bdd=new PDO('mysql:dbname='.$dataBase.';charset=utf8;host='.$host,$login,$password);
        $this->_bdd->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_WARNING);
    }

    /*================================
            RECUP CONNEXION BDD
    =================================*/

    public function getBdd()
    {
        return $this->_bdd;
    }

    /*==================================================
            RECUP TOUT LES ELEMENT D'UNE 
                    TABLE ET 
            INSTANCIATION DE LA CLASSE $OBJ
    ===================================================*/

    protected function getAll($table,$obj)
    {
        $var=[];
        $req=$this->getBdd()->prepare('SELECT * FROM '.$table.' ORDER BY id desc');
        $req->execute();
        while($data=$req->fetch(PDO::FETCH_ASSOC))
        {
            $var[]=new $obj($data);
        }
        $req->closeCursor();
        //var_dump($var);die();
        return $var;
    }

       /*==================================================
            RECUP PARTIELLE D'ELEMENTS 
                    D'UNE TABLE
            INSTANCIATION DE LA CLASSE $OBJ
    ===================================================*/
    protected function getPartial($table,$obj , $criteria)
    {
        $var=[];
        $sql='SELECT * FROM '.$table.' WHERE '.$criteria;

        $req=$this->getBdd()->prepare($sql);
        $req->execute();
        while($data=$req->fetch(PDO::FETCH_ASSOC))
        {
            $var[]=new $obj($data);
        }
        $req->closeCursor();

        return $var;
    }
}

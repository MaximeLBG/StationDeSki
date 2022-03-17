<?php
class UserManager extends Model
{
    /*==========================================================
                    Constructeur
    ===========================================================*/
    public function __construct()
    {
        $this->setBdd('db_capteur');
    }
    /*===========================================================
         Enregistrement d'un nouvel user dans la table avec 
                les arguments fournis par $POST
    ============================================================*/
    public function registerNewUser($POST)
    {
        //on genere le hachage du mot de passe
        //Le même mot de passe ne sera pas haché 2 fois
        //de la même manière car password_hash applique un salage du
        //mot de passe avant de le hacher, c'est à dire qu'il
        //concatène le mot de passe avec une chaine aléatoire elle même
        //incluse (encodée en base 64) dans le hachage obtenu
        $password=password_hash($POST['password'],PASSWORD_BCRYPT);

        //var_dump($password);die();

        if(isset($POST['priorite']))
            $priorite=2;
        else
            $priorite=1;
    

    $sql="INSERT INTO tb_user SET pseudo ='".$POST['pseudo']."', password='".$password."', priorite=".$priorite;
    //var_dump($sql);die();
    $req=$this->getBdd()->query($sql);
    }

    /*=============================================
        methode permettant 
        l'affichage de tous les utilisateur
    ==============================================*/
    public function getAllUsers()
    {
        $var=[];
        $var=$this->getAll("tb_user", "User");
        return $var;
    }
    /*=============================================
        methode permettant 
        la suppression d'un utilisateur
    ==============================================*/
    public function deleteUser($pseudo)
    {
        $sql="DELETE FROM tb_user WHERE pseudo='".$pseudo."'";
        $this->getBdd()->query($sql);
    }
}
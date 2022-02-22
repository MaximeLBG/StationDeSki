<?php
class Router {
    public function routeReq(){

        try {

            
            //chargement automatique des classes 
            spl_autoload_register(function($class){
                require_once('model/'.$class.'.php');
            });

            if(isset($_GET['url'])) {
                
                //Décomposer l'URL
                $url=explode('/',filter_var($_GET['url'],FILTER_SANITIZE_URL));

                // Le nom du controller commence par une majuscule (ucfirst) puis est suivi de l'url 0 en minuscules
                $controller=ucfirst(strtolower($url[0]));
                $controllerClass="Controller".$controller;
                $controllerFile="controller/".$controllerClass.".php";

                if(file_exists($controllerFile)) {
                    require_once($controllerFile);
                    $this->_ctrl=new $controllerClass($url);
                }
                else
                    throw new Exception('Contrôleur introuvable');
            }
            else //index.php a été appelé sans paramètre 
            {
                require_once('controller/ControllerAccueil.php');
                $this->_ctrl=new ControllerAccueil();
            }
        }//fin du bloc try

        catch(Exception $e){
            var_dump($e->getMessage());die();
        }
    }
}
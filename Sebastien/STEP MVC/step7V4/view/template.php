<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <link rel="stylesheet" href=<?=Router::makeURL("public/css/styles.css")?>>
    <title><?= $title ?></title>
</head>
<body>
    
        
    <h2>Bienvenue sur mon site MVC</h2><br>

    <header class="navbar navbar-dark sticky-top bg-dark flex-md-nowrap p-0 shadow">
    <a class="navbar-brand col-md-3 col-lg-2 me-0 px-3" href="#">Bienvenue Chez Les Skis</a>
    <p class="h5 my-0 me-md-auto fw-normal">
    <div class="paragrapheBandeau">
        <?php
        //==========MESSAGE DE BIENVENUE POUR LES USERS CONNECTES===============
        if(UserManager::level()>0) 
            echo "Bonjour ".$_SESSION["connectedUser"][0];
        ?>
    </div>

    <a class="btn btn-outline-primary" href="<?php
        //LIEN VERS PAGE DE DECONNEXION/CONNEXION 
        if(UserManager::level()>0)
            echo Router::makeURL("user/logout");
        else
            echo Router::makeURL("user/login");
    ?>">
        <?php
            if(UserManager::level()>0)
                echo "Déconnexion";
                else echo "Connexion";
        ?>
    </a>

    </header>
    
    <div class="container-fluid">
        <div class="row">
            <nav id="sidebarMenu" class="col-md-3 col-lg-2 d-md-block bg-light sidebar collapse">
                <div class="position-sticky pt-3">
                    <ul class="nav flex-column">
                    <li class="nav-item">
                    <a class="nav-link active" aria-current="page" href=<?=Router::makeURL("index.php")?>>
                    <span data-feather="Accueil"></span>
                    Accueil
                    </a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="<?=Router::makeURL("vent")?>">
                        <span data-feather="Données enregistrées"></span>
                        Données enregistrées                   
                        </a>
                    </li>

                    <?php
                        if(isset($_SESSION["connexion"])
                        && $_SESSION["connexion"]==true 
                        && $_SESSION["connectedUser"][1]==2)
                        {
                    ?>     
                        <li class="nav-item">
                            <a class="nav-link" href=<?=Router::makeURL("user")?>>
                            <span data-feather="Administration"></span>
                            Administration
                            </a>
                        </li>
                    <?php
                        }
                    ?>                
                    

                    <li class="nav-item">
                        <a class="nav-link" href="#">
                        <span data-feather="A propos"></span>
                        À propos
                        </a>
                    </li> 
                    </ul>
                </div>
            </nav>
        

    <main class="col-md-9 ms-sm-auto col-lg-10 px-md-4">
    

    <!-- C'est ici que vient se greffer le contenu généré par la vue associée -->
    <?= $content ?>
    </main>
</div>    
    <footer class="my-5 pt-5 text-muted text-center text-small">
        <p class="mb-1">&copy; Lycée Charles De Foucauld - Nancy - Supervision De La Remontée Mécanique D'une Station De Ski</p>
    </footer>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/3.7.1/chart.min.js"></script>
    <script type ="text/javascript" src="../public/js//codeJavascriptPerso.js"></script>
</body>
</html>
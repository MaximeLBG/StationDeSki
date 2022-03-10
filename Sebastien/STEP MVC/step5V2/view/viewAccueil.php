<?php

$title='Vue Accueil';

ob_start(); // on place en mémoire tampon tout le code html qui suit
?> 

<h1>Ma splendide page d'acceuil</h1>
<p>Bienvenue sur notre site MVC</p>

<?php
$content=ob_get_clean();
require('template.php');// on appele la page template


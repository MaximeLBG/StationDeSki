<?php

$title='Vue Accueil';

ob_start(); // on place en mémoire tampon tout le code html qui suit
?> 
<div id="page"></div>
<h1>Ma splendide page d'accueil</h1>

<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<?php




$content=ob_get_clean();
require('template.php');// on appelle la page template


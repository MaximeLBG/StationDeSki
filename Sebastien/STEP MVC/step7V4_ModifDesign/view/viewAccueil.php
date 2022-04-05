<?php

$title='Accueil';

ob_start(); // on place en mémoire tampon tout le code html qui suit
?> 

<div id="page"></div>

<h2>Bienvenue sur notre supervision de station de ski</h2>
<p>Ce site vous permettra de voir en temps réel les informations dont vous avez besoin.</p>
<p>Ainsi, la station pourra fermer les remontées mécaniques en cas de besoin pour assurer votre sécurité</p>


<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<?php




$content=ob_get_clean();
require('template.php');// on appelle la page template


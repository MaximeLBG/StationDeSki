<?php
ob_start();
//Affichage des données
$title='À Propos';
?>


<?php
$content=ob_get_clean();
require('template.php');// on appelle la page template
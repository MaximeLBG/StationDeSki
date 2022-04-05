<?php
ob_start();
$title='Erreur';
?>

<h2>Identifiant inexistant</h2>
<a href="http://localhost/MVC/ProjetStationDeSki/step7V4_ModifDesign/user/login"><input type="button" name="Retour à la page de connexion"value="Retour à la page de connexion"/></a>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<?php
$content=ob_get_clean();
require ('template.php');
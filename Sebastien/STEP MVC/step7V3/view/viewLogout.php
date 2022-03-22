<?php
ob_start();
?>

<h2><?=$titre?></h2>

<?php
$content=ob_get_clean();
require ('template.php');
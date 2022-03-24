<?php
ob_start();
?>

<h2><?=$titre?></h2>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<?php
$content=ob_get_clean();
require ('template.php');
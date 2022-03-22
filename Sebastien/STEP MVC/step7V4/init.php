<?php
define ('URL',str_replace("index.php","",(isset($_SERVER['HTTPS'])?"https":"http")."://$_SERVER[HTTP_HOST]$_SERVER[PHP_SELF]"));
define ("APP_PROTOCOL", stripos($_SERVER["SERVER_PROTOCOL"], "https") === true ? "https://" : "http://");
define ("APP_URL", APP_PROTOCOL . $_SERVER["HTTP_HOST"] . str_replace("public_html", "", dirname($_SERVER["SCRIPT_NAME"])) . "/");
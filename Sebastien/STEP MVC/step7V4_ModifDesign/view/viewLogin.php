<?php
ob_start();
$title='Page de connexion';
?>

<h2><?=$titre?></h2>

<div class=form-signin >
    <form action="<?=Router::makeURL("user/loginAnswer")?>" method=POST>
        
        <br><br>
        <label for="input" class="visually-hidden">Identifiant</label>
        <input type="text" id="pseudo" class="form-control" name="pseudo" placeholder="Votre Identifiant" required autofocus>
        <br><br>
        <label for="inputPassword" class="visually-hidden">Mot de passe</label>
        <input type="password" id="inputPassword" class="form-control" name="password" placeholder="Votre mot de passe" required>
        <br><br><br><br>
        <button class="w-100 btn btn-lg btn-primary" type="submit">Se connecter</button>
        <br><br><br><br><br><br><br><br>
    </form>
</div>
<?php
$content=ob_get_clean();
require ('template.php');
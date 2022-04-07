<?php
ob_start();
$title='Nouvel utilisateur';
?>

<h2><?=$titre?></h2>

<form action="<?=Router::makeURL("user/newAnswer")?>" class="form-signin" method=POST>
    <div class="form-check">
    <input class="form-check-input" type="checkbox" value="0" id="flexCheckDefault" name="priorite">

    <label class="form-check-label" for="flexCheckDefault">
        Administrateur
    </label>
    </div>
    <div class="form-group">
        <input class="form-control" type="text" name="pseudo" placeholder="Définir le pseudo" required>
    </div>
    <div class="form-group">
        <input class="form-control" type="password" name="password" placeholder="Définir le mot de passe" required >
    </div>
    <div class="form-group">
        <input class="form-control" type="password" name="password_confirm" placeholder="Confirmation du mot de passe" required>
    </div>
    <button class="btn btn-primary"> Valider les changements</button>
    <input type="button" class="btn btn-primary" name="Annuler" value="Annuler" onClick="window.location.href='<?=Router::makeURL("user")?>';"/>
</form>
<br><br><br><br><br><br>
<?php
$content=ob_get_clean();
require('template.php');// on appelle la page template
//on ne ferme pas les balise php pour déboguer plus facilement
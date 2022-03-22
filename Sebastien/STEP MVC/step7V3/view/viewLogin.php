<?php
ob_start();
?>

<h2><?=$titre?></h2>

<div class=form-signin >
    <form action="<?=Router::makeURL("user/loginAnswer")?>" method=POST>
        <h1 class="h3 mb-3 fw-normal">Connectez-vous</h1>
        <label for="input" class="visually-hidden">Pseudo</label>
        <input type="text" id="pseudo" class="form-control" name="pseudo" placeholder="Pseudo" required autofocus>
        <label for="inputPassword" class="visually-hidden">Password</label>
        <input type="password" id="inputPassword" class="form-control" name="password" placeholder="Password" required>

        <button class="w-100 btn btn-lg btn-primary" type="submit">Login</button>
        <p class="mt-5 mb-3 text-muted">&copy; 2021-2022</p>
    </form>
</div>
<?php
$content=ob_get_clean();
require ('template.php');
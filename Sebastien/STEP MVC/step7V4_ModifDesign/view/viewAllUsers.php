<?php
ob_start();
//Affichage des données
?>

<h2><?=$titre?></h2>
<div class="table-responsive">
    <table class="table table-striped table-sm">
        <thead>
            <tr>
            <th scope="col">pseudo</th>
            <th scope="col">priorite</th>
            </tr>
        </thead>
        <tbody>
        
        <?php
        foreach ($data as $laData): ?>
            <tr>
                <td>
                    <a href=<?=Router::makeURL("user/pseudo/".$laData->getPseudo())?>>
                        <?=$laData->getPseudo()?>
                    </a>
                </td>
                <td>
                    <?=$laData->getPriorite()?>
                </td>
                <td>
                    <input type="button" class="btn btn-primary" name="Supprimer" value="Supprimer" onClick="window.location.href='<?=Router::makeURL("user/delete/".$laData->getPseudo())?>';"/>
                </td> 
            </tr>
        <?php endforeach;?>
        
        </tbody>
    </table>
</div>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<?php
$content=ob_get_clean();
require('template.php');// on appelle la page template
?>
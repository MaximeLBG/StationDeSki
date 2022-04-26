<?php
ob_start();
//Affichage des données
$title='Liste utilisateurs';
?>

<h2><?=$titre?></h2>
<div class="table-responsive">
    <table class="tabview">
        <thead>
            
            <tr style="background-color: #6e6e6e">
            <th scope="th-sm">Pseudo</th>
            <th scope="th-sm">Priorité</th>
            <th scope="th-sm">Action sur l'utilisateur</th>
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
    <br>
</div>

<a href="http://localhost/MVC/ProjetStationDeSki/step7V4_ModifDesign/user/new"><input type="button" name="Ajouter un utilisateur "value="   Ajouter un utilisateur   "/></a>

<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<?php
$content=ob_get_clean();
require('template.php');// on appelle la page template
?>
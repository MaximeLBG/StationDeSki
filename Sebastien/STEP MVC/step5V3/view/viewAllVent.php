<?php
ob_start();
//Affichage de toutes les températures
?>



<div class="table-responsive">
    <table class="table table-striped table-sm">
        <thead>
            <tr>
                <th scope="col">Id</th>
                <th scope="col">IdCapteur</th>
                <th scope="col">Instant D'acquisition</th>
                <th scope="col">Vitesse du vent</th>
                <th scope="col">Direction du vent</th>
                <th scope="col">Température</th>
            </tr>
            </thead>
            <tbody>
               
            <?php
                foreach ($data as $laData): ?>
            <tr>
               
            <td><?=$laData->getId()?></td>
            <td><?=$laData->getIdCapteur() ?></td>
            <td><?=$laData->getDateTme()?></td>
            <td><?=$laData->getVitesse()?> km/h </td>
            <td><?=$laData->getDirvent()?>°</td>
            <td><?=$laData->getTemp()?>°C</td>
        
            </tr>

<?php endforeach;?>
            <td></td>
            <td></td>
            <td></td>
            <td></td>

            </tr>
            </tbody>
        </table>
    </div>

<?php
$content=ob_get_clean();
require ('template.php');
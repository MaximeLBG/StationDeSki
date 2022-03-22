<?php
ob_start();
//Affichage de toutes les températures
?>

<script type="text/javascript">
    var lesDates=<?= json_encode($lesDates) ?>;
    var lesMesures=<?= json_encode($lesMesures) ?>;
</script>


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
            <td>
                <a href=<?=Router::makeURL("vent/".$laData->getidCapteur())
                //redirection vers l'url des num de capteur
                ?>>     
                    <?=$laData->getIdCapteur() ?>                  
                </a>
            </td>
            
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


<canvas id="myChart" width="400" height="400"></canvas>

<?php
$content=ob_get_clean();
require ('template.php');
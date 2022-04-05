<?php
ob_start();
//Affichage de toutes les températures
$title='Données enregistrées';
?>

<script type="text/javascript">
    var lesDates=<?= json_encode($lesDates) ?>;
    var lesMesures=<?= json_encode($lesMesures) ?>;
</script>

<br>
<div class="table-responsive">
    <table id="dtBasicExample" class="table table-striped table-bordered table-sm" cellspacing="0" style="width:100%">
        <thead>
            <tr style="background-color: #6e6e6e">
                <th class="th-sm">Id</th>
                <th class="th-sm">IdCapteur</th>
                <th class="th-sm">Instant D'acquisition</th>
                <th class="th-sm">Vitesse du vent</th>
                <th class="th-sm">Direction du vent</th>
                <th class="th-sm">Température</th>
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
            <td><?=$laData->getVitesse()?> m/s </td>
            <td><?=$laData->getDirvent()?>°</td>
            <td><?=$laData->getTemp()?>°C</td>
        
            </tr>

<?php endforeach;?>
           

            </tr>
            </tbody>
            <tfoot>
                <tr style="background-color: #6e6e6e">
                
                    <th class="th-sm">Id</th>
                    <th class="th-sm">IdCapteur</th>
                    <th class="th-sm">Instant D'acquisition</th> 
                    <th class="th-sm">Vitesse du vent</th>
                    <th class="th-sm">Direction du vent</th>
                    <th class="th-sm">Température</th>         
                </tr>
            </tfoot>
        </table>
    </div>


<canvas id="myChart"></canvas>

<?php
$content=ob_get_clean();
require ('template.php');
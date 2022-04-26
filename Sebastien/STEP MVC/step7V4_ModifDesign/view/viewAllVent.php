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
    <table id="dtBasicExample" class="tabview" cellspacing="0" style="width:100%">
        <thead>
            <tr style="background-color: #6e6e6e">
                <th class="th-sm"> Id </th>
                <th class="th-sm"> IdCapteur </th>
                <th class="th-sm"> Instant D'acquisition </th>
                <th class="th-sm"> Vitesse du vent </th>
                <th class="th-sm"> Direction du vent </th>
                <th class="th-sm"> Température </th>
                <th class="th-sm"> Etat de l'alerte </th>
            </tr>
            </thead>
            <tbody>
               
            <?php
                foreach ($data as $laData): ?>
            
            <?php
            if($laData->getSeuilDepasse() == 1){
            ?>
                <tr bgcolor="red">
            <?php }
            ?>
            <?php
            if($laData->getSeuilDepasse() == 2){
            ?>
                <tr bgcolor="orange">
            <?php }
            ?>

            
            
            
            
            

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

            
                <?php
                    if($laData->getSeuilDepasse() == 0)
                    {
                ?>
                    <td>Rien à signaler </td>
                <?php }
                    if($laData->getSeuilDepasse() == 1){
                ?>
                    <td>ALERTE, VENTS VIOLENTS :     
                    <input type="button"  name="Acquitte" value="Acquittement alarme" onClick="window.location.href='<?=Router::makeURL("Param/Acquitte")?>';"/>
                </td>
                <?php 
                    }    
                ?>
                <?php
                    if($laData->getSeuilDepasse() == 2){
                ?>
                    <td> L'alarme à été aquittée par un administrateur</td>
                <?php }
                ?>
            </tr>

            
<?php endforeach;?>
           

            </tr>
            </tbody>
            <tfoot>
                <tr style="background-color: #666666">
                
                    <th class="th-sm">Id</th>
                    <th class="th-sm">IdCapteur</th>
                    <th class="th-sm">Instant D'acquisition</th> 
                    <th class="th-sm">Vitesse du vent</th>
                    <th class="th-sm">Direction du vent</th>
                    <th class="th-sm">Température</th>
                    <th class="th-sm">Etat de l'alerte</th>       
                </tr>
            </tfoot>
        </table>
    </div>


<canvas id="myChart"></canvas>

<?php
$content=ob_get_clean();
require ('template.php');
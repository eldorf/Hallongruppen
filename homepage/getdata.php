<?php

// set file to write 
$alcoFile = "alko_value"; 
$thermoFile = "thermo_value"; 

// open file  
$falco = fopen($alcoFile, "r") or die("Could not open alco file!");  
$fthermo = fopen($thermoFile, "r") or die("Could not open thermo file!");  

$alcoValue = fread($falco, filesize($alcoFile));

if($alcoValue < 400) {
$calculatedPromille = 0; 
}
else {
$calculatedPromille = $alcoValue / 0.2;
} 

$thermoValue = fread($fthermo, filesize($thermoFile));

// close files
fclose($falco);
fclose($fthermo);

// return result
echo $calculatedPromille.";".$thermoValue;

?>

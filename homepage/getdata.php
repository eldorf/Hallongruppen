<?php

// set file to write 
//$file = "/dev/ttyAMA0"; 
$alcoFile = "alko_value"; 
$thermoFile = "thermo_value"; 
// open file  
$falco = fopen($alcoFile, "r") or die("Could not open alco file!");  
$fthermo = fopen($thermoFile, "r") or die("Could not open thermo file!");  

$alcoValue = fread($falco, filesize($alcoFile));
$thermoValue = fread($fthermo, filesize($thermoFile));
//while(strpos($contents , '0:') === true) {
//	$fp = fopen($file, "r") or die("Could not open file!");  
//	$contents = fread($fp, filesize($file));
//}
//$result = substr($contents, 0, strlen($contents)); 
 
fclose($alcoFile);
fclose($thermoFile);
echo $alcoValue.";".$thermoValue;
//echo $result;

?>

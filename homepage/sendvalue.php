<?php

$drinkerFile = "drinker"; 
$alcoFile = "alko_value"; 
$thermoFile = "thermo_value"; 

// open files
$fdrinker = fopen($drinkerFile, "r") or die("Could not open alco file!");  
$falco = fopen($alcoFile, "r") or die("Could not open alco file!");  
$fthermo = fopen($thermoFile, "r") or die("Could not open thermo file!");  

// read values
$drinkerValue = fread($fdrinker, filesize($drinkerFile));
$alcoValue = fread($falco, filesize($alcoFile));
$thermoValue = fread($fthermo, filesize($thermoFile));

// compose data  to send 
$data = $drinkerValue.", ".$alcoValue;

// URL to Xively
$url = "https://api.xively.com/v2/feeds/843323762.csv";

// compose headers
$opts = array(
	'http' => array(
		'method' => 'PUT', 
		'header' => 'X-ApiKey: dZvK4Wcj2AkZzY1uyOpUezcO4LSlQbhNS0zCF4PzaJpcLW4a', 
		'content' => $data
	)
);
	
// perform PUT request and get output, but don't care about the result...
$context  = stream_context_create($opts);
$result = file_get_contents( $url, false, $context);

// close files
fclose($fdrinker);
fclose($falco);
fclose($fthermo);

?>
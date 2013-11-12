<?php

	//get the q parameter from URL
	$drinker=$_GET["drinker"];

	//lookup all hints from array if length of q>0
	if (strlen($drinker) > 40){
		echo "Name must not be more than 40 chars";
	}
	else {
		$file = "drinker"; 
		$fp = fopen($file, "w") or die("Could not open file!");
		fwrite($fp, $drinker) or die("Could not write to file");  
		// close file  
		fclose($fp); 
		
		echo "Commence drinking ".$drinker."!" ;
	}

?>
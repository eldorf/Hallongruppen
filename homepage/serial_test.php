<?php

error_reporting(E_ALL);
ini_set('display_errors', '1');
include "php_serial.class.php";
 
$serial = new phpSerial;
$serial->deviceSet("/dev/ttyAMA0");
$serial->confBaudRate(115200);
$serial->confParity("none");
$serial->confCharacterLength(8);
$serial->confStopBits(1);
$serial->deviceOpen();

sleep(3);

$read = $serial->readPort(); 
echo "Read: ".$read;

$serial->deviceClose();
echo "I've read a message! \n\r";
?>

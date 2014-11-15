<?php
	$host="localhost";
	$database="honordb";
	$username="296user";
	$password="abc123";

	$mysqli=new mysqli($host, $username, $password, $database);
	if(mysqli_connect_errno()){
		echo "0";
		echo "connect";
		exit;
	}
	$query="
		INSERT INTO info
		VALUES(".$_GET['id'].",".$_GET['latitude'].",".$_GET['longitude'].",\"".$_GET['message']."\");";
	$result=$mysqli->query($query);
	if($mysqli->errno){
		echo "0";
		echo "no table";
		exit;
	}
	echo "1";
?>

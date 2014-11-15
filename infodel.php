<?php
	$host="localhost";
	$database="honordb";
	$username="296user";
	$password="abc123";

	$mysqli=new mysqli($host, $username, $password, $database);
	if(mysqli_connect_errno()){
		echo "0";
		exit;
	}
	$query="
		DELETE FROM info
		WHERE id=".$_GET['id']." AND latitude=".$_GET['latitude']." AND longitude=".$_GET['longitude']." AND message=\"".$_GET['message']."\";";
	$result=$mysqli->query($query);
	echo $query;
	if($mysqli->errno){
		echo"0";
		exit;
	}
	echo "1";
?>

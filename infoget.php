<?php
	$host="localhost";
	$database="honordb";
	$username="296user";
	$password="abc123";

	$mysqli=new mysqli($host, $username, $password, $database);
	if(mysqli_connect_errno()){
		exit;
	}

	$r=63710000;
	$dif_lati=$_GET['distance']/$r;
	$dif_longi=$_GET['distance']/$r/cos(40/360*2*pi());

	$lati_max=$_GET['latitude']+$dif_lati;
	$lati_min=$_GET['latitude']-$dif_lati;
	$longi_max=$_GET['longitude']+$dif_longi;
	$longi_min=$_GET['longitude']-$dif_longi;

	$query="
		SELECT * FROM info
		WHERE id <>".$_GET['id']." AND latitude<".$lati_max." AND latitude > ".$lati_min." AND longitude < ".$longi_max." AND longitude > ".$longi_min.";";
	$result=$mysqli->query($query);
	if($mysqli->errno){
		echo "select error";
		exit;
	}

	while($rows=mysqli_fetch_array($result)){
		echo $rows['id']." ".$rows['latitude']." ".$rows['longitude']." ".$rows['message'];
		echo "\n";
	}
?>

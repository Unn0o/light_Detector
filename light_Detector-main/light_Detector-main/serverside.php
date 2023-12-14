<html>
<head>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script>
        $(document).ready(function () {
            setInterval( function() {
                $("#main").load(location.href + " #val");
             }, 1000 );
        });
    </script>
</head>
<body style="align-items:center;">
  <div id="main">
    <?php
    echo "<div id='val' style='float: left; padding: 10px; text-align: center;'>";
    echo "<h2>Sensor 1</h2><br>";
    $myfile = fopen("knowledge.txt", "r+") or die("Unable to open file!");
    fwrite($myfile, $_POST['sensorValue']);
    while(!feof($myfile)) {
        echo fgets($myfile) . "<br>";
    }
    fclose($myfile);
    echo "</div>";
    ?>
  </div>
</body>
</html>

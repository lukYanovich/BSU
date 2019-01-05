<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/css/bootstrap.min.css"
      integrity="sha384-rwoIResjU2yc3z8GV/NPeZWAv56rSmLldC3R/AZzGRnGxQQKnKkoFVhFQhNUwEyJ" crossorigin="anonymous">


<?php
$table = "People";#$_GET['table'];

$conn = mysqli_connect("localhost", "root", "","Cities") or die(mysqli_error());

$result = mysqli_query($conn,"SELECT * FROM $table") or die (mysqli_error());


echo '<table border="1" cellpadding="5" style="border-collapse: collapse;">';

$printed_headers = false;
while($row = mysqli_fetch_assoc($result))
{
    if (!$printed_headers) {
        echo "<tr>";
        foreach (array_keys($row) as $header)
        {
            echo "<th>$header</th>";
        }
        echo "</tr>";
        $printed_headers = true;
    }

    echo "<tr>";
    foreach ($row as $val)
    {
        echo "<td>$val</td>";
    }
    echo "</tr>";
}
echo '</table>';

mysqli_close($conn);
?>


<script src="https://cdnjs.cloudflare.com/ajax/libs/tether/1.4.0/js/tether.min.js"
        integrity="sha384-DztdAPBWPRXSA/3eYEEUWrWCy7G5KFbe8fFjk5JAIxUYHKkDx6Qin1DkWx51bBrb"
        crossorigin="anonymous"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/js/bootstrap.min.js"
        integrity="sha384-vBWWzlZJ8ea9aCX4pEW3rVHjgjt7zpkNpZk+02D9phzyeVkE+jo0ieGizqPLForn"
        crossorigin="anonymous"></script>

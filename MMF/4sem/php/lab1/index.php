<link rel="stylesheet" href="style/style.css">
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/css/bootstrap.min.css" integrity="sha384-rwoIResjU2yc3z8GV/NPeZWAv56rSmLldC3R/AZzGRnGxQQKnKkoFVhFQhNUwEyJ" crossorigin="anonymous">


<?php
function print_matrix($matrix)
{
    echo("<table>");
    foreach ($matrix as &$arr) {
        echo("<tr>");
        foreach ($arr as &$element) {
            echo("<td><pre> $element </pre></td>");
        }
        echo("</tr>");
    }
    echo("</table>");
}

#iniz from file
$file=file_get_contents("./resources/input.json");
$data=json_decode($file);
$n=$data->{'n'};
$m=$data->{'m'};
$k=$data->{'k'};
#iniz matrix
$matrix=[];
for($i = 0; $i < $n; $i++) {
    $arr = [];
    for ($j = 0; $j < $m; $j++) {
        array_push($arr, random_int(-5, 5));
    }
    array_push($matrix, $arr);
}

#print
echo ("
    <h2>условие:</h2>
    <img src='task.jpg'>
    <br>
    <p>
        n = $n, m = $m, k = $k
    </p>
");

echo("matrix:<br>");
print_matrix($matrix);

#solution
$sum = 0;
if ($n >= $k) {
    for ($i = 0; $i < $n; $i++) {
        for ($j = 0; $j < $m; $j++) {
            if ($i - $j = $k) {
                $sum += $matrix[$i][$j];
            }
        }
    }
}
echo ("<br>sum: $sum");
?>


<script src="https://cdnjs.cloudflare.com/ajax/libs/tether/1.4.0/js/tether.min.js" integrity="sha384-DztdAPBWPRXSA/3eYEEUWrWCy7G5KFbe8fFjk5JAIxUYHKkDx6Qin1DkWx51bBrb" crossorigin="anonymous"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/js/bootstrap.min.js" integrity="sha384-vBWWzlZJ8ea9aCX4pEW3rVHjgjt7zpkNpZk+02D9phzyeVkE+jo0ieGizqPLForn" crossorigin="anonymous"></script>

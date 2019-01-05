<link rel="stylesheet" href="style/style.css">
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/css/bootstrap.min.css" integrity="sha384-rwoIResjU2yc3z8GV/NPeZWAv56rSmLldC3R/AZzGRnGxQQKnKkoFVhFQhNUwEyJ" crossorigin="anonymous">


<?php

function f($x){ return 0.7*$x*$x - 2*$x - 4; }
function f_der($x) { return 1.4*$x -2; }

function newton_method($a, $b, $eps, $f, $f_der){
    $x_beg = $a;
    $x_next = $b;
    while(abs(f($x_next) - f($x_beg)) >= $eps ){
        $x_beg = $x_next;
        $x_next = $x_beg - f($x_beg)/f_der($x_beg);
    }
    return $x_next;
}

#iniz from file
$file=file_get_contents("./resources/input.json");
$data=json_decode($file);
$a=$data->{'a'};
$b=$data->{'b'};
$eps=$data->{ 'eps' };


#print
echo ("
    <h2>условие:</h2>
    <img src='task.jpg'>
    <br><br>
    <pre>
        a = $a, b = $b, eps = $eps
    </pre>
    <img src='graphic.png'>
    <br>
");

echo newton_method($a, $b, $eps, $f, $f_der);

?>


<script src="https://cdnjs.cloudflare.com/ajax/libs/tether/1.4.0/js/tether.min.js" integrity="sha384-DztdAPBWPRXSA/3eYEEUWrWCy7G5KFbe8fFjk5JAIxUYHKkDx6Qin1DkWx51bBrb" crossorigin="anonymous"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/js/bootstrap.min.js" integrity="sha384-vBWWzlZJ8ea9aCX4pEW3rVHjgjt7zpkNpZk+02D9phzyeVkE+jo0ieGizqPLForn" crossorigin="anonymous"></script>

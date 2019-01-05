<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/css/bootstrap.min.css"
      integrity="sha384-rwoIResjU2yc3z8GV/NPeZWAv56rSmLldC3R/AZzGRnGxQQKnKkoFVhFQhNUwEyJ" crossorigin="anonymous">
<link rel="stylesheet" href="styles/style.css">


<?php
function _print($arr)
{
    echo "<pre><span>список:</span>\n";
    foreach ($arr as $el) {
        echo "$el\n";
    }
    echo "</pre>";
}


#вывод задачи
echo "<img src=\"task/task.jpg\">";


$filename = './resources/list.txt';
$file = file_get_contents($filename, true);
$array_of_referer = preg_split("/[\n]+/", $file);
$list_referer = $_SERVER['HTTP_REFERER'];
if ($list_referer) {
    $flag = false;
    foreach ($array_of_referer as $str) {
        if (!strcmp($str, $list_referer)) {
            $flag = true;
            break;
        }
    }
    if (!$flag) {
        array_push($array_of_referer, $_SERVER['HTTP_REFERER']);
        file_put_contents($filename, PHP_EOL . $list_referer, FILE_APPEND);
    }
}
_print($array_of_referer);
?>


<script src="https://cdnjs.cloudflare.com/ajax/libs/tether/1.4.0/js/tether.min.js"
        integrity="sha384-DztdAPBWPRXSA/3eYEEUWrWCy7G5KFbe8fFjk5JAIxUYHKkDx6Qin1DkWx51bBrb"
        crossorigin="anonymous"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/js/bootstrap.min.js"
        integrity="sha384-vBWWzlZJ8ea9aCX4pEW3rVHjgjt7zpkNpZk+02D9phzyeVkE+jo0ieGizqPLForn"
        crossorigin="anonymous"></script>

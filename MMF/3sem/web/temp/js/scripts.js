$(document).ready(function (e) {
    $("#checkOfRoad").click(function () {
        if ($(this).is(":checked")) {
            $("#dateWhere").attr("disabled", false);
        } else {
            $("#dateWhere").attr("disabled", true);
        }
    });

    $("#imgSwap").click(function () {
        let temp = $("#stationFrom").val();
        $("#stationFrom").val($("#stationWhere").val());
        $("#stationWhere").val(temp);
    });

    $("#header").fadeTo(100, 1, function () {
        $("html, body").animate({
            scrollTop: $("#content").offset().top
        }, 2000);
    });

    $("#tableWithTrains tr").click(function () {   
        alert($(this).find("td.d-none").html());
    });
    
    $("#tableWithPlaces tr").click(function () {   
        alert($(this).find("td.d-none").html());
    });


});

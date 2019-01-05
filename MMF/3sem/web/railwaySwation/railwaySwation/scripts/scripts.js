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

    /*$("#tableWithTrains tr").click(function () {   
        alert($(this).find("td.d-none").html());
    });
    
    $("#tableWithPlaces tr").click(function () {   
        alert($(this).find("td.d-none").html());
    });*/

    $("#tableWithTrains tr").click(function (e) {
        var nextPageUrl = $('input[name="url-to-nex-page"]').val();
        var trainId = $(e.currentTarget).data("train");
        if(nextPageUrl.length > 0 && typeof(trainId) != "undefined"){
            $('#goToNextPage').attr('href', nextPageUrl + '/' + trainId);
        }
    });

});

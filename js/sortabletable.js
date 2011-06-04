$(document).ready(function () {
    
    $(function() {
        $( ".sortabletable tbody" ).sortable({
            placeholder: "ui-state-highlight",
//            handle: ".tr-sort",
            axis: "y",
            forcePlaceholderSize: true,
            update: function (event, ui) {
                var order = $(this).sortable('serialize'); //serialize shoots back an array of all the ID's
//                $("#info").load("process-sortable.php?"+order);
//                alert(order);
            }
        });
        $( ".sortabletable" ).disableSelection();

    });

});
$(document).ready(function () {
    
    $(function() {
        $( ".sortablelist" ).sortable({
            placeholder: "ui-state-highlight",
            forcePlaceholderSize: true,
            update : function () {
                var order = $(this).sortable('serialize'); //serialize shoots back an array of all the ID's
//                $("#info").load("process-sortable.php?"+order);
//                $.ajax({
//                 type: "POST",
//                 url: "url.php",
//                 data: "name=John&location=Boston",
//                 success: function(msg) {
//                     alert( "Data Saved: " + msg);
//                 }
//                });
                alert(order);
            }
            //handle: ".handle"
        });
        $( ".sortablelist" ).disableSelection();
        
    });

});
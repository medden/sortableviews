Drupal.behaviors.sortableviews = function(context) {
    var viewsName       = Drupal.settings.sortablelist.views_name;
    var viewsDisplay    = Drupal.settings.sortablelist.views_display;
    var viewsType       = Drupal.settings.sortablelist.views_type;
    
    $(function() {
        $(".sortablelist", context).sortable({
            placeholder: "ui-state-highlight",
            forcePlaceholderSize: true,
            update : function () {
                var order = $(this).sortable('serialize'); //serialize shoots back an array of all the ID's
//                $("#info").load("process-sortable.php?"+order);
                $.ajax({
                 type: "POST",
                 url: "sortableviews/"+viewsType,
//                 data: { 0: order, 1: viewsName, 2: viewsDisplay, 3: viewsType}, // use json for multiple strings
                 data: order+"&views_name="+viewsName+"&views_display="+viewsDisplay, // doest the trick, but not sure if it should be written like this.
                 success: function(msg) {
//                     alert( "Order saved" );
                 }
                });
//                alert(order);
//                alert(viewsName);
//                alert(viewsDisplay);
            }
            //handle: ".handle"
        });
        $(".sortablelist", context).disableSelection();
        
    });



}







///*
// * Save the current state of the homebox
// *
// * @param save
// *   Optionally, A JSON-encoded custom block object. This is passed in
// *   because we want to first save the current state, then add the
// *   custom block so changes are preserved, and that we can only
// *   add if and when the first ajax call is successful.
// */
//Drupal.homebox.saveBoxes = function(save) {
//  var color = new String();
//  var open = new Boolean();
//  var block = new String();
//  var name = $('#homebox').find('input:hidden.name').val();
//  var blocks = {};
//
//  // Show progress dialog
//  $('#homebox-save-message').dialog('open');
//
//  $columns = Drupal.homebox.equalizeColumnsHeights($columns);
//  $columns.each(function(colIndex) {
//    // Determine region
//    var colIndex = colIndex + 1;
//    $(this).find('>.homebox-portlet').each(function(boxIndex) {
//      // Determine block name
//      block = $(this).find('input:hidden.homebox').val();
//
//      // Determine visibility
//      visible = 0;
//      if ($(this).is(':visible')) {
//        visible = 1;
//      };
//
//      // Determine custom color, if any
//      attributes = $(this).attr('class').split(' ');
//      color = 'default';
//      for (a in attributes) {
//        if (attributes[a].substr(0, 14) == 'homebox-color-') {
//          color = attributes[a].substr(14);
//        }
//      }
//
//      // Determine state (open/closed)
//      open = $(this).find(".portlet-content").is(':visible');
//
//      // Build blocks object
//      if (block.search('homebox_') != -1) {
//        // If block is custom, we need more data
//        blocks[block] = {
//          region: colIndex,
//          status: visible,
//          color: color,
//          open: open,
//          title: $(this).find('.portlet-title').html().stripTags(),
//          content: $(this).find('.portlet-content').html(),
//          module: 'homebox',
//          delta: block.replace('homebox_', '')
//        }
//      }
//      else {
//        blocks[block] = {
//          region: colIndex,
//          status: visible,
//          color: color,
//          open: open
//        }
//      }
//    });
//  });
//
//  // Encode JSON
//  blocks = JSON.stringify(blocks);
//
//  $.ajax({
//    url: Drupal.settings.basePath + '?q=homebox/js/save',
//    type: "POST",
//    cache: "false",
//    dataType: "json",
//    data: {name: name, blocks: blocks},
//    success: function() {
//      $('#homebox-save-message').dialog('close');
//      $('#homebox-changes-made').hide();
//
//      if (save) {
//        // If a block was passed in, save it as a
//        // custom block after ajax success.
//        Drupal.homebox.addItemAjax(name, save);
//      }
//    },
//    error: function() {
//      $('#homebox-save-message').html('<span style="color:red;">' + Drupal.t('Save failed. Please refresh page.') + '</span>');
//    }
//  });
//};
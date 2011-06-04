<?php
// $id$

/**
 * @file
 * Derives the view style plugins
 */

/**
 * Implementing hook_views_plugins
 */
function sortableviews_views_plugins() {
    return array(
        'module' => 'sortableviews',
        'style' => array(
            'sortablelist' => array(
                'path' => drupal_get_path('module', 'sortableviews') .'/views',
                'title' => t('Sortable List'),
                'help' => t('Displays views results in a list and makes them sortable.'),
                'handler' => 'sortableviews_plugin_style_sortablelist', // see sortableviews_plugin_style_sortablelist.inc
                'theme' => 'sortablelist_view', // include in sortableviews.theme.inc as template_preprocess_sortableviews_view_sortablelist
                'theme file' => 'sortableviews.theme.inc', // where all the phptemplate_preprocess stuff in going on.
                'theme path' => drupal_get_path('module', 'sortableviews') .'/theme',
                'uses row plugin' => TRUE,
                'uses fields' => TRUE,
                'uses options' => TRUE, // yes, I'm going to include options
                'uses pager' => FALSE,
                'uses grouping' => TRUE,
                'type' => 'normal', // not sure what the other types are
                'parent' => 'list', // this style is based on the list style.
            ),
           // 'sortabletable' => array(
               // 'path' => drupal_get_path('module', 'sortableviews') .'/views',
               // 'title' => t('Sortable Table'),
               // 'help' => t('Displays views results in a table and makes them sortable.'),
               // 'handler' => 'sortableviews_plugin_style_sortabletable', // see sortableviews_plugin_style_sortabletable.inc
               // 'theme' => 'sortabletable_view', // include in sortableviews.theme.inc as template_preprocess_sortableviews_view_sortabletable
               // 'theme file' => 'sortableviews.theme.inc', // where all the phptemplate_preprocess stuff in going on.
               // 'theme path' => drupal_get_path('module', 'sortableviews') .'/theme',
               // 'uses row plugin' => TRUE,
               // 'uses fields' => TRUE,
               // 'uses options' => TRUE, // yes, I'm going to include options
               // 'uses pager' => FALSE,
               // 'uses grouping' => TRUE,
               // 'type' => 'normal', // not sure what the other types are
               // 'parent' => 'table', // this style is based on the table style.
           // ),
        ),
    );
}

/**
 * Implementing hook_views_handlers
 */
function sortableviews_views_handlers() {
    return array(
      'info' => array(
          'path' => drupal_get_path('module', 'sortableviews') .'/views/handlers',
      ),
      'handlers' => array(
          // sort handlers
          'views_handler_sort_sortableviews_structure' => array(
              'parent' => 'views_handler_sort',
          ),
          // field handler
          'views_handler_field_sortableviews_structure' => array(
              'parent' => 'views_handler_field',

          ),
      ),
  );
}

/**
 * Implementing hook_views_data
 */
function sortableviews_views_data() {
  $data = array();

  $base_tables = array(
    'nid' => 'node',
    'uid' => 'users',
    'cid' => 'comments',
    'vid' => 'node_revisions',
    'tid' => 'term_data',
  );

  foreach ($base_tables AS $base_field => $base_table) {
    for ($i = 0; $i < 2; $i++) {
      $data['sortableviews_structure_'. $base_table . $i]['table'] = array(
        'group' => t('SortableViews'),
        'join' => array(
          $base_table => array(
            'table' => 'sortablelist',
            'left_field' => $base_field,
            'field' => 'nid',
//            'extra' => array(
//              array(
//                'field' => 'delta',
//                'operator' => '=',
//                'value' => $i,
//                'numeric' => TRUE,
//              ),
//            ),
          ),
        ),
      );
      $data['sortableviews_structure_'. $base_table . $i]['value'. $i] = array(
        'real field' => 'position',
        'title' => t($i == 0 ? 'Order' : 'Parent'),
        'field' => array(
          'handler' => 'views_handler_field_sortableviews_structure',
          'help' => t('This value provided by sortableviews is unique for each view.'),
          'click sortable' => $i == 0 ? TRUE : FALSE,
          'sortableviews_delta' => $i,
        ),
      );
      if ($i == 0) {
        $data['sortableviews_structure_'. $base_table . $i]['value'. $i]['sort'] = array(
          'handler' => 'views_handler_sort_sortableviews_structure',
          'help' => t('Sort by value'),
        );
      }
    }
  }
    //dsm($data);
    return $data;
}
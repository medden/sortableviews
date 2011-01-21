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
//                'uses pager' => false,
                'uses grouping' => TRUE,
                'type' => 'normal', // not sure what the other types are
                'parent' => 'list', // this style is based on the list style.
            ),
            'sortabletable' => array(
                'path' => drupal_get_path('module', 'sortableviews') .'/views',
                'title' => t('Sortable Table'),
                'help' => t('Displays views results in a table and makes them sortable.'),
                'handler' => 'sortableviews_plugin_style_sortabletable', // see sortableviews_plugin_style_sortabletable.inc
                'theme' => 'sortabletable_view', // include in sortableviews.theme.inc as template_preprocess_sortableviews_view_sortabletable
                'theme file' => 'sortableviews.theme.inc', // where all the phptemplate_preprocess stuff in going on.
                'theme path' => drupal_get_path('module', 'sortableviews') .'/theme',
                'uses row plugin' => TRUE,
                'uses fields' => TRUE,
                'uses options' => TRUE, // yes, I'm going to include options
//                'uses pager' => false,
                'uses grouping' => TRUE,
                'type' => 'normal', // not sure what the other types are
                'parent' => 'table', // this style is based on the table style.
            ),
        ),
    );
}

/**
 * Implementing hook_views_handlers
 */
//function sortableviews_views_handlers() {
//    return array(
//      'info' => array(
//          'path' => drupal_get_path('module', 'sortableviews') .'/views/handlers',
//      ),
//      'handlers' => array(
//          // sort handlers
//          'views_handler_sort_sortableviews_structure' => array(
//              'parent' => 'views_handler_sort',
//          ),
//          // field handler
//          'views_handler_field_sortableviews_structure' => array(
//              'parent' => 'views_handler_field',
//
//          ),
//      ),
//  );
//}

/**
 * Implementing hook_views_data
 */
//function sortableviews_views_data() {
//
//    $data = array();
//
//    $base_tables = array(
//        'nid' => 'node',
//        'uid' => 'users',
//        'cid' => 'comments',
//        'vid' => 'node_revisions',
//        'tid' => 'term_data',
//    );
//
//    // don't know what I'm doing here. just copying
//    foreach ($base_tables AS $base_field => $base_table) {
//
//            $data['sortableviews_structure_'. $base_table]['table'] = array(
//                'group' => t('SortableViews'),
//                'join' => array(
//                    $base_table => array(
//                        'table' => 'sortableviews_structure',
//                        'left_field' => $base_field,
//                        'field' => 'nid',
////                        'extra' => array(
////                            array(
////                                'field' => 'delta',
////                                'operator' => '=',
////                                'value' => '0',
////                                'numeric' => TRUE,
////                            ),
////                        ),
//                    ),
//                ),
//            );
//            $data['sortableviews_structure_'. $base_table]['value'] = array(
//                'real field' => 'position',
//                'title' => t('Order'),
//                'field' => array(
//                    'handler' => 'views_handler_field_sortableviews_structure',
//                    'help' => t('This value provided by sortableviews is unique for each view.'),
//                  ),
//            );
//            $data['sortableviews_structure_'. $base_table]['value']['sort'] = array(
//                    'handler' => 'views_handler_sort_sortableviews_structure',
//                    'help' => t('Sort by value'),
//            );
//    }
//
//    return $data;
//}

/**
 * Implementing hook_views_query_alter
 */
//function sortableviews_views_query_alter(&$view, &$query) {
//    dsm($view);
//    dsm($query);
//  $exists = FALSE;
////  for ($i = 0; $i < 2; $i++) {
//    if (isset($query->table_queue['sortableviews_structure_'. $view->base_table . '0'])) {
//      $exists = TRUE;
//    }
////  }
//  if (!$exists) {
//    // No "SortableViews: Order/Parent" fields available.
//    return;
//  }
//
//  // We look for a display of this view that uses arguments.
//  // If any of the displays uses arguments we'll use arguments for this display too, except the
//  // style plugin configuration of this display tells us explicitly something else.
//  $use_args = FALSE;
//  if (isset($view->style_plugin->options['sortableviews_arguments']['use_args'])) {
//    $use_args = !empty($view->style_plugin->options['sortableviews_arguments']['use_args']);
//  }
//  else {
//    foreach ($view->display AS $display_id => $display) {
//      if (isset($display->display_options['style_plugin'])) {
//        $display_options = $display->display_options;
//        // We don't care about the fact that displays probably don't contain
//        // all their information because of inheritance of the default display.
//        // We'll check the default display anyway.
//        if ($display_options['style_plugin'] == 'sortaabletable') {
//          if (!empty($display_options['style_options']['sortableviews_arguments']['use_args'])) {
//            $use_args = TRUE;
//          }
//        }
//      }
//    }
//  }
//
//  for ($i = 0; $i < 2; $i++) {
//    if (isset($query->table_queue['sortableviews_structure_'. $view->base_table . $i])) {
//      $query->table_queue['sortableviews_structure_'. $view->base_table . $i]['join']->extra[] = array(
//        'field' => 'view_name',
//        'operator' => '=',
//        'value' => $view->name,
//      );
//      $args = NULL;
//      if ($use_args) {
//        if (!empty($view->args)) {
//          $args = implode('/', $view->args);
//        }
//      }
//      $query->table_queue['sortableviews_structure_'. $view->base_table . $i]['join']->extra[] = array(
//        'field' => 'args',
//        'operator' => '=',
//        'value' =>  $args,
//      );
//    }
//  }
//}
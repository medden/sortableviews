<?php

// $Id$

/**
 * @file
 * sortableviews style plugin definition
 */

/**
 * Template preprocess function for the draggable list.
 * Based on the default views list preprocess function,
 * which only includes the unformatted preprocess function.
 */
function template_preprocess_sortablelist_view(&$vars) {
    template_preprocess_views_view_unformatted($vars);

    $module_path = drupal_get_path('module', 'sortableviews');
    drupal_add_js($module_path .'/js/sortablelist.js');
    drupal_add_css($module_path .'/css/sortablelist.css');


    // get views name
    $views_name = $vars['view']->name;
    // get views display name
    $views_display = $vars['view']->current_display;

    // send gathered info to js
    drupal_add_js( array('sortablelist' => array('views_name' => $views_name,
                                                 'views_display' => $views_display,
                                                 'views_type' => 'list')), 'setting');

    // extract all nid's listed in the views results.
    $results = $vars['view']->result;

    $node_ids = array();
    foreach ($results as $id => $key):
        $node_ids[] = $key->nid;
    endforeach;

    $vars['node_ids'] = $node_ids;
    // dsm($node_ids);
    // dsm($results);
    // dsm($vars);
}

/**
 * Template preprocess function for the draggable table.
 * Based on the default views table preprocess function,
 * which only includes the unformatted preprocess function.
 */
function template_preprocess_sortabletable_view(&$vars) {
    template_preprocess_views_view_table($vars);

    $module_path = drupal_get_path('module', 'sortableviews');
    drupal_add_js($module_path .'/js/sortabletable.js');
    drupal_add_css($module_path .'/css/sortabletable.css');
    //dsm($vars);
}
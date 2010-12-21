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
// function sortableviews_views_handlers() {

/**
 * Implementing hook_views_data
 */
// function sortableviews_views_data() {

/**
 * Implementing hook_views_query_alter
 */
// function sortableviews_views_query_alter(&$view, &$query) {
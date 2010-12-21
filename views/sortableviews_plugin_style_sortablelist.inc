<?php
// $Id$

/**
 * @file
 * sortablelist style plugin definition
 */

/**
 * Style plugin to render each item as a row in a draggable grid
 * Inherits all from views_plugin_list
 */
class sortableviews_plugin_style_sortablelist extends views_plugin_style_list {
    /**
     * Set default options 
     */
    function option_definition() {
        $options = parent::option_definition();

        $options['test'] = array('default' => 'some value');

        return $options;
    }

    /**
     * Render the given style.
     */
    function options_form(&$form, &$form_state) {
        // inherit options from style_list
        parent::options_form($form, $form_state);
        $form['test'] = array(
          '#type' => 'textfield',
          '#title' => t('Test field'),
          '#size' => 20,
          '#default_value' => $this->options['test'],
        );
    }


//    function validate() {
//        $errors = parent::validate();
//
//        // add validation options
//
//        return $errors;
//    }
//
//    /**
//     * Render the sortablelist style. (not sure this applies to this module.)
//     */
//    function render() {
//        $output = '';
//
//        return $output;
//    }


}
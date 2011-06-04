<?php
// $Id$
/**
 * @file sortablelist-view.tpl.php
 * (Modified version of views-view-list.tpl.php,
 * v 1.3 2008/09/30 19:47:11 merlinofchaos)
 *
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>
<div class="item-list">
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <<?php print $options['type']; ?> class="sortablelist">
    <?php foreach ($rows as $id => $row): ?>
  <?php //dsm($options); ?>
      <li class="<?php print $classes[$id]; ?>" id="<?php print 'nid_'.$node_ids[$id]; ?>"><div class="handle"></div><?php print $row; ?></li>
    <?php endforeach; ?>
  </<?php print $options['type']; ?>>
</div>
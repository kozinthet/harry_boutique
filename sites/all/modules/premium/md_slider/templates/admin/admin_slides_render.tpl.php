<?php
/**
 * @file: admin_tabs_render.tpl.php
 * User: Duy
 * Date: 1/28/13
 * Time: 4:39 PM
 */
?>
<?php if (count($slides) > 0):?>
<div id="md-tabs">
  <ul class="md-tabs-head clearfix">
  <?php for ($index = 0; $index < count($slides); $index++):?>
    <li class="tab-item first clearfix">
      <a class="tab-link" href="#tabs-<?php print $index+1;?>"><span class="tab-text">Slide <?php print $index+1;?></span></a>
      <span class="ui-icon ui-icon-close">Remove Tab</span>
    </li>
  <?php endfor;?>
  </ul>
  <?php foreach ($slides as $index => $slide):?>
    <div id="tabs-<?php print $index+1;?>" class="md-tabcontent clearfix" data-timelinewidth="<?php print $slide->settings['timelinewidth'];?>">
      <div class="settings">
        <a href="#" class="panel-settings-link">[Settings]</a> &nbsp;
        <a class="panel-clone" href="#">[Clone slide]</a>
        <input type="hidden" autocomplete="off" class="panelsettings" value='<?php print drupal_json_encode($slide->settings);?>' />
      </div>
      <div class="md-slidewrap<?php print $class_fullwidth;?>" style="height: <?php print $slider->settings['height'];?>px;<?php if(!$slider->settings['full_width']): print 'width:' . $slider->settings['width'] . 'px'; endif; ?>">
        <div class="md-slide-image"><img src="<?php print $slide->background_url;?>" /></div>
        <div class="md-objects" style="width: <?php print $slider->settings['width'];?>px; height: <?php print $slider->settings['height'];?>px;">
        	<?php foreach ($slide->layers as $layer) { print theme('admin_layers_render', array('layer' => $layer));}?>
        </div>
      </div>
    </div>
  <?php endforeach;?>
</div>
<?php else:?>
<div id="md-tabs">
    <ul class="md-tabs-head clearfix">
        <li class="tab-item first clearfix">
            <a class="tab-link" href="#tabs-1"><span class="tab-text">Slide 1</span></a>
            <span class="ui-icon ui-icon-close">Remove Tab</span>
        </li>
    </ul>
    <div id="tabs-1" class="md-tabcontent clearfix" data-timelinewidth="<?php print $slider->settings['delay'];?>">
        <div class="settings">
          <a href="#" class="panel-settings-link">[Settings]</a> &nbsp;
          <a class="panel-clone" href="#">[Clone slide]</a>
          <input type="hidden" autocomplete="off" class="panelsettings" value='{"slide_id": -1, "background_image": -1, "custom_thumbnail": -1, "transitions": []}' /></div>
        <div class="md-slidewrap<?php print $class_fullwidth;?>" style="height: <?php print $slider->settings['height'];?>px;<?php if(!$slider->settings['full_width']): print 'width:' . $slider->settings['width'] . 'px'; endif; ?>">
            <div class="md-slide-image"><img src="<?php print $default_bg;?>"<?php if(!$slider->settings['full_width']): ?> width="<?php print $slider->settings['width'];?>" height="<?php print $slider->settings['height'];?>"<?php endif; ?> /></div>
            <div class="md-objects" style="width: <?php print $slider->settings['width'];?>px; height: <?php print $slider->settings['height'];?>px;">
            </div>
        </div>
    </div>
</div>
<?php endif;?>

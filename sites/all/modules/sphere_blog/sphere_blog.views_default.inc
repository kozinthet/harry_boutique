<?php
/**
 * @file
 * sphere_blog.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sphere_blog_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'blog_categories';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Blog Categories';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Blog Categories';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'tags' => 'tags',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['blog_categories'] = $view;

  $view = new view();
  $view->name = 'view_blog';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Blog';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Blog';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  /* Field: Content: Blog Date */
  $handler->display->display_options['fields']['field_blog_date']['id'] = 'field_blog_date';
  $handler->display->display_options['fields']['field_blog_date']['table'] = 'field_data_field_blog_date';
  $handler->display->display_options['fields']['field_blog_date']['field'] = 'field_blog_date';
  $handler->display->display_options['fields']['field_blog_date']['label'] = '';
  $handler->display->display_options['fields']['field_blog_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_blog_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blog_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_blog_date']['settings'] = array(
    'format_type' => 'news',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_class'] = 'blog-date';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php

$bdate = strtotime($data->_field_data[\'nid\'][\'entity\']->field_blog_date[\'und\'][0][\'value\']);
echo "<span class=\'day\'>".date(\'d\', $bdate)."</span>";
echo "<span class=\'month\'>".date(\'M\', $bdate)."</span>";
echo "<span class=\'year\'>".date(\'Y\', $bdate)."</span>";

?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'continue reading';
  $handler->display->display_options['fields']['body']['alter']['more_link_path'] = '[path]';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Blog Author */
  $handler->display->display_options['fields']['field_blog_author']['id'] = 'field_blog_author';
  $handler->display->display_options['fields']['field_blog_author']['table'] = 'field_data_field_blog_author';
  $handler->display->display_options['fields']['field_blog_author']['field'] = 'field_blog_author';
  $handler->display->display_options['fields']['field_blog_author']['label'] = '';
  $handler->display->display_options['fields']['field_blog_author']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_blog_author']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'blog_listing_large',
    'image_link' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="blog-heading col-md-12 cols-sm-12 col-xs-12 clearfix">
<div class="blog-date-container col-md-2 col-sm-2 col-xs-3">
<div class="blog-date-inner"><p>[php]</p></div>
</div>
<div class="blog-title-container col-md-10 col-sm-10 col-xs-8">
<h3 class="blog-title">[title]</h3>
<p class="blog-author">Written by [field_blog_author]</p>
</div>
</div>
<div class="blog-image col-md-12 col-sm-12 col-xs-12">[field_image]</div>
<div class="blog-description col-md-12 col-sm-12 col-xs-12">[body]</div>
<div class="blog-links col-md-12 col-sm-12 col-xs-12">
<div class="blog-tags col-md-6 col-sm-6 col-xs-12">
<span class="icon-tag"></span> [field_tags]
</div>
<div class="blog-share   col-md-6 col-sm-6 col-xs-12 clearfix">
<div class="share-text">
<a href="https://www.facebook.com/sharer/sharer.php?u=[path]" class="icon-facebook"></a>
<a href="https://twitter.com/intent/tweet?u=[path]" class="icon-twitter"></a>
<a href="http://www.linkedin.com/shareArticle?url=[path]" class="icon-linkedin"></a>
</div>
<div class="share-this-text"> Share this article:</div>
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Blog Date -  start date (field_blog_date) */
  $handler->display->display_options['sorts']['field_blog_date_value']['id'] = 'field_blog_date_value';
  $handler->display->display_options['sorts']['field_blog_date_value']['table'] = 'field_data_field_blog_date';
  $handler->display->display_options['sorts']['field_blog_date_value']['field'] = 'field_blog_date_value';
  $handler->display->display_options['sorts']['field_blog_date_value']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Blog Date -  start date (field_blog_date) */
  $handler->display->display_options['arguments']['field_blog_date_value']['id'] = 'field_blog_date_value';
  $handler->display->display_options['arguments']['field_blog_date_value']['table'] = 'field_data_field_blog_date';
  $handler->display->display_options['arguments']['field_blog_date_value']['field'] = 'field_blog_date_value';
  $handler->display->display_options['arguments']['field_blog_date_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_blog_date_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_blog_date_value']['summary']['sort_order'] = 'desc';
  $handler->display->display_options['arguments']['field_blog_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_blog_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_blog_date_value']['summary_options']['base_path'] = 'blog/archive';
  $handler->display->display_options['arguments']['field_blog_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_blog_date_value']['validate']['fail'] = 'summary';
  $handler->display->display_options['arguments']['field_blog_date_value']['title_format'] = 'custom';
  $handler->display->display_options['arguments']['field_blog_date_value']['title_format_custom'] = 'F Y';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Coming soon ...';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'blog';

  /* Display: Archive Block */
  $handler = $view->new_display('block', 'Archive Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Archive';

  /* Display: Archive */
  $handler = $view->new_display('page', 'Archive', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Archive';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_blog_date_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  /* Field: Content: Blog Date */
  $handler->display->display_options['fields']['field_blog_date']['id'] = 'field_blog_date';
  $handler->display->display_options['fields']['field_blog_date']['table'] = 'field_data_field_blog_date';
  $handler->display->display_options['fields']['field_blog_date']['field'] = 'field_blog_date';
  $handler->display->display_options['fields']['field_blog_date']['label'] = '';
  $handler->display->display_options['fields']['field_blog_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_blog_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blog_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_blog_date']['settings'] = array(
    'format_type' => 'news',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_class'] = 'blog-date';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php

$bdate = strtotime($data->_field_data[\'nid\'][\'entity\']->field_blog_date[\'und\'][0][\'value\']);
echo "<span class=\'day\'>".date(\'d\', $bdate)."</span>";
echo "<span class=\'month\'>".date(\'M\', $bdate)."</span>";
echo "<span class=\'year\'>".date(\'Y\', $bdate)."</span>";

?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'continue reading';
  $handler->display->display_options['fields']['body']['alter']['more_link_path'] = '[path]';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Blog Author */
  $handler->display->display_options['fields']['field_blog_author']['id'] = 'field_blog_author';
  $handler->display->display_options['fields']['field_blog_author']['table'] = 'field_data_field_blog_author';
  $handler->display->display_options['fields']['field_blog_author']['field'] = 'field_blog_author';
  $handler->display->display_options['fields']['field_blog_author']['label'] = '';
  $handler->display->display_options['fields']['field_blog_author']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_blog_author']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'blog_listing_large',
    'image_link' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="blog-heading col-md-12 cols-sm-12 col-xs-12">
<div class="blog-date-container col-md-2 col-sm-2 col-xs-3">
<div class="blog-date-inner"><p>[php]</p></div>
</div>
<div class="blog-title-container col-md-10 col-sm-10 col-xs-8">
<h3 class="blog-title">[title]</h3>
<p class="blog-author">Written by [field_blog_author]</p>
</div>
</div>
<div class="blog-image col-md-12 col-sm-12 col-xs-12">[field_image]</div>
<div class="blog-description col-md-12 col-sm-12 col-xs-12">[body]</div>
<div class="blog-links col-md-12 col-sm-12 col-xs-12">
<div class="blog-tags col-md-6 col-sm-6 col-xs-12">
<span class="icon-tag"></span> [field_tags]
</div>
<div class="blog-share   col-md-6 col-sm-6 col-xs-12">
<div class="share-text">
<a href="https://www.facebook.com/sharer/sharer.php?u=[path]" class="icon-facebook"></a>
<a href="https://twitter.com/intent/tweet?u=[path]" class="icon-twitter"></a>
<a href="http://www.linkedin.com/shareArticle?url=[path]" class="icon-linkedin"></a>
</div>
<div class="share-this-text"> Share this article:</div>
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Blog Date */
  $handler->display->display_options['fields']['field_blog_date_1']['id'] = 'field_blog_date_1';
  $handler->display->display_options['fields']['field_blog_date_1']['table'] = 'field_data_field_blog_date';
  $handler->display->display_options['fields']['field_blog_date_1']['field'] = 'field_blog_date';
  $handler->display->display_options['fields']['field_blog_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_blog_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_blog_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blog_date_1']['settings'] = array(
    'format_type' => 'archive_list',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Blog Date -  start date (field_blog_date) */
  $handler->display->display_options['arguments']['field_blog_date_value']['id'] = 'field_blog_date_value';
  $handler->display->display_options['arguments']['field_blog_date_value']['table'] = 'field_data_field_blog_date';
  $handler->display->display_options['arguments']['field_blog_date_value']['field'] = 'field_blog_date_value';
  $handler->display->display_options['arguments']['field_blog_date_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_blog_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_blog_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_blog_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'blog/archive/%';

  /* Display: Tags */
  $handler = $view->new_display('page', 'Tags', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Blog';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_tags',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Tags (field_tags) */
  $handler->display->display_options['arguments']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['arguments']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['arguments']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['arguments']['field_tags_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_tags_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tags_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tags_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tags_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'blog/tags/%';

  /* Display: Related Posts */
  $handler = $view->new_display('block', 'Related Posts', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related Posts';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Tags (field_tags) */
  $handler->display->display_options['relationships']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['relationships']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['relationships']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  /* Field: Content: Blog Date */
  $handler->display->display_options['fields']['field_blog_date']['id'] = 'field_blog_date';
  $handler->display->display_options['fields']['field_blog_date']['table'] = 'field_data_field_blog_date';
  $handler->display->display_options['fields']['field_blog_date']['field'] = 'field_blog_date';
  $handler->display->display_options['fields']['field_blog_date']['label'] = '';
  $handler->display->display_options['fields']['field_blog_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_blog_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blog_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_blog_date']['settings'] = array(
    'format_type' => 'news',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_class'] = 'blog-date';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php

$bdate = strtotime($data->_field_data[\'nid\'][\'entity\']->field_blog_date[\'und\'][0][\'value\']);
echo "<span class=\'day\'>".date(\'d\', $bdate)."</span>";
echo "<span class=\'month\'>".date(\'M\', $bdate)."</span>";
echo "<span class=\'year\'>".date(\'Y\', $bdate)."</span>";

?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'continue reading';
  $handler->display->display_options['fields']['body']['alter']['more_link_path'] = '[path]';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Blog Author */
  $handler->display->display_options['fields']['field_blog_author']['id'] = 'field_blog_author';
  $handler->display->display_options['fields']['field_blog_author']['table'] = 'field_data_field_blog_author';
  $handler->display->display_options['fields']['field_blog_author']['field'] = 'field_blog_author';
  $handler->display->display_options['fields']['field_blog_author']['label'] = '';
  $handler->display->display_options['fields']['field_blog_author']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_blog_author']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['empty'] = '<div class="no-image">&nbsp;</div>';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'related_articles',
    'image_link' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="related-articles">
<div class="related-articles-img">
[field_image]
</div>
<div class="related-articles-title">
[title]
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_tags_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['vocabularies'] = array(
    'tags' => 'tags',
  );
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  $export['view_blog'] = $view;

  return $export;
}

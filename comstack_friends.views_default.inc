<?php
/**
 * @file
 * comstack_friends.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function comstack_friends_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'comstack_friends';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'user_relationships';
  $view->human_name = 'Comstack Friends';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Friends';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<p class="text-center">You\'ve not added any friends yet.</p>';
  /* Relationship: User relationships: Requestee user */
  $handler->display->display_options['relationships']['requestee_id']['id'] = 'requestee_id';
  $handler->display->display_options['relationships']['requestee_id']['table'] = 'user_relationships';
  $handler->display->display_options['relationships']['requestee_id']['field'] = 'requestee_id';
  /* Relationship: User relationships: Requester user */
  $handler->display->display_options['relationships']['requester_id']['id'] = 'requester_id';
  $handler->display->display_options['relationships']['requester_id']['table'] = 'user_relationships';
  $handler->display->display_options['relationships']['requester_id']['field'] = 'requester_id';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'requestee_id';
  /* Field: User relationships: User relationship add / remove action */
  $handler->display->display_options['fields']['ur_action']['id'] = 'ur_action';
  $handler->display->display_options['fields']['ur_action']['table'] = 'users';
  $handler->display->display_options['fields']['ur_action']['field'] = 'ur_action';
  $handler->display->display_options['fields']['ur_action']['relationship'] = 'requestee_id';
  $handler->display->display_options['fields']['ur_action']['label'] = '';
  $handler->display->display_options['fields']['ur_action']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ur_action']['ur-type'] = '4';
  $handler->display->display_options['fields']['ur_action']['ur-actions'] = array(
    'add' => 'add',
    'remove' => 0,
    'requested' => 0,
    'received' => 0,
  );
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'requestee_id';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'harmony-32-32';
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'requestee_id';
  /* Contextual filter: User relationships: Requester user */
  $handler->display->display_options['arguments']['requester_id']['id'] = 'requester_id';
  $handler->display->display_options['arguments']['requester_id']['table'] = 'user_relationships';
  $handler->display->display_options['arguments']['requester_id']['field'] = 'requester_id';
  $handler->display->display_options['arguments']['requester_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['requester_id']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['requester_id']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['requester_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['requester_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['requester_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['requester_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['requester_id']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['requester_id']['validate_options']['type'] = 'either';
  /* Filter criterion: User relationships: Relationship status */
  $handler->display->display_options['filters']['approved']['id'] = 'approved';
  $handler->display->display_options['filters']['approved']['table'] = 'user_relationships';
  $handler->display->display_options['filters']['approved']['field'] = 'approved';
  $handler->display->display_options['filters']['approved']['value'] = '1';
  /* Filter criterion: User relationships: Relationship type */
  $handler->display->display_options['filters']['rtype']['id'] = 'rtype';
  $handler->display->display_options['filters']['rtype']['table'] = 'user_relationships';
  $handler->display->display_options['filters']['rtype']['field'] = 'rtype';
  $handler->display->display_options['filters']['rtype']['value'] = array(
    0 => '5',
  );
  $handler->display->display_options['filters']['rtype']['expose']['operator_id'] = 'rtype_op';
  $handler->display->display_options['filters']['rtype']['expose']['label'] = 'Relationship type';
  $handler->display->display_options['filters']['rtype']['expose']['operator'] = 'rtype_op';
  $handler->display->display_options['filters']['rtype']['expose']['identifier'] = 'rtype';
  $handler->display->display_options['filters']['rtype']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'requestee_id';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Friends */
  $handler = $view->new_display('page', 'Friends', 'page');
  $handler->display->display_options['path'] = 'friends/%/friends';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Friends';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Friends';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Pending */
  $handler = $view->new_display('page', 'Pending', 'page_1');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<p class="text-center">You\'ve not got any pending requests.</p>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'requester_id';
  /* Field: User relationships: User relationship add / remove action */
  $handler->display->display_options['fields']['ur_action']['id'] = 'ur_action';
  $handler->display->display_options['fields']['ur_action']['table'] = 'users';
  $handler->display->display_options['fields']['ur_action']['field'] = 'ur_action';
  $handler->display->display_options['fields']['ur_action']['relationship'] = 'requester_id';
  $handler->display->display_options['fields']['ur_action']['label'] = '';
  $handler->display->display_options['fields']['ur_action']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ur_action']['ur-type'] = '4';
  $handler->display->display_options['fields']['ur_action']['ur-actions'] = array(
    'add' => 'add',
    'remove' => 0,
    'requested' => 0,
    'received' => 0,
  );
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'requester_id';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'harmony-32-32';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'requester_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User relationships: Requestee user */
  $handler->display->display_options['arguments']['requestee_id']['id'] = 'requestee_id';
  $handler->display->display_options['arguments']['requestee_id']['table'] = 'user_relationships';
  $handler->display->display_options['arguments']['requestee_id']['field'] = 'requestee_id';
  $handler->display->display_options['arguments']['requestee_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['requestee_id']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['requestee_id']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['requestee_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['requestee_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['requestee_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['requestee_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['requestee_id']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['requestee_id']['validate_options']['type'] = 'either';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User relationships: Relationship status */
  $handler->display->display_options['filters']['approved']['id'] = 'approved';
  $handler->display->display_options['filters']['approved']['table'] = 'user_relationships';
  $handler->display->display_options['filters']['approved']['field'] = 'approved';
  $handler->display->display_options['filters']['approved']['value'] = '0';
  /* Filter criterion: User relationships: Relationship type */
  $handler->display->display_options['filters']['rtype']['id'] = 'rtype';
  $handler->display->display_options['filters']['rtype']['table'] = 'user_relationships';
  $handler->display->display_options['filters']['rtype']['field'] = 'rtype';
  $handler->display->display_options['filters']['rtype']['value'] = array(
    0 => '5',
  );
  $handler->display->display_options['filters']['rtype']['expose']['operator_id'] = 'rtype_op';
  $handler->display->display_options['filters']['rtype']['expose']['label'] = 'Relationship type';
  $handler->display->display_options['filters']['rtype']['expose']['operator'] = 'rtype_op';
  $handler->display->display_options['filters']['rtype']['expose']['identifier'] = 'rtype';
  $handler->display->display_options['filters']['rtype']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'requester_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['path'] = 'friends/%/pending';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Pending';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Blocked */
  $handler = $view->new_display('page', 'Blocked', 'page_2');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<p class="text-center">You\'ve not blocked any other users.</p>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User relationships: Relationship status */
  $handler->display->display_options['filters']['approved']['id'] = 'approved';
  $handler->display->display_options['filters']['approved']['table'] = 'user_relationships';
  $handler->display->display_options['filters']['approved']['field'] = 'approved';
  $handler->display->display_options['filters']['approved']['value'] = '1';
  /* Filter criterion: User relationships: Relationship type */
  $handler->display->display_options['filters']['rtype']['id'] = 'rtype';
  $handler->display->display_options['filters']['rtype']['table'] = 'user_relationships';
  $handler->display->display_options['filters']['rtype']['field'] = 'rtype';
  $handler->display->display_options['filters']['rtype']['value'] = array(
    0 => '4',
  );
  $handler->display->display_options['filters']['rtype']['expose']['operator_id'] = 'rtype_op';
  $handler->display->display_options['filters']['rtype']['expose']['label'] = 'Relationship type';
  $handler->display->display_options['filters']['rtype']['expose']['operator'] = 'rtype_op';
  $handler->display->display_options['filters']['rtype']['expose']['identifier'] = 'rtype';
  $handler->display->display_options['filters']['rtype']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'requestee_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['path'] = 'friends/%/blocked';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Blocked';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['comstack_friends'] = $view;

  $view = new view();
  $view->name = 'comstack_friends_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Comstack Friends Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['operator'] = 'starts';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Username';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'friends/%/search';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Search';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['comstack_friends_search'] = $view;

  return $export;
}

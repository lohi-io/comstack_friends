<?php

/**
 * @file
 * Contains comstack_friends_handler_filter_exclude_roles
 */

class comstack_friends_handler_filter_exclude_roles extends views_handler_filter_many_to_one {
  function operators() {
    $operators = array(
      'not' => array(
        'title' => t('Is none of'),
        'short' => t('not'),
        'short_single' => t('<>'),
        'method' => 'op_helper',
        'values' => 1,
        'ensure_my_table' => 'helper',
      ),
    );

    return $operators;
  }

  function get_value_options() {
    $all_roles = user_roles(TRUE);
    unset($all_roles[DRUPAL_AUTHENTICATED_RID]);
    $excluded_roles = variable_get('comstack_friends_exclude_roles', array());
    $roles = array();

    foreach ($all_roles as $rid => $name) {
      if (in_array($name, $excluded_roles)) {
        $roles[$rid] = $name;
      }
    }

    $this->value_options = $roles;
  }

  function can_expose() {
    return FALSE;
  }

  function option_definition() {
    $options = parent::option_definition();

    $all_roles = user_roles(TRUE);
    $excluded_roles = variable_get('comstack_friends_exclude_roles', array());
    $roles = array();

    foreach ($all_roles as $rid => $name) {
      if (in_array($name, $excluded_roles)) {
        $roles[] = $rid;
      }
    }

    $options['operator']['default'] = 'not';
    $options['value']['default'] = $roles;

    if (isset($this->helper)) {
      $this->helper->option_definition($options);
    }
    else {
      $helper = new views_many_to_one_helper($this);
      $helper->option_definition($options);
    }

    return $options;
  }
}

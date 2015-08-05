<?php

/**
 * @file
 * Contains comstack_friends_plugin_access_current_perm.
 */

/**
 * Access plugin that provides permission-based access control.
 *
 * @ingroup views_access_plugins
 */
class comstack_friends_plugin_access_current_perm extends views_plugin_access_perm {
  function access($account) {
    return comstack_friends_views_check_perm($this->options['bypass_perm'], $this->options['perm'], $account);
  }

  function get_access_callback() {
    $callback = parent::get_access_callback();
    return array('comstack_friends_views_check_perm', array($this->options['bypass_perm'], $this->options['perm']));
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['bypass_perm'] = array('default' => 'administer users');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['bypass_perm'] = array(
      '#type' => 'select',
      '#options' => $form['perm']['#options'],
      '#title' => t('Bypass permission'),
      '#default_value' => $this->options['bypass_perm'],
      '#description' => t('Users with this permission will be allowed to access this view even if they are not the user in question.'),
      '#weight' => -1,
    );
  }
}

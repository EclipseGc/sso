<?php

$plugin = array(
  'schema' => 'sso_auth_methods',
  'access' => 'administer sso authentication methods',
  'menu' => array(
    'menu prefix' => 'admin/structure',
    'menu item' => 'sso_auth_methods',
    'menu title' => 'SSO Authentication Methods', 
    'menu description' => 'Create and administer SSO Methods',
  ),
  'title singular' => t('method'),
  'title singular proper' => t('Method'),
  'title plural' => t('methods'),
  'title plural proper' => t('Methods'),
  'form' => array(
    'settings' => 'sso_slave_auth_methods_export_ui_form',
    'validate' => 'sso_slave_auth_methods_export_ui_form_validate',
    'submit' => 'sso_slave_auth_methods_export_ui_form_submit',
  ),
  'redirect' => array(
    'activate' => 'admin/structure/sso_auth_methods',
  ),
);

function sso_slave_auth_methods_export_ui_form(&$form, &$form_state) {
  ctools_include('plugins');
  $method_plugins = ctools_get_plugins('sso_slave', 'auth_methods');
  $options = array();
  foreach ($method_plugins as $plugin_name => $plugin) {
    $options[$plugin_name] = $plugin['title'];
  }
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Method Name'),
    '#default_value' => $form_state['item']->name,
    '#required' => TRUE,
  );
  $form['auth_type'] = array(
    '#type' => 'select',
    '#title' => t('Authentication Method'),
    '#options' => $options,
    '#required' => TRUE,
    '#default_value' => $form_state['item']->auth_type,
    '#ajax' => array(
      'wrapper' => 'auth_methods_settings',
      'callback' => 'sso_slave_auth_methods_ajax_settings',
      'method' => 'replace',
    ),
  );
  $form['settings'] = array(
    '#tree' => TRUE,
    '#title' => t('Authentication Method Settings'),
    '#collapsible' => FALSE,
    '#prefix' => '<div id="auth_methods_settings">',
    '#suffix' => '</div>',
  );
  if ($callback = ctools_plugin_load_function('sso_slave', 'auth_methods', isset($form_state['values']['auth_type']) ? $form_state['values']['auth_type'] : $form_state['item']->auth_type, 'settings form')) {
    $callback($form['settings'], $form_state);
  }
}

function sso_slave_auth_methods_ajax_settings($form, $form_state) {
  return $form['settings'];
}

function sso_slave_auth_methods_export_ui_form_validate(&$form, &$form_state) {
}

function sso_slave_auth_methods_export_ui_form_submit(&$form, &$form_state) {
}

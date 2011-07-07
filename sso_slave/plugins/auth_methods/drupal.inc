<?php

$plugin = array(
  'title' => t('Drupal Authentication'),
  'settings form' => 'sso_slave_drupal_settings_form',
  'settings form validate' => 'sso_slave_drupal_settings_form_validate',
  'settings form submit' => 'sso_slave_drupal_settings_form_submit',
  'validate' => 'sso_slave_drupal_validate',
);

function sso_slave_drupal_settings_form(&$form, &$form_state) {
  $form['server'] = array(
    '#type' => 'textfield',
    '#title' => t('Server'),
    '#description' => t('The drupal server you wish to contact.'),
    '#default_value' => $form_state['item']->settings['server'],
  );
  return $form;
}

function sso_slave_drupal_settings_form_validate(&$form, &$form_state) {
  
}

function sso_slave_drupal_settings_form_submit($form, &$form_state) {
  
}

function sso_slave_drupal_validate(&$form, &$form_state) {
  $content = array(
    'username' => $form_state['input']['name'],
    'password' => $form_state['input']['pass'],
  );

  /*$response = drupal_http_request(
    variable_get('sso_slave_drupal_server', ''),
    array(
      'headers' => array('content-type' => 'application/json'),
      'method' => 'POST',
      'data' => $content,
    )
  );
  drupal_set_message('<pre>' . var_export($response, TRUE) . '</pre>');*/
  drupal_set_message('<pre>' . var_export($form_state['input'], TRUE) . '</pre>');
}

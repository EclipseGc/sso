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

function sso_slave_drupal_validate(&$form, &$form_state, $method) {
  $content = array(
    'username' => $form_state['input']['name'],
    'password' => $form_state['input']['pass'],
  );

  $response = drupal_http_request(
    $method->settings['server'] .'/user/login',
    array(
      'headers' => array('content-type' => 'application/json'),
      'method' => 'POST',
      'data' => json_encode($content),
    )
  );
  if ($response->code == 200) {
    user_external_login_register($form_state['input']['name'], 'sso_slave');
  }
}

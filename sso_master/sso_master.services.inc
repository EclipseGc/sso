<?php

/**
 * @file
 * Bulk export of services objects generated by Bulk export module.
 */

/**
 * Implementation of hook_default_services_endpoint()
 */
function sso_master_default_services_endpoint() {
  $endpoints = array();

  $endpoint = new stdClass;
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'sso';
  $endpoint->title = 'Single Sign On';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'sso';
  $endpoint->authentication = array();
  $endpoint->resources = array(
    'user' => array(
      'actions' => array(
        'login' => array(
          'enabled' => 1,
        ),
        'logout' => array(
          'enabled' => 1,
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $endpoints['sso'] = $endpoint;

  return $endpoints;
}

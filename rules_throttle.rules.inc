<?php

/**
 * @file
 * Rules Throttle creates a simple, timer-based delay mechanism for reducing
 * resource usage. For example, implementing a short delay between requests to
 * third pary APIs, or to add a delay between outgoing system emails.
 *
 * The action returns "before" and "after" timestamps, and calculated total
 * duration.
 *
 * This file contains the code for that rules action.
 */

/**
 * Implement hook_rules_action_info().
 *
 * Allows the administrator to specify a single integer value representing the
 * number of microseconds (millionths of a second) to $delay processing. For
 * more info, see the PHP "usleep" function.
 */
function rules_throttle_rules_action_info() {
  return array(
    'rules_throttle_delay_timer' => array(
      'label' => t('Throttle rules processing'),
      'group' => t('System'),
      'parameter' => array(
        'delay' => array(
          'type' => 'integer',
          'label' => t('Duration of delay, in millionths of a second:'),
          'description' => t('Specify a positive integer representing the
          length of time processing should be delayed, in millionths of a
          second. For example, one second (0:01) = 1000000. PHP integers
          generally have a maximum supported value of about two billion,
          e.g. two thousand seconds.'),
        ),
      ),
      'provides' => array(
        'timestamp_before_delay' => array(
          'type' => 'text',
          'label' => t('The unix timestamp before delay begins'),
        ),
        'timestamp_after_delay' => array(
          'type' => 'text',
          'label' => t('The unix timestamp after delay completes'),
        ),
        'delay_duration' => array(
          'type' => 'text',
          'label' => t('Calculation of time elapsed during throttle delay.'),
        ),
      ),
    ),
  );
}

/**
 * This callback uses the php "usleep" function to implement the delay,
 * using the $delay parameter provided through rules' UI (above).
 * As true for usleep, return values are rounded to millionths of a second.
 */
function rules_throttle_delay_timer($delay) {
  $time_before = round(microtime(true), 6);
  // Convert provided integer to absolute (positive) value, usleep ($delay).
  usleep(abs($delay));
  $time_after = round(microtime(true), 6);
  $duration = round(($time_after-$time_before), 6);
  return array(
    'timestamp_before_delay' => $time_before,
    'timestamp_after_delay' => $time_after,
    'delay_duration' => $duration,
  );
}

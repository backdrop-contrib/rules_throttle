Rules Throttle
======================

The Rules Throttle module allows an administrator to insert a "throttle" delay
action into a rule set. The delay can be specified by the administrator in
millionths of a second, up to a theoretical maximum of 2,000 seconds [1].

The action also provides three return values:
1. A microtime() timestamp from before the delay begins;
2. A microtime() timestamp from after the delay completes
3. A calculation of the duration of the delay. 
These values are available to subsequent rules actions.

Although the delay can be implemented for any number of reasons, the original
idea for the module was to help an administrator buffer or throttle rules' use
of resources, especially when those rules/actions depend on outside services,
like API's, where usage limits may be imposed. Examples of this include API's
such as 3rd party geocoders, weather providers, financial data, email services,
which often restrict the number of API calls your site can make during a given
period of time. On high volume sites, this can cause inconsistent results when
working with large data sets. This module allows you to "throttle" those API
calls to help keep within those usage limits.


[1] The Rules Throttle module delay feature relies entirely on the PHP "usleep"
function. That function accepts a single parameter (time in microseconds),
which is provided as an integer. In general, PHP integers have a maximum value
of about two billion, which equates to 2,000 seconds.

This module is a port from a Drupal 7
[sandbox project of the same name](https://www.drupal.org/sandbox/jweirather/2603990)
available as a zip file from that page. There is no history to import.

Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules.

Usage
-----

1. Click to edit your Rule
2. Under Actions click '+Add action'
3. Scroll down to 'System' and select 'Throttle rules processing'
4. Enter the number of millionths of a second
5. If required, modify the variable names and/or labels


Issues
------

Bugs and Feature requests should be reported in the Issue Queue:
https://github.com/backdrop-contrib/rules_throttle/issues.

Current Maintainers
-------------------

- [Martin Price](https://github.com/yorkshire-pudding)


Credits
-------

- Ported to Backdrop CMS by
  [Martin Price](https://github.com/yorkshire-pudding).
- Originally written for Drupal by
  [Joe Weirather](https://github.com/jweirather).

License
-------

This project is GPL v2 software. 
See the LICENSE.txt file in this directory for complete text.

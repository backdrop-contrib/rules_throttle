/**
 * @file
 * Custom javascript for the My Module module.
 */

(function($) {
  Backdrop.behaviors.myModule = {
    attach: function(context, settings) {

      console.log('Hello world!');

    }
  };
})(jQuery);

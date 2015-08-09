(function ($) {

  /**
   * This file copies the Flag modules approach of attaching behaviours to the
   * page and structure. Thanks Flag <3
   */

  Drupal.csFriends = function(context, settings) {
    var currentLink = null;

    /**
     * When a comstack friends link is clicked, perform the action.
     */
    function linkClick(event) {
      event.preventDefault();
      currentLink = $(this);

      // Prevent clicks on disabled links.
      if (currentLink.attr('disabled') === 'disabled') {
        return false;
      }

      // If the link has been click already, prevent subsequent clicks.
      if (currentLink.hasClass('cs-f-clicked')) {
        return false;
      }
      else {
        currentLink.addClass('cs-f-clicked');
      }

      // Does this type require a confirm modal?
      var action = currentLink.attr('data-cs-f-action');
      if (settings.comstackFriends.useConfirmModal[action]) {
        triggerModal(action);
      }
      // Nope just go for it.
      else {
        sendRequest();
      }
    }

    function triggerModal(action) {
      // Put together the pieces.
      var title = settings.comstackFriends.modalStrings[action].title;
      var modal_text = settings.comstackFriends.modalStrings[action].text;
      var username = currentLink.attr('data-username');
      var ok = settings.comstackFriends.modalStrings.buttons.confirm;
      var cancel = settings.comstackFriends.modalStrings.buttons.cancel;
      var final_text = Drupal.t(modal_text, {'@username': username}) + '<div class="text-right modal-buttons"><button id="cs-f-modal-cancel" class="btn btn-default form-submit">' + cancel + '</button> <button id="cs-f-modal-ok" class="btn btn-default form-submit">' + ok + '</button></div>';

      // Trigger the modal.
      var modal_options = {

      };
      Drupal.CTools.Modal.show(modal_options);

      // Set the text.
      $('#modal-title').text(title);
      $('#modal-content').html(final_text);

      // Setup the button callbacks.
      $('#cs-f-modal-cancel').click(modalCancel);
      $('#cs-f-modal-ok').click(modalOK);

      // Remove the clicked link blocker as modals can be closed via multiple
      // buttons.
      currentLink.removeClass('cs-f-clicked');
    }

    function modalCancel() {
      Drupal.CTools.Modal.dismiss();
      currentLink.removeClass('cs-f-clicked');
      currentLink = null;
    }

    function modalOK() {
      sendRequest();
      // Disable the modal windows buttons.
      $('#cs-f-modal-cancel,#cs-f-modal-ok').attr('disabled', 'disabled');
    }

    function updateLink(html) {
      var requester = currentLink.attr('data-requester-uid');
      var requestee = currentLink.attr('data-requestee-uid');
      var action = currentLink.attr('data-cs-f-action');

      $("a.cs-f-link[data-requester-uid='" + requester + "'][data-requestee-uid='" + requestee + "'][data-cs-f-action='" + action + "']").html(html).click(linkClick);;
    }

    function sendRequest() {
      // Get the link URL and replace the last "nojs" segment ctools style.
      var url = currentLink.attr('href').replace('/nojs', '/ajax');

      $.ajax({
        type: 'POST',
        url: url,
        data: {
          js: true
        },
        dataType: 'json',
        success: function (data) {
          // Be prepared to receive an error!
          if (data.errors != '') {
            $('#modal-content').html('<p>' + data.message + '</p><div class="text-right modal-buttons"><button id="cs-f-modal-cancel" class="btn btn-default form-submit"></button></div>');
            return;
          }

          // If the response says to disable some buttons, do it.
          if (data.disableSelector && data.disableSelector != '') {
            $(data.disableSelector, context).attr('disabled', 'disabled');
          }

          // The response can prevent the clicked link from being updated.
          if (!data.preventDefault) {
            updateLink(data.html);
          }

          // Remove the modal.
          modalCancel();
        },
        error: function (xmlhttp) {
          alert('An HTTP error '+ xmlhttp.status +' occurred.\n'+ url);
          modalCancel();
        }
      });
    }

    // Add the click behaviour to all the links via class.
    $('a.cs-f-link:not(.cs-f-processed)', context).click(linkClick);
  };

  // Attach function.
  Drupal.behaviors.comstackFriends = {
    attach: function(context, settings) {
      Drupal.csFriends(context, settings);
    }
  };

})(jQuery);

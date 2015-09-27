<?php

/**
 * @file
 * Contains ComstackFriendsFriendsResource__1_0.
 */

class ComstackFriendsFriendsResource__1_0 extends \ComstackFriendsRestfulBase {
  /**
   * Overrides \RestfulEntityBase::controllersInfo().
   */
  public static function controllersInfo() {
    return array(
      // Listings.
      '' => array(
        \RestfulInterface::GET => 'getList',
        \RestfulInterface::POST => 'newRequest',
      ),
      // A specific entity.
      '^([\d]+)$' => array(
        \RestfulInterface::GET => 'viewEntity',
      ),
      // Actions against a specific relationship.
      '^([\d]+)\/approve$' => array(
        \RestfulInterface::PUT => 'approveEntity',
      ),
      '^([\d]+)\/reject$' => array(
        \RestfulInterface::POST => 'rejectEntity',
      ),
    );
  }

  /**
   * Overrides \ComstackFriendsRestfulBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();

    $public_fields['approved'] = array(
      'property' => 'approved',
    );

    return $public_fields;
  }

  /**
   * Approve a relationship request.
   */
  public function approveEntity() {
    // Check access.
    $account = $this->getAccount();
    $bundle = $this->bundle;

    if (!$this->checkEntityAccess('approve')) {
      $params = array('@bundle' => $bundle);
      $this->setHttpHeaders('Status', 403);
      throw new RestfulForbiddenException(format_string('You do not have access to approve @bundle relationships.', $params));
    }

    $entity_id = $this->getEntityID();

    if (entity_get_controller($this->entityType, $account)->accept($entity_id)) {
      $this->clearResourceRenderedCacheEntity($entity_id);
      return $this->viewEntity($entity_id);
    }

    return FALSE;
  }

  /**
   * Reject a relationship request.
   */
  public function rejectEntity() {
    // Check access.
    $account = $this->getAccount();
    $bundle = $this->bundle;

    if (!$this->checkEntityAccess('delete')) {
      $params = array('@bundle' => $bundle);
      $this->setHttpHeaders('Status', 403);
      throw new RestfulForbiddenException(format_string('You do not have access to delete or reject new @bundle relationships.', $params));
    }

    $entity_id = $this->getEntityID();
    $request_data = $this->getRequestData();

    // Set the default reason as "disapprove".
    if (empty($request_data['reason'])) {
      $request_data['reason'] = 'disapprove';
    }

    // Validate the request has all the data we need.
    if (!is_string($request_data['reason']) || is_string($request_data['reason']) && !in_array($request_data['reason'], array('cancel', 'disapprove'))) {
      $this->setHttpHeaders('Status', 400);
      throw new \RestfulBadRequestException(format_string('If you want to reject this relationship you need to set a reason. @data', array('@data' => print_r($request_data, TRUE) )));
    }

    // Grab the controller.
    $this->deleteRelationship($entity_id, $request_data['reason']);
  }
}

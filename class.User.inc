<?php

/**
 * Class User
 */
class User {
  // protected propertie firstName
  protected $_firstName;
  // protected propertie lastName
  protected $_lastName;
  // protected propertie username
  protected $_username;
  // protected propertie password
  protected $_password;
  // when the object is created (format dd-mm-yyyy)
  protected $_dateCreated;

  
/**
 * Constructor
 * @param aray $data. Array of properties
 */
function __construct($data = array()) {
    
    $this->_dateCreated = date("d-m-Y");
    
    
    // To enshure that there is at least one propertie
    if (!is_array($data)) {
      trigger_error('Unable to construct User object');
    }
    
    // If there is at least one value, populate the User
    if (count($data) > 0) {
      foreach ($data as $name => $value) {
        // Special case for protected properties.
        if (in_array($name, array(
          'firstName',
          'lastName',
          'username',
          'password',
          'dateCreated',
        ))) {
          $name = '_' . $name;
        }
        $this->$name = $value;
      }
    }
  }
  
  /**
   * Magic __get.
   * @param string $name 
   * @return mixed
   */
  function __get($name) {
       
    // Return a protected property by name
    $protected_property_name = '_' . $name;
    if (property_exists($this, $protected_property_name)) {
      return $this->$protected_property_name;
    }
    
    // Unable to access property; trigger error.
    trigger_error('Undefined property via __get: ');
    return NULL;
  }
  
   /**
   * Magic __set.
   * @param string $name
   * @param mixed $value 
   */
  function __set($name, $value) {
    // Set the protected atributes 
    if (in_array($name, array(
          'firstName',
          'lastName',
          'username',
          'password',
          'dateCreated',
        ))) {
            $this->$name = $value;
            return;
        }
     
    // Unable to access property
    trigger_error('Undefined or unallowed property via __set()');
  }
  
  /**
   * Getting all properties from the User object
   * @return array of properties ($key => $value)
   */
  public function get_user_properties () {
      $result1 = get_object_vars($this);
      return $result1;
    
  }
}
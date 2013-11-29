<?php
/**
 * Class Container
 * This class conatins queue of User objects
 */
class Container extends SplQueue{
  
/**
 * Reset the queue
 * All object from the queue are deleted
 * While there is object in the queue -> dequeue 
 */
  function reset() {
    while($this->count()>0){
    $this->dequeue();
    }
 }
 
 
 /**
  * Find the objects in the queue with certain property
  * @param string $search_string
  * @param string $property_name
  * @return NULL if there is no objects, or list of object for that criteria
  */
 function search($search_string, $property_name ) {

   //set the Iterator Mode
   $this->setIteratorMode(
    SplDoublyLinkedList::IT_MODE_FIFO|SplDoublyLinkedList::IT_MODE_KEEP); 
   $result = new Container();
         // check every single object from the list
    
   foreach ($this as $objekt) {
     // get all properties from the $objects as an array
     $properties = $objekt->get_user_properties();
     foreach ($properties as $key => $value) {
     // var_dump (strpos("Ivana", "Ivana"));
      //var_dump (strspn("abcdefand","abc"));
       // $mystring = 'abc';
        //$findme   = 'a';
        //$pos = strpos($mystring, $findme);
      // var_dump (strpos('Ivana', 'na'));
      //var_dump (strspn($value, $search_string));
//      var_dump("=========");
//      var_dump($search_string);
//      var_dump($value);
//      var_dump(strpos($value, $search_string) !== false);
//      var_dump("=========");
      
           // Check if there is property which conatins the search string
           if( $key == "_".$property_name && strpos($value, $search_string) !== false ) {
                    $result->enqueue($objekt);
                    
            }
       }
       
     }
       
     var_dump($result);
      return $result;
  
  }
 
}
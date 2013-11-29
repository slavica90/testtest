<!DOCTYPE html>
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title></title>
  </head>
  <body>
    <?php
    error_reporting(E_ALL);
ini_set('display_errors', '1');
    // require 'class.User.inc';
      function __autoload($class_name) {
       include 'class.' . $class_name . '.inc';
   }
   
    echo "TEST USER";
    $korisnik = new User(array (
      'firstName' => 'Slavica1',
      'lastName' => 'Kostadinova1',
      'username' => 'slavica901',
      'password' => '123456-1',
      ));
    
    echo '<pre>';
    var_dump($korisnik);
    echo '</pre>';
    
    
    
    echo "TEST EMPLOYEE";
    $employee = new Employee(array (
      'firstName' => 'Slavica2',
      'lastName' => 'Kostadinova2',
      'username' => 'slavica902',
      'password' => '123456-2',
     ));
    
    echo '<pre>';
    var_dump($employee);
    echo '</pre>';
    
    
    
    echo "TEST ADMINISTRATOR";
    $administrator = new Administrator(array (
      'firstName' => 'Slavica3',
      'lastName' => 'Kostadinova3',
      'username' => 'slavica903',
      'password' => '123456-3',
      ));
    
    $administrator2 = new Administrator(array (
      'firstName' => 'Ivana',
      'lastName' => 'Ivanova',
      'username' => 'ivana123',
      'password' => '1212312',
      ));
    
    echo '<pre>';
    var_dump($administrator2);
    echo '</pre>';
    
    
    echo '<h2>ENQUEUE METHOD</h2>';
    $lista = new Container();
 
    // add some objects to the queue
    $lista->enqueue($employee);
    $lista->enqueue($employee);
    $lista->enqueue($employee);
    $lista->enqueue($administrator);
    $lista->enqueue($administrator);
    $lista->enqueue($administrator);
     $lista->enqueue($administrator2);
    
    echo '<pre>';
    var_dump($lista);
    echo '</pre>';
    
    
    
    echo '<h2>DEQUEUE METHOD</h2>';
    $lista->dequeue();
    $lista->dequeue();
    
    echo '<pre>';
    var_dump($lista);
    echo '</pre>';
    
    
    echo '<h2>Search Method</h2>';
    echo '<pre>';
    $lista->search("van","firstName");
    echo '</pre>';
    
    
    echo '<h2>Reset Method and isEmpty Method</h2>';
       
    echo '<h2>IsEmpty before RESET</h2>';
    var_dump($lista->isEmpty());
    
    
    echo '<h2>CLEAR LIST</h2>';
    $lista->reset();
    echo '<pre>';
    var_dump($lista);
    echo '</pre>';
    
    echo '<h2>IsEmpty after RESET</h2>';
    var_dump($lista->isEmpty());
    
      
    ?>
  </body>
</html>

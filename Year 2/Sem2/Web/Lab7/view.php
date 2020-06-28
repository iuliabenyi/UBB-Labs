<?php

require_once 'book.php';

class View
{
    public function __construct() {
    }

    public function outputBook($book) {
        /*echo "ID" . $student->getId() . "<br/>";
		echo "Name: " . $student->getName() . "<br/>";
		echo "Password: " . $student->getPassword() . "<br/>";
		echo "Group ID: " . $student->getGroup_id() . "<br/>";*/

		echo json_encode($book);
    }

    public function output($param) {
    	echo json_encode($param);
    }
}

?>

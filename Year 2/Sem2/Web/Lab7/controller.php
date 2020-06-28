<?php

require_once 'model.php';
require_once 'view.php';

class Controller
{
    private $view;
    private $model;	

    public function __construct(){
    	$this->model = new Model ();
        $this->view = new View();
    }

    public function service() {
	   if (isset($_GET['action']) && !empty($_GET['action'])) {
            if ($_GET['action'] == "getUser") {
   	            $this->{$_GET['action']}($_GET['user']);
            } 
			else if($_GET['action'] == "insertBook"){
				$this->{$_GET['action']}($_GET['Author'], $_GET['Genre'], $_GET['Pages'], $_GET['Title'], $_GET['Lent']);
				echo "Title: ";
				echo $_GET['Title'];
			}
			else if($_GET['action'] == "deleteBook"){
				$this->{$_GET['action']}($_GET['Title']);
				echo "Title: ";
				echo $_GET['Title'];
			}
			else if($_GET['action'] == "updateBook"){
				$this->{$_GET['action']}($_GET['Title'], $_GET['Lent']);
			}
			else if($_GET['action'] == "filterBook"){
				$this->{$_GET['action']}($_GET['Genre']);
			}
			else if($_GET['action'] == "lendBook"){
				$this->{$_GET['action']}($_GET['Title']);
			}
			else {
                $this->{$_GET['action']}();
            } 
	   }
    }

    public function getUser($user) {
	   $book = $this->model->getBook($user);
	   return $this->view->output($book);
    }

    public function getAllBooks() {
       $books = $this->model->getAllBooks();
       return $this->view->output($books);
    }
	
	public function insertBook($Author, $Genre, $Pages, $Title){
		$affectedRows = $this->model->insertBook($Author, $Genre, $Pages, $Title, $Lent);
		//$affectedRows = $this->model->insertBook('a1', 'g1', 1, 't1');
		//echo "inserting ";
		return $this->view->output($affectedRows);
	}
	
	public function deleteBook($Title){
		$affectedRows = $this->model->deleteBook($Title);
		//echo $Title;
		return $this->view->output($affectedRows);
	}
	
	public function updateBook($Title, $Lent){
		$affectedRows = $this->model->updateBook($Title, $Lent);
		return $this->view->output($affectedRows);
	}
	
	public function filterBook($Genre){
		$books = $this->model->filterBook($Genre);
        return $this->view->output($books);
	}
	
	public function lendBook($Title){
		$affectedRows = $this->model->lendBook($Title);
		return $this->view->output($affectedRows);
	}
}

$controller = new Controller();
$controller->service();

?>

<?php

require_once 'DBUtils.php';
require_once 'book.php';

class Model {
	private $db;

	public function __construct() {
		$this->db = new DBUtils ();
	}

	public function getBook($user) {
		$resultset = $this->db->selectBook($user);
	    //var_dump($resultset);
        $book = new Book($resultset[0]['id'], $resultset[0]['author'], $resultset[0]['genre'], $resultset[0]['pages'], $resultset[0]['title'], $resultset[0]['lent']);
        return $book;
	}

	public function getAllBooks(){
		return $this->db->selectAllBooks();
	}
	
	public function insertBook($Author, $Genre, $Pages, $Title, $Lent){
		return $this->db->insert($Author, $Genre, $Pages, $Title, $Lent);
	}
	
	public function deleteBook($Title){
		return $this->db->deleteBook($Title);
	}
	
	public function updateBook($Title, $Lent){
		return $this->db->update($Title, $Lent);
	}
	
	public function filterBook($Genre){
		return $this->db->filterBook($Genre);
	}
	
	public function lendBook($Title){
		return $this->db->lendBook($Title);
	}
	
}

?>

<?php

class Book implements JsonSerializable {
	private $author;
	private $genre;
	private $pages;	
	private $title;

	public function __construct($author, $genre, $pages, $title, $lent) {
		$this->author = $author;
		$this->genre = $genre;
		$this->pages = $pages;
		$this->title = $title;
		$this->lent = $lent;
	}

	public function getAuthor() {
		return $this->author;
	}
	public function getGenre() {
		return $this->genre;
	}
	public function getPages() {
		return $this->pages;
	}
	public function getTitle() {
		return $this->title;
	}
	
	public function getLent() {
		return $this->lent;
	}

	public function jsonSerialize() {
        $vars = get_object_vars($this);
        return $vars;
    }
}

?>

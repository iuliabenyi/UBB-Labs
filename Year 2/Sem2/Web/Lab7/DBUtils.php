<?php



class DBUtils {
	private $host = '127.0.0.1';
	private $db   = 'books';
	private $user = 'root';
	private $pass = '';
	private $charset = 'utf8mb4';	

	private $pdo;
	private $error;

	public function __construct () {
		$dsn = "mysql:host=$this->host;dbname=$this->db;charset=$this->charset";
		$opt = array(PDO::ATTR_ERRMODE            => PDO::ERRMODE_EXCEPTION,
			PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
			PDO::ATTR_EMULATE_PREPARES   => false);
		try {
			$this->pdo = new PDO($dsn, $this->user, $this->pass, $opt);		
		} // Catch any errors
		catch(PDOException $e){
			$this->error = $e->getMessage();
			echo "Error connecting to DB: " . $this->error;
		}
	}

	public function select() {
		$stmt = $this->pdo->query("SELECT * FROM Book");
		return $stmt->fetchAll(PDO::FETCH_ASSOC);
	}	

	public function selectBook($title) {
        $stmt = $this->pdo->query("SELECT * FROM Book where Title='" . $title ."'");
        return $stmt->fetchAll(PDO::FETCH_ASSOC);
    }

    public function selectAllBooks() {
    	$stmt = $this->pdo->query("SELECT * FROM Book");
        return $stmt->fetchAll(PDO::FETCH_ASSOC);
    }

    /*public function selectGradeForStudent($studentid) {
    	$stmt = $this->pdo->query("SELECT * FROM Grades where studentid=" . $studentid);
        return $stmt->fetchAll(PDO::FETCH_ASSOC);
    }*/

	public function insert($Author, $Genre, $Pages, $Title, $Lent) {
		$affected_rows = $this->pdo->exec("INSERT INTO Book VALUES ('" . $Author . "','" . $Title . "'," . $Pages . ",'" . $Genre ."', " . $Lent .");");
		return $affected_rows;
	}

	public function deleteBook($Title) {
		$affected_rows = $this->pdo->exec("DELETE FROM Book WHERE Title = '" . $Title . "';");
		echo "DELETE FROM Book WHERE Title = '" . $Title . "';";
		return $affected_rows;
	}

	public function update($Title, $Genre) {
		$affected_rows = $this->pdo->exec("UPDATE Book SET Lent='" . $Lent ."' where Title= '" . $Title . "'; ");
		return affected_rows;
	}
	
	public function filterBook($Genre){
		$stmt = $this->pdo->query("SELECT * FROM Book WHERE Genre = '" . $Genre ."'; ");
		return $stmt->fetchAll(PDO::FETCH_ASSOC);
	}
	
	public function lendBook($Title){
		$affected_rows = $this->pdo->exec("UPDATE Book SET Lent=1 where Title= '" . $Title . "'; ");
		return affected_rows;
	}
}
 

?>


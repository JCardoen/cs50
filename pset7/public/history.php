<?php
    // configuration
    require("../includes/config.php"); 
	
	$id = $_SESSION["id"];
	
	// Retrieves all the transactions from the database ordered by date
	$history = cs50::query("SELECT symbol, transaction, shares, price, time FROM history WHERE id = $id ORDER BY time DESC");
	
    // render portfolio
    render("history_form.php", ["title" => "History", "history" => $history]);
?>
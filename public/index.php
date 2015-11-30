<?php

    // configuration
    require("../includes/config.php"); 
 
    $rows =	query("SELECT * FROM portfolio WHERE id = ?", $_SESSION["id"]);	
	
	$portfolio = ();

	// for each of user's stocks
	foreach ($rows as $row)	
    {   
        
        $stock = lookup($row["symbol"]);
        
        $stock["shares"] = $row["shares"];
        
        $stock["total"] = $row["shares"] * $stock["price"];    

        $portfolio[] = $stock;
    }
    
    // query cash for template
    $users = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);

    // render portfolio (pass in new portfolio table and cash)
    render("portfolio.php", ["title" => "Portfolio", "portfolio" => $portfolio, "users" => $users]);

?>

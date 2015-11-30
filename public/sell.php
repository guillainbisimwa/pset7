<?php
    
    // configuration 
    require("../includes/config.php");   
    
   
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $stock = lookup($_POST["symbol"]);
        
        $shares = query("SELECT shares FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        
        $val = $stock["price"] * $shares[0]["shares"];
        
        query("UPDATE users SET cash = cash + ? WHERE id = ?", $val, $_SESSION["id"]);

        query("DELETE FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);        
        
        $type = 'SELL';
        
        query("INSERT INTO history (id, type, symbol, shares, price) VALUES (?, ?, ?, ?, ?)", $_SESSION["id"], $type, $_POST["symbol"], $shares[0]["shares"], $stock["price"]);

        redirect("/");
    }

    else
    {
        $rows =	query("SELECT * FROM portfolio WHERE id = ?", $_SESSION["id"]);	

        $stocks = [];

        foreach ($rows as $row)	
        {   
            $stock = $row["symbol"];

            $stocks[] = $stock;       
        }    

        render("sell_form.php", ["title" => "Sell_Form", "stocks" => $stocks]);
    }
?>

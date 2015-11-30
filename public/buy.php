<?php
    
    // configuration 
    require("../includes/config.php");   
    
   
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        if (empty($_POST["symbol"]) || empty($_POST["shares"]))
        {
           
            apologize("please, put a stock symbol and quantity of shares to buy...");
        }
        
       
        if (lookup($_POST["symbol"]) === false)
        {
            
            apologize("Plese, this is an invalid stock symbol...");
        }
     
        $stock = lookup($_POST["symbol"]);
        
        // calculate total cost (stock's price * shares)
        $cost = $stock["price"] * $_POST["shares"];
        
        
        $cash =	query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);	
        
       
        if ($cash < $cost)
        {
            // apologize
            apologize("Impossible to buy...");
        }         
        
        else
        {
            query("INSERT INTO portfolio (id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], $_POST["symbol"], $_POST["shares"]);
            
            
            query("UPDATE users SET cash = cash - ? WHERE id = ?", $cost, $_SESSION["id"]);
                 
       
            $type = 'BUY';
        
            
            query("INSERT INTO history (id, type, symbol, shares, price) VALUES (?, ?, ?, ?, ?)", $_SESSION["id"], $type, $_POST["symbol"], $_POST["shares"], $stock["price"]);

    
           redirect("/");  
        }
    }
    
    
    else
    {
        // render buy form
        render("buy_form.php", ["title" => "Buy Form"]);
    }
    
?>

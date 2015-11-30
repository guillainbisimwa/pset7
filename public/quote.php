<?php

    // configuration
    require("../includes/config.php"); 

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $_POST = lookup($_POST["symbol"]); 
        if($_POST === false)
        {
            apologize("Invalid Stock Symbol");
        }    
        //print("Price : " . number_format($s["price"], 2));
        render("quote.php", ["title" => "Quote"]);
    }
    else
    {
        render("quote_form.php", ["title" => "Quote"]);
    }

?>

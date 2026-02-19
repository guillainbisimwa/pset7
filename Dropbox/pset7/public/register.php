<?php

    // configuration
    require("../includes/config.php"); 

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["username"]))
        {
            apologize("You must provide your username.");
        }
        else if (empty($_POST["password"]))
        {
            apologize("You must provide your password.");
        }
        else if ($_POST["password"] != $_POST["confirm"])
        {
            apologize("Passwords don't macth");
        }

        // query database for user
       if(query("INSERT INTO users (username, hash, cash) VALUES (?, ?, 10000.0)", $_POST["username"], crypt($_POST["password"]))=== false)
       {
            apologize("user name already exists");
       }
       else
       {
            $rows = query("SELECT LAST_INSERT_ID() AS id");
            
            $_SESSION["id"] = $rows[0]["id"];
            redirect("index.php");
       }

    }
    else
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

?>

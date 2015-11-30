<?php
    // configuration


require("../includes/config.php");
// if form was submitted

if ($_SERVER["REQUEST_METHOD"] == "POST")
{
		$rows = query("SELECT * FROM users WHERE  id = ?", $_SESSION["id"]);
            $row = $rows[0];

		if (empty($_POST["username"]))
        {
            apologize("You must provide a username.");
        }
        
        if ($_POST["username"] != $row["username"])
        {
            apologize("Sorry, put your correct name.");
        }
        
        if (crypt($_POST["oldpw"], $row["hash"]) != $row["hash"])
        {
            apologize("Sorry, your old Password is not correct.");
        }
        

		if ($_POST["pw"] != $_POST["confirm"])
	    {
		    apologize("Please, the new password added does'nt match...");
        }
		
        if (query("UPDATE users SET hash = ( ? ) WHERE username = ( ? )", crypt($_POST["confirm"]),$_POST["username"]) === false)
        {
			apologize("Sorry, impossible to change password...");
		}
		else
		{
		    print("Password has been changed... ");	
			redirect("index.php");
		}
        
        
    }  
    else
    {
        // else render form
        render("changepassword_form.php", ["title" => "Change Password"]);
    }
?>

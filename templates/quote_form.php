
<div id="menu">
    <div class="form1">
        <div class="profile">
            
        </div>
        <?php
	$user = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
	printf("<p class=\"hi\">Hello <strong>%s</strong><br/>Your balance is at <strong>%.2f $</strong>.</p>",$user [0]['username'], $user [0]['cash']);
	//print_r ($user);
	?>
        <a href="index.php">  Portfolio  </a><br> 
        <a href="quote.php" style="color:red;">  Quote  </a> <br> 
        <a href="buy.php">  Buy  </a> <br> 
        <a href="sell.php">  Sell  </a> <br> 
        <a href="history.php">  History  </a> <br> 
        <a href="changepassword.php">  Change password  </a> <br> 
        <a href="logout.php"><strong>  Log Out  </strong></a><br> 
    </div>
    <div class="form">
        <form action="quote.php" method="post">
            <fieldset>
                <div class="form-group">
                    <input autofocus class="form-control" name="symbol" placeholder="Symbol" type="text"/>
                
                    <button type="submit" class="btn btn-default" style="margin-left:20px;">Get Quote</button>
                </div>
            </fieldset>
        </form>
 
    </div>
    
<div>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><hr>

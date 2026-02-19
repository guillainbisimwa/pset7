
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
        <a href="quote.php">  Quote  </a> <br> 
        <a href="buy.php" style="color:red;">  Buy  </a> <br> 
        <a href="sell.php">  Sell  </a> <br> 
        <a href="history.php">  History  </a> <br> 
        <a href="changepassword.php">  Change password  </a> <br> 
        <a href="logout.php"><strong>  Log Out  </strong></a><br> 
    </div> 
   
    <div class="form" >
        <form action="buy.php" method="post">         
                <div class="buy" class="form-group">
                    <input  name="symbol" class="form-control" placeholder=" Symbol" type="text"/>
                
                    <input name="shares" class="form-control" placeholder=" Shares" type="text"/>
                
                    <button type="submit" class="btn btn-default">Buy</button>
                </div>
            
        </form>
    </div>
<div>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><hr>


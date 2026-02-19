<div id="menu"> 	
	 <div class="form1">
        <div class="profile">
            
        </div>
        <?php
	$user = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
	printf("<p class=\"hi\">Hello <strong>%s</strong><br/>Your balance is at <strong>%.2f $</strong>.</p>",$user [0]['username'], $user [0]['cash']);
	
	?>
        <a href="index.php">  Portfolio  </a><br> 
        <a href="quote.php">  Quote  </a> <br> 
        <a href="buy.php">  Buy  </a> <br> 
        <a href="sell.php">  Sell  </a> <br> 
        <a href="history.php">  History  </a> <br> 
        <a href="changepassword.php"   style="color:red;">  Change password  </a> <br>
        <a href="logout.php"><strong>  Log Out  </strong></a><br> 
    </div>
    <div class="table"> 
        <form action="changepassword.php" method="post">
            <fieldset>
                <div class="form-group">
                    <input autofocus class="form-control" name="username" placeholder="Username" type="text"/>
                </div>
                <div class="form-group">
                    <input class="form-control" name="oldpw" placeholder="Old password" type="password"/>
                </div>
                <div class="form-group">
                    <input class="form-control" name="pw" placeholder="New password" type="password"/>
                </div>
                <div class="form-group">
                    <input class="form-control" name="confirm" placeholder="Confirm password" type="password"/>
                </div>
                <div class="form-group">
                    <button type="submit" class="btn btn-default">Confirm</button>
                </div>
            </fieldset>
        </form>
    </div>
</div>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><hr>      

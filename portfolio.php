	
<div id="menu"> 	
	 <div class="form1">
        <div class="profile">
            
        </div>
        <?php
	        $user = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
	        printf("<p class=\"hi\">Hello <strong>%s</strong><br/>Your balance is at <strong>%.2f $</strong>.</p>",$user [0]['username'], $user [0]['cash']);
	    ?>
        <a href="index.php" style="color:red;">  Portfolio  </a><br> 
        <a href="quote.php">  Quote  </a> <br> 
        <a href="buy.php">  Buy  </a> <br> 
        <a href="sell.php">  Sell  </a> <br> 
        <a href="history.php">  History  </a> <br> 
        <a href="changepassword.php">  Change password  </a> <br> 
        <a href="logout.php"><strong>  Log Out  </strong></a><br> 
    </div>
    <div class="table">  
        <table  align="center" border="2"  cellpadding="5" width="90%" > 
            <thead>
                 <tr bgcolor="cccccc" >
                    <th style="text-align:center;"  width="18%">Symbol</th>
                    <th style="text-align:center;" width="18%">Name</th>
                    <th style="text-align:center;" width="18%">Shares</th>
                    <th style="text-align:center;" width="18%">Price</th>
                    <th style="text-align:center;" width="18%">TOTAL</th> 
                </tr>
                
            </thead>   
            <tbody>
                <?php
	                foreach ($portfolio as $row)	
                    {   
                        echo("<tr>");
                        echo("<td>" . $row["symbol"] . "</td>");
                        echo("<td>" . $row["name"] . "</td>");
                        echo("<td>" . $row["shares"] . "</td>");
                        echo("<td>$" . number_format($row["price"], 2) . "</td>");
                        echo("<td>$" . number_format($row["total"], 2) . "</td>");
                        echo("</tr>");
                    }
                ?>
           <tbody>
        </table>
    </div>
</div>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><hr>





<?php
//Turn on error reporting
ini_set('display_errors', 'On');
//Connects to the database
$mysqli = new mysqli('oniddb.cws.oregonstate.edu','conleyme-db','t50AD6dCxtftZ7zb','conleyme-db');
if ($mysqli->connect_error) {
    die('Connect Error (' . $mysqli->connect_errno . ') '
            . $mysqli->connect_error);
}

$inventory = array();

?>

<!DOCTYPE html> 
<html>
  <head>
    <title>Grocery Store Inventory</title>
  </head>
  <body>
     <h1>Grocery Store Inventory</h1>
	    <form action="add.php" method="post">
		<fieldset>
            <legend>Add new inventory item</legend>
			<div>
				<label>Name</label>
				<input type="text" name="name" id="name">
			</div>
			<div>
				<label>Category</label>
				<input type="text" name="category" id="category">
			</div>
			<div>
				<label>Price</label>
				<input type="text" name="price" id="price">
			</div>
			<input type="submit" value="Add new item">
        </fieldset>
        </form>
		
	<div>
        <form method="post" action="alter.php">
                <fieldset>
					<legend>Update price of category</legend>
					<select name="category">
							<?php
							if(!($stmt = $mysqli->prepare("SELECT DISTINCT category FROM inventory ORDER BY name ASC"))){
									echo "Prepare failed: "  . $stmt->errno . " " . $stmt->error;
							}

							if(!$stmt->execute()){
									echo "Execute failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
							}
							if(!$stmt->bind_result($category)){
									echo "Bind failed: "  . $mysqli->connect_errno . " " . $mysqli->connect_error;
							}
							while($stmt->fetch()){
							 echo '<option> ' . $category . '</option>\n';
							}
							$stmt->close();
							?>

					</select>
					<label>Enter percent of change</label>
					<input type="text" name="modifier">
					<input type="submit" value="Update category" />
				</fieldset>
        </form>
	</div>
	<div>
	<fieldset>
		<form method="POST" action="delete_all.php"><input type="hidden" name="deleteall" />
			<input type="submit" value='Delete all items from table' />
		</form>
	</fieldset>
	
	<?php
	if($rows = $mysqli->query("SELECT * FROM inventory")){
		if($rows->num_rows){
		while($item = $rows->fetch_object()){
			$inventory[] = $item;
			}
		}
	}
	
    if(!count($inventory)){
         echo "No items added to the inventory database yet.";
    } else {
    ?>
     <table>
        <thead>
           <tr>
			<th>Name</th>
			<th>Category</th>
			<th>Price</th>
       	   <tr>
         </thead>
  	    <?php 
 		foreach($inventory as $items){
		$thisname = $items->name;
		$thiscat = $items->category;
		$thisprice = $items->price;
		?>
            <tr>
			<td><?php echo $thisname; ?></td>
			<td><?php echo $thiscat; ?></td>
			<td><?php echo $thisprice; ?></td>
	        <td><form method="POST" action="delete.php"><input type="hidden" value="<?php echo $items->id;?>" name="id" />
			<input type="submit" value='Delete this item' />
				</form>
	      </tr>
 	    <?php
		}
	    ?>
		</table>
    <?php
    }
    ?>
	</body>
</html>
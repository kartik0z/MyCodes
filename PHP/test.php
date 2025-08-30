<?php
session_start(); // Start session at the top
?>

<!DOCTYPE html>
<html>
<head>
    <title>PHP Functions, Forms & State Management Demo</title>
</head>
<body>

<h2>1. PHP Functions</h2>
<?php
// Defining and Calling Function
function greet($name) {
    echo "Hello, $name!<br>";
}
greet("Kartik");

// Passing by Value vs Reference
function addFive($num) {
    $num += 5;
}
function addTen(&$num) {
    $num += 10;
}
$a = 10;
addFive($a);
echo "Passing by Value: $a<br>"; // 10

$b = 10;
addTen($b);
echo "Passing by Reference: $b<br>"; // 20

// Inbuilt Functions
echo "String Length: " . strlen("Hello PHP") . "<br>";
echo "String Reverse: " . strrev("Hello") . "<br>";
echo "Uppercase: " . strtoupper("php") . "<br>";
echo "Random Number (1-100): " . rand(1,100) . "<br>";

// Variable Scope
$x = 50; // Global
function testScope() {
    global $x;
    $y = 20; // Local
    echo "Inside function: x=$x, y=$y<br>";
}
testScope();
echo "Outside function: x=$x<br>";

// PHP Errors demo
// echo $undefinedVar; // Notice
// include("missing.php"); // Warning
// undefinedFunction(); // Fatal Error
?>

<hr>

<h2>2. Working with Forms</h2>

<!-- GET Form -->
<form method="get">
    Name (GET): <input type="text" name="get_name">
    <input type="submit" value="Submit via GET">
</form>

<?php
if(isset($_GET['get_name'])){
    echo "GET Received: " . $_GET['get_name'] . "<br>";
}
?>

<!-- POST Form -->
<form method="post">
    Email (POST): <input type="email" name="post_email">
    <input type="submit" value="Submit via POST">
</form>

<?php
if(isset($_POST['post_email'])){
    echo "POST Received: " . $_POST['post_email'] . "<br>";
}
?>

<hr>

<h2>3. HTML Form Controls</h2>
<form method="post">
    Username: <input type="text" name="username"><br>
    Password: <input type="password" name="password"><br>

    Gender:
    <input type="radio" name="gender" value="Male"> Male
    <input type="radio" name="gender" value="Female"> Female <br>

    Hobbies:
    <input type="checkbox" name="hobbies[]" value="Reading"> Reading
    <input type="checkbox" name="hobbies[]" value="Sports"> Sports <br>

    Country:
    <select name="country">
        <option value="India">India</option>
        <option value="USA">USA</option>
    </select><br>

    <input type="submit" name="form_submit" value="Submit Form">
</form>

<?php
if(isset($_POST['form_submit'])){
    echo "Username: " . $_POST['username'] . "<br>";
    echo "Password: " . $_POST['password'] . "<br>";
    echo "Gender: " . ($_POST['gender'] ?? 'Not selected') . "<br>";
    echo "Hobbies: " . (isset($_POST['hobbies']) ? implode(", ", $_POST['hobbies']) : 'None') . "<br>";
    echo "Country: " . $_POST['country'] . "<br>";
}
?>

<hr>

<h2>4. State Management</h2>

<?php
// Cookies
setcookie("username", "Kartik", time()+3600); // Set cookie
if(isset($_COOKIE['username'])){
    echo "Cookie Value: " . $_COOKIE['username'] . "<br>";
} else {
    echo "Cookie not set.<br>";
}

// Sessions
$_SESSION['user'] = "Kartik";
echo "Session Value: " . $_SESSION['user'] . "<br>";

// Query String Example
echo '<a href="?name=Kartik&age=21">Click for Query String</a><br>';
if(isset($_GET['name'])){
    echo "Query String -> Name: " . $_GET['name'] . ", Age: " . $_GET['age'] . "<br>";
}

// Hidden Field Example
?>
<form method="post">
    <input type="hidden" name="userid" value="12345">
    <input type="submit" name="hidden_submit" value="Submit Hidden Field">
</form>

<?php
if(isset($_POST['hidden_submit'])){
    echo "Hidden Field Value: " . $_POST['userid'] . "<br>";
}
?>

</body>
</html>

<?php

//==================================================
// UNIT-II: PHP Core Concepts & State Management
//==================================================

/*--------------------------------------------------
 | 1. Core PHP Concepts
 *-------------------------------------------------*/

/**
 * @section 1.1 Variable Scope
 * Defines where a variable can be accessed.
 */

$global_var = "I am outside any function."; // Global scope

function myFunction() {
    $local_var = "I am inside a function."; // Local scope
    echo $local_var; // Accessible here

    // To access a global variable, use the 'global' keyword
    global $global_var;
    echo $global_var;
}

// echo $local_var; // This would cause an error (undefined variable)


/**
 * @section 1.2 Mail Function
 * A built-in function to send emails from a PHP script.
 * Syntax: mail(to, subject, message, [headers], [parameters]);
 */

/*
$to = 'recipient@example.com';
$subject = 'Test Email from PHP';
$message = 'Hello! This is a test email.';
$headers = 'From: webmaster@example.com';

if (mail($to, $subject, $message, $headers)) {
    echo "Email sent successfully!";
} else {
    echo "Email sending failed.";
}
*/


/**
 * @section 1.3 PHP Errors
 * Different levels of errors in PHP scripts.
 * error_reporting() can be used to set the level of error logging.
 */

// E_NOTICE: Non-critical issue, e.g., using an undefined variable. Script continues.
// E_WARNING: A non-fatal error. Script continues but indicates a problem.
// E_ERROR (Fatal Error): A critical error that halts script execution.


/*--------------------------------------------------
 | 2. Working with Forms
 *-------------------------------------------------*/

/**
 * @section 2.1 GET and POST Methods
 * Methods to send user-submitted data to a server.
 *
 * <form action="process.php" method="POST">
 * <input type="text" name="username">
 * <input type="submit">
 * </form>
 */

// GET Method:
// - Appends data to the URL (e.g., page.php?name=value).
// - Visible, limited in size, good for bookmarks/search.
// - Data is accessed via the $_GET superglobal array.
$username_get = $_GET['username'] ?? 'guest';

// POST Method:
// - Sends data in the HTTP request body.
// - Not visible in the URL, no size limit.
// - More secure for sensitive data (passwords, etc.).
// - Data is accessed via the $_POST superglobal array.
$username_post = $_POST['username'] ?? 'guest';


/**
 * @section 2.2 HTML Form Controls
 * Elements used to collect user input.
 */
/*
<input type="text" name="name">
<input type="password" name="pwd">
<textarea name="comment"></textarea>

<input type="radio" name="gender" value="male">
<input type="checkbox" name="vehicle" value="Car">
<select name="city">
  <option value="delhi">Delhi</option>
</select>

<input type="submit" value="Submit">
<input type="reset" value="Clear">
<button type="button">Click Me</button>
*/


/*--------------------------------------------------
 | 3. PHP State Management
 | HTTP is stateless. These techniques help maintain user data across multiple pages.
 *-------------------------------------------------*/

/**
 * @section 3.1 Cookies
 * A small file the server embeds on the user's computer.
 */
// Setting a cookie (name, value, expiration_time, path)
setcookie("user", "JohnDoe", time() + (86400 * 30), "/"); // Expires in 30 days

// Accessing a cookie
if (isset($_COOKIE["user"])) {
    echo "Welcome back, " . $_COOKIE["user"];
}


/**
 * @section 3.2 Sessions
 * Stores information on the server, linked by a unique session ID (often stored in a cookie).
 * More secure than cookies for sensitive data.
 */
// Must be at the top of the script
session_start();

// Storing session data
$_SESSION['user_id'] = 123;
$_SESSION['username'] = "admin";

// Accessing session data
if (isset($_SESSION['username'])) {
    echo "Hello, " . $_SESSION['username'];
}

// Destroying a session
// session_unset();    // Remove all session variables
// session_destroy();  // Destroy the session


/**
 * @section 3.3 Application State
 * Data/state that is shared across the entire application for all users.
 * Often managed via databases, configuration files, or server-side caching.
 */


/**
 * @section 3.4 Query String
 * Part of a URL containing data, starting with a "?".
 * Example: https://example.com/search.php?product=laptop&page=2
 */
// The data is accessed using the $_GET array.
$product = $_GET['product']; // "laptop"
$page = $_GET['page'];       // "2"


/**
 * @section 3.5 Hidden Field
 * A form input that is not visible to the user.
 * Used to pass data that shouldn't be changed by the user.
 */
/*
<form action="update.php" method="POST">
    <input type="hidden" name="user_id" value="101">
    <input type="text" name="email">
    <input type="submit">
</form>
*/
// In update.php, the user_id can be accessed via $_POST['user_id']

?>

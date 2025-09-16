<?php
declare(strict_types=1);

/**
 * -----------------------------
 * Error reporting (development)
 * -----------------------------
 */
error_reporting(E_ALL);          // Report all errors
ini_set('display_errors', '1');  // Show errors on screen (disable in production)
ini_set('log_errors', '1');      // Log errors to server logs
// error_log('Custom log entry'); // Example manual log

/**
 * -----------------------------
 * Variable scope demonstration
 * -----------------------------
 * - global: defined outside functions; use `global $var` inside to access
 * - local: defined inside a function; only visible there
 * - static: retains value across function calls
 */
$globalVar = 'I am global';

function scope_demo(): array {
    $localVar = 'I am local';
    global $globalVar;            // Access global inside function
    static $counter = 0;          // Static retains value
    $counter++;
    return [$localVar, $globalVar, $counter];
}
list($local, $global, $count1) = scope_demo();
list($_,     $_g2,   $count2) = scope_demo();

/**
 * -----------------------------
 * Sessions (application state)
 * -----------------------------
 * Must be called before any output
 */
session_start(); // Start/resume per-user session

// Initialize/advance a session counter
$_SESSION['visits'] = ($_SESSION['visits'] ?? 0) + 1;

// Store some session state
if (!isset($_SESSION['cart'])) {
    $_SESSION['cart'] = ['items' => [], 'total' => 0];
}

/**
 * -----------------------------
 * Cookies (client-side state)
 * -----------------------------
 * Must be sent before any output (they are HTTP headers)
 * Secure flags: secure (HTTPS only) and httponly (not accessible to JS)
 */
setcookie(
    'theme',
    'light',
    [
        'expires'  => time() + 86400 * 30,   // 30 days
        'path'     => '/',
        'secure'   => isset($_SERVER['HTTPS']),
        'httponly' => true,
        'samesite' => 'Lax'
    ]
);

/**
 * -----------------------------
 * Simple mail() example
 * -----------------------------
 * Will only succeed if the server has a working mail transport configured
 */
// Uncomment to test in a properly configured environment
// $sent = mail('someone@example.com', 'Test Subject', "Hello from PHP.\n");
// if (!$sent) { error_log('mail() failed'); }

/**
 * -----------------------------
 * Start of HTML (no output before this point for sessions/cookies)
 * -----------------------------
 */
?>
<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <title>PHP Notes: Forms, State, Scope, Mail, Errors</title>
  <style>
    body { font-family: system-ui, sans-serif; margin: 2rem; }
    pre { background: #f6f8fa; padding: 1rem; overflow:auto; }
    fieldset { margin-bottom: 1.25rem; }
    label { display: inline-block; margin-right: .75rem; }
  </style>
</head>
<body>

<h2>Query string (GET)</h2>
<p>
  <a href="?q=php&ref=notes&n=2">Click to add a query string</a>
</p>
<?php
// $_GET comes from URL parameters ?key=value
if (!empty($_GET)) {
    echo '<pre>$_GET = ' . htmlspecialchars(print_r($_GET, true)) . '</pre>';
}
?>

<h2>POST form controls</h2>
<form method="post" action="">
  <fieldset>
    <legend>Text inputs</legend>
    <label>Full name <input type="text" name="name" required></label>
    <label>Email <input type="email" name="email"></label>
    <input type="hidden" name="hidden_token" value="<?php echo bin2hex(random_bytes(8)); ?>">
  </fieldset>

  <fieldset>
    <legend>Choices</legend>
    <label><input type="checkbox" name="skills[]" value="php"> PHP</label>
    <label><input type="checkbox" name="skills[]" value="html"> HTML</label>
    <label><input type="checkbox" name="skills[]" value="css"> CSS</label>

    <label><input type="radio" name="role" value="user" checked> User</label>
    <label><input type="radio" name="role" value="admin"> Admin</label>

    <label>City
      <select name="city">
        <option value="delhi">Delhi</option>
        <option value="mumbai">Mumbai</option>
        <option value="pune">Pune</option>
      </select>
    </label>
  </fieldset>

  <button type="submit" name="submit" value="1">Submit POST</button>
</form>

<?php
// $_POST collects form data sent in the HTTP request body
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Safely read values
    $name   = $_POST['name']   ?? '';
    $email  = $_POST['email']  ?? '';
    $skills = $_POST['skills'] ?? [];
    $role   = $_POST['role']   ?? '';
    $city   = $_POST['city']   ?? '';
    $token  = $_POST['hidden_token'] ?? '';

    echo '<pre>';
    echo "name: "   . htmlspecialchars($name) . "\n";
    echo "email: "  . htmlspecialchars($email) . "\n";
    echo "skills: " . htmlspecialchars(implode(',', $skills)) . "\n";
    echo "role: "   . htmlspecialchars($role) . "\n";
    echo "city: "   . htmlspecialchars($city) . "\n";
    echo "hidden_token: " . htmlspecialchars($token) . "\n";
    echo "</pre>";
}
?>

<h2>Session and cookie</h2>
<?php
echo '<pre>';
echo "session visits: " . (int)$_SESSION['visits'] . "\n";
echo "cookie theme: " . htmlspecialchars($_COOKIE['theme'] ?? 'not set') . "\n";
echo "</pre>";
?>

<h2>Scope demo (global/local/static)</h2>
<?php
echo '<pre>';
echo "local: $local\n";
echo "global in function: $global\n";
echo "static counter call #1: $count1, call #2: $count2\n";
echo "</pre>";
?>

<h2>Quick tips</h2>
<ul>
  <li>Use htmlspecialchars() when echoing user input to prevent XSS.</li>
  <li>Validate server-side regardless of form attributes like required or type=email.</li>
  <li>Prefer prepared statements (PDO/MySQLi) for DB operations to avoid SQL injection.</li>
</ul>

</body>
</html>

<?php
define("SITE_NAME", "MyWebsite");
echo "Constant SITE_NAME: " . SITE_NAME . "<br><br>";

$name = "Kartik";
$age = 18;
echo "Name: " . $name . "<br>";
echo "Age: " . $age . "<br><br>";

$num1 = 10;
$num2 = 3;
echo "Addition: " . ($num1 + $num2) . "<br>";
echo "Subtraction: " . ($num1 - $num2) . "<br>";
echo "Multiplication: " . ($num1 * $num2) . "<br>";
echo "Division: " . ($num1 / $num2) . "<br>";
echo "Modulus: " . ($num1 % $num2) . "<br><br>";

$x = 5;
$x += 3;
echo "After += : " . $x . "<br>";

$x -= 2;
echo "After -= : " . $x . "<br>";

$x *= 4;
echo "After *= : " . $x . "<br>";

$x /= 2;
echo "After /= : " . $x . "<br><br>";

$y = 5;
echo "Original y: " . $y . "<br>";
echo "Post-increment y++: " . $y++ . "<br>";
echo "Now y is: " . $y . "<br>";
echo "Pre-increment ++y: " . ++$y . "<br><br>";

$z = 5;
echo "Original z: " . $z . "<br>";
echo "Post-decrement z--: " . $z-- . "<br>";
echo "Now z is: " . $z . "<br>";
echo "Pre-decrement --z: " . --$z . "<br><br>";

$str1 = "Hello";
$str2 = "World";

$result = $str1 . " " . $str2;
echo "Concatenation (.) : " . $result . "<br>";

$str1 .= " PHP";
echo "After . assignment: " . $str1 . "<br>";
?>
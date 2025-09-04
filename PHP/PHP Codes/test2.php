<!DOCTYPE html>
<html>

<head>
    <title>Associative Array Example</title>
</head>
<style>
</style>

<body>
    <h2>Enter Student Details</h2>
    <form method="POST">
        Name: <input type="text" name="name"><br><br>
        Age: <input type="number" name="age"><br><br>
        Course: <input type="text" name="course"><br><br>
        <input type="submit" value="Submit">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Creating an associative array from form inputs
        $student = [
            "Name" => $_POST['name'],
            "Age" => $_POST['age'],
            "Course" => $_POST['course']
        ];

        // Displaying values
        echo "<h3>Student Details:</h3>";
        foreach ($student as $key => $value) {
            echo "$key : $value <br>";
        }
    }
    ?>
</body>

</html>
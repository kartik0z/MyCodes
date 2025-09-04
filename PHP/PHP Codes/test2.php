<!DOCTYPE html>
<html>

<head>
    <title>Associative Array Example</title>
    <style>
        body {
            align-items: center;
            background-color: #000;
            display: flex;
            justify-content: center;
            height: 100vh;
        }

        .form {
            background-color: #15172b;
            border-radius: 20px;
            box-sizing: border-box;
            min-height: 500px;
            padding: 20px;
            width: 320px;
        }

        .title {
            color: #eee;
            font-family: sans-serif;
            font-size: 28px;
            font-weight: 600;
            text-align: center;
            margin-top: 10px;
        }

        .subtitle {
            color: #eee;
            font-family: sans-serif;
            font-size: 16px;
            font-weight: 600;
            margin-top: 10px;
            text-align: center;
        }

        .input-container {
            height: 50px;
            position: relative;
            width: 100%;
        }

        .ic1 {
            margin-top: 40px;
        }

        .ic2 {
            margin-top: 30px;
        }

        .input {
            background-color: #303245;
            border-radius: 12px;
            border: 0;
            box-sizing: border-box;
            color: #eee;
            font-size: 18px;
            height: 100%;
            outline: 0;
            padding: 4px 20px 0;
            width: 100%;
        }

        .cut {
            background-color: #15172b;
            border-radius: 10px;
            height: 20px;
            left: 20px;
            position: absolute;
            top: -20px;
            transform: translateY(0);
            transition: transform 200ms;
            width: 76px;
        }

        .cut-short {
            width: 50px;
        }

        .input:focus~.cut,
        .input:not(:placeholder-shown)~.cut {
            transform: translateY(8px);
        }

        .placeholder {
            color: #65657b;
            font-family: sans-serif;
            left: 20px;
            line-height: 14px;
            pointer-events: none;
            position: absolute;
            transform-origin: 0 50%;
            transition: transform 200ms, color 200ms;
            top: 20px;
        }

        .input:focus~.placeholder,
        .input:not(:placeholder-shown)~.placeholder {
            transform: translateY(-30px) translateX(10px) scale(0.75);
        }

        .input:not(:placeholder-shown)~.placeholder {
            color: #808097;
        }

        .input:focus~.placeholder {
            color: #dc2f55;
        }

        .submit {
            background-color: #08d;
            border-radius: 12px;
            border: 0;
            box-sizing: border-box;
            color: #eee;
            cursor: pointer;
            font-size: 18px;
            height: 50px;
            margin-top: 38px;
            text-align: center;
            width: 100%;
        }

        .submit:active {
            background-color: #06b;
        }

        .result {
            margin-top: 30px;
            padding: 15px;
            border-radius: 12px;
            background-color: #303245;
            color: #eee;
            font-family: sans-serif;
            font-size: 16px;
        }

        .result h3 {
            margin-top: 0;
            color: #08d;
        }
    </style>
</head>

<body>

    <form method="POST" class="form">
        <div class="title">Student Form</div>
        <div class="subtitle">Enter your details</div>

        <div class="input-container ic1">
            <input type="text" class="input" name="name" placeholder=" " required />
            <div class="cut"></div>
            <label class="placeholder">Name</label>
        </div>

        <div class="input-container ic2">
            <input type="number" class="input" name="age" placeholder=" " required />
            <div class="cut cut-short"></div>
            <label class="placeholder">Age</label>
        </div>

        <div class="input-container ic2">
            <input type="text" class="input" name="course" placeholder=" " required />
            <div class="cut"></div>
            <label class="placeholder">Course</label>
        </div>

        <input type="submit" class="submit" value="Submit">

        <?php
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            // Creating associative array from form inputs
            $student = [
                "Name" => $_POST['name'],
                "Age" => $_POST['age'],
                "Course" => $_POST['course']
            ];

            echo '<div class="result">';
            echo "<h3>Student Details</h3>";
            foreach ($student as $key => $value) {
                echo "<strong>$key:</strong> $value <br>";
            }
            echo '</div>';
        }
        ?>
    </form>

</body>

</html>
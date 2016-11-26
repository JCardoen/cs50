#!/usr/bin/env php
<?php

    // requirement
    require(__DIR__ . "/../includes/config.php");
    
    // make sure there is an appropriate number of command-line arguments
    if ($argc != 2)
    {
	print("Usage: ./import text");
	exit(1);
    } 
    
    
    // check if file exists
    if (!file_exists($argv[1]))
    {
	print("File not found.");
	exit(1);
    }
    
    // check if file is readable
    if (!is_readable($argv[1]))
    {
	print("File not readable.");
	exit(1);
    }
    
    // open file
    $file = fopen($argv[1], "r");
    
    // check if open was successful
    if ($file == false)
    {
	print("Unable to open file.");
	exit(1);
    }
    
    // get line and insert into database
    while ($row = fgetcsv($file, 1000, "\t"))
    {
	cs50::query("INSERT INTO places (country_code, postal_code, place_name,
	      admin_name1, admin_code1, admin_name2, admin_code2, admin_name3,
	      admin_code3, latitude, longitude, accuracy) VALUES(?, ?, ?, ?,
	      ?, ?, ?, ?, ?, ?, ?, ?)", $row[0], $row[1], $row[2], $row[3],
	      $row[4], $row[5], $row[6], $row[7], $row[8], $row[9], $row[10],
	      $row[11]);
    }
    // close file
    fclose($file);

?>
<?php

/**
 * FFI Example
 * @link https://www.php.net/manual/en/book.ffi.php
 * @author Gavin R. Nesmith <grnesmith@gmail.com>
 * @license MIT
 * @version 1.0.0
 */

if (!extension_loaded('ffi')) {
    die("FFI extension not loaded");
}

// Define the C function prototypes and data types
$ffi = FFI::cdef("
    int netstat();
    int ping(const char* host);
    int test_port(const char* host, int port);
", "./_nettools.so");

// Usage example
$ffi->netstat();  // Execute netstat command
$ffi->ping("example.com");  // Ping example.com
$ffi->test_port("localhost", 80);  // Test if port 80 is open on localhost

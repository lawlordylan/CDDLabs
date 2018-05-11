#Lab 5 - Producer Consumer
#Author: Dylan Lawlor
#Date: 11/05/2018
#Licence: GNU General Public License v3.0

This Lab demonstrates a 2 classes a producer and consumer working on a thread safe buffer using semaphores.
The producer generates random characters from ‘a’ to ‘z’ at random intervals (between 0 and 1 second in length). It adds these to a thread safe buffer that has a finite holding capacity of N characters. It generates a preset number of characters (determined at runtime) and when it has finished it add an ‘X’ character to the buffer and exits.
The consumer takes these letters from the buffer at random time intervals (between 0 and 1 second in length) and records how many of each letter it consumes. Once it sees an ‘X’ in the buffer it adds its character count to a central buffer and exits.

To create the executable open the directory in the terminal.
run the command 'make'
This produces an executable that can be run with the './main' command.


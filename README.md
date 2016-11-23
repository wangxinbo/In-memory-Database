# In-memory-Database
Simulate a simple in-memory database: https://www.thumbtack.com/challenges/simple-database

Data Commands

SET name value – Set the variable name to the value value. Neither variable names nor values will contain spaces.

GET name – Print out the value of the variable name, or NULL if that variable is not set.

UNSET name – Unset the variable name, making it just like that variable was never set.

NUMEQUALTO value – Print out the number of variables that are currently set to value. If no variables equal that value, print 0.

END – Exit the program. Your program will always receive this as its last command.

Transaction Commands

BEGIN – Open a new transaction block. Transaction blocks can be nested; a BEGIN can be issued inside of an existing block.

ROLLBACK – Undo all of the commands issued in the most recent transaction block, and close the block. Print nothing if successful, or print NO TRANSACTION if no transaction is in progress.

COMMIT – Close all open transaction blocks, permanently applying the changes made in them. Print nothing if successful, or print NO TRANSACTION if no transaction is in progress.

1. To compile the code:
   a. Go the ./build folder
   b. Type in: cmake ..
   b. Type in: make

2. To test the code
   a. Go to ./tests
   b. Type in: python test.py

3. To run the executable of the code
   a. Go to ./bin
   b. Type in: ./simpleDB
4. "integrated_code.cpp" is a single compliable file that integrates all codes.

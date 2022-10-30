# CSC254Project2


---------------------------------------------------------
Completed by: Junfei Liu (jliu137) & Pinxin Liu (pliu23)
---------------------------------------------------------

Hi grader,

--------------------- How to run ---------------------------------

Compilation and run instructions are:
You need to go the CSC254_project3 directory and type make in commandline for compilation.
After that, you can run the program by typing the following command:
ocamlc -o test_ecl str.cma ecl_test.ml
then a executable binary file named test_ecl will be generated. You can run it by typing:
./test_ecl < [input file] > [output file]
where input file is the file containing extended calculator language code and the output file
will contain generated Pidgin C code. You can compile the genrated Pidgin C code by typing:
gcc -o [executable] [generated C file]
where the generated C file is Pidgin C code and output file is the generated executable.
You can then run the C program by typing:
./[executable]

For example, you can generate the C code for primes-generating program by following:
Create primes.ecl file containing the primes-generating program in extended calculator language
ocamlc -o test_ecl str.cma ecl_test.ml
./test_ecl < primes.ecl > primes.c
Then you can compile and run primes.c by typing:
gcc -o primes primes.c
./primes

We provide the following sample test files:
primes.ecl --- contains the primes_prog
gcd.ecl --- contains the gcd_prog
sum.ecl --- contains the sum_ave_prog
sqrt.ecl --- contains the sqrt_prog
and the following custom test files:
parallel_scope.ecl --- contains several parallel scope in addition to nested scope
long_binop.ecl --- contains complicated binops in a line


To run the test files, you can use the following commands:
./test_ecl < primes.ecl > primes_test.c
./test_ecl < gcd.ecl > gcd_test.c
./test_ecl < sum.ecl > sum_test.c
./test_ecl < sqrt.ecl > sqrt_test.c
./test_ecl < parallel_scope.ecl > parallel_scope_test.c
./test_ecl < long_binop.ecl > long_binop_test.c


--------------------- work we have done ------------------------------

### 1. Translate the parse tree into a syntax tree

To generate the syntax tree, we first define the data type for syntax tree. There are two types of syntax tree:
1. The syntax tree for expressions

We found that AST nodes will have vloc and aloc for locations when they see a non-termal to be placed
Thus, while generating the AST nodes, these ASTs will have the localtion information. Because these are the expression,
These will be generated during the ast_ize_expr, when we see the E, T, or F non-terminals.
This type of syntax tree is defined as follows:
AST_int: 
    this will get the value of a terminal that has a type of integer
AST_real: 
    this will get the value of a terminal that has a type of real
AST_id: 
    this will get the value of a terminal that has a type of identifier
AST_float: 
    this will get the value of a terminal that has a type of float
AST_trunc: 
    this will get the value of a non-terminal and will transform the original data type from real to integer
AST_binop: 
    this will get the value of a non-terminal that is a binary operation, and it will also get the left and right child of the non-terminal
    We see this correponds to the Condition rules and expression tails.

2. The syntax tree for statements
We look at the parse tree and found out that each statement will be a non-terminal and will have the functions
defined by the following AST trees. As a result, we look at PT_nt (non-terminal) and PT_t (terminal) to see
how the non-terminal and terminal should be used for geneating the AST nodes. We only see these rules used in the statement,
so we will generate the AST nodes during the ast_ize_stmt.
This type of syntax tree is defined as follows:

AST_assign: 
    this will get the value of a non-terminal that is an assignment statement, and it will also get the left and right child of the non-terminal
    We look at the parse tree and see the operations for assign, then we define the way when we see typical rules for assign statement.
AST_if: 
    this will get the value of a non-terminal that is an if statement, and it will also get the left and right child of the non-terminal
AST_while: 
    this will get the value of a non-terminal that is a while statement, and it will also get the left and right child of the non-terminal
AST_i_dec: 
    this will get the value of a non-terminal that is an integer declaration statement
AST_r_dec: 
    this will get the value of a non-terminal that is a real declaration statement
AST_read: 
    this will get the value of a non-terminal that is a read statement
AST_write: 
    this will get the value of a non-terminal that is a write statement
AST_error: 
    this will generate the error if the AST is unable to be generated



You can check ASTs generated through the ocaml interpreter. By typing
ocaml
in the command line, you can enter the ocaml interpreter. Then type
#use "ecl_test.ml";;
Now you can see the ASTs generated for test cases.


### 2. Translate the AST into an equivalent program in Pidgin C

1. symtab definition
To generate the code in pidgin C, we first defiend the symtab for using the corresponding data.

We define the symtab as follows:
type symtab =
   { 
     temp_scopes: scope_info list;
     scopes     : scope_info list;
     layer      : int;
     max_mem    : int;
     max_temp   : int;
     
   };;

Here the temp_scope is the place to store the temp variables for each scope. THe scope is to store the variables for each scope. 
The layer is to store the current layer of the scope, this will be added when we see a while or a if statement to go to a deeper scope.
The max_mem is to store the maximum memory used during the code generating steps. The max_temp is to store the maximum temp variable used during the code generating steps.

2. insertion and lookup of the symtab

We define the insertion step that when a new variable is declared, then we need to insert a new variable in the current scope.
For temp variables, each time we see a binary operation, you should have a temp variable to save its value.
Loopup is to check if variables are redecalred or not. If the variable is redeclared, then we will generate the error message.
If a varaible does not exist, then we will generate the error message.

3. code generation
We define the code generation step that when we see a statement, we will generate the corresponding code in pidgin C. 
We will generate the code for each statement and then combine them together to generate the final code.
There are two types of code to generate:
i. The code for statement
AST_i_dec: 
    this will generate the code for integer declaration statement
AST_r_dec:
    this will generate the code for real declaration statement
AST_assign:
    this will generate the code for assign statement
AST_if:
    this will generate the code for if statement, it looks at the condition, get to the next layer
    and if the condition does not match, go to where the next layer is defined
AST_while:
    this will generate the code for while statement, it looks at the condition, get to the next layer
    and if the condition does not match, go to the layer that ends the while loop. On the other side,
    if the condition matches, then it will go to the next layer and generate the code for the statements.
    At the end of AST_while, you will go back to the layer before the condition for the future check as the loop back.
AST_read:
    this will generate the code for read statement, it will read the value from the input and print out a message of getint() or getreal().
AST_write:
    this will generate the code for write statement, it will write the value to the output and print out a message of putint() or putreal().
AST_error:
    this will generate the error message if the AST is unable to be generated

ii. The code for expression
During this step, the expression may be a varable or a temp varaible, if it is a variable, then the oprand will be Atom,
if it is a temp variable, then the oprand will be Temp. If a Atom variable is generated, it does not need to look at the previous code
However, if a temp varaible is generated, for the next line of code, it needs to concat with the current code generated by the temp variable

The following are how we generate the code for expression:
AST_int: 
    this will generate the code for integer
AST_real:   
    this will generate the code for real
AST_id:
    this will generate the code for identifier
AST_float:
    this will generate the code that will transform the int to float, it will generate a temp variable
AST_trunc: 
    this will generate the code that will transform the real to int, it will generate a temp variable
AST_binop:
    this will look at the left and right child of the non-terminal and generate the code for the binary operation
    it will generate a temp variable for the operation.

iii. memeory check
We only use i, r, ti, tr for this program, where i is the integer, r is the real, ti is the temp integer, tr is the temp real.
Each time we insert an variable into the symtab, we call the new memery function to allocate new space. Each time we generate a temp variable, we call the new temp function to allocate new space. 
The memeory used during the whole program will be the length of the i, r, ti, tr array to be allocated in the pidgin C.


### 3. static error checking
1. Use of an undeclared variable
we will use the lookup function each time when we see a variable, if the variable is not declared, then we will generate the error message.

2. Redeclaration of a variable in the same scope
It only happens when the program see the AST_r_dec and AST_i_dec, we will use the insert function to check if the variable is redeclared or not. 
If the variable is redeclared, then it will return a false and we will throw an error message.

3. Non-integer provided to float
It only happens when the program see the AST_float, we will check if the oprand is an integer or not. If the oprand is not an integer, then we will throw an error message.

4. Non-float provided to int
It only happens when the program see the AST_trunc, we will check if the oprand is a real or not. If the oprand is not a real, then we will throw an error message.

5. Type clash in binary expression, comparison, or assignment
It happens when the program see the AST_binop, or AST_assign. We will check if the left and right child are the same type or not. 
If they are not the same type, then we will throw an error message.


You can check the pidgin c programs generated by instructions in How to run section above.

### Extra credits




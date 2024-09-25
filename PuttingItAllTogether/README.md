# C Statistics Gathering Program
## Preliminary Specification 
>[!WARNING]
>This document is a preliminary specification. Any resemblance to any software living or dead is purely coincidental. 

The program stat gathers statics about C source files and prints them. The command line is:
```bash
  stat <files..>
```
Where <files..> is a list of source files. The following shows the output of the program on a short test file. 
```bash
[File: stat/stat.out]

```

## Code Design 
First, we have a token scanner, which reads raw C code and turns it into tokens. This subdivides into three smaller modules. 
- The first reads the input file
- The second determiens what type of character we ahve
- Lastly, assembles this information into a token

A token is a group of characters that form a single word, number, or symbol.

The main module consumes tokens and output statistics. Again, this module breaks down into smaller submodules: a do_file procedure to manage each file and a submodule for each statistic. 

### Token Module
Our program scans C source code and uses the tokens to genereate statistics. For example, the line:
```C
anwser = (123 + 456) / 89; /* Compute some sort of result */
```
consists of the tokens:

Tokens     |Descriptions|
-----------|------------|
T_ID       | The word "answer"
T_OPERATOR | The character "="
T_L_PAREN  | Left parenthesis
T_NUMBER   | The number 123
T_OPERATOR | The character "+"
T_NUMBER   | The number 456
T_R_PAREN  | The right parenthesis
T_OPERATOR | The divide operator
T_NUMBER   | The number 89
T_OPERATOR | The semicolon
T_COMMENT  | The comment 
T_NEW_LINE | The end-of-line character

We can easily distinguish between * character as an operator token, and the "a" character as the start of an identifer. However, some characters are ambiguous. Like, the / character, it could be the divide operator, or it could be the start of a /* comment. In order to identify this character, we need to look ahead one character. 

So one of the requirements for our input module is that it allow us to peek ahead one character. 
(current character, currect character + 1)

The token module builds tokens from groups of characters. For example, an identifier is defined as a letter or underscore, followed by any number of letters or digits. So our tokenizer needs to contain the pseudo code:
```pseudo
if the current character is a letter, then 
  scan until we get a character that's not a letter or digit
```
Our tokenizer depends a great deal on character types, so we need a module to hlep[ ]


## Coding 
But rather than try to write the entire program at once and then debug it, we will 
use a method called fast prototyping. We implement the smallest portion of the 
specificaiton that will still do something. In our case, we will cut our four fucntions down to a 
one-function calcualtor. 

## Testing
After we have compiled our fast prototyping program, we can now start writing a test plan.
This document is simply a list of the steps we perform to make sure the program works. 
It is written for two reasons:
* If a bug is found, we want to be able to reproduce it. 
* If we change the program, w will want to retest it to make sure new code did not break any of the sections of the program that were previously working. 

Our test palce starts out as:
```text
Try the following operations:
  + 123 Result should be 123
  + 52 Result should be 175
  x 37 Error message should be output
```
```bash
Result: 0
Enter operator and number: + 123
Result: 123
Enter operator and number: + 52
Result: 175
Enter operator and number: x 37
Result: 212
Enter operator and number:
```
Something is clearly wrong. We should have gotten the following meessage "Unknown operator".

## Debugging 
We can add printf statements to observer the behavior of the logic. 
But a quick code review, we will see that if condition on the operator is an assignment not an condition. 

Before:
```bash
    if (operator = '+')
    {
      result += value;
    } else {
      pritnf("Unknown operator %c\n", operator);
    }
```

After:
```bash
    if (operator == '+')
    {
      result += value;
    } else {
      pritnf("Unknown operator %c\n", operator);
    }
```

Execute the test plan, again. 
```bash
Result: 0
Enter operator and number: + 123
Result: 123
Enter operator and number: + 52
Result: 175
Enter operator and number: x 37
Unknown operator x
Result: 175
Enter operator and number: 
```
Test plan executed successfully. 

## Final Test Plan

```text
Try the following operations:
  + 123 Result should be 123
  + 52 Result should be 175
  x 37 Error message should be output
  - 175 Result should be zero
  + 10 Result should be 10
  / 5 Result should be 2
  / 0 Divide by zero error
  * 8 Result should be 16
  q Programshould exit
```

Final Test Results
```bash
Result: 0
Enter operator and number: + 123
Result: 123
Enter operator and number: + 52
Result: 175
Enter operator and number: x 37
Unknown operator x
Result: 175
Enter operator and number: - 175
Result: 0
Enter operator and number: + 10
Result: 10
Enter operator and number: / 5
Result: 2
Enter operator and number: / 0
Error: Divide by zero
        operation ignored
Result: 2
Enter operator and number: * 8
Result: 16
Enter operator and number: q

```
## Maintenance
While testing the program, we find that, much to our surprise, the program works. 
The word "Preliminary" is removed form the specification, and the program, test plan, and 
specification are released. 

The maintenance phase follows, bugs will be reported by the end user. Bugs will be fixed, 
the program is texted and the program is released again. 

## Revisions
After the program is in use for a few months, someone a client or enduser will come to us and ask, 
"Can you add a modulus oeprators?". We will to revise the specificaitons, add the change to the program, 
update the test plan, test the program, and then release the program again. 

After so many added features and changes, sooner or later we reach the point where the program
needs to be scrapped and a new one written from scratch. At the point, we write a preliminary
specification and start the process again. 


### Reference
Oualline, Steve. Practioncal C Programming. 3rd Edition. August 1997.
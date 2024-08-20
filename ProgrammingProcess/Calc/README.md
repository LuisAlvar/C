# Calc: A Four Function Calculator
## Preliminary Specification 
>[!WARNING]
>This document is a preliminary specification. Any resemblance to any
software living or dead is purely coincidental. 

Calc is a program that allows the user to trun a $2,000 computer into a $1.98 
four-functions calculator. The program will add, subtract, multiply, and divide 
simple integers

When the program is run, it will zero the result register and display the
register's contents. The user can then type in an operator and number. The result
will be updated and displayed. The following operators are valid:

|Operator|Meaning       |
|:-------|--------------|
|+       |Addition      |
|-       |Subtraction   |
|*       |Multiplication|
|/       |Division      |

For example:
```bash
calc
Result: 0
Enter operator and number: + 123
Result: 123
Enter operator and number: - 23
Result: 100
Enter operator and number: / 25
Result: 4
Enter operator and number: * 4
Result: 16
0
```

## Code Design 
Our simple caculator uses no files and requires no fancy data structures. What's
left for this phase is to design the major algorithm. Outlined in pseudo code, a shorthand halfway between English and real code, the major algorithm is:

```bash
Loop
  Read an operator and number
  Do the calculation
  Display the result
End-Loop
```

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
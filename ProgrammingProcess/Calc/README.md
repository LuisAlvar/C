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

For example: (user input is in boldface)
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

### Reference
Oualline, Steve. Practioncal C Programming. 3rd Edition. Augest 1997.
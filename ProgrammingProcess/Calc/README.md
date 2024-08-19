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
><strong>calc</strong>
<br/>
Result: 0
<br/>
Enter operator and number: <strong>+ 123</strong>
<br/>
Result: 123
<br/>
Enter operator and number: <strong>- 23</strong>
<br/>
Result: 100
<br/>
Enter operator and number: <strong>/ 25</strong>
<br/>
Result: 4
<br/>
Enter operator and number: <strong>* 4</strong>
<br/>
Result: 16
<br/>
0

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
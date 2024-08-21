# DaysInBetween: Calculate the Day Difference Between Two Dates
## Preliminary Specification 
>Warning: This document is a preliminary specification. Any resemblance to any software living or dead is purely coincidental. 

DaysInBetween is a program that allows the user enter two different days: first date before the second date. It will return the days difference between these two dates. 

When the program runs, it will display a prompt to enter an first date, and then re-prompted to enter a second date. Afterward, it will display the the days between the two dates. 


For example: (user input is in boldface)
```text
Enter first date (mm/dd/yyy): 06/06/1990
Enter second date (mm/dd/yyy): 04/03/1992
Number of days in between: ### day(s)
```

## Code Design 
Our conversion app will not use any files or require any type of data structures. What's left for this phase is to design the major algorithm.

```text
Loop
  Read first date
  Read second date
  Map date to time_t object
  Compute the number of days in between
  Display the result
End-Loop
```

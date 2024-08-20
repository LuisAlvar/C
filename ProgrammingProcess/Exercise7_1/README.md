# Convert: Conversion of Imperial To Metric Units
## Preliminary Specification 
>Warning: This document is a preliminary specification. Any resemblance to any software living or dead is purely coincidental. 

Convert is a program that allows the user enter any imperial unit value and be confidental that the metric unit value conversion is precise and accurry. 

When the program runs, it will display a prompt to enter an imperial value along with its unit. The result will be a metric value along with a unit.

The initial verison of this program will contain 
a short list of unit conversion requested by client. 

### Length 
|Imperial Unit| Metric Units|
|:------------|-------------|
|Inches (in)  |Meter (m)|
|Feet (ft)    |Meter (m)|
|Yard (yd)    |Meter (m)|
|Mile         |Meter (m)|

For example: (user input is in boldface)
> Enter a imperial value along with unit: <strong>12 in</strong>
<br/>
> Result: 30.48 cm


## Code Design 
Our conversion app will not use any files or require any type of data structures. What's left for this phase is to design the major algorithm.

```bash
Loop
  Read value and imperial unit. 
  Map imperial unit to metric units
  Compute the metric conversion 
  Display the result
End-Loop
```

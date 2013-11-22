# Robot Controller
This library provides a group of functions that can be used to 
drive a two-wheeled robot in multiple directions.


## Description


There is only one turn function for each direction and the length of the 
turn is determined by using the `_delay_cycles(numberOfCycles)` command. 
All commands are designed to end with the `stop()` function in order to
better prevent damage to the motors from sudden direction changes.



## Functions


`initPins()` -This function initializes the Timer_A output pins that will 
be used to drive the robot's motors.

`initTimer()` -This will initialize the internal Timer_A system.

`stop()` -This function is used to stop the robot between each   
This allows for pauses and better protects the motors from sudden changes.

`moveForward()` -Moves the robot forward at 50% duty cycle.

`moveReverse()` -Move the robot backwards at 50% duty cycle.

`turnLeft()` Turns the robot left.  Size of turn is based on how long 
the `_delay_cycles(numberOfCycles)` command is called.
Turns the right wheel forward and left wheel backwards.

`turnRight()` -Turns the robot right.  Again, the size of the turn is 
based on how long you allow the function to run.
Turns the left wheel forward and the right wheel backwards.


## Documentation

C2C Busho explained to me my initial approach to using the timer with `OUTMOD_4` 
and `OUTMOD_5`. I later changed my code at the recommendation of Capt Branchflower 
to run more consistently and with fewer bugs.
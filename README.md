# Traffic-Light-Control-System

A basic Arduino implementation of embedded systems using timed state transitions in order to produce a traffic light simulation. 

##How it Works
LED and LCD components are identified based on the associated pins on the Arduino UNO R3 and the times for each light are pre-set. The program loops and keeps track of the amount of time left for each state. After a full traffic cycle occurs the loop resets all values all the program to continue to the following cycle. 

##Plans for the Future
I plan to create a physical version of this program using an Arduino Uno R3 board and solderless breadboard, as well as explore the implementation of other Arduino based components that can help with visualizing the traffic system. 

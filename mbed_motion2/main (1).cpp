/*
Terminal Setup for Serial Monitor

Copy pasta this into terminal to get usb port n#
ls /dev/tty.usbmodem*

It will return the end digits for the following command

Then copy pasta:
screen /dev/tty.usbmodem1422
*/

/*
Name: Benn Hamer
Task: 3.1
Objective: Wire up a motion sensor with mbed.
*/

#include "mbed.h"

DigitalOut led1(LED1);
DigitalIn alarm(p29, PullUp); //internal pull up 
 
Serial pc(USBTX, USBRX);

int main() {  
    wait(2);
    
    pc.printf("Motion Sensor test! \n\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    
    while(1) {
        if (alarm){
            led1=1;
            wait(1);
            
            pc.printf("Alarm \n\b\b\b\b\b\b");
        }
        else
        {
            led1=0;
            wait(1);
            
            pc.printf("No Motion \n\b\b\b\b\b\b\b\b\b\b");
        }
        
    }
}
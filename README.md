Lab 7
======
#Purpose

To build code that uses the IR sensors on the robot and the LEDs on the MSP430 to determine how close it is to a wall. To characterize each IR sensor since there is a lot of variation between each. And to create a ADC10 Library for general use. 

#Hardware Schematic



#Debugging

There was not a lot of debugging for this lab, the most difficult section I had trouble with was getting the correct light conditions. Small shadows had an effect on what the IR was reading. 

#Testing Methedology/Results

Required: I used the left sensor for the Red LED, right sensor Green LED, and the center sensor for both LEDS. The code became rather simple, the program polls each sensor and stores it in a variable. Then the variable is compared to a general value and the light will turn on if it meets the threshold. 

B Funct: The library I created is pretty straight forward. It returns an unsigned short that contains an ADC10 value depending on each pin that is used. My library uses pins 1.2, 1.3 and 1.4.

A Funct: To get A functionality I measured the distance from the wall to each IR sensor. A DMM measured the voltage and each distance, then an Excel graph was created from this. 

##Required Functionality

Required Funct- Check

A/B Funct - Sent to Dr York via email, Check

#Observations/Conclusions

The ADC10 Library will help setup Lab 8 when the IR sensors direct what the motors should be doing.

##Documentation
None

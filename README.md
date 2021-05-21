# Blinking

**This is my first challenge in course from Ucode IT Academy featuring Ajax Systems.**

## The main idea

**Make my first step in IoT, make a couple blinks with random frequency.**

## My equipment

- **TI LaunchPad CC1352R1**
- **IMac**

## Software

**CodeComposerStudio (CCS)**

### Running this project
 - ***git clone***
 - ***open project with CCS***
 - ***select `empty_CC1352R1_LAUNCHXL_tirtos_ccs` in your project explorer***
 - ***press `hammer` icon to build this project***
 - ***there are various ways to flash the board with built project:***
    - ***select `empty_CC1352R1_LAUNCHXL_tirtos_ccs` in your project explorer and ...***
   - ***... press `curly brackets in a folder` icon***

## What is my project about

**This project was made to gain knowledge about CodeComposerStudio and simplest libraries.**

## How does it works

**In my empty.c file by using the library TRNG and function TRNG_getRandomBytes() I generate a true random number, UAR2 libraty helps to output numbers in terminal using function UART2_write(). Blinking is an app that will turn a built-in LED on/off at random intervals for a random time from 1 to 10 seconds.**

## Example

![Alt Text](https://github.com/okhramkov/blinking_ucode_ajax_iot/blob/master/materials/1.jpg)
![Alt Text](https://github.com/okhramkov/blinking_ucode_ajax_iot/blob/master/materials/2.png)

## Author

**Oleksii Khramkov, 21 y.o, Ukraine, Kiev, junior embedded developer**

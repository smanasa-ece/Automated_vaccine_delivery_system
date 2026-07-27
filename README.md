# Automated Vaccine Delivery System

Arduino-based automated vaccine delivery system for monitoring vaccine storage conditions during transportation using temperature sensing, GPS tracking, LEDs, and a buzzer.

## Overview

The Automated Vaccine Delivery System is designed to improve the safety of vaccine transportation by continuously monitoring storage conditions. It alerts the user whenever the temperature goes outside the safe range and provides GPS location tracking.

## Problem Statement

Vaccines must be transported within a safe temperature range. Manual monitoring may lead to delays in detecting unsafe conditions, resulting in vaccine wastage. This project automates temperature monitoring and alerts users immediately if unsafe conditions occur.

## Components Used

- Arduino UNO
- DS18B20 Temperature Sensor
- NEO-6M GPS Module
- Active Buzzer
- Red LED
- Green LED
- Breadboard
- Jumper Wires
- Power Supply

## Features

• Monitors vaccine temperature in real time.
• Indicates safe and unsafe conditions using LEDs.
• Sounds a buzzer when the temperature is outside the safe range.
• Tracks the vaccine carrier location using GPS.
• Arduino-based and easy to operate.

## Working

The DS18B20 temperature sensor continuously measures the vaccine storage temperature. If the temperature remains within the safe range, the green LED indicates normal operation. If the temperature exceeds or falls below the safe range, the red LED turns on and the buzzer alerts the user. The GPS module provides the current location of the vaccine carrier for tracking purposes.

## Applications

• Vaccine transportation
• Hospitals
• Primary Health Centres
• Medical supply chain monitoring
• Cold chain logistics

## Future Improvements

• IoT-based remote monitoring
• Mobile application integration
• Cloud data storage
• Battery backup
• Real-time notification system

## Author

**S Manasa**

*Mini Project – ECE*

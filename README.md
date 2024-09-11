# Photon-Intensity-Bio-Test-System

This project focuses on testing the effects of varying light intensities and colors (yellow, green, and blue) on biological cells, with the goal of understanding how different light wavelengths and photon intensities affect cell survival over time. The system is designed to be modular, allowing easy modification and recharging, making it both flexible and efficient for experimentation.

Components and Setup:
- 24V Battery System:
Batteries: The system is powered by three lithium-ion batteries, providing a total of 24V. The battery management is handled by a 3S BMS (20A) to ensure safe charging and discharging.
Rechargeable: The battery system is designed to be easily rechargeable, enabling long-term use and repeatability for experiments.

- Arduino Nano:
System Controller: The Arduino Nano acts as the brain of the system, managing the light intensity, timing, and interfacing with the rotary encoder for user input.
PWM Control: Pulse Width Modulation (PWM) is used to adjust the intensity of the diode lights, ensuring precise control over the light levels.
24V Diode Lights (Yellow, Green, Blue):

- Light Source:
The system utilizes three different diode lights to test various wavelengths (yellow, green, and blue). These lights are connected to the Arduino via 2N3904 NPN transistors for PWM control.
Adjustable Intensity: The light intensity can be controlled using the rotary encoder, allowing fine-tuned experiments to be conducted.
Rotary Encoder:

- User Input:
The rotary encoder is used to select the intensity of light, the color, and how long the system will operate. This makes it easy to control the system without needing additional hardware.
2x16 LCD Display:

- Data Display:
  The LCD screen shows real-time data, including the selected light color, intensity, and duration. This allows users to monitor and adjust the system easily during experiments.

Functionality and Goals:
- The system allows for automatic and precise control over light intensity and timing, using different wavelengths of light to observe how cells react to varying conditions. The primary goal is to determine which cells can survive under specific light wavelengths (yellow, green, blue), intensities, and exposure times. By monitoring cell survival under these conditions, the system can help uncover valuable insights into how light affects cellular biology.

Modularity and Flexibility:
- Modular LED System:
The LED system is designed to be easily modifiable, allowing users to switch out light sources or adjust the system for different experiments.
Battery Management: The rechargeable battery system ensures the device is self-sufficient and can be used continuously without the need for frequent battery replacements.

Additional Features:
- Real-Time Adjustments:
Light intensity and timing can be adjusted on the fly, offering flexibility during experiments.
- Client-Specific:
This project was developed for a specific client, tailored to their requirements for a modular, efficient, and flexible testing system.

Circuit Diagram:
- A detailed circuit diagram outlining the connections between the batteries, Arduino, LED lights, rotary encoder, and display will be included. [Insert Circuit Diagram]

Project Video:
- A video demonstration of the system in action is available, showcasing the different light intensities, colors, and real-time data monitoring. [Insert Video Link]

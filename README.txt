
Automated Plant Monitoring and Management System

This project is an Arduino-based system designed to monitor and manage environmental conditions for different types of plants. By using temperature, humidity, and soil moisture sensors, the system checks whether the environment is within the optimal range for the selected plant and provides real-time feedback on an OLED display. Users can switch between different plant profiles using a three-way switch.

Features

- Real-time Monitoring: Continuously measures soil moisture, temperature, and humidity.
- Plant Profiles: Includes predefined profiles for different plants, with customizable thresholds.
- OLED Display: Visualizes sensor data and indicates whether conditions are optimal, too high, or too low.
- Easy Navigation: A three-way switch allows users to switch between plant profiles quickly.
- User Feedback: Provides intuitive feedback on environmental conditions, helping users maintain the best conditions for their plants.

Components Used

- Arduino Uno - The brain of the system.
- DHT11 Sensor - Measures temperature and humidity.
- Soil Moisture Sensor - Monitors soil moisture levels.
- OLED Display (SH1106 controller) - Displays sensor readings and plant status.
- Three-Way Switch - Allows navigation between plant profiles.

Code Overview

The Arduino code integrates multiple sensors and the OLED display, with a simple logic flow to compare sensor readings against predefined thresholds for each plant profile. The code is structured as follows:

- Setup: Initializes the sensors, display, and switch.
- Loop: Continuously reads sensor data, checks the switch for user input, updates the plant profile if necessary, and refreshes the display with the current data.
- Functions: Includes helper functions to read sensor data, map moisture levels, and update the display.

How to Use

1. Clone the Repository:
   git clone https://github.com/yourusername/Automated-Plant-Monitoring-System.git
   cd Automated-Plant-Monitoring-System

2. Upload the Code:
   - Open the PlantMonitoringSystem.ino file in the Arduino IDE.
   - Select your board and port.
   - Upload the code to your Arduino.

3. Connect the Components:
   - Assemble the hardware as per the wiring diagram provided.
   - Ensure the sensors and display are correctly connected to the Arduino.

4. Monitor Your Plants:
   - Use the three-way switch to select the plant profile.
   - Check the OLED display to see if your plant's environment is within the optimal range.
   - Adjust your plant's environment based on the feedback provided.

Project Structure

Automated-Plant-Monitoring-System/
├── README.txt
├── PlantMonitoringSystem.ino
└── Images/
    └── wiring_diagram.png

Future Enhancements

- Multiple Plant Support: Expand the system to support more plant profiles.
- Data Logging: Implement data logging to track environmental conditions over time.
- Mobile Integration: Develop a mobile app to remotely monitor and control the system.



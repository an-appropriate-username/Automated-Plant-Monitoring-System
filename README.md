# Automated Plant Monitoring and Management System

An **Arduino-based system** to monitor and manage environmental conditions for plants.  
It measures **soil moisture, temperature, and humidity**, then compares readings against **plant-specific profiles**.  
A three-way switch lets you toggle between different plant profiles, while an **OLED display** provides real-time feedback.

---

## Features

| Feature              | Description                                                                 |
|----------------------|-----------------------------------------------------------------------------|
| Real-time Monitoring | Continuously measures **soil moisture**, **temperature**, and **humidity**. |
| Plant Profiles       | Predefined profiles with customizable thresholds for different plants.      |
| OLED Display         | Shows live sensor readings and plant condition status.                      |
| Easy Navigation      | Switch between profiles with a **three-way switch**.                        |
| User Feedback        | Intuitive feedback (optimal / too high / too low).                          |

---

## Components Used

| Component                  | Purpose                                   |
|-----------------------------|-------------------------------------------|
| Arduino Uno                | Core microcontroller (main logic).        |
| DHT11 Sensor               | Measures **temperature & humidity**.      |
| Soil Moisture Sensor        | Monitors soil water content.              |
| OLED Display (SH1106)       | Visualizes readings and status.           |
| Three-Way Switch           | Navigates between plant profiles.          |

---

## Code Structure

**Setup**
  - Initialize sensors, display, and switch.

**Loop**
  - Read sensor values.
  - Check switch position for profile changes.
  - Compare readings to thresholds.
  - Update OLED with current status.

**Functions**
  - readSensors() -> Collects sensor data.
  - mapMoisture() -> Maps raw values to % scale.
  - updateDisplay() -> Refreshes OLED output.

---

## How to Use

1. **Clone the Repository**
   ```bash
   git clone https://github.com/an-appropriate-username/Automated-Plant-Monitoring-System.git
   cd Automated-Plant-Monitoring-System
   ```

2. **Upload the Code**
   - Open `PlantMonitoringSystem.ino` in the **Arduino IDE**.
   - Select your **board** and **port**.
   - Upload to your Arduino.

3. **Connect the Components**
   - Follow the wiring diagram in \`/Images/wiring_diagram.png\`.
   - Double-check sensor/display connections.

4. **Monitor Your Plants**
   - Use the **switch** to pick a plant profile.  
   - Read the **OLED display** -> "Optimal / Too high / Too low".  
   - Adjust watering, humidity, or placement accordingly.

---

## Project Structure

```text
Automated-Plant-Monitoring-System/
├── README.md
├── PlantMonitoringSystem.ino
└── Images/
    └── wiring_diagram.png
```

---

## Future Enhancements

- **Data Logging** -> Save conditions over time for analysis.  
- **Expanded Profiles** -> Add support for more plant types.  
- **Mobile Integration** -> Remote monitoring/control via app.  

---

> **Note:** The provided diagram is for visualization only, wiring may vary depending on the specific modules you use.

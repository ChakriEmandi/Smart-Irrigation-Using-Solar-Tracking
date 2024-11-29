# Smart Farming Using Solar Tracking

This project aims to address the lack of electricity in rural areas by developing an automated irrigation system powered by solar energy. The system utilizes photovoltaic panels with solar tracking capabilities to optimize energy capture and power an automated irrigation system. This solution is efficient, eco-friendly, and reduces water wastage.


## **Abstract**

The project leverages solar energy to operate an irrigation system in regions with no direct access to utility grids. The system includes:
- Solar tracking for optimal photovoltaic efficiency.
- Automatic irrigation controlled by moisture sensors and an Arduino-based microcontroller.
- Automation of water pump operation based on soil moisture conditions.

An experimental evaluation of the system demonstrated its effectiveness in conserving water and energy, making it particularly suitable for drought-prone areas.


## **Key Features**

1. **Solar Tracking System**:
   - Utilizes LDR sensors to track the sun's position.
   - Servo motors adjust the angle of the solar panels for maximum sunlight capture.
   - Increases energy efficiency by up to 52.8%.

2. **Automatic Irrigation**:
   - Soil moisture sensors monitor the soil's condition.
   - The system automatically operates the water pump to maintain optimal soil moisture levels.
   - Supports drip irrigation for water conservation.

3. **Eco-Friendly Energy Source**:
   - Entire system powered by renewable solar energy.
   - Reduces dependency on non-renewable fossil fuels.


## **Problem Statement**

Conventional irrigation systems rely on electricity from fossil fuels, which is both non-renewable and inaccessible in many rural areas. The project addresses these challenges by:
- Utilizing solar energy for irrigation.
- Automating the irrigation process to minimize human intervention and water wastage.


## **Components Used**

1. **Arduino Microcontroller**: Handles system control and automation.
2. **Servo Motor**: Adjusts solar panels for sun tracking.
3. **LDR Sensors**: Detect light intensity for solar tracking.
4. **Solar Panel**: Converts sunlight into electricity to power the system.
5. **Soil Moisture Sensor**: Measures soil moisture levels to control the water pump.
6. **Relay Module**: Controls the pump's operation based on microcontroller signals.
7. **Water Pump**: Delivers water to the crops.


## **System Workflow**

### **Solar Tracking**:
1. LDR sensors detect the sun's position.
2. A servo motor adjusts the solar panels to maximize sunlight capture.
3. Voltage differences between LDR sensors are used to align the panels with the sun.

### **Smart Irrigation**:
1. Soil moisture sensors monitor the soil's condition.
2. If moisture falls below a threshold, the Arduino activates the water pump.
3. The pump shuts off automatically when the moisture level is restored.


## **Code Overview**

The system's functionality is implemented using Arduino code, which:
- Processes inputs from sensors.
- Controls the servo motor for solar tracking.
- Manages the water pump operation for irrigation.

```cpp
#include <Servo.h>

Servo myservo;
int moistureSensor = A0;
int waterPump = A1;

void setup() {
    myservo.attach(2);
    pinMode(moistureSensor, INPUT);
    pinMode(waterPump, OUTPUT);
}

void loop() {
    int moistureValue = analogRead(moistureSensor);
    if (moistureValue < 600) {
        digitalWrite(waterPump, HIGH);
    } else {
        digitalWrite(waterPump, LOW);
    }
}

## Results
### Solar Tracking Efficiency:
Dynamic solar panels produced an average of 3.004V, compared to 1.416V for static panels.
Overall efficiency improvement: 52.8%.
Water Conservation:
Automated irrigation reduced water wastage significantly.
Drip irrigation ensured efficient water distribution.

### Advantages
Reduced water wastage and energy consumption.
Cost-effective solution for rural and drought-prone areas.
Eco-friendly and sustainable, leveraging renewable energy.
Minimizes human intervention and labor.

### Future Enhancements
Integration with IoT for real-time monitoring.
Addition of pH sensors for soil quality analysis.
Improved solar tracking using dual-axis systems.
Cloud-based data storage and analytics for crop monitoring.

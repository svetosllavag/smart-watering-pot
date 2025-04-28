# Self-Watering Pot Prototype

## Project Overview
I’ve always had a passion for plants, gardening, and cooking. Combining these hobbies with my studies as a mechatronics student led me to create a **self-watering pot** prototype.  
The goal is to automate watering for fresh herbs — and maybe even yellow pear tomatoes (which I’m growing from seeds!).

This project focuses on developing a simple, functional prototype using basic electronics (including Arduino, sensors to detect soil moisture and water levels, and an automated water pump system.

Future goals include making the system **eco-friendly** and adding **artificial sunlight** features.

---

## Components Used
- **Arduino Uno** – Main controller.
- **I2C LCD Display** – Displays moisture and water levels.
- **HC-SR04 Ultrasonic Sensor** – Measures water level in the tank.
- **Soil Moisture Sensor** – Detects soil humidity.
- **Relay Module** – Controls the water pump.
- **Water Pump** – Waters the plant when soil is dry.
- **Breadboard & Jumper Wires** – Circuit connections.
- **Capacitors & Diode** – Stabilize power and protect the circuit.

---

## Disclaimer
Paper tape was temporarily used to keep jumper wires and components stable during prototyping.  
There are **no exposed cables** — the tape is not insulation, only for **preventing disconnections**.  
Future iterations will implement more permanent securing methods.

---

## Development Process

### Step 1: Gathering Parts
Spent a week researching compatible components, ordered online, and built a simple home lab setup.

### Step 2: Wiring and Testing
Connected all components: ultrasonic sensor, soil moisture sensor, LCD, relay, pump. Discovered I needed a breadboard and faced challenges connecting the water pump securely.

### Step 3: Arduino Code
Started with an online Arduino code example.  
Uploaded and adapted the code (still learning C++), debugging pin connections and understanding Arduino power requirements.

### Step 4: Fixing Power Issues
Faced power instability when the pump ran. Solved it by:
- Sharing a **common ground** across components.
- Adding **capacitors** to stabilize power.

### Step 5: Tinkercad Simulation
Recreated the wiring in **Tinkercad** for electrical verification and visualization.

## Status
- Prototype built and tested successfully
- Code adjustments done during testing phase

## Acknowledgment
- Base code from Open Source resources, adjusted during learning phase

## Future Plans
- Design a custom enclosure in Fusion 360
- Improve code and build a PCB

---

## Notes for Improvements
- **Eco-friendly Power**: Explore solar panels or rechargeable battery systems.
- **Improved Power Management**: Implement low-power Arduino modes.
- **Code Optimization**: As C++ skills improve, rewrite and optimize the current codebase.

---


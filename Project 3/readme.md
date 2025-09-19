# Traffic Signal System (Low-Level Design Implementation)

This project is a **C++ implementation of a Traffic Signal System**, inspired by real-world traffic lights.  
It demonstrates **object-oriented design**, **time-based simulation**, and **basic system functionalities** such as signal sequencing, timing updates, and cycle control.

---

## Overview

The system models a traffic signal controller with the following entities:

- **Signal**: Represents an individual traffic light (Red, Yellow, Green) with its color, ID, and time interval.
- **TrafficSignalSystem**: Manages the signals, updates their timing, and simulates signaling cycles.

Key features implemented:

- Each signal (Red, Yellow, Green) has a **default time interval**.
- Ability to **update signal intervals** using either the signal’s ID or color.
- Simulation of **traffic light cycles** using time delays (`std::this_thread::sleep_for`).
- Run the system for a fixed number of cycles.

---

## Key Learnings

- Applying **OOP principles** in system design.
- Using **encapsulation** to manage signal properties.
- Implementing **class relationships** (TrafficSignalSystem owns Signal objects).
- Using **time intervals and delays** with `chrono` and `thread`.
- Building a simple **real-world simulation** using C++.

---

## Example Flow

1. Default signals are created:  
   - Red → 60s  
   - Yellow → 5s  
   - Green → 50s  

2. Update Yellow to 10s (by color).  
3. Update Green to 40s (by ID).  
4. Start the system → runs **2 full cycles**:  

---

## Future Enhancements

- **Dynamic Configuration**  
Allow users to change signal timings at runtime through input commands.

- **Multiple Intersections**  
Simulate more than one traffic signal system running simultaneously.

- **Synchronization**  
Implement coordination between signals at intersections for real-world accuracy.

- **Pedestrian Signals**  
Extend the system to handle pedestrian crossing lights.

- **Emergency Override**  
Add functionality to switch signals for emergency vehicles.

- **Persistence Layer**  
Store configurations in files (JSON/CSV) so timing persists across runs.

- **Visualization**  
Build a CLI or graphical interface to visualize signals changing in real time.

---

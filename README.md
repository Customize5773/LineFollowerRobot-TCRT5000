# LineFollowerRobot
This repository contains code and diagram for Line Follower Robot using Arduino

---
> Improvement 🪛
# AnalogLineMaster 🚗✨  
**Advanced Analog IR Line Following Robot using Arduino**

AnalogLineMaster is a precision line-following robot built on Arduino using **analog IR sensors**. Unlike digital line followers, this version uses analog readings to make **fine-grained decisions** for smoother, more accurate motion. The robot also includes a **dynamic calibration feature**, ensuring consistent performance across various surfaces.

---

## 🔧 Hardware Requirements

| Component                | Quantity |
|--------------------------|----------|
| Arduino Uno/Nano         | 1        |
| Analog IR Sensors (TCRT5000 recommended) | 2        |
| TT Gear Motors           | 2        |
| L298N or Dual H-Bridge Driver | 1        |
| Motor Driver PWM Pins (D5, D6) | Used    |
| Chassis, Wheels, Power Source | 1 Set    |

---

## ⚙️ Pin Configuration

| Arduino Pin | Function             |
|-------------|----------------------|
| A0          | Right IR Sensor (Analog) |
| A1          | Left IR Sensor (Analog)  |
| 5 (PWM)     | Left Motor Enable    |
| 6 (PWM)     | Right Motor Enable   |
| 7, 8        | Right Motor Direction |
| 9, 10       | Left Motor Direction  |

---

## 📦 Features

- ✅ Analog IR sensor readings for fine-tuned detection  
- ✅ Dynamic threshold calibration at startup  
- ✅ Modular motor control functions  
- ✅ Enhanced PWM frequency for better motor control  
- ✅ Debug output over Serial Monitor  

---

## 🚀 How It Works

1. **Startup Calibration**
   - Robot asks the user to place sensors on **white** surface and then on **black** line.
   - Calculates threshold value between black and white for each sensor.

2. **Main Loop Behavior**
   - Reads analog values from left and right IR sensors.
   - Compares them against calibrated thresholds.
   - Determines movement:
     - Both sensors on white → Move Forward
     - One sensor on black → Turn in opposite direction
     - Both sensors on black → Stop

3. **Motor Control**
   - Speed and direction are controlled using `analogWrite()` and `digitalWrite()` via H-bridge motor driver.
   - PWM frequency on D5 and D6 is increased (~7.8 kHz) to improve low-speed responsiveness.

---

## 🧪 How to Use

1. **Upload the code to your Arduino.**
2. **Open the Serial Monitor** at 9600 baud.
3. **Follow calibration instructions:**
   - Place robot over white surface → wait for prompt.
   - Place robot over black line → wait for prompt.
4. **Watch it go!**

---

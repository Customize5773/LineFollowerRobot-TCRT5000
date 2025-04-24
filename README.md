# LineFollowerRobot
This repository contains code and diagram for Line Follower Robot using Arduino

---
> Improvement 🪛
# AnalogLineMaster 🚗✨  
**Advanced Analog IR Line Following Robot using Arduino**

![F3RNI9HJBQU4BU8](https://github.com/user-attachments/assets/5f37ef24-c1bd-460a-b61c-357f0c839afa)
> _Copyright © : [mybotic](https://www.instructables.com/How-to-Use-TCRT5000-IR-Sensor-Module-With-Arduino-/)_


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

## ⚠️ TCRT5000 Sensor Weaknesses & User Suggestions

While the TCRT5000 is a popular and affordable choice for line-following robots, it has some limitations you should be aware of. This section provides transparency and practical advice for users seeking optimal performance.

### 🚫 Weaknesses of the TCRT5000 Sensor

| Weakness                          | Description |
|----------------------------------|-------------|
| **Ambient Light Sensitivity**    | Strong sunlight or uneven lighting can skew readings significantly. |
| **Short Range Detection**        | Performs best within 2–10mm of surface. Readings become unreliable beyond that. |
| **Angle Sensitivity**            | Small changes in mounting angle can drastically affect reflectivity values. |
| **Nonlinear Output**             | Output doesn't change linearly with distance or surface brightness. |
| **Noisy Analog Signal**          | Reflections may fluctuate due to jitter or surface inconsistencies. |

---

### ✅ Suggestions to Improve Your Sensor Accuracy

| Improvement                         | Description |
|-------------------------------------|-------------|
| **Use Analog Filtering**            | Apply a simple moving average or exponential filter to smooth noisy readings. |
| **Shield from Ambient Light**       | Use black tubes or hoods to block stray IR from the environment. |
| **Adjustable Mounts**               | Use servo brackets or 3D-printed holders to fine-tune sensor angle. |
| **Surface Calibration**             | Always calibrate on the exact surface where the robot will operate. |
| **Add More Sensors**                | Add center or rear sensors to detect intersections and improve tracking. |
| **Switch to Better IR Sensors**     | For high-end use, consider sensors like QRE1113GR or Pixy2 camera for color-based line following. |

---

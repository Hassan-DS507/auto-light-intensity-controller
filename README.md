# Auto Light Intensity Controller by External Light Sense

## 📘 Course
Microcontrollers and Their Applications  
Department of Electronics and Communication Engineering

## 👨‍🏫 Instructor
Dr. Sherine Hassan

## 👨‍💻 Team Members
- Hassan Abdelrazek El-Sayed Abdelrazek (Team Leader)  
- Mohamed Mahmoud Mosad Mohamed El-Saragy  
- Ahmed Nasr Abdelmonem Ghanem  
- Ziad Omar Talaat Ali Shendy  
- Kamal Fadel Fadel El-Saadany  
- Abdelrahman Mohamed Amara El-Degla  
- Rehab Abdelmegid Mousa  
- Maha Gamal Nasr Eldin Nada  
- Donia Shaaban Mohamed Mohamed  
- Nourhan Ramadan Ahmed Ahmed

---

## 🧠 Project Description

This project aims to control the intensity of artificial lighting based on ambient light levels using a Light Dependent Resistor (LDR) sensor. The system utilizes a PIC16F877A microcontroller with built-in ADC to detect analog voltage changes from the sensor and control an LED/lamp accordingly.

---

## 🛠️ Tools & Components Used

- **Microcontroller:** PIC16F877A  
- **Sensor:** LDR (Light Dependent Resistor)  
- **Simulation Software:** Proteus 8  
- **Programming Language:** C (MikroC PRO for PIC)  
- **Other components:** Resistors, Transistor, LED, Power supply

---

## 🔧 How It Works

1. The LDR forms a voltage divider circuit and produces a varying analog voltage depending on light levels.
2. The analog signal is fed to the microcontroller's ADC input pin.
3. The microcontroller reads the voltage, converts it to a digital value, and decides whether to turn on/off or adjust the intensity of the LED.
4. The output is connected to a transistor driving the LED/lamp.

---


## 🧪 Simulation

The Proteus simulation is included in the `/Proteus` folder. It contains:
- Full wiring of the circuit
- Working ADC setup with PIC16F877A
- Real-time light level testing

---

## 🧾 Report

Check the `/Report/final_report.pdf` for:
- Full explanation
- Circuit diagrams
- Code explanation
- Team roles

---

## 📂 How to Run

1. Open `auto_light.pdsprj` in Proteus 8.
2. Load the compiled `.hex` file from MikroC into the microcontroller.
3. Simulate and adjust LDR resistance to observe LED behavior.

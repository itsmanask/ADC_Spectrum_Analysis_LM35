# Analog to Digital Conversion and Spectrum Analysis of LM35 Sensor Signal

## 📌 Project Overview

This project demonstrates how to digitize analog temperature signals from an **LM35 temperature sensor** using **Arduino's built-in ADC**, and how to analyze the signal in both **time** and **frequency domains** using **Python (FFT with SciPy and Matplotlib)**.

The aim is to bridge theoretical signal processing concepts—**sampling**, **quantization**, and **aliasing**—with practical implementation.

---

## Block Diagram

LM35 ──> Arduino UNO ──> Serial Monitor ──> CSV Logger ──> Python (FFT Analysis)


---

## 🎯 Key Features

- 📈 **Analog to Digital Conversion** using Arduino’s 10-bit ADC
- 🧮 **Sampling** at 10 Hz for accurate temperature tracking
- 📉 **Quantization Effects** demonstrated with 8-bit downscaling
- 🧠 **FFT Analysis** of temperature signal to view frequency components
- 📊 **Real-time Visualization** using Python (Matplotlib)

---

## 🛠️ Hardware Components

- LM35 Temperature Sensor
- Arduino UNO

---

## 🧪 Software Requirements

- Arduino IDE
- Python
  - `numpy`
  - `scipy`
  - `matplotlib`
  - `pandas`

---

## 🔍 Methodology

1. **Signal Acquisition:**  
   LM35 generates analog voltage (10mV/°C).

2. **ADC Conversion:**  
   Arduino samples voltage at 10 Hz using its 10-bit ADC.

3. **Data Logging:**  
   Values (10-bit and downscaled 8-bit) are stored in CSV.

4. **Time & Frequency Analysis:**  
   Python scripts apply FFT and plot results.

---

## 📊 Results Summary

- **Time Domain:**  
  Smooth analog signal, step-wise 8-bit digital version.  
  Highlights quantization noise.

- **Frequency Domain:**  
  Dominant low-frequency content (<1 Hz).  
  No aliasing at 10 Hz sampling.  
  Quantization introduces high-frequency components.

---

## 🎓 Learning Outcomes

- Understanding ADC, quantization, and sampling
- Real-world signal acquisition using LM35
- Practical FFT implementation in Python
- Insight into signal stability and noise effects

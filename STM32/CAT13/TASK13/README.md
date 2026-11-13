# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 13

**TASK:** TASK13

**STUDENT REGISTER NO:** 25011102088

**COURSE:** Foundations of IoT (FIoT)

**NAME OF EXP:** CAT 13 Task 13: End-to-End Capstone IoT Weather Station & MQTT Cloud Telemetry

**HARDWARE SETUP / PLATFORM:** STM32 Nucleo-64 (ARM Cortex-M4) + BME280 + ESP8266 + Node-RED Dashboard

---

## 1. Objective
To build an end-to-end IoT Edge Telemetry System by integrating a Bosch BME280 environmental sensor over I2C with an ESP8266 Wi-Fi transceiver over USART on an STM32 ARM Cortex-M4 microcontroller. The firmware periodically samples calibrated ambient temperature, barometric pressure, and relative humidity, formats the readings into a structured JSON payload, and publishes telemetry packets to an MQTT cloud broker (`broker.emqx.io`) under the topic `college/weather/bme280` for live cloud monitoring and Node-RED dashboard visualization.

---

## 2. Hardware Connections & Pin Mapping

| Microcontroller Pin | Peripheral Line | Target Module | Description |
|:---:|:---:|:---:|:---|
| **PB6** | I2C1_SCL | Bosch BME280 | I2C Serial Clock (Standard/Fast Mode with 4.7 kΩ pull-up) |
| **PB7** | I2C1_SDA | Bosch BME280 | I2C Serial Data Line (Address `0x76` / `0x77`) |
| **PA9** | USART1_TX | ESP8266 RXD | AT Command Transmission (115200 Baud) |
| **PA10** | USART1_RX | ESP8266 TXD | AT Response Reception (Interrupt/Buffered) |
| **PA2** | USART2_TX | Host PC USB | Debug Telemetry Console (115200 Baud, 8-N-1) |
| **PA3** | USART2_RX | Host PC USB | Debug Serial Console Input |
| **3V3 & GND** | Power Rail | BME280 / ESP | 3.3V DC Regulated Power Supply & Common Ground |

---

## 3. Project Images & Visualizations

### 📊 Image 1: Node-RED Live Weather Dashboard & AI Environmental Gauges (`proj1`)
![Project Dashboard (proj1)](proj1.jpeg)

*Figure 1: Node-RED Real-time Telemetry Dashboard displaying live Temperature (°C), Relative Humidity (%), and Barometric Pressure (hPa) gauges alongside dynamic environmental status classification.*

---

### 🔀 Image 2: Node-RED Cloud Integration & MQTT Flow Architecture (`proj2`)
![Node-RED MQTT Architecture (proj2)](proj2.jpeg)

*Figure 2: Complete Node-RED data processing pipeline showing MQTT broker subscription node (`broker.emqx.io:1883`), JSON parsing routines, conditional threshold triggers, and UI dashboard widgets.*

---

### 🖥️ Image 3: Hardware Serial Debug Console & MQTT Packet Telemetry (`proj3`)
![Serial Debug Log (proj3)](proj3.jpeg)

*Figure 3: Live hardware serial console output (USART2 @ 115200 baud) verifying BME280 sensor handshake, ESP8266 Wi-Fi association, TCP socket connection to MQTT broker, and periodic JSON telemetry transmission.*

---

### 📐 Circuit Schematic & Hardware Wiring Diagram
![Circuit Diagram](circuit.png)

*Figure 4: Interfacing schematic showing STM32F401RET6 connections to Bosch BME280 (I2C1 bus) and ESP8266 Wi-Fi module (USART1).*

---

## 4. Theory & Technical Overview

The architecture implements a three-tier embedded IoT edge solution:

1. **Sensor Acquisition Layer (`bme280.c` / `bme280.h`):**
   - Microcontroller queries the BME280 device ID register (`0xD0`) via I2C1 to verify presence at address `0x76`.
   - Reads factory calibration trimming coefficients stored in non-volatile sensor memory.
   - Converts raw 20-bit analog pressure and temperature ADC readouts using high-precision 32/64-bit integer compensation mathematics.

2. **Network & Communications Layer (`ESPLib.c` / `ESPLib.h`):**
   - Configures the ESP8266 into Station Mode (`AT+CWMODE=1`).
   - Associates with the local Wi-Fi Access Point (`AT+CWJAP`).
   - Establishes a persistent TCP socket with the cloud broker on port 1883 (`AT+CIPSTART="TCP","broker.emqx.io",1883`).

3. **MQTT Application Protocol Layer:**
   - Serializes connection control packets with client identifier `STM32_BME280_Device01`.
   - Constructs JSON payloads:
     ```json
     {"temperature": 26.50, "pressure": 1013.25, "humidity": 62.10}
     ```
   - Publishes telemetry packets with Quality of Service QoS0 to the topic `college/weather/bme280` at 5-second intervals.

4. **Cloud Analytics & Visualization (Node-RED):**
   - Subscribes to `college/weather/bme280` and visualizes live readings via gauge charts and historical trend curves.
   - Evaluates dynamic environmental thermal boundaries (>26°C Increasingly Hot, <24°C Cold).

---

## 5. Build, Flash & Verification Steps

1. **Open Keil µVision Project:**
   - Launch Keil µVision and open `MDK-ARM/IOT_project.uvprojx` (or `MDK-ARM/TASK13.uvprojx`).
2. **Compile Target Firmware:**
   - Click **Project -> Rebuild all target files** (`F7`).
   - The compiled binary target is generated at `MDK-ARM/IOT_project/IOT_project.hex`.
3. **Flash Microcontroller:**
   - Connect the STM32 Nucleo board via USB ST-LINK.
   - Click **Flash -> Download** (`F8`) to program the internal flash.
4. **Serial Terminal Verification:**
   - Open a serial monitor (PuTTY / Tera Term / Arduino Serial Monitor) on the ST-Link COM port at **115200 baud, 8-N-1**.
   - Observe initialization logs, BME280 detection, Wi-Fi connectivity confirmation, and periodic telemetry publish events.
5. **Dashboard Inspection:**
   - Open the Node-RED web dashboard (`http://localhost:1880/dashboard`) to view live gauges and telemetry curves.

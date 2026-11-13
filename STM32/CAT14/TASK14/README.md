# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 14

**TASK:** TASK14

**STUDENT REGISTER NO:** 25011102088

**COURSE:** Foundations of IoT (FIoT)

**NAME OF EXP:** CAT 14 Task 14: Multi-Sensor Telemetry & Edge Gateway Integration

**HARDWARE SETUP / PLATFORM:** STM32F401 Nucleo-64 + Bosch BME280 + ESP8266 Wi-Fi

---

## 1. Objective
To design and deploy a multi-peripheral embedded edge gateway on STM32 ARM Cortex-M4 interfacing I2C environmental sensors with serial communication transceivers. The edge node acquires sensor data, applies numerical calibration and filtering, and formats the output into serial telemetry streams for remote monitoring.

---

## 2. Hardware Connections & Pin Mapping

| Microcontroller Pin | Peripheral Line | Target Module | Description |
|:---:|:---:|:---:|:---|
| **PB6** | I2C1_SCL | BME280 | I2C Serial Clock (400 kHz Fast Mode) |
| **PB7** | I2C1_SDA | BME280 | I2C Serial Data Line |
| **PA9** | USART1_TX | ESP8266 RXD | Wireless Telemetry Transmission |
| **PA10** | USART1_RX | ESP8266 TXD | Wireless Telemetry Reception |
| **PA2** | USART2_TX | Host Console | Serial Debug Output (115200 Baud) |
| **3V3 & GND** | Power Rails | System Bus | Regulated 3.3V DC Power Supply |

---

## 3. Circuit Schematic Diagram
![Circuit Diagram](circuit.png)

*Figure 1: Hardware Interfacing Schematic for STM32F401RE Multi-Sensor Edge Gateway.*

---

## 4. Theory & Technical Overview
1. **I2C Bus Transaction Sequence**: The STM32 master initiates repeated start conditions to access sensor register maps, verifying calibration coefficients and executing burst reads.
2. **Data Filtering & Formatting**: Sensor readings are processed using polynomial temperature compensation formulas to convert raw ADC register values into calibrated physical units.
3. **Telemetry Streaming**: Processed records are framed into structured ASCII/JSON lines and forwarded via USART peripherals.

---

## 5. Build, Flash & Verification Steps
1. Open `MDK-ARM/TASK14.uvprojx` in Keil µVision.
2. Build the project (`F7`).
3. Connect the hardware debugger (ST-LINK) and flash the MCU (`F8`).
4. Inspect serial terminal at 115200 baud to verify continuous multi-sensor telemetry acquisition.

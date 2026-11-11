# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 13

**TASK:** TASK13

**STUDENT REGISTER NO:** 25011102088

**COURSE:** Foundations of IoT (FIoT)

**NAME OF EXP:** CAT 13 Task 13: End-to-End Capstone IoT Weather Telemetry Station

**HARDWARE SETUP / PLATFORM:** Embedded Development Kit + Keil / STM32CubeIDE

---

## 1. Objective
To integrate Bosch BME280 sensor acquisition over I2C with ESP8266 Wi-Fi connectivity and stream formatted JSON telemetry to MQTT cloud brokers.

---

## 2. Hardware Connections & Pin Mapping

| Microcontroller Pin | Peripheral Line | Description |
|:---:|:---:|:---|
| **PB6 / PB7** | I2C1 | BME280 Sensor (SCL/SDA) |
| **PA9 / PA10** | USART1 | ESP8266 Wi-Fi Module (TX/RX) |
| **PA2 / PA3** | USART2 | Debug Serial Console (115200 Baud) |

---

## 3. Circuit Schematic Diagram
![Circuit Diagram](circuit.png)

---

## 4. Theory & Technical Overview
The system coordinates three subsystem layers on STM32 ARM Cortex-M4:
1. **Sensor Acquisition Layer**: Reads calibrated ambient temperature, barometric pressure, and relative humidity from the Bosch BME280 over the I2C1 bus.
2. **Connectivity Layer**: Drives the ESP8266 Wi-Fi SoC using AT commands over USART1, establishing station connectivity with the local wireless network.
3. **Application & Cloud Layer**: Encapsulates telemetry into lightweight MQTT fixed-header packets via `ESPLib` and publishes messages to the MQTT broker (`broker.emqx.io`).

---

## 5. Build, Flash & Verification Steps
1. Open the Keil project file (`MDK-ARM/IOT_project.uvprojx` or `MDK-ARM/TASK13.uvprojx`).
2. Build the target firmware (Press `F7`).
3. Connect the ST-Link V2 debugger via SWD interface.
4. Download the compiled binary (`F8`).
5. Open serial terminal at 115200 baud to monitor Wi-Fi connection, MQTT handshake, and periodic telemetry publishes.

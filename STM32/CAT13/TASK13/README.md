# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 13

**TASK:** TASK13

**STUDENT REGISTER NO:** 25011102088

**COURSE:** Foundations of IoT (FIoT)

**NAME OF EXP:** CAT 13 Task 13: MQTT Protocol Telemetry Publisher via ESP8266 Wi-Fi

**HARDWARE SETUP / PLATFORM:** STM32F401 Nucleo-64 + ESP8266 Wi-Fi Module + EMQX MQTT Broker

---

## 1. Objective
To implement MQTT (Message Queuing Telemetry Transport) client connectivity on the STM32 ARM Cortex-M4 microcontroller using an ESP8266 Wi-Fi module over USART. The firmware configures wireless access, establishes a persistent TCP connection to an MQTT broker (`broker.emqx.io:1883`), and publishes periodic telemetry packets with Quality of Service QoS0.

---

## 2. Hardware Connections & Pin Mapping

| Microcontroller Pin | Peripheral Line | Target Module | Description |
|:---:|:---:|:---:|:---|
| **PA2** | USART2_TX | Host PC / Debug | Virtual COM Port Telemetry Output (115200 Baud) |
| **PA3** | USART2_RX | Host PC / Debug | Serial Console Input |
| **PA9** | USART1_TX | ESP8266 RXD | AT Command Output |
| **PA10** | USART1_RX | ESP8266 TXD | AT Response Input |
| **3V3 & GND** | Power Rails | ESP8266 | 3.3V DC Regulated Power & Common Ground |

---

## 3. Circuit Schematic Diagram
![Circuit Diagram](circuit.png)

*Figure 1: Hardware Interfacing Schematic for STM32F401RE and ESP8266 Wi-Fi Transceiver.*

---

## 4. Theory & Technical Overview
1. **Wi-Fi Station Association**: Firmware sends `AT+CWMODE=1` to enter station client mode, then issues `AT+CWJAP` with network credentials.
2. **TCP Socket Establishment**: Issues `AT+CIPSTART="TCP","broker.emqx.io",1883` to connect to the MQTT broker.
3. **MQTT Protocol Engine**: Constructs standard variable and fixed header packets (`MQTTconnect`, `MQTTpublish`), serializing UTF-8 encoded topic strings and payload byte arrays.

---

## 5. Build, Flash & Verification Steps
1. Open `MDK-ARM/LAB13.uvprojx` or `MDK-ARM/TASK13.uvprojx` in Keil µVision.
2. Rebuild all target files (`F7`).
3. Connect the STM32 Nucleo board via ST-LINK USB and download firmware (`F8`).
4. Monitor serial logs at 115200 baud to observe Wi-Fi association and MQTT publish events.

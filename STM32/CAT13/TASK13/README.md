# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 13

**TASK:** TASK13

**STUDENT REGISTER NO:** 25011102088

**COURSE:** Foundations of IoT (FIoT)

**NAME OF EXP:** CAT 13 Task 13: MQTT Protocol Handshake & Telemetry Publisher

**HARDWARE SETUP / PLATFORM:** Embedded Development Kit + Keil / STM32CubeIDE

---

## 1. Objective
To perform MQTT protocol handshake with public broker (broker.emqx.io:1883) via ESP8266 and publish periodic telemetry packets with QoS 0.

---

## 2. Hardware Connections & Pin Mapping

| Microcontroller Pin | Peripheral Line | Description |
|:---:|:---:|:---|
| **PA9 / PA10** | USART1 | ESP8266 Wi-Fi Module |
| **TCP 1883** | MQTT Broker | broker.emqx.io |

---

## 3. Circuit Schematic Diagram
![Circuit Diagram](circuit.png)

---

## 4. Theory & Technical Overview
The experiment utilizes embedded peripheral drivers, hardware abstraction libraries, and structured control flow to achieve real-time deterministic execution.

---

## 5. Build, Flash & Verification Steps
1. Open the Keil project file (`*.uvproj` or `MDK-ARM/*.uvprojx`).
2. Build the target firmware (Press `F7`).
3. Connect the hardware debugger (USBasp for 8051 or ST-Link V2 for STM32).
4. Download the compiled binary (`F8`).
5. Open serial terminal or inspect visual indicators to verify task execution.

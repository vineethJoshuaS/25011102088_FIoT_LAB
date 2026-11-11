# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 10

**TASK:** TASK10C

**STUDENT REGISTER NO:** 25011102088

**COURSE:** Foundations of IoT (FIoT)

**NAME OF EXP:** CAT 10 Task 10C: Embedded HTTP Web Server on STM32 + ESP8266

**HARDWARE SETUP / PLATFORM:** Embedded Development Kit + Keil / STM32CubeIDE

---

## 1. Objective
To bind ESP8266 in multi-connection server mode on TCP port 80, accept browser GET requests, and serve dynamic HTML IoT dashboards.

---

## 2. Hardware Connections & Pin Mapping

| Microcontroller Pin | Peripheral Line | Description |
|:---:|:---:|:---|
| **USART1** | ESP8266 AT Bus | 115200 bps 8N1 |
| **Ext 3.3V** | VCC / CH_PD | Power Supply |

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

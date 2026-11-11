# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 10

**TASK:** TASK10B

**STUDENT REGISTER NO:** 25011102088

**COURSE:** Foundations of IoT (FIoT)

**NAME OF EXP:** CAT 10 Task 10B: Explore ESP8266 AT Command State Machine

**HARDWARE SETUP / PLATFORM:** Embedded Development Kit + Keil / STM32CubeIDE

---

## 1. Objective
To execute AT diagnostic commands ('AT', 'AT+GMR', 'AT+CWMODE=1', 'AT+CIFSR') from STM32 and evaluate modem status responses.

---

## 2. Hardware Connections & Pin Mapping

| Microcontroller Pin | Peripheral Line | Description |
|:---:|:---:|:---|
| **USART1/2** | ESP8266 Comm Bus | Baud rate: 115200 bps |

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

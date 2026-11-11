# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 5 - SUBTASK B.3

**TASK:** TASK5B.3

**STUDENT REGISTER NO:** 25011102088

**COURSE:** Foundations of IoT (FIoT)

**NAME OF EXP:** CAT 5 Task 5B.3: Timer 0 Mode 2 (8-Bit Auto-Reload) Pulse Generator

**HARDWARE SETUP / PLATFORM:** Embedded Development Kit + Keil / STM32CubeIDE

---

## 1. Objective
To implement high-frequency pulse generation using Timer 0 in Mode 2 (8-bit auto-reload mode) on Port 2.2.

---

## 2. Hardware Connections & Pin Mapping

| Microcontroller Pin | Peripheral Line | Description |
|:---:|:---:|:---|
| **P2.2** | High Frequency Pulse Output | Digital Output |
| **Internal** | Timer 0 (TMOD=0x02) | 8-bit auto-reload |

---

## 3. Circuit Schematic Diagram
![Circuit Diagram](circuit.png)

---

## 4. Theory & Technical Overview
In Mode 2, register TH0 holds the reload byte while TL0 counts. Upon overflow, TL0 is automatically reloaded from TH0 without CPU software reload overhead.

---

## 5. Build, Flash & Verification Steps
1. Open the Keil project file (`*.uvproj` or `MDK-ARM/*.uvprojx`).
2. Build the target firmware (Press `F7`).
3. Connect the hardware debugger (USBasp for 8051 or ST-Link V2 for STM32).
4. Download the compiled binary (`F8`).
5. Open serial terminal or inspect visual indicators to verify task execution.

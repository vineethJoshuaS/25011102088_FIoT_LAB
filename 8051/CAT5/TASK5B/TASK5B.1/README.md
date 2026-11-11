# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 5 - SUBTASK B.1

**TASK:** TASK5B.1

**STUDENT REGISTER NO:** 25011102088

**COURSE:** Foundations of IoT (FIoT)

**NAME OF EXP:** CAT 5 Task 5B.1: Timer 0 Mode 1 (16-Bit Timer) Delay Routine

**HARDWARE SETUP / PLATFORM:** Embedded Development Kit + Keil / STM32CubeIDE

---

## 1. Objective
To implement a 20ms calibrated delay routine utilizing Timer 0 in Mode 1 (16-bit mode) to toggle LED indicators on Port 2.0.

---

## 2. Hardware Connections & Pin Mapping

| Microcontroller Pin | Peripheral Line | Description |
|:---:|:---:|:---|
| **P2.0** | LED Output | Digital Output |
| **Internal** | Timer 0 (TMOD=0x01) | 16-bit count mode |

---

## 3. Circuit Schematic Diagram
![Circuit Diagram](circuit.png)

---

## 4. Theory & Technical Overview
TMOD register lower nibble is set to 0x01. Initial counts TH0=0xB8, TL0=0x00 provide exactly 20ms timing at 11.0592 MHz. TF0 flag indicates overflow.

---

## 5. Build, Flash & Verification Steps
1. Open the Keil project file (`*.uvproj` or `MDK-ARM/*.uvprojx`).
2. Build the target firmware (Press `F7`).
3. Connect the hardware debugger (USBasp for 8051 or ST-Link V2 for STM32).
4. Download the compiled binary (`F8`).
5. Open serial terminal or inspect visual indicators to verify task execution.

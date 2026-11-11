# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 5 - SUBTASK B.2

**TASK:** TASK5B.2

**STUDENT REGISTER NO:** 25011102088

**COURSE:** Foundations of IoT (FIoT)

**NAME OF EXP:** CAT 5 Task 5B.2: Timer 1 Mode 1 (16-Bit Timer) Delay Routine

**HARDWARE SETUP / PLATFORM:** Embedded Development Kit + Keil / STM32CubeIDE

---

## 1. Objective
To configure Timer 1 in Mode 1 (16-bit mode) for 50ms interval generation and drive LED indicator on Port 2.1.

---

## 2. Hardware Connections & Pin Mapping

| Microcontroller Pin | Peripheral Line | Description |
|:---:|:---:|:---|
| **P2.1** | LED Output | Digital Output |
| **Internal** | Timer 1 (TMOD=0x10) | 16-bit count mode |

---

## 3. Circuit Schematic Diagram
![Circuit Diagram](circuit.png)

---

## 4. Theory & Technical Overview
TMOD upper nibble is configured for Timer 1 Mode 1 (0x10). Preload registers TH1=0x4B and TL1=0xFD generate a 50ms period without interfering with Timer 0.

---

## 5. Build, Flash & Verification Steps
1. Open the Keil project file (`*.uvproj` or `MDK-ARM/*.uvprojx`).
2. Build the target firmware (Press `F7`).
3. Connect the hardware debugger (USBasp for 8051 or ST-Link V2 for STM32).
4. Download the compiled binary (`F8`).
5. Open serial terminal or inspect visual indicators to verify task execution.

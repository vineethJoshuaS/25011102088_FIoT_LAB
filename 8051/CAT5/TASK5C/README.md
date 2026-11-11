# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 5

**TASK:** TASK5C

**STUDENT REGISTER NO:** 25011102088

**COURSE:** Foundations of IoT (FIoT)

**NAME OF EXP:** CAT 5 Task 5C: Timer Interrupt-Based Periodic Signal Generator

**HARDWARE SETUP / PLATFORM:** Embedded Development Kit + Keil / STM32CubeIDE

---

## 1. Objective
To configure 8051 Timer 0 Interrupt (Vector Address 0x000B) for non-blocking periodic signal generation on pin P1.0.

---

## 2. Hardware Connections & Pin Mapping

| Microcontroller Pin | Peripheral Line | Description |
|:---:|:---:|:---|
| **P1.0** | Interrupt Waveform Output | Digital Output |
| **IE Reg** | EA=1, ET0=1 | Global and Timer 0 Interrupt Enable |

---

## 3. Circuit Schematic Diagram
![Circuit Diagram](circuit.png)

---

## 4. Theory & Technical Overview
Instead of busy-waiting in polling loops, the CPU executes main code while the hardware timer fires an Interrupt Service Routine (ISR) upon overflow to toggle pin P1.0.

---

## 5. Build, Flash & Verification Steps
1. Open the Keil project file (`*.uvproj` or `MDK-ARM/*.uvprojx`).
2. Build the target firmware (Press `F7`).
3. Connect the hardware debugger (USBasp for 8051 or ST-Link V2 for STM32).
4. Download the compiled binary (`F8`).
5. Open serial terminal or inspect visual indicators to verify task execution.

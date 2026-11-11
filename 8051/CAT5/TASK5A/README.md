# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 5

**TASK:** TASK5A

**STUDENT REGISTER NO:** 25011102088

**COURSE:** Foundations of IoT (FIoT)

**NAME OF EXP:** CAT 5 Task 5A: Hardware Timer 0 Delay and Waveform Generation

**HARDWARE SETUP / PLATFORM:** Embedded Development Kit + Keil / STM32CubeIDE

---

## 1. Objective
To configure 8051 Hardware Timer 0 in Mode 1 (16-bit timer mode) to generate accurate 50ms timing intervals and produce a symmetric 10 Hz square wave on pin P2.0.

---

## 2. Hardware Connections & Pin Mapping

| Microcontroller Pin | Peripheral Line | Description |
|:---:|:---:|:---|
| **P2.0** | Square Wave Output Pin | Digital Output |
| **XTAL1/2** | 11.0592 MHz Crystal | Clock reference for 12-clock timer tick |

---

## 3. Circuit Schematic Diagram
![Circuit Diagram](circuit.png)

---

## 4. Theory & Technical Overview
Timer 0 counts from initial preload value (TH0=0x4B, TL0=0xFD) up to 0xFFFF. The timer overflow flag TF0 is monitored via polling to produce jitter-free hardware-timed delays.

---

## 5. Build, Flash & Verification Steps
1. Open the Keil project file (`*.uvproj` or `MDK-ARM/*.uvprojx`).
2. Build the target firmware (Press `F7`).
3. Connect the hardware debugger (USBasp for 8051 or ST-Link V2 for STM32).
4. Download the compiled binary (`F8`).
5. Open serial terminal or inspect visual indicators to verify task execution.

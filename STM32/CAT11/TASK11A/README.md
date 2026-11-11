# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 11

**TASK:** TASK11A

**STUDENT REGISTER NO:** 25011102088

**COURSE:** Foundations of IoT (FIoT)

**NAME OF EXP:** CAT 11 Task 11A: STM32F4 Nucleo GPIO & LED Manipulation

**HARDWARE SETUP / PLATFORM:** Embedded Development Kit + Keil / STM32CubeIDE

---

## 1. Objective
To configure STM32F401RE / STM32F410RB ARM Cortex-M4 GPIO peripheral on PA5 (Nucleo Green User LED) for high-speed output toggling.

---

## 2. Hardware Connections & Pin Mapping

| Microcontroller Pin | Peripheral Line | Description |
|:---:|:---:|:---|
| **PA5** | LD2 User LED | GPIO Output Push-Pull |

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

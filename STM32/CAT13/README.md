# CAT 13: Capstone IoT Weather Station & MQTT Cloud Telemetry

## Overview
Continuous Assessment 13 encompasses the end-to-end Capstone IoT Project combining:
- **Embedded Edge Sensing**: Bosch BME280 temperature, barometric pressure, and relative humidity sensor acquired via I2C1.
- **Compute Platform**: STM32 Nucleo-64 (ARM Cortex-M4 @ 84 MHz) with HAL peripheral drivers.
- **Wireless Connectivity**: ESP8266 Wi-Fi SoC operated in Station Mode via AT commands over USART1.
- **Cloud Telemetry**: Lightweight MQTT publish/subscribe messaging over TCP (`broker.emqx.io:1883`) to topic `college/weather/bme280`.
- **Live Cloud Dashboard**: Node-RED interactive visualization interface (`/dashboard`) featuring real-time gauges, trend charts, and environmental boundary classifications.

---

### Project Visualizations

| Dashboard View (`proj1`) | Node-RED Flow (`proj2`) | Debug Console (`proj3`) |
|:---:|:---:|:---:|
| [![Dashboard](proj1.jpeg)](TASK13/proj1.jpeg) | [![Flow](proj2.jpeg)](TASK13/proj2.jpeg) | [![Console](proj3.jpeg)](TASK13/proj3.jpeg) |

---

### Circuit Interfacing Schematic
![Circuit Diagram](circuit.png)

---

### Subtasks Index
- [TASK13](TASK13/): End-to-End Capstone IoT Weather Station & MQTT Cloud Telemetry (Complete firmware, Keil µVision project, `.ioc` configuration, and build targets)

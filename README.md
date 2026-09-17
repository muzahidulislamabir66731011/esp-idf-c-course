# ESP32 C Curriculum:

A free, open-source, beginner-friendly ESP32 learning curriculum built around **ESP-IDF**, **C**, and practical project-based learning.

This repository is designed to teach ESP32 development in a **smooth, linear, and gentle way**. Instead of jumping randomly between topics, each project introduces only **one or two new concepts**, helping learners move from bare-metal basics all the way to advanced wireless networking without feeling overwhelmed.

The curriculum includes:

- Heavily commented **C code**
- Step-by-step standalone ESP-IDF projects
- **LaTeX theory sources**
- Clean, readable compiled **PDF explanations**
- Wiring diagrams and hardware visuals
- Explanatory videos(later)
- Additional learning resources such as setup guides, cheat sheets, and build scripts

> The goal is simple: make ESP32 learning easier, clearer, and more structured.

---

## Repository Description

This project is a structured ESP32 learning path for people who want to understand what is really happening underneath the code.

You will start with simple concepts like GPIO, logging, and FreeRTOS task delays. Then you will move through interrupts, ADC, PWM, timers, I2C, SPI, UART, file systems, custom protocols, Wi-Fi, sockets, HTTP, low-power modes, BLE, and finally LoRa.

Each lesson is designed to be small enough to understand quickly, but complete enough to build real confidence.

---

## Why This Curriculum Exists

Many ESP32 tutorials jump straight into advanced libraries, cloud platforms, or complicated frameworks without explaining the fundamentals. This curriculum takes a different approach.

It is built to help learners understand:

- How the ESP32 hardware works
- How C controls real physical pins and peripherals
- How FreeRTOS tasks and timing behave
- How sensors, displays, and communication protocols work
- How to design your own reliable embedded communication
- How Wi-Fi, IP networking, BLE, and LoRa fit into real systems

The learning path is intentionally **linear and not steep**. Every project builds on the previous one.

---

## Who This Is For

This curriculum is for you if you want to learn:

- ESP32 using ESP-IDF
- Embedded C programming
- FreeRTOS basics
- Bare-metal and driver-level thinking
- Hardware communication protocols
- Embedded networking
- Low-power embedded design
- Long-range wireless communication with LoRa

You do **not** need prior ESP32 experience.

Basic C knowledge is helpful, but the early projects are designed to ease beginners into embedded programming.

---

## What Makes This Project Different

- **Linear learning path**  
  Topics are ordered carefully from simple to advanced.

- **One or two concepts per project**  
  No lesson tries to teach too much at once.

- **Standalone ESP-IDF projects**  
  Each folder can be opened, built, and flashed independently.

- **Theory and code together**  
  Every project is paired with explanation material.

- **LaTeX-powered documentation**  
  Theory explanations are written in LaTeX and compiled into clean PDFs.

- **Video support**  
  Explanatory videos are included or planned to support visual learners.

- **Beginner-friendly structure**  
  The repository is organized so students can easily find code, theory, diagrams, and instructions.

- **Open to contributions**  
  If you can make learning easier, improvements are welcome.

---

## Curriculum Overview

The curriculum is divided into seven phases.

---

# Phase 1: Bare Metal & Digital Foundations

Goal: Understand the ESP32 hardware, the FreeRTOS environment, and basic digital logic.

| # | Project | Folder | Concepts |
|---|---|---|---|
| 1 | Hello ESP32 | - | Toolchain setup, serial logging, `ESP_LOG`, `app_main()` lifecycle |
| 2 | Digital Output | - | GPIO output, push-pull configuration, driving an LED, 3.3V logic |
| 3 | Infinite Loop & Timing | - | FreeRTOS `vTaskDelay()`, blocking vs yielding |
| 4 | Digital Input | - | Reading buttons, pull-up and pull-down resistors |
| 5 | Interrupts & Debouncing | - | ISR basics, GPIO interrupts, software debouncing |
| 6 | Finite State Machines | - | Enums, state logic, `switch` statements, multi-state behavior |

---

# Phase 2: Analog Signals & Timing

Goal: Bridge the gap between digital logic and the physical, continuous world.

| # | Project | Folder | Concepts |
|---|---|---|---|
| 7 | Analog-to-Digital Conversion | - | ADC reading, resolution, attenuation, sensors like potentiometers |
| 8 | Pulse Width Modulation | - | LEDC peripheral, duty cycle, LED brightness control |
| 9 | Digital-to-Analog Conversion | - | DAC output, voltage levels, basic waveform generation |
| 10 | Hardware Timers | - | Microsecond precision timers, periodic callbacks, sampling |

---

# Phase 3: Standard Peripherals & Interfaces

Goal: Learn how microcontrollers talk to external chips using industry-standard protocols.

| # | Project | Folder | Concepts |
|---|---|---|---|
| 11 | I2C Master Basics | - | I2C bus scanning, reading sensors, addressing, clocking |
| 12 | SPI Master Basics | - | SPI communication, high-speed transfers, SPI devices |
| 13 | OLED Display | - | SSD1306, I2C display, rendering text and sensor data |
| 14 | Audio Generation | - | Timers, PWM/DAC, tone generation, simple beeps |

---

# Phase 4: Concepts on Hardware

Goal: Apply software engineering concepts to physical data.

| # | Project | Folder | Concepts |
|---|---|---|---|
| 15 | Bitwise Operations | - | Masks, shifting, packing/unpacking data |
| 16 | Non-Volatile Storage | - | Saving data to flash, reboot persistence |
| 17 | File Systems | - | LittleFS/SPIFFS, file creation, appending logs, CSV storage |

---

# Phase 5: Wired Communication & Custom Protocols

Goal: Stop using “magic” libraries and build your own communication protocols.

| # | Project | Folder | Concepts |
|---|---|---|---|
| 18 | UART Basics | - | Serial communication, TX/RX, ESP32-to-ESP32 or ESP32-to-PC |
| 19 | Custom Frame Design | - | Binary packets, header, length, payload |
| 20 | Error Detection | - | Checksums, CRC8, corrupted packet detection |
| 21 | Reliable Transfer | - | Sequence numbers, ACKs, retransmission logic |

---

# Phase 6: Wireless Networking

Goal: Connect the ESP32 to the world using standard IP networking.

| # | Project | Folder | Concepts |
|---|---|---|---|
| 22 | Wi-Fi Station Mode | - | Connecting to a router, events, IP address assignment |
| 23 | Wi-Fi Access Point Mode | - | Broadcasting an SSID, assigning IPs to clients |
| 24 | TCP Sockets | - | Reliable streams, TCP client/server |
| 25 | UDP Sockets | - | Connectionless packets, packet loss observation |
| 26 | SNTP Time Sync | - | Fetching real-world UTC time from NTP servers |
| 27 | HTTP & REST APIs | - | Web server, JSON sensor endpoints, HTTP basics |

---

# Phase 7: Low Power & Advanced Wireless

Goal: Optimize for battery life and explore long-range, non-IP communication.

| # | Project | Folder | Concepts |
|---|---|---|---|
| 28 | Deep Sleep & Wake Sources | - | RTC, ULP, GPIO wake, timer wake |
| 29 | BLE Basics | - | BLE GATT server, services, characteristics |
| 30 | LoRa PHY Basics | - | Raw packet transmission, SX127x/SX1262 |
| 31 | LoRa Link Quality | - | RSSI, SNR, signal quality logging |
| 32 | LoRa Reliable Network | - | Reliable protocol over LoRa, node/mesh-style concepts |

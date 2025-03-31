# 🌿 Project Oasis

Project Oasis is an AI-assisted, ESP32-S3-based smart plant watering system. It is designed for modularity, offline operation, secure OTA updates, and energy-efficient solar-powered deployment. The project includes a Flutter-based Firebase dashboard and full hardware abstraction.

## 🚀 Features

- Automatic watering of up to 6 plants
- Modular hardware abstraction (easy sensor/actuator replacement)
- Firebase integration for configuration, telemetry, OTA
- Secure OTA updates (signed + verified)
- Local Wi-Fi provisioning via HTTPS captive portal
- Power-efficient RTC wake + deep sleep
- Debug mode with remote logging to Firebase
- QEMU-first development (simulate logic before deploying)

## 🧪 Development Modes

- **QEMU Mode**: Simulates sensors, actuators, OTA, config, and logic.
- **Hardware Mode**: Real-world sensor/actuator integration.

## 🔧 Components (ESP32)

- ESP32-S3-DevKitC-1 (40-pin)
- Ultrasonic water level sensor
- 12V pump or solenoid valves
- TP4056 + LiPo + Boost Converter
- Optional: leak/rain sensors, flow meter, RTC

## 🛠 Build & Run

```bash
idf.py build
idf.py flash
idf.py monitor
```

## 📁 Project Structure

```
main/
  ├── oasis.c                # Application entry
  ├── oasis_config.[ch]      # Config management (NVS)
  ├── sensors/               # Sensor drivers (mock + real)
  ├── wifi/                  # Wi-Fi connection + provisioning
  ├── firebase/              # REST API for config + telemetry
```

## 🪪 License

This project is licensed under the **GNU General Public License v2.0**. See [LICENSE](LICENSE) for details.

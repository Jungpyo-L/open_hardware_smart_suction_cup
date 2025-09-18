# Smart Suction Cup Library

This repository contains the customized `SSC_MPRLS_Library` Arduino library. You should copy this library into your Arduino libraries folder to use this code.
Follow the instructions below to install it into your Arduino IDE.

## 📥 Installation

### 1. Clone this repository

```bash
git clone https://github.com/Jungpyo-L/open_hardware_smart_suction_cup.git
```

### 2. Copy the library into your Arduino libraries folder

🪟 Windows (PowerShell)
```powershell
Copy-Item -Recurse -Force "open_hardware_smart_suction_cup\Arduino_library\SSC_MPRLS_Library" "$env:USERPROFILE\Documents\Arduino\libraries\SSC_MPRLS_Library"
```

🍎 macOS / 🐧 Linux (bash)
```bash
cp -r repo-name/Arduino_library/JP_MPRLS_Library ~/Documents/Arduino/libraries/JP_MPRLS_Library
```

### 3. Restart Arduino IDE
After restarting, the library will appear under:
```bash
Sketch → Include Library → JP_MPRLS_Library
```

You can now include it in your sketches with:
```cpp
#include <SSC_MPRLS_Library.h>
```


## 🔧 Hardware Information

This library has been tested with the following hardware components:

- **Microcontroller:** [Adafruit Feather ESP32-S3](https://www.adafruit.com/product/5323)  
- **Pressure Sensor:** [Adafruit MPRLS Ported Pressure Sensor](https://www.adafruit.com/product/3965)  
- **I2C Multiplexer:** [Adafruit PCA9546A 1-to-4 I²C Multiplexer](https://www.adafruit.com/product/5664)  

### Connection Notes

- The **MPRLS sensor** communicates via **I²C** (default address `0x18`).
- The **PCA9546 I²C multiplexer** allows multiple MPRLS sensors to be connected on separate I²C channels.  
- Connect the multiplexer to the Feather ESP32-S3 via I²C (SDA, SCL).  
- Ensure all devices and ports on **MPRLS** share a common **GND** and use the appropriate **3.3V power supply**.  

📌 For detailed wiring, please refer to the datasheets of each component or Adafruit’s product guides.

## 👤 Author

- **Name:** Jungpyo Lee  
- **Email:** jungpyolee@berkeley.edu  
- **Affiliation:** Embodied Dexterity Group, UC Berkeley  
- **GitHub:** [jungpyolee](https://github.com/Jungpyo-L)  

# Smart Suction Cup Library

This repository contains the `SSC_MPRLS_Library` Arduino library.  
Follow the instructions below to install it into your Arduino IDE.

## 📥 Installation

### 1. Clone this repository

```bash
git clone https://github.com/Jungpyo-L/open_hardware_smart_suction_cup.git
```

### 2. Copy the library into your Arduino libraries folder

🪟 Windows (PowerShell)
```bash
Copy-Item -Recurse -Force "repo-name\Arduino_library\JP_MPRLS_Library" "$env:USERPROFILE\Documents\Arduino\libraries\JP_MPRLS_Library"
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
```bash
#include <JP_MPRLS_Library.h>
```

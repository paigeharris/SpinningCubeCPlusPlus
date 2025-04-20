# Game Launcher (SDL2)

![SDL2](https://img.shields.io/badge/Library-SDL2-blue)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey)
![License](https://img.shields.io/badge/License-MIT-green)

This is a basic game launcher using SDL2. It includes a simple start screen ("Press Any Button") and transitions into a placeholder game screen. It's meant to be a skeleton for creating your own game launcher or menu system.

---

## 🧰 Requirements

### SDL2 Development Library
Install SDL2 before compiling:

#### On Ubuntu / Debian:
```bash
sudo apt update
sudo apt install libsdl2-dev
```

#### On macOS (with Homebrew):
```bash
brew install sdl2
```

#### On Windows:
Download SDL2 for your compiler from:  
[https://www.libsdl.org/download-2.0.php](https://www.libsdl.org/download-2.0.php)

Make sure to:
- Place the `SDL2.dll` in your project directory (next to your .exe)
- Link to the `include` and `lib` folders in your compiler

---

## 🧱 Build Instructions

### On Linux/macOS:
```bash
g++ main.cpp menu.cpp game.cpp -o launcher -lSDL2
./launcher
```

### On Windows (MinGW example):
```bash
g++ main.cpp menu.cpp game.cpp -IC:/path/to/SDL2/include -LC:/path/to/SDL2/lib -lmingw32 -lSDL2main -lSDL2 -o launcher.exe
launcher.exe
```

> Replace `C:/path/to/SDL2` with your actual SDL2 path.

---

## 🎮 Features

- Start screen waiting for any key or controller input
- Transitions to a basic game loop with a different background
- Structured to scale into full games or engines

---

## 📁 File Overview

| File       | Purpose                                 |
|------------|-----------------------------------------|
| `main.cpp` | Handles initialization and transitions  |
| `menu.cpp` / `menu.h` | Start screen logic            |
| `game.cpp` / `game.h` | Game loop placeholder         |

---

## ❓ Troubleshooting

- **SDL2.dll not found (Windows)**: Make sure it's in the same folder as your `.exe`.
- **No input working**: Ensure your SDL2 is correctly initialized with keyboard/controller flags.
- **Black screen only**: Add `SDL_Delay()` or rendering logic to visually confirm it’s running.

---

## 🛠️ Customize

To expand this launcher:
- Use `SDL_image` to load PNG backgrounds
- Add music with `SDL_mixer`
- Render fonts with `SDL_ttf`
- Add animations, settings menu, save/load system

---

## 📜 License

This project is released under the [MIT License](https://opensource.org/licenses/MIT). Feel free to use and modify for personal or commercial use.

---

## 💬 Feedback & Contributions

Feel free to fork or submit issues/PRs to improve the base system or port it to other engines/platforms. Let's make a great launcher together!
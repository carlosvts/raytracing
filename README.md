# 2D Raytracing Engine in C++ & SFML

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![SFML](https://img.shields.io/badge/SFML-8CC449?style=for-the-badge&logo=sfml&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

A 2D Raytracing engine developed in C++ using the SFML graphics library. This project was created for educational purposes to explore rendering concepts, computational geometry, and light simulation.

## Screenshots

![TODO](TODO)

## About the Project

This project implements a real-time ray casting/tracing system. The goal is to simulate the interaction of "light" or field of view with geometric obstacles in a 2D environment.
Main objective: understand more about ray casting and computer graphics while enhancing C++ skills.

The architecture separates the core physics logic (`raytracing`) from the drawing logic (`renderer`), ensuring modular and maintainable code.

## Technologies

* **Language:** C++
* **Graphics Library:** [SFML](https://www.sfml-dev.org/) (Simple and Fast Multimedia Library)
* **Build System:** GNU Make

## How to Build and Run

### Prerequisites

Before compiling, ensure you have **g++**, **Make**, and the **SFML** library installed.

#### Linux Dependencies

* **Debian / Ubuntu / Pop!_OS:**
    ```bash
    sudo apt-get install libsfml-dev g++ make
    ```

* **Arch Linux:**
    ```bash
    sudo pacman -S sfml base-devel
    ```

* **Fedora:**
    ```bash
    sudo dnf install SFML-devel gcc-c++ make
    ```

### Compiling

This project uses a `Makefile` for easy compilation. Open your terminal in the project folder and run:

```bash
make
```

## File Structure

The source code is organized as follows:

```text
📁 Project
├── 📄 main.cpp              # Entry point: initializes window and main loop
├── 📄 raytracing.cpp        # Implementation of ray math logic
├── 📄 raytracing.hpp        # Definitions and data structures for raytracing
├── 📄 renderer.cpp          # Handles drawing objects and rays to the SFML window
├── 📄 renderer.hpp          # Renderer interface
├── 📄 Makefile              # Automated build script
├── 📄 UniverseCondensed.ttf # Font used for UI/Debug text | You can use another one (just make sure you change in the main.cpp file)
└── 📄 .gitignore
```

# 2D Raytracing Engine in C++

A 2D Raytracing engine developed in C++ using the SFML graphics library. This project was created for educational purposes to explore rendering concepts, computational geometry, and light simulation.

## Screenshots

![Project Demo](TODO)

## About the Project

This project implements a real-time ray casting/tracing system. The goal is to simulate the interaction of "light" or field of view with geometric obstacles in a 2D environment.
Main objective: understand more about ray casting and computer graphics while enhancing C++ skills

The architecture separates the core physics logic (`raytracing`) from the drawing logic (`renderer`), ensuring modular and maintainable code.

## Technologies

* **Language:** C++ (Modern C++)
* **Graphics Library:** [SFML](https://www.sfml-dev.org/) (Simple and Fast Multimedia Library)
* **Build System:** GNU Make

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

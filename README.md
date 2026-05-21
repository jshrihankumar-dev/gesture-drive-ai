# Gesture Drive AI

Gesture Drive AI is an AI-powered gesture control system that allows users to control a device using hand movements. Instead of relying on a keyboard, controller, or joystick, the system uses computer vision to detect hand gestures and convert them into movement commands.

## Overview

The goal of Gesture Drive AI is to create a more natural and accessible way to control machines through human hand motion. By using a camera and real-time gesture recognition, the system can detect commands such as moving forward, turning, stopping, or performing custom actions.

This project combines artificial intelligence, computer vision, and robotics-style control logic to create an interactive gesture-based driving experience.

## Features

- Real-time hand gesture detection
- Camera-based control system
- Gesture-to-command conversion
- Support for movement commands such as:
  - Forward
  - Backward
  - Left
  - Right
  - Stop
- Beginner-friendly structure for future improvements
- Expandable for robotics, drones, vehicles, or smart devices

## Tech Stack

- Python
- OpenCV
- MediaPipe
- Computer Vision
- AI/ML Gesture Recognition
- Optional: Arduino, Raspberry Pi, or robotics hardware

## How It Works

1. The camera captures the user's hand movements.
2. The system detects the hand using computer vision.
3. Key hand landmarks are identified.
4. The program classifies the hand gesture.
5. Each gesture is converted into a control command.
6. The command can be used to control a robot, vehicle, or simulation.

## Example Gestures

| Gesture | Command |
|---|---|
| Open Palm | Stop |
| Index Finger Up | Move Forward |
| Thumb Left | Turn Left |
| Thumb Right | Turn Right |
| Closed Fist | Move Backward |

## Project Goals

The main goal of this project is to explore how gesture-based interfaces can make control systems more intuitive, hands-free, and accessible. Gesture Drive AI could be expanded for robotics competitions, assistive technology, smart vehicles, or human-computer interaction research.

## Future Improvements

- Add more gesture commands
- Improve gesture accuracy in different lighting conditions
- Add a physical robot or car controlled by the gestures
- Create a web dashboard for live camera feedback
- Add voice feedback or sound alerts
- Train a custom machine learning model for better recognition
- Add safety features to prevent accidental movements

## Potential Applications

- Gesture-controlled robots
- Assistive technology for people with limited mobility
- Smart home control
- Educational robotics
- Human-computer interaction research
- Contactless control systems

## Installation

Clone the repository:

```bash
git clone https://github.com/your-username/gesture-drive-ai.git
cd gesture-drive-ai
```
Install dependencies:

```bash
pip install opencv-python mediapipe numpy
```

Run the project:

```bash
python main.py
```

Requirements
Python 3.8+
Webcam or camera module
OpenCV
MediaPipe
NumPy

Status

This project is currently in development. More features, gesture controls, and hardware integration will be added in future versions.

Author
Created by Shrihan Jadigam

License
This project is open source and available under the MIT License.


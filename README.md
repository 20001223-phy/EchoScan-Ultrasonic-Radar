
# EchoScan: Real-Time Ultrasonic Radar

An Arduino-based ultrasonic scanning system that measures object distances across a 180° range and visualizes the measurements in real time using Python.

## Project Overview

EchoScan combines embedded electronics, ultrasonic sensing, servo motor control, serial communication, and real-time data visualization.

An HC-SR04 ultrasonic sensor is mounted on an SG90 servo motor. The servo rotates the sensor through a 180° scanning range, while the Arduino measures the distance to detected objects. Measurements are displayed on a 16×2 LCD and transmitted to a computer, where Python generates a live polar plot.

## Features

- 180° scanning using an SG90 servo motor.
- Distance measurement using the HC-SR04 ultrasonic sensor.
- Real-time angle and distance display on a 16×2 LCD.
- Serial data transmission from Arduino to Python.
- Live radar-style visualization using Matplotlib.
- Distance calculations based on ultrasonic time-of-flight measurements.

## Hardware Components

| Component | Purpose |
|---|---|
| Arduino Uno | Main microcontroller |
| HC-SR04 | Ultrasonic distance measurement |
| SG90 Micro Servo | Rotates the sensor |
| 16×2 LCD | Displays angle and distance |
| 10kΩ Potentiometer | LCD contrast adjustment |
| Breadboard | Circuit connections |
| Jumper Wires | Electrical connections |
| USB Cable | Power and serial communication |

## Software and Libraries

- Arduino IDE
- Python 3
- Visual Studio Code
- PySerial
- NumPy
- Matplotlib

## Project Structure

```text
EchoScan-Ultrasonic-Radar/
├── Arduino/
│   └── ultrasonic_radar.ino
├── Python/
│   └── radar_visualization.py
├── requirements.txt
├── README.md
├── LICENSE
└── .gitignore
```

## How It Works

1. The servo rotates the HC-SR04 sensor from 0° to 180° in 10° increments.
2. The sensor emits an ultrasonic pulse and measures the time taken for its echo to return.
3. The Arduino calculates the distance from the measured echo time.
4. The angle and distance are displayed on the LCD.
5. The Arduino transmits the measurements to the computer through serial communication.
6. Python reads the incoming data and updates a polar plot in real time.

## Setup and Execution

### 1. Arduino Setup

- Connect the hardware components according to the circuit connections.
- Open `Arduino/ultrasonic_radar.ino` in the Arduino IDE.
- Select the correct Arduino board and COM port.
- Upload the sketch.

### 2. Python Setup

Install the required libraries:

```bash
pip install -r requirements.txt
```

### 3. Run the Visualization

- Ensure the Arduino is connected to the computer.
- Close the Arduino Serial Monitor before running the Python script.
- Check the COM port in `Python/radar_visualization.py` and change `COM3` if necessary.
- Run:

```bash
python Python/radar_visualization.py
```

## Current Limitations

- The system uses ultrasonic sound waves, not electromagnetic radar waves.
- It measures distance rather than directly detecting motion.
- Measurement accuracy depends on object surface, orientation, and environmental conditions.
- Scanning occurs in discrete 10° increments.
- The visualization is two-dimensional and does not provide object identification or 3D mapping.

## Future Improvements

- CSV data logging.
- Improved radar visualization and scan refresh.
- Adjustable scanning resolution and detection range.
- Object tracking across successive scans.

## Author

Laiba Iqbal

Physics Graduate | Nonlinear Plasma Physics | Computational Physics | Embedded Systems



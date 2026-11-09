
import serial
import matplotlib.pyplot as plt
import numpy as np

arduino = serial.Serial('COM3', 9600, timeout=2)
plt.ion()

fig = plt.figure(figsize=(8, 8))
ax = fig.add_subplot(111, projection='polar')

ax.set_theta_zero_location('N')
ax.set_theta_direction(-1)
ax.set_thetamin(0)
ax.set_thetamax(180)
ax.set_ylim(0, 100)
ax.set_title("Ultrasonic Radar Scanner")

angles = []
distances = []

try:
    while True:
        line = arduino.readline().decode('utf-8', errors='ignore').strip()

        if not line or line == "Angle,Distance":
            continue

        try:
            angle_str, distance_str = line.split(',')

            if distance_str == "Out":
                continue

            angle = float(angle_str)
            distance = float(distance_str)

            angles.append(np.radians(angle))
            distances.append(distance)

            if len(angles) > 19:
                angles = angles[-19:]
                distances = distances[-19:]

            ax.clear()
            ax.set_theta_zero_location('N')
            ax.set_theta_direction(-1)
            ax.set_thetamin(0)
            ax.set_thetamax(180)
            ax.set_ylim(0, 100)
            ax.set_title("Ultrasonic Radar Scanner")

            ax.scatter(angles, distances, s=35)
            ax.plot(angles, distances)

            plt.pause(0.01)

        except ValueError:
            continue

except KeyboardInterrupt:
    print("Radar stopped.")

finally:
    arduino.close()
    plt.ioff()
    plt.show()

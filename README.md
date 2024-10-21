# ASL Translation Glove using Arduino

This repository contains the Arduino code for a specialized glove that translates American Sign Language (ASL) gestures into spoken phrases. The glove uses sensors to capture hand movements and transmits the data to an Android application, which then displays the recognized phrases and outputs them via speech.

## Project Overview
This project is designed to assist individuals with speech impairments by enabling communication through ASL. The glove translates hand gestures into text and speech in real-time, facilitating easy interaction without the need for a human translator. 

### Key Components
- **Gyroscope Sensor**: Detects hand orientation and motion.
- **Flex Sensors**: Measures finger bending to identify specific ASL gestures.
- **Arduino**: Acts as the processing unit, reading sensor data and sending it to the connected Android app via Bluetooth or another communication module.
- **Android Application**: Receives sensor data, processes it to display the corresponding phrase, and converts it into speech output.

## Features
- **Real-time ASL Translation**: Recognizes and translates ASL gestures into phrases.
- **Bluetooth Communication**: Data is transmitted wirelessly to an Android device.
- **Text and Speech Output**: Displays the recognized phrase on the Android app and speaks it aloud using text-to-speech (TTS) functionality.

## Components Used
- **Arduino Nano**: The microcontroller used to interface with sensors.
- **MPU-6050 Gyroscope**: Captures the glove's orientation and motion.
- **Flex Sensors**: Five flex sensors are attached to the glove, one for each finger.
- **HC-05 Bluetooth Module**: Facilitates wireless communication between the glove and the Android app.
- **Android Device**: Runs the app that displays the translated phrase and speaks it aloud.

## How it Works
1. **Gesture Capture**: When the user performs a sign, the flex sensors measure the bending of the fingers, while the gyroscope detects hand orientation.
2. **Data Transmission**: The sensor data is processed by the Arduino and sent to the Android application using Bluetooth.
3. **Phrase Translation**: The app processes the data and maps it to a predefined phrase corresponding to the ASL gesture.
4. **Output**: The phrase is displayed on the Android app, and a text-to-speech engine converts it into spoken words.

## Getting Started

### Prerequisites
1. **Hardware Setup**:
    - Connect the flex sensors to the Arduino according to the pin diagram.
    - Attach the gyroscope (MPU-6050) and Bluetooth module (HC-05) to the appropriate pins on the Arduino.
  
2. **Software**:
    - Install the Arduino IDE from [Arduino Official Site](https://www.arduino.cc/en/software).
    - Install the necessary libraries (e.g., `Wire.h` for I2C communication with the MPU-6050).

3. **Android Application**:
    - Set up the companion Android application that will receive and process the sensor data.
    - MIT Open Source Android application compatible with HC-05 bluetooth module.

### Uploading the Code
1. Clone this repository:
    ```bash
    git clone https://github.com/your-username/sign-language-translator.git
    cd sign-language-translator
    ```

2. Open the `.ino` file in the Arduino IDE.

3. Upload the code to your Arduino board:
    - Select the correct board type (e.g., Arduino Uno).
    - Select the correct port for your Arduino.
    - Click the upload button.

### Connecting to the Android App
1. Pair the Android device with the Bluetooth module (HC-05).
2. Open the Android application and select the Bluetooth device.
3. The app will begin receiving data and translating ASL gestures.

## Future Enhancements
- **Expand Phrase Library**: Increase the number of ASL phrases recognized by the system.
- **Gesture Accuracy**: Improve gesture recognition through advanced filtering or machine learning models.
- **Enhanced Connectivity**: Explore Wi-Fi or BLE for more reliable communication between the glove and app.
- **Multilingual Support**: Add the ability to translate ASL gestures into multiple languages.

## Acknowledgments
- Arduino community for providing extensive resources on sensor integration.
- Open-source projects related to gesture recognition and Bluetooth communication.

---

Feel free to contribute to this project by submitting issues or pull requests. Together, we can help make communication more accessible for everyone.

/************************************************************
                CONTROL DEVICE BY AUDIO PROJECT
************************************************************/
The system includes two nodes. Node 1 receives audio data via 
the I2S protocol and sends it to a host device (desktop) for 
processing, which returns a prediction to control the device.

/************************************************************
                      GENERAL INFORMATION
************************************************************/
MCU: ESP32

Sensors:
    - DHT11 (Temperature and Humidity)
    - INMP441 (Microphone for Audio Receiving)

Actuators:
    - TFT ST7735 (Display)
    - Relay (for controlling real devices)

Protocols:
    - Websockets (ESP32 (node1) to Desktop)
    - MQTT (Desktop send control signal to ESP32 (node2))

Internal Protocols:
    - I2S: Between INMP441 and ESP32 (node1)
    - SPI: Between TFT ST7735 and ESP32 (node2)
    - GPIO

/************************************************************
                     ADDITIONAL INFORMATION
************************************************************/
An AI model is trained using data received from the INMP441 
microphone. 
Preprocessing steps include noise reduction, trimming, and MFCC 
extraction. 
The model is trained using a CNN algorithm.
    - Dataset: 160 audio files divided into 4 classes (40 files 
    per class)
    - Model Size: Approximately 1500 KB
    - Accuracy: 96% on the test set
    - Edge computing: Not implemented

/************************************************************
                          VIDEO DEMO
************************************************************/
https://youtube.com/shorts/bEUPPwgqJIA
This is not comprehensive and can be modified as needed.

# AD8400

Library implementing SPI-communication between 1-channel digital potentiometer AD8400 and Arduino;

## Default pins:
- MOSI - 11
- Cheap Select - 10
- CLK - 13

## Example

    #include <AD8400.h>

    AD8400 ad8400;

    void setup() {
        ad8400.begin();
    }

    void loop() {
        for (int i = 0; i < 256; i++) {
            ad8400.sendData(i);
            delay(500);
        }
    }
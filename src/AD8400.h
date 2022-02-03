#pragma once

class AD8400 {
public:
    AD8400(uint8_t mosiPin = 11, uint8_t cheapSelectPin = 10, uint8_t clockPin = 13);
    void begin();
    void sendData(byte value);
};

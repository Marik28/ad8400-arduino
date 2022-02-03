#include <Arduino.h>
#include <String.h>

// class representing AD8400 1 channel digital potentiometer
class AD8400 {
private:
    uint8_t _mosiPin;
    uint8_t _cheapSelectPin;
    uint8_t _clockPin;

    void _selectAddress()
    {
        digitalWrite(this->_mosiPin, LOW);
        for (int i = 0; i < 2; i++) {
            digitalWrite(this->_clockPin, LOW);
            digitalWrite(this->_clockPin, HIGH);
        }
    }

public:
    AD8400(uint8_t mosiPin = 11, uint8_t cheapSelectPin = 10, uint8_t clockPin = 13)
    {
        this->_mosiPin = mosiPin;
        this->_cheapSelectPin = cheapSelectPin;
        this->_clockPin = clockPin;
    }
    void begin()
    {
        pinMode(this->_mosiPin, OUTPUT);
        pinMode(this->_cheapSelectPin, OUTPUT);
        pinMode(this->_clockPin, OUTPUT);
        digitalWrite(this->_cheapSelectPin, HIGH);
    }

    // value - integer between 0 and 255
    void sendData(uint8_t value)
    {
        digitalWrite(this->_cheapSelectPin, LOW);
        this->_selectAddress();
        for (int i = 7; i >= 0; i--) {
            digitalWrite(this->_clockPin, LOW);

            bool bit = bitRead(value, i);
            digitalWrite(this->_mosiPin, bit);
            digitalWrite(this->_clockPin, HIGH);
        }
        digitalWrite(this->_cheapSelectPin, HIGH);
    }
};
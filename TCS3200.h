#pragma once

#define S0  4
#define S1  0
#define S2  2
#define S3  14
#define OUT 12


struct tcs_color_t {
  uint16_t r, g, b;
};

class TCS3200 {
 public:
  void begin() {
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(OUT, INPUT);
    // Setting frequency-scaling to 20%
    digitalWrite(S0,HIGH);
    digitalWrite(S1,LOW);
  }

  tcs_color_t getRaw() {
    return tcs_color_t{
        _read16(LOW, LOW),
        _read16(HIGH, HIGH),
        _read16(LOW, HIGH),
    };
  }

 private:
  uint16_t _read16(uint8_t s2, uint8_t s3) {
    digitalWrite(S2,s2);
    digitalWrite(S3,s3);
    return pulseIn(OUT, LOW);  // Reading the output Red frequency
  }
};
#ifndef PCA9685_H
#define PCA9685_H

#include <string>
#include <memory>

namespace PCA9685 {

class I2CPeripheral;

class PCA9685 {
public:
    explicit PCA9685(const std::string &device = "/dev/i2c-1", int address = 0x40);
    ~PCA9685();

    void set_pwm_freq(const double freq_hz);
    void set_pwm(const int channel, const uint16_t on, const uint16_t off);
    void set_all_pwm(const uint16_t on, const uint16_t off);
    void set_pwm_ms(const int channel, const double ms);

    void set_high(const uint8_t channel); 
    void set_low(const uint8_t channel); 
    void set_channel(const uint8_t channel, const bool high);

private:
    std::unique_ptr<I2CPeripheral> i2c_dev;

    double frequency = 200.0;  // Default frequency pulled from PCA9685 datasheet.

};
}  // namespace PCA9685
#endif //PCA9685_H

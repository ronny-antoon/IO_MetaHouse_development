#pragma once

#include <driver/gpio.h>

#include "RelayModuleInterface.hpp"

/**
 * @brief Concrete implementation of the RelayModuleInterface using GPIO.
 */
class RelayModule : public RelayModuleInterface {
 public:
  /**
   * @brief Constructor for the RelayModule.
   * @param relay_pin GPIO pin connected to the relay.
   * @param active_level Logic level to activate the relay.
   * @param initial_state Initial state of the relay (0 for off, 1 for on, -1 for undefined).
   */
  RelayModule(int8_t relay_pin = -1, int8_t active_level = 1, int8_t initial_state = -1);

  /**
   * @brief Default destructor.
   */
  virtual ~RelayModule() = default;

  /**
   * @brief Set the power state of the relay.
   * @param state True to turn the relay on, false to turn it off.
   */
  void setPower(bool state) override;

  /**
   * @brief Check if the relay is currently on.
   * @return True if the relay is on, false otherwise.
   */
  bool isOn() override;

 private:
  gpio_num_t m_relay_pin;  ///< GPIO pin connected to the relay.
  int8_t m_active_level;   ///< Logic level to activate the relay.
};

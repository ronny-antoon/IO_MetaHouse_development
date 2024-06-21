#include "RelayModule.hpp"

#include <esp_log.h>

static const char* TAG = "RelayModule";

RelayModule::RelayModule(int8_t relay_pin, int8_t active_level, int8_t initial_state) {
  ESP_LOGI(TAG, "Creating RelayModule [ relay_pin : %d | active_level : %d | initial_state : %d ]", relay_pin,
           active_level, initial_state);

  m_relay_pin = static_cast<gpio_num_t>(relay_pin);
  m_active_level = active_level;

  gpio_set_direction(m_relay_pin, GPIO_MODE_INPUT_OUTPUT);

  if (initial_state == 0) {
    gpio_set_level(m_relay_pin, !m_active_level);
    ESP_LOGD(TAG, "Initial state set to OFF");
  } else if (initial_state == 1) {
    gpio_set_level(m_relay_pin, m_active_level);
    ESP_LOGD(TAG, "Initial state set to ON");
  } else {
    ESP_LOGD(TAG, "Initial state undefined, relay left in default state");
  }
}

void RelayModule::setPower(bool state) {
  ESP_LOGV(TAG, "Setting power state to %d", state);

  gpio_set_level(m_relay_pin, state ? m_active_level : !m_active_level);
}

bool RelayModule::isOn() {
  bool is_on = gpio_get_level(m_relay_pin) == m_active_level;
  ESP_LOGV(TAG, "Checking if relay is on: %d", is_on);

  return is_on;
}

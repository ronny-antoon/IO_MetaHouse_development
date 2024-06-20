#include "ButtonModule.hpp"

#include <esp_log.h>

static const char *TAG = "ButtonModule";

ButtonModule::ButtonModule(int8_t button_pin, uint8_t active_level, uint16_t long_press_time_ms,
                           uint16_t short_press_time_ms) {
  ESP_LOGI(TAG,
           "Creating ButtonModule [ button_pin : %d | active_level : %d | long_press_time_ms : %d | "
           "short_press_time_ms : %d ]",
           button_pin, active_level, long_press_time_ms, short_press_time_ms);

  gpio_set_direction((gpio_num_t)button_pin, GPIO_MODE_INPUT);

  button_config_t button_config = {.type = BUTTON_TYPE_GPIO,
                                   .long_press_time = long_press_time_ms,
                                   .short_press_time = short_press_time_ms,
                                   .gpio_button_config = {
                                       .gpio_num = button_pin,
                                       .active_level = active_level,
                                   }};

  m_button_handle = iot_button_create(&button_config);
}

ButtonModule::~ButtonModule() {
  ESP_LOGI(TAG, "Destroying ButtonModule");

  iot_button_delete(m_button_handle);
}

void ButtonModule::onSinglePress(CallBackButtonFunction cb, AnyType *cb_parameter) {
  ESP_LOGI(TAG, "Registering single press callback");

  m_single_press_cb = cb;
  m_single_press_cb_parameter = cb_parameter;

  iot_button_register_cb(
      m_button_handle, BUTTON_SINGLE_CLICK,
      [](void *button_handle, void *this_ptr) {
        ESP_LOGD(TAG, "Single press detected");

        ButtonModule *button_module = static_cast<ButtonModule *>(this_ptr);
        if (button_module->m_single_press_cb) {
          button_module->m_single_press_cb(button_module->m_single_press_cb_parameter);
        }
      },
      this);
}

void ButtonModule::onDoublePress(CallBackButtonFunction cb, AnyType *cb_parameter) {
  ESP_LOGI(TAG, "Registering double press callback");

  m_double_press_cb = cb;
  m_double_press_cb_parameter = cb_parameter;

  iot_button_register_cb(
      m_button_handle, BUTTON_DOUBLE_CLICK,
      [](void *button_handle, void *this_ptr) {
        ESP_LOGD(TAG, "Double press detected");

        ButtonModule *button_module = static_cast<ButtonModule *>(this_ptr);
        if (button_module->m_double_press_cb) {
          button_module->m_double_press_cb(button_module->m_double_press_cb_parameter);
        }
      },
      this);
}

void ButtonModule::onLongPress(CallBackButtonFunction cb, AnyType *cb_parameter) {
  ESP_LOGI(TAG, "Registering long press callback");

  m_long_press_cb = cb;
  m_long_press_cb_parameter = cb_parameter;

  iot_button_register_cb(
      m_button_handle, BUTTON_LONG_PRESS_START,
      [](void *button_handle, void *this_ptr) {
        ESP_LOGD(TAG, "Long press detected");

        ButtonModule *button_module = static_cast<ButtonModule *>(this_ptr);
        if (button_module->m_long_press_cb) {
          button_module->m_long_press_cb(button_module->m_long_press_cb_parameter);
        }
      },
      this);
}
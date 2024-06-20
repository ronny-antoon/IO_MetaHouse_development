#pragma once

#include <iot_button.h>

#include "ButtonModuleInterface.hpp"

/**
 * @brief Concrete implementation of the ButtonModuleInterface using iot_button.
 */
class ButtonModule : public ButtonModuleInterface {
 public:
  /**
   * @brief Constructor for the ButtonModule.
   * @param button_pin GPIO pin connected to the button.
   * @param active_level Logic level to detect a button press.
   * @param long_press_time_ms Duration in milliseconds to detect a long press.
   * @param short_press_time_ms Duration in milliseconds to detect a short press.
   */
  ButtonModule(int8_t button_pin = -1, uint8_t active_level = 1, uint16_t long_press_time_ms = 2000,
               uint16_t short_press_time_ms = 100);

  /**
   * @brief Destructor for the ButtonModule.
   */
  virtual ~ButtonModule();

  /**
   * @brief Register a callback function for a single press event.
   * @param cb Callback function to be called on a single press.
   * @param cb_parameter Optional parameter to be passed to the callback function.
   */
  void onSinglePress(CallBackButtonFunction cb, AnyType *cb_parameter = nullptr) override;

  /**
   * @brief Register a callback function for a double press event.
   * @param cb Callback function to be called on a double press.
   * @param cb_parameter Optional parameter to be passed to the callback function.
   */
  void onDoublePress(CallBackButtonFunction cb, AnyType *cb_parameter = nullptr) override;

  /**
   * @brief Register a callback function for a long press event.
   * @param cb Callback function to be called on a long press.
   * @param cb_parameter Optional parameter to be passed to the callback function.
   */
  void onLongPress(CallBackButtonFunction cb, AnyType *cb_parameter = nullptr) override;

 private:
  CallBackButtonFunction m_single_press_cb;  ///< Callback function for single press event.
  CallBackButtonFunction m_double_press_cb;  ///< Callback function for double press event.
  CallBackButtonFunction m_long_press_cb;    ///< Callback function for long press event.
  AnyType *m_single_press_cb_parameter;      ///< Parameter for single press callback.
  AnyType *m_double_press_cb_parameter;      ///< Parameter for double press callback.
  AnyType *m_long_press_cb_parameter;        ///< Parameter for long press callback.
  button_handle_t m_button_handle;           ///< Handle for the button.
};

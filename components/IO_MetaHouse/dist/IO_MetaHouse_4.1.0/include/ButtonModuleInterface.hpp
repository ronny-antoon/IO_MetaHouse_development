#pragma once

/**
 * @brief Interface for a button module.
 */
class ButtonModuleInterface {
 public:
  /**
   * @brief Type definition for a callback function for button events.
   */
  using CallBackButtonFunction = void (*)(void *);

  /**
   * @brief Type definition for a generic parameter type for callbacks.
   */
  using AnyType = void;

  /**
   * @brief Virtual destructor for the interface.
   */
  virtual ~ButtonModuleInterface() = default;

  /**
   * @brief Register a callback function for a single press event.
   * @param cb Callback function to be called on a single press.
   * @param cb_parameter Optional parameter to be passed to the callback function.
   */
  virtual void onSinglePress(CallBackButtonFunction cb, AnyType *cb_parameter = nullptr) = 0;

  /**
   * @brief Register a callback function for a double press event.
   * @param cb Callback function to be called on a double press.
   * @param cb_parameter Optional parameter to be passed to the callback function.
   */
  virtual void onDoublePress(CallBackButtonFunction cb, AnyType *cb_parameter = nullptr) = 0;

  /**
   * @brief Register a callback function for a long press event.
   * @param cb Callback function to be called on a long press.
   * @param cb_parameter Optional parameter to be passed to the callback function.
   */
  virtual void onLongPress(CallBackButtonFunction cb, AnyType *cb_parameter = nullptr) = 0;
};

#pragma once

/**
 * @brief Interface for a relay module.
 */
class RelayModuleInterface {
 public:
  /**
   * @brief Virtual destructor for the interface.
   */
  virtual ~RelayModuleInterface() = default;

  /**
   * @brief Set the power state of the relay.
   * @param state True to turn the relay on, false to turn it off.
   */
  virtual void setPower(bool state) = 0;

  /**
   * @brief Check if the relay is currently on.
   * @return True if the relay is on, false otherwise.
   */
  virtual bool isOn() = 0;
};

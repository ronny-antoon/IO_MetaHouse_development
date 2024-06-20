# IO_MetaHouse

IO_MetaHouse is a C++ component for handling relay and button modules on ESP32 devices.

## Overview

IO_MetaHouse provides classes for interfacing with relay modules and button modules on ESP32 microcontrollers. It includes two main classes:

- `RelayModule`: Interface for controlling relay power states.
- `ButtonModule`: Interface for handling button events like single press, double press, and long press.

## Features

- Control relay power states.
- Handle button events such as single press, double press, and long press.
- Simple to integrate into ESP32 projects.

## Installation

Clone this repository into your ESP32 project components directory:

```bash
git clone https://github.com/your/repository.git components/IO_MetaHouse
```

## Usage

### RelayModule
```cpp
#include "RelayModule.hpp"

// Create a relay module instance
RelayModule relay;

// Set the power state of the relay
relay.setPower(true); // Turns the relay on

// Check if the relay is on
bool isOn = relay.isOn();
```

### ButtonModule
```cpp
#include "ButtonModule.hpp"

// Create a button module instance
ButtonModule button;

// Register callbacks for button events
button.onSinglePress([](void *param) {
    // Callback for single press
});

button.onDoublePress([](void *param) {
    // Callback for double press
});

button.onLongPress([](void *param) {
    // Callback for long press
});
```

## Dependencies
 - ESP-IDF: ESP32 IoT Development Framework

## License
This project is licensed under the [MIT License](LICENSE) - see the LICENSE file for details.

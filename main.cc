#include <iostream>
#include "sensor.pb.h"

int main() {
    Sensor sensor;
    sensor.set_name("Laboratory");
    sensor.set_temperature(23.4);
    sensor.set_humidity(68);
    sensor.set_door(Sensor_SwitchLevel_OPEN);
    std::cout << "Serialized data: " << sensor.SerializeAsString() << std::endl;
    return 0;
}



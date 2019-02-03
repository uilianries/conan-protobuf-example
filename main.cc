#include <iostream>
#include "sensor.pb.h"

int main() {
    Sensor sensor;
    sensor.set_name("Laboratory");
    sensor.set_temperature(23.4);
    sensor.set_humidity(68);
    sensor.set_door(Sensor_SwitchLevel_OPEN);

    const std::string serialized_sensor = sensor.SerializeAsString();

    std::cout << "Serialized data: " << serialized_sensor << std::endl;

    {
	 Sensor sensor;
	 sensor.ParseFromString(serialized_sensor);
	 std::cout << "Name: " << sensor.name() << std::endl;
	 std::cout << "Temperature: " << sensor.temperature() << std::endl;
	 std::cout << "Humidity: " << sensor.humidity() << std::endl;
	 std::cout << "Door is: " << (sensor.door() ? "Open" : "Closed") << std::endl;
    }

    return 0;
}



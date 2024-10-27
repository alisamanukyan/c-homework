#include <stdio.h>

union SensorData {
    int temperature; 
    float pressure;  
    float humidity;  
};

struct Sensor {
    char type[20];    
    union SensorData data; 
};

int main() {
    struct Sensor sensor;

    printf("Enter sensor type (t, p, h): ");
    scanf("%s", sensor.type);

    if (sensor.type[0] == 't') {  
        printf("Enter temperature reading (integer): ");
        scanf("%d", &sensor.data.temperature);
    } else if (sensor.type[0] == 'p'){
        printf("Enter pressure reading (float): ");
        scanf("%f", &sensor.data.pressure);
    } else if (sensor.type[0] == 'h'){
        printf("Enter humidity reading (float): ");
        scanf("%f", &sensor.data.humidity);
    } else {
        printf("Invalid sensor type.\n");
        return 1;
    }

    printf("Sensor Type: %s\n", sensor.type);
    if (sensor.type[0] == 't') {
        printf("Temperature Reading: %d°C\n", sensor.data.temperature);
    } else if (sensor.type[0] == 'p') {
        printf("Pressure Reading: %.2f hPa\n", sensor.data.pressure);
    } else if (sensor.type[0] == 'h') {
        printf("Humidity Reading: %.2f%%\n", sensor.data.humidity);
    }

    return 0;
}

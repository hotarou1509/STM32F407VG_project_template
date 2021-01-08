#include "led.h"

void led_on(uint8_t led){
    unsigned int pin = 0;
    switch (led){
        case 3:
            pin = 13;
            break;
		case 4:
            pin = 12;
            break;
        case 5:
            pin = 14;
            break;
        case 6:
            pin = 15;
            break;
		default:
			break;
    }
    Set_Pin(HIGH, pin);
}

void led_off(uint8_t led){
    unsigned int pin = 0;
    switch (led){
        case 3:
            pin = 13;
            break;
        case 4:
            pin = 12;
            break;
        case 5:
            pin = 14;
            break;
        case 6:
            pin = 15;
            break;
		default:
			break;
    }
    Set_Pin(LOW, pin);
}

/*
 * File: gpio_led_register.c
 * Description: Blink LED using register-level programming
 * Microcontroller: ATmega328P
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Set PB5 (Arduino UNO LED pin) as output
    DDRB |= (1 << DDB5);

    while (1)
    {
        // Turn LED ON
        PORTB |= (1 << PORTB5);
        _delay_ms(500);

        // Turn LED OFF
        PORTB &= ~(1 << PORTB5);
        _delay_ms(500);
    }
}

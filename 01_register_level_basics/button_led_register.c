/*
 * File: button_led_register.c
 * Description: Control LED using push button (register-level)
 * Microcontroller: ATmega328P
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Set PB5 (LED) as output
    DDRB |= (1 << DDB5);

    // Set PD2 (Button) as input
    DDRD &= ~(1 << DDD2);

    // Enable internal pull-up resistor on PD2
    PORTD |= (1 << PORTD2);

    while (1)
    {
        // Check if button is pressed (active low)
        if (!(PIND & (1 << PIND2)))
        {
            PORTB |= (1 << PORTB5);   // LED ON
        }
        else
        {
            PORTB &= ~(1 << PORTB5);  // LED OFF
        }

        _delay_ms(50); // Simple debounce delay
    }
}

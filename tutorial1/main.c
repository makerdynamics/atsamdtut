/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * This is a bare minimum user application template.
 *
 * For documentation of the board, go \ref group_common_boards "here" for a link
 * to the board-specific documentation.
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to system_init()
 * -# Basic usage of on-board LED and button
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>

void configure_port_pins(void)
{
	struct port_config config_port_pin;							/* create a PORT module pin configuration struct */
	port_get_config_defaults(&config_port_pin);					/* Initialize the pin configuration struct with module's default values */

	config_port_pin.direction = PORT_PIN_DIR_INPUT;				/* User Button pin configured as Input */
	config_port_pin.input_pull = PORT_PIN_PULL_UP;				/* User Button pin configured to enable Pull-Up */
	port_pin_set_config(BUTTON_0_PIN, &config_port_pin);		/* set the port config for user button, PA15 pin */

	config_port_pin.direction = PORT_PIN_DIR_OUTPUT;			/* LED pin configured as Output */
	port_pin_set_config(LED_0_PIN, &config_port_pin);			/* set the port config for LED, PB30 pin */
}

int main (void)
{
	system_init();

	while(1)
	{
		bool user_button_pin_state = port_pin_get_input_level(BUTTON_0_PIN);		/* get the pin state from PA15 user button */

		port_pin_set_output_level(LED_0_PIN, user_button_pin_state);				/* set the output for the LED PB30 with the user button pin state */
	}
}

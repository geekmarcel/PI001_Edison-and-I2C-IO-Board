

#include "mraa.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  /* Setup your example here, code that should run once
   */

	mraa_platform_t platform = mraa_get_platform_type();
	mraa_gpio_context d_pin = NULL;

	d_pin = mraa_gpio_init(13);

	// set the pin as output
	if (mraa_gpio_dir(d_pin, MRAA_GPIO_OUT) != MRAA_SUCCESS) {
		fprintf(stderr, "Can't set digital pin as output, exiting");
		return MRAA_ERROR_UNSPECIFIED;
	};

	// loop forever toggling the on board LED every second
	for (;;) {
		mraa_gpio_write(d_pin, 0);
		sleep(3);
		mraa_gpio_write(d_pin, 1);
		sleep(1);
	}

	return MRAA_SUCCESS;
}

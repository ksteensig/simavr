#include <stdlib.h>
#include <stdio.h>
#include <libgen.h>
#include <GL/glut.h>
#include <pthread.h>

#include "sim_avr.h"
#include "avr_ioport.h"
#include "sim_elf.h"
#include "sim_gdb.h"
#include "sim_vcd_file.h"

uint8_t	pin_state = 0;

avr_t *avr = NULL;
elf_firmware_t f;
const char *fname = "blink-sample.elf";

avr_vcd_t vcd_file;

void pin_changed_hook(struct avr_irq_t * irq, uint32_t value, void * param)
{
	pin_state = (pin_state & ~(1 << irq->irq)) | (value << irq->irq);
}
void *avr_run_thread()
{
    for (int i = 0; i < 1000000; i++)
    {
        avr_run(avr);
    }

    return NULL;
}

int main()
{
    elf_read_firmware(fname, &f);

    avr = avr_make_mcu_by_name("atmega328p");

    avr_init(avr);
    avr_load_firmware(avr, &f);

    for (int i = 0; i < 8; i++)
		avr_irq_register_notify(
			avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('B'), i),
			pin_changed_hook, 
			NULL);

    avr_vcd_init(avr, "gtkwave_output.vcd", &vcd_file, 100000 /* usec */);
	avr_vcd_add_signal(&vcd_file, 
		avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('B'), IOPORT_IRQ_PIN_ALL), 8 /* bits */ ,
		"portb" );

    avr_vcd_start(&vcd_file);

    pthread_t run;
    pthread_create(&run, NULL, avr_run_thread, NULL);
    avr_vcd_stop(&vcd_file);

    return 0;
}
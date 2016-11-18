#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <libgen.h>

#include "sim_avr.h"
#include "sim_elf.h"
#include "sim_hex.h"
#include "sim_wcet.h"

int main(int argc, char *argv[])
{
    avr_t *avr;
    elf_firmware_t f;
	char * fname =  argv[0];

	elf_read_firmware(fname, &f);

   	avr = avr_make_mcu_by_name(f.mmcu);

    avr_init(avr);
	avr_load_firmware(avr, &f);

    uint64_t cycles = wcet_calculate_clock_cycles(avr);

    printf("%s took %lu cycles\n", argv[0], cycles);

    return 0;
}
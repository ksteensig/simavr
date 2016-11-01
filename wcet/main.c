#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <libgen.h>

#include "sim_avr.h"
#include "avr_ioport.h"
#include "sim_elf.h"
#include "sim_hex.h"

#include "wcet.h"

int main()
{
    avr_t *avr = NULL;
    elf_firmware_t f;

    const char *fname = "blink-sample.elf";

    elf_read_firmware(fname, &f);

    avr = avr_make_mcu_by_name("atmega328p");

    avr_init(avr);
    avr_load_firmware(avr, &f);

    uint32_t i = 0;

    while(avr->opcode != 0xCFFF) {
        avr_run(avr);
        printf("%d\t%x\n", avr->state, avr->opcode);
        i += decode_instr(avr->opcode);
    }

    printf("%u\n", i);
}

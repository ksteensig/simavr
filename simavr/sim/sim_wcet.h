#ifndef __SIM_WCET_H__
#define __SIM_WCET_H__

#include "sim_avr.h"

enum {
    ADD     = 1,
    ADC     = 1,
    ADIW    = 2,
    SUB     = 1,
    SUBI    = 1,
    SBC     = 1,
    SBCI    = 1,
    SBIW    = 2,
    AND     = 1,
    ANDI    = 1,
    OR      = 1,
    ORI     = 1,
    EOR     = 1,
    COM     = 1,
    NEG     = 1,
    SBR     = 1,
    CBR     = 1,
    INC     = 1,
    DEC     = 1,
    TST     = 1,
    CLR     = 1,
    SRT     = 1,
    MUL     = 2,
    MULS    = 2,
    MULSU   = 2,
    FMUL    = 2,
    FMULS   = 2,
    FMULSU  = 2,
    DES     = 2,
    RJMP    = 2,
    IJMP    = 2,
    EIJMP   = 2,
    JMP     = 3,
    RCALL   = 4,
    ICALL   = 4,
    EICALL  = 4,
    CALL    = 5,
    RET     = 5,
    RETI    = 5,
    CPSE    = 3,
    CP      = 1,
    CPC     = 1,
    CPI     = 1,
    SBRC    = 3,
    SBRS    = 3,
    SBIC    = 3,
    SBIS    = 3,
    BRBS    = 2,
    BRBC    = 2,
    BREQ    = 2,
    BRNE    = 2,
    BRCS    = 2,
    BRCC    = 2,
    BRSH    = 2,
    BRLO    = 2,
    BRMI    = 2,
    BRPL    = 2,
    BRGE    = 2,
    BRLT    = 2,
    BRHS    = 2,
    BRHC    = 2,
    BRTS    = 2,
    BRTC    = 2,
    BRVS    = 2,
    BRVC    = 2,
    BRIE    = 2,
    BRID    = 2,
    MOV     = 1,
    MOVW    = 1,
    LDI     = 1,
    LDS     = 1,
    LD2     = 2,
    LD3     = 3,
    LDD     = 2,
    STS     = 2,
    ST      = 2,
    STD     = 2,
    LPM     = 3,
    ELPM    = 3,
    IN      = 1,
    OUT     = 1,
    PUSH    = 2,
    POP     = 2,
    XCH     = 1,
    LAS     = 1,
    LAC     = 1,
    LAT     = 1,
    LSL     = 1,
    LSR     = 1,
    ROL     = 1,
    ROR     = 1,
    ASR     = 1,
    SWAP    = 1,
    BSET    = 1,
    BCLR    = 1,
    SBI     = 1,
    CBI     = 1,
    BST     = 1,
    BLD     = 1,
    SEC     = 1,
    CLC     = 1,
    SEN     = 1,
    CLN     = 1,
    SEZ     = 1,
    SEI     = 1,
    CLI     = 1,
    SES     = 1,
    CLS     = 1,
    SEV     = 1,
    CLV     = 1,
    SET     = 1,
    CLT     = 1,
    SEH     = 1,
    CLH     = 1,
    BREAK   = 1,
    NOP     = 1,
    SLEEP   = 1,
    WDR     = 1
};

uint8_t wcet_calculate_clock_cycle(uint32_t opcode);

uint64_t wcet_calculate_clock_cycles(avr_t *avr);

#endif //__SIM_WCET_H__

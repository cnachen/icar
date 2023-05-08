#ifndef _CAR_H
#define _CAR_H

#include <stdint.h>
#include "motor.h"

enum {
    CAR_STOP = '0',
    CAR_FORWARD,
    CAR_BACKWARD,
    CAR_LEFT,
    CAR_RIGHT,
};

struct Car {
    uint8_t control;
    struct Motor motor;
    void (* update)(struct Car *);
    void (* set_control)(struct Car *, uint8_t);
};

struct Car Car_Init();

#endif
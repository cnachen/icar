#ifndef _MOTOR_H
#define _MOTOR_H

#include "main.h"

struct Motor {
    void (* left_forward)(struct Motor *);
    void (* right_forward)(struct Motor *);
    void (* left_backward)(struct Motor *);
    void (* right_backward)(struct Motor *);
    void (* left_stop)(struct Motor *);
    void (* right_stop)(struct Motor *);
};

struct Motor Motor_Init();

#endif
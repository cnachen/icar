#include "car.h"

static void update(struct Car *);
static void set_control(struct Car *, uint8_t);

struct Car Car_Init() {
    struct Car car = {
        .control = CAR_STOP,
        .motor = Motor_Init(),
        .update = update,
        .set_control = set_control,
    };

    return car;
}

static void update(struct Car * car) {
    switch (car->control) {
        case CAR_FORWARD:
            car->motor.left_forward(&car->motor);
            car->motor.right_forward(&car->motor);
            break;
        case CAR_BACKWARD:
            car->motor.left_backward(&car->motor);
            car->motor.right_backward(&car->motor);
            break;
        case CAR_LEFT:
            car->motor.left_backward(&car->motor);
            car->motor.right_forward(&car->motor);
            break;
        case CAR_RIGHT:
            car->motor.left_forward(&car->motor);
            car->motor.right_backward(&car->motor);
            break;
        default:
            car->motor.left_stop(&car->motor);
            car->motor.right_stop(&car->motor);
            break;
    }
}

static void set_control(struct Car *car, uint8_t control) {
    car->control = control;
}
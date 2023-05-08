#include "motor.h"

static void left_forward(struct Motor *);
static void right_forward(struct Motor *);
static void left_backward(struct Motor *);
static void right_backward(struct Motor *);
static void left_stop(struct Motor *);
static void right_stop(struct Motor *);

struct Motor Motor_Init() {
    struct Motor motor = {
        .left_forward = left_forward,
        .right_forward = right_forward,
        .left_backward = left_backward,
        .right_backward = right_backward,
        .left_stop = left_stop,
        .right_stop = right_stop,
    };

    return motor;
}

static void left_forward(struct Motor *) {
    // Front
    HAL_GPIO_WritePin(IN11_GPIO_Port, IN11_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(IN12_GPIO_Port, IN12_Pin, GPIO_PIN_RESET);
    // Rear
    HAL_GPIO_WritePin(IN21_GPIO_Port, IN21_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(IN22_GPIO_Port, IN22_Pin, GPIO_PIN_RESET);
}

static void right_forward(struct Motor *) {
    // Front
    HAL_GPIO_WritePin(IN13_GPIO_Port, IN13_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(IN14_GPIO_Port, IN14_Pin, GPIO_PIN_RESET);
    // Rear
    HAL_GPIO_WritePin(IN23_GPIO_Port, IN23_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(IN24_GPIO_Port, IN24_Pin, GPIO_PIN_RESET);
}

static void left_backward(struct Motor *) {
    // Front
    HAL_GPIO_WritePin(IN11_GPIO_Port, IN11_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN12_GPIO_Port, IN12_Pin, GPIO_PIN_SET);
    // Rear
    HAL_GPIO_WritePin(IN21_GPIO_Port, IN21_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN22_GPIO_Port, IN22_Pin, GPIO_PIN_SET);
}

static void right_backward(struct Motor *) {
    // Front
    HAL_GPIO_WritePin(IN13_GPIO_Port, IN13_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN14_GPIO_Port, IN14_Pin, GPIO_PIN_SET);
    // Rear
    HAL_GPIO_WritePin(IN23_GPIO_Port, IN23_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN24_GPIO_Port, IN24_Pin, GPIO_PIN_SET);
}

static void left_stop(struct Motor *) {
    // Front
    HAL_GPIO_WritePin(IN11_GPIO_Port, IN11_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN12_GPIO_Port, IN12_Pin, GPIO_PIN_RESET);
    // Rear
    HAL_GPIO_WritePin(IN21_GPIO_Port, IN21_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN22_GPIO_Port, IN22_Pin, GPIO_PIN_RESET);
}

static void right_stop(struct Motor *) {
    // Front
    HAL_GPIO_WritePin(IN13_GPIO_Port, IN13_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN14_GPIO_Port, IN14_Pin, GPIO_PIN_RESET);
    // Rear
    HAL_GPIO_WritePin(IN23_GPIO_Port, IN23_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN24_GPIO_Port, IN24_Pin, GPIO_PIN_RESET);
}
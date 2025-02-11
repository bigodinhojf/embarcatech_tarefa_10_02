// -- Inclusão de bibliotecas
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "inc/ssd1306.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"

// -- Definição de constantes
// Display I2C
#define display_i2c_port i2c1 // Define a porta I2C
#define display_i2c_sda 14 // Define o pino SDA na GPIO 14
#define display_i2c_scl 15 // Define o pino SCL na GPIO 15
#define display_i2c_endereco 0x3C // Define o endereço do I2C
ssd1306_t ssd; // Inicializa a estrutura do display

// GPIO
#define button_A 5 // Define o Botão A na GPIO 5
#define LED_Green 11 // Define o LED Verde na GPIO 11
#define LED_Blue 12 // Define o LED Azul na GPIO 12
#define LED_Red 13 // Define o LED Vermelho na GPIO 13
#define joystick_PB 22 // Define o Push Button do Joystick na GPIO 22
#define joystick_Y 26 // Define o pino VRY do Joystick na GPIO 26
#define joystick_X 27 // Define o pino VRX do Joystick na GPIO 27

// PWM
#define pwm_wrap 4095 // Define o valor do Wrap

// Função para fazer a configuração de PWM para GPIO
void pwm_init_gpio(uint gpio, uint wrap){
    gpio_set_function(gpio, GPIO_FUNC_PWM); // Define a função da porta GPIO como PWM
    uint slice = pwm_gpio_to_slice_num(gpio); // Guarda o canal do PWM
    pwm_set_wrap(slice, wrap); // Define o valor do Wrap do canal correspondente
    pwm_set_enabled(slice, true); // Habilita o PWM no canal
}


int main()
{
    // -- Inicializações
    // Monitor serial
    stdio_init_all();

    // Display I2C
    i2c_init(display_i2c_port, 400 * 1000); // Inicializa o I2C usando 400kHz
    gpio_set_function(display_i2c_sda, GPIO_FUNC_I2C); // Define o pino SDA (GPIO 14) na função I2C
    gpio_set_function(display_i2c_scl, GPIO_FUNC_I2C); // Define o pino SCL (GPIO 15) na função I2C
    gpio_pull_up(display_i2c_sda); // Ativa o resistor de pull up para o pino SDA (GPIO 14)
    gpio_pull_up(display_i2c_scl); // Ativa o resistor de pull up para o pino SCL (GPIO 15)
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, display_i2c_endereco, display_i2c_port); // Inicializa o display
    ssd1306_config(&ssd); // Configura o display
    ssd1306_send_data(&ssd); // Envia os dados para o display
    ssd1306_fill(&ssd, false); // Limpa o display
    ssd1306_send_data(&ssd); // Atualiza o display

    // GPIO
    gpio_init(button_A); // Inicia a GPIO 5 do botão A
    gpio_set_dir(button_A, GPIO_IN); // Define a direção da GPIO 5 do botão A como entrada
    gpio_pull_up(button_A); // Habilita o resistor de pull up da GPIO 5 do botão A

    gpio_init(joystick_PB); // Inicia a GPIO 22 do botão do Joystick
    gpio_set_dir(joystick_PB, GPIO_IN); // Define a direção da GPIO 22 do botão do Joystick como entrada
    gpio_pull_up(joystick_PB); // Habilita o resistor de pull up da GPIO 22 do botão do Joystick
    
    gpio_init(LED_Green); // Inicia a GPIO 11 do LED Verde
    gpio_set_dir(LED_Green, GPIO_OUT); // Define a direção da GPIO 11 do LED Verde como saída
    gpio_put(LED_Green, false); // Estado inicial do LED apagado

    // PWM
    pwm_init_gpio(LED_Blue, pwm_wrap); // Inicia o PWM para a GPIO 12 do LED Azul
    pwm_init_gpio(LED_Red, pwm_wrap); // Inicia o PWM para a GPIO 13 do LED Vermelho

    // ADC
    adc_init();
    adc_gpio_init(joystick_Y); // Inicia o ADC para o GPIO 26 do VRY do Joystick
    adc_gpio_init(joystick_X); // Inicia o ADC para o GPIO 27 do VRX do Joystick

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}

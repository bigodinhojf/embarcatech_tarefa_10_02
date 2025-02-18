<div align="center">
    <img src="https://moodle.embarcatech.cepedi.org.br/pluginfile.php/1/theme_moove/logo/1733422525/Group%20658.png" alt="Logo Embarcatech" height="100">
</div>

<br>

# Conversor analógico-digital (ADC)

## Sumário

- [Descrição](#descrição)
- [Funcionalidades Implementadas](#funcionalidades-implementadas)
- [Ferramentas utilizadas](#ferramentas-utilizadas)
- [Objetivos](#objetivos)
- [Instruções de uso](#instruções-de-uso)
- [Vídeo de apresentação](#vídeo-de-apresentação)
- [Aluno e desenvolvedor do projeto](#aluno-e-desenvolvedor-do-projeto)
- [Licensa](#licença)

## Descrição

Este projeto implementa o controle de LEDs RGB e a exibição de um quadrado 8x8 móvel em um display SSD1306, utilizando um joystick analógico e o microcontrolador Raspberry Pi Pico W. O projeto consiste em fazer uso do conversor analógico-digital (ADC) para capturar os valores dos eixos X e Y do joystick, aplicar o PWM para controlar a intensidade dos LEDs Azul e Vermelho com base nos valores capturados e ainda fazer a movimentação de um quadrado de 8x8 pixels no display SSD1306, utilizando o protocolo de comunicação I2C. O botão do joystick é utilizado para alternar o estado do LED Verde e modificar a borda do display, enquanto o botão A ativa ou desativa os LEDs PWM. O projeto também implementa interrupções para os botões e debouncing via software, garantindo um funcionamento preciso e eficiente.

## Funcionalidades Implementadas

1. Controle de intensidade luminosa dos LEDs Azul e Vermelho:

  - O LED Azul tem seu brilho ajustado pelo valor do eixo Y do joystick, sendo apagado no centro e máximo nas extremidades cima e baixo.
  - O LED Vermelho tem seu brulho ajustado pelo valor do eixo X do joystick, sendo apagado no centro e máximo nas extremidades direita e esquerda.
  - Observei que o Joystick solto não fica com o valor central fixo de 2047, então fiz testes utilizando o monitor serial e defini os valores máximos e mínimos para considerar o joystick no centro para X e Y:
--------------------------------- AQUI ENTRA UMA IMAGEM ---------------------------------
  - Com esses valores desenvolvi as equações que definem o valor da intensidade de cada LED a partir de uma lógica de adimensionalização, o desenvolvimento das equações está exposto na imagem a seguir:
--------------------------------- AQUI ENTRA UMA IMAGEM ---------------------------------

2. Exibir um quadrado de 8x8 pixels no display que se move:

   - Um quadrado de 8x8 pixels é exibido no display e se move de acordo com os valores de X e Y do joystick.
   - As equações para definir a posição do quadrado foi desenvolvida seguindo a mesma lógica de adimensionalização.
  
3. Acionamento do botão A:

   - Ativa ou desativa os LEDs PWM.
    
4. Acionamento do botão do joystick:

   - Alterna o estado do LED Verde.
   - Modifica a borda do display, alternando entre diferentes estilos.
   - Desenvolvi uma função que exibe um retângulo pontilhado como borda, foi utilizado como base a função que desenha retângulos já implementada.

## Ferramentas utilizadas

- **Simulador de eletrônica wokwi**: Ambiente utilizado para simular o hardware e validar o funcionamento do sistema.
- **Ferramenta educacional BitDogLab (versão 6.3)**: Placa de desenvolvimento utilizada para programar o microcontrolador.
- **Microcontrolador Raspberry Pi Pico W**: Responsável pelo controle de todos os componentes utilizados.
- **Joystick**: Responsável por modificar a intensidade dos LEDs PWM, movimentar o quadrado 8x8 e mudar o estilop da borda no display e alternar o estado do LED Verde.
- **LED RGB**: O azul e o vermelho mudam sua intensidade de acordo com a movimentação do joystick e o verde alterna o estado com o acionamento do botão A.
- **Push button**: Responsável por ativar e desativar os LEDs PWM.
- **Visual Studio Code (VS Code)**: IDE utilizada para o desenvolvimento do código com integração ao Pico SDK.
- **Pico SDK**: Kit de desenvolvimento de software utilizado para programar o Raspberry Pi Pico W em linguagem C.
- **Monitor serial do VS Code**: Ferramenta utilizada para monitorar o valores lidos pelo ADC e realizar testes necessários na implementação.

## Objetivos

1. compreender o funcionamento do conversor analógico-digital (ADC) no RP2040.
2. Utilizar o **PWM** para controlar a intensidade de dois LEDs RGB com base nos valores do joystick.
3. Representar a posição do joystick no display **SSD1306** por meio de um quadrado móvel.
4. Aplicar o protocolo de comunicação I2C na integração com o display.

## Instruções de uso

1. **Clonar o Repositório**:

```bash
git clone https://github.com/bigodinhojf/embarcatech_tarefa_10_02.git
```

2. **Compilar e Carregar o Código**:
   No VS Code, configure o ambiente e compile o projeto com os comandos:

```bash	
cmake -G Ninja ..
ninja
```

3. **Interação com o Sistema**:
   - Conecte a placa ao computador.
   - Clique em run usando a extensão do raspberry pi pico.
   - Mova o Joystick para observar a mudança de intensidade dos LEDs Azul e Vermelho e a movimentação do quadrado no display.
   - Clique no botão A e mova o joystick para observar que os LEDs PWM estão desativados.
   - Clique no botão do joystick para observar a mudança de estilo da borda no display.

## Vídeo de apresentação

O vídeo apresentando o projeto pode ser assistido [clicando aqui](https://youtu.be/mVY0w1Lo0Og).

## Aluno e desenvolvedor do projeto

<a href="https://github.com/bigodinhojf">
        <img src="https://github.com/bigodinhojf.png" width="150px;" alt="João Felipe"/><br>
        <sub>
          <b>João Felipe</b>
        </sub>
</a>

## Licença

Este projeto está licenciado sob a licença MIT.

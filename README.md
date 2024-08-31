# Controle para MeArm
Código para o controle do braço robótico [MeArm](https://www.instructables.com/Pocket-Sized-Robot-Arm-meArm-V04/). Este projeto permite controlar o MeArm utilizando dois módulos joystick conectados em um Arduino, com um controle manual e além do modo automático que movimenta os servos em uma sequência predefinida.

## Componentes Ultilizados
- 1 x Arduino Uno (ou compatível)
- 4 x Servomotores
- 2 x Módulos Joystick
- 1 x Botão
- 1 x LED
- 1 x Capacitor eletrolítico de 1000uF
- Resistores, fios e protoboard

## Como Usar
**Montagem:** Conecte os componentes ao Arduino conforme o modelo.
**Carregue o Código:** Abra o arquivo ```controle.ino``` no IDE do Arduino e faça o upload para o seu Arduino.

![image](https://github.com/user-attachments/assets/277067b0-7adb-4dff-9a59-5b3f92301a96)


## Operação:

**Modo Manual:** Controle os servos diretamente usando os joysticks.
**Modo Automático:** Pressione o botão para alternar para o modo automático. O LED acenderá para indicar que o modo automático está ativo. Para retornar ao controle manual, pressione o botão novamente.
image

## Observações
- Lembre-se de verificar os angulos passados para os servos antes de executar o código, evitando que os motores sejam forçados.
- **Velocidade de Movimento:** Altere a variável velocidade para ajustar a rapidez com que os servos se movem.
- **Zona Morta:** Modifique a variável zonaMorta para ajustar apartir de qual posição dos joysticks os motores serão acionados.

## Links:
- [MeArm](https://www.instructables.com/Pocket-Sized-Robot-Arm-meArm-V04/)
- [TinkerCard](https://www.tinkercad.com/things/3Cn2Zm6O56a-robot-arm)

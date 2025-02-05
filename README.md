# Projeto U4C5-1

Este é um projeto de atividade do Embarcatech, um curso de desenvolvimento de software embarcado.

## Descrição

O projeto consiste em controlar três LEDs (vermelho, amarelo e verde) conectados a um microcontrolador. Os LEDs acendem em sequência com um intervalo de 3 segundos entre cada mudança.

## Hardware Necessário

- Microcontrolador compatível com a biblioteca Pico SDK
- LEDs (vermelho, amarelo e verde)
- Resistores apropriados para os LEDs
- Fios de conexão

## Configuração dos Pinos

- LED Vermelho: Pino 11
- LED Amarelo: Pino 12
- LED Verde: Pino 13

## Compilação e Execução

1. Instale o Pico SDK e configure o ambiente de desenvolvimento conforme a documentação oficial.
2. Clone este repositório.
3. Navegue até o diretório do projeto.
4. Compile o código com o comando:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```
5. Carregue o binário gerado no microcontrolador.

## Execução

Após carregar o binário no microcontrolador, os LEDs começarão a piscar em sequência com um intervalo de 3 segundos entre cada mudança.

## Autor

Reinan Lopes Argolo
Este projeto foi desenvolvido como parte do curso Embarcatech.

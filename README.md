# Biblioteca B_events

Biblioteca para detecção de eventos de botão com Arduino.

## Recursos
- Detecção de clicks curtos
- Detecção de clicks longos (tempo configurável)
- Estado atual do botão (pressionado/solto)
- Debounce integrado
- Suporte para pull-up interno e externo

## Instalação
1. Baixe o ZIP da biblioteca
2. No Arduino IDE: Sketch > Incluir Biblioteca > Adicionar Biblioteca .ZIP
3. Selecione o arquivo baixado

## Exemplo Básico

```cpp
#include <B_events.h>

B_events button(2, true); // Pino 2 com pull-up interno

void setup() {
    Serial.begin(9600);
}

void loop() {
    button.update();
    
    if(button.shortPress()) {
        Serial.println("Click curto detectado!");
    }
    
    if(button.longPress()) {
        Serial.println("Click longo detectado!");
    }
    
    if(button.isPressed()) {
        Serial.println("Botão pressionado...");
    }
}
```

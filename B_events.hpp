#ifndef B_EVENTS_H
#define B_EVENTS_H

#include "Arduino.h"

/**
 * @brief Biblioteca para detecção avançada de eventos de botão
 *
 * Detecta clicks curtos, longos e mantém estado de pressionado
 * com debounce integrado e suporte para pull-up interno/externo
 */
class B_events {
public:
    /**
     * @brief Construtor da classe
     * @param pin Pino digital onde o botão está conectado
     * @param level true para pull-up interno (HIGH quando solto)
     * @param longPressTime Tempo em ms para considerar click longo (padrão: 500ms)
     */
    B_events(uint8_t pin, bool level, unsigned long longPressTime = 500);

    /**
     * @brief Deve ser chamado no loop() principal
     */
    void update();

    /**
     * @brief Verifica se ocorreu um click curto
     * @return true se ocorreu um click curto (auto-reset)
     */
    bool shortPress();

    /**
     * @brief Verifica se ocorreu um click longo
     * @return true se ocorreu um click longo (auto-reset)
     */
    bool longPress();

    /**
     * @brief Verifica se o botão está pressionado no momento
     * @return true se o botão está atualmente pressionado
     */
    bool isPressed();

private:
    uint8_t _pin;
    bool _level;
    unsigned long _pressStartTime;
    bool _lastState;
    unsigned long _longPressTime;
    bool _shortPressFlag;
    bool _longPressFlag;
    bool _currentPress;
};

#endif

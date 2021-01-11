#pragma once

#include <eventSystem/listeners/areaListener.h>
#include <vector>

// Añade un evento a la cola
void init();

void addEventQueue(AreaEvent event);

// Añade un listener
void addListener(AreaListener* listener, int idEntity);

// Añade los eventos
void pollEvents();

// Llama a los listeners
void callEvents();
#pragma once

#include <eventSystem/areaEventSystem.h>
#include <tools/memory/queue.h>

#define MAX_QUEUE_EVENTS 16
#define MAX_LISTENERS   256

Queue<AreaEvent> queueEvents(16);
std::vector<AreaListener*> listeners;
std::vector<int> idEntityListeners;

void init()
{
    listeners.reserve(MAX_LISTENERS);
    idEntityListeners.reserve(MAX_LISTENERS);
}

// Añade un evento a la cola
void addEventQueue(AreaEvent event)
{
    queueEvents.push(event);
}

// Añade un listener
void addListener(AreaListener* listener, int idEntity)
{
    listeners.emplace_back(listener);
    idEntityListeners.emplace_back(idEntity);
}

// Añade los eventos
void pollEvents()
{
    
}

// Llama a los listeners
void callEvents()
{
    // Llamar a los listeners y eliminar los eventos
    for (int j = 0; j < queueEvents.totalReserve(); j++)
    {
        const AreaEvent& phyEvent = queueEvents.at(j);

        for (int i = 0; i < listeners.size(); i++)
        {
            if (idEntityListeners[i] == phyEvent.idEntity)
            {
                if (phyEvent.typeEventArea == TypeEventArea::INAREA)
                {
                    listeners[i]->inArea(phyEvent);
                }
                else if (phyEvent.typeEventArea == TypeEventArea::OUTAREA)
                {
                    listeners[i]->outArea(phyEvent);
                }
                
            }
        }
    }

    queueEvents.clear({-1, -1});
}
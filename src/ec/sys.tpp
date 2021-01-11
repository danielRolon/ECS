#include <ec/sys.h>
#include <iostream>

template <typename TComponent>
TComponent&       createComponentGeneral(TComponent* components, int& countComponents, int idEntity)
{
    auto& cmp = components[countComponents++];
    cmp.idEntity = idEntity;
    return cmp;
}

template <typename TComponent>
void              destroyComponentGeneral(TComponent* components, int& countComponents, int idEntity)
{
    auto& lastCmp = components[countComponents-1];
    
    for (int i = 0; i < countComponents; ++i)
    {
        auto& cmp = components[i];
        if (cmp.idEntity == idEntity)
        {
            cmp = lastCmp;
            countComponents--;
            return;
        }
    }

    std::cout << "Not exist this id entity\n";
}

template <typename TComponent>
TComponent&       getComponentGeneral(TComponent* components, int countComponents, int idEntity)
{
    for (int i = 0; i < countComponents; ++i)
    {
        auto& cmp = components[i];

        if (cmp.idEntity == idEntity)
        {
            return cmp;
        }
    }

    //std::cout << "Not exist this id entity: " << idEntity << "\n";

    static TComponent component_static;

    return component_static;
}

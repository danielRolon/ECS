#include <ec/sys/physys.h>
#include <ec/cmp/rencmp.h>
#include <ec/sys/areasys.h>

#define MAX_COMPONENTS 255

inline int countPhysicsComponents = 0;

inline PhysicsComponent *physicsComponents = new PhysicsComponent[MAX_COMPONENTS];

inline bool collision1(const PhysicsComponent& phyCmp0, const PhysicsComponent& phyCmp1);

template<> inline PhysicsComponent& createComponent<PhysicsComponent>(int idEntity) {
    createComponentGeneral(physicsComponents, countPhysicsComponents, idEntity);
}

template<> inline void              destroyComponent<PhysicsComponent>(int idEntity) {
    destroyComponentGeneral<PhysicsComponent>(physicsComponents, countPhysicsComponents, idEntity);
}

template<> inline PhysicsComponent& getComponent<PhysicsComponent>(int idEntity) {
    getComponentGeneral<PhysicsComponent>(physicsComponents, countPhysicsComponents, idEntity);
}

template<>
void inline update<PhysicsComponent>()
{
    for (int i = 0; i < countPhysicsComponents; i++)
    {
        auto& phyCmp = physicsComponents[i];
        auto oldPhyCmp = phyCmp;

        // Update Speed
        phyCmp.x += phyCmp.vx;
 
        // collision1 horizontal
        for (int j = 0; j < countPhysicsComponents; j++)
        {
            if (i == j) continue;
            auto& phyCmp_compare = physicsComponents[j];

            if (collision1(phyCmp, phyCmp_compare))
            {
                phyCmp.x -= phyCmp.vx;
                phyCmp.vx = 0;
                break;
            }
        }

        oldPhyCmp.y += phyCmp.vy;

        // collision1 vertical
        for (int j = 0; j < countPhysicsComponents; j++)
        {
            if (i == j) continue;
            auto& phyCmp_compare = physicsComponents[j];

            if (collision1(oldPhyCmp, phyCmp_compare))
            {
                phyCmp.vy = 0;
                break;
            }
        }

        phyCmp.y += phyCmp.vy; // Solitario

        // Get other components
        auto& renCmp = getComponent<RendererComponent>(phyCmp.idEntity);
        auto& areaCmp = getComponent<AreaComponent>(phyCmp.idEntity);

        // Sum velocity to render component
        renCmp.x += phyCmp.vx;
        renCmp.y += phyCmp.vy;
        areaCmp.x += phyCmp.vx;
        areaCmp.y += phyCmp.vy;
        
    }
}

bool collision1(const PhysicsComponent& p0, const PhysicsComponent& p1)
{
    float left   = p0.x;
    float right  = p0.x + p0.w;
    float up     = p0.y;
    float bottom = p0.y + p0.h;

    float left_other   = p1.x;
    float right_other  = p1.x + p1.w;
    float up_other     = p1.y;
    float bottom_other = p1.y + p1.h;

    return (left < right_other && right > left_other && up < bottom_other && bottom > up_other);
}
#include <ec/sys/areasys.h>
#include <eventSystem/areaEventSystem.h>
#include <tools/render.h>

#define MAX_COMPONENTS 255

inline int countareaComponents = 0;

inline AreaComponent *areaComponents = new AreaComponent[MAX_COMPONENTS];

inline bool collision(const AreaComponent& phyCmp0, const AreaComponent& phyCmp1);

template<> inline AreaComponent& createComponent<AreaComponent>(int idEntity) {
    createComponentGeneral(areaComponents, countareaComponents, idEntity);
}

template<> inline void              destroyComponent<AreaComponent>(int idEntity) {
    destroyComponentGeneral<AreaComponent>(areaComponents, countareaComponents, idEntity);
}

template<> 
inline AreaComponent& getComponent<AreaComponent>(int idEntity) {
    getComponentGeneral<AreaComponent>(areaComponents, countareaComponents, idEntity);
}

template<>
void inline update<AreaComponent>()
{
    for (int i = 0; i < countareaComponents; i++)
    {
        auto& areaCmp = areaComponents[i];
        bool firtsColl = false;

        for (int j = i+1; j < countareaComponents; j++)
        {
            auto& areaCmp_compare = areaComponents[j];

            if (collision(areaCmp, areaCmp_compare))
            {
                if (!areaCmp.collide)
                {
                    addEventQueue({areaCmp.idEntity, areaCmp_compare.idEntity, TypeEventArea::INAREA});
                    addEventQueue({areaCmp_compare.idEntity, areaCmp.idEntity, TypeEventArea::INAREA});
                    areaCmp.collide = true;
                }
                firtsColl = true;
            }
            else
            {
                if (areaCmp.lastCollide)
                {
                    addEventQueue({areaCmp.idEntity, areaCmp_compare.idEntity, TypeEventArea::OUTAREA});
                    addEventQueue({areaCmp_compare.idEntity, areaCmp.idEntity, TypeEventArea::OUTAREA});
                }
                
                areaCmp.collide = false;
            }



            if (areaCmp.lastCollide != areaCmp.collide)
            {
                areaCmp.lastCollide = areaCmp.collide;
            }

            if (firtsColl)
                break;
        }

        //draw
        Renderer2D::SetAlpha(0.5);
        Renderer2D::SetColor(100, 0, 100);
        Renderer2D::DrawRect(areaCmp.x, areaCmp.y, areaCmp.w, areaCmp.h);
        Renderer2D::SetAlpha(1.0);
    }
}

bool collision(const AreaComponent& p0, const AreaComponent& p1)
{
    float left   = p0.x;
    float right  = p0.x + p0.w;
    float up     = p0.y;
    float bottom = p0.y + p0.h;

    float left_other   = p1.x;
    float right_other  = p1.x + p1.w;
    float up_other     = p1.y;
    float bottom_other = p1.y + p1.h;

    return (left <= right_other && right >= left_other && up <= bottom_other && bottom >= up_other);
}
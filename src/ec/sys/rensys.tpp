#include <ec/sys/rensys.h>
#include <tools/render.h>

#define MAX_renderComponents 255

inline int countrendererrenderComponents = 0;

inline RendererComponent *renderComponents = new RendererComponent[MAX_renderComponents];

template<> inline RendererComponent& createComponent<RendererComponent>(int idEntity) {
    createComponentGeneral(renderComponents, countrendererrenderComponents, idEntity);
}

template<> inline void               destroyComponent<RendererComponent>(int idEntity) {
    destroyComponentGeneral<RendererComponent>(renderComponents, countrendererrenderComponents, idEntity);
}

template<> inline RendererComponent&  getComponent<RendererComponent>(int idEntity) {
    getComponentGeneral<RendererComponent>(renderComponents, countrendererrenderComponents, idEntity);
}

template <> 
inline void update<RendererComponent>()
{
    for (int i = 0; i < countrendererrenderComponents; i++)
    {
        auto& cmp = renderComponents[i];
        Renderer2D::SetColor(cmp.rgb.R, cmp.rgb.G, cmp.rgb.B);
        Renderer2D::FillRect(cmp.x, cmp.y, cmp.w, cmp.h);
    }
}
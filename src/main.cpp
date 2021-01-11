#include <tools/render.h>
#include <tools/keyboard/keyboard.h>

#include <load/loadRender.h>
#include <load/loadPhysics.h>
#include <load/loadArea.h>

#include <ec/ec.h>

#include <eventSystem/AreaEventSystem.h>

bool run = true;


class Player : public AreaListener
{
public:
    Player() {}

    void inArea(AreaEvent areaEvent) override
    {
        std::cout << "InArea id: " << areaEvent.idEntityCollide << "\n";
        auto& phyCmp = getComponent<PhysicsComponent>(areaEvent.idEntityCollide);
        phyCmp.vx *= -1;
    }

    void outArea(AreaEvent areaEvent) override
    {
        std::cout << "OutArea\n";
    }
};

int main(int argc, char* args[])
{
    Renderer2D::CreateWindow("EC", 640, 480);

    addSystem(update<RendererComponent>);
    addSystem(update<PhysicsComponent>);
    addSystem(update<AreaComponent>);

    loadCmp<RendererComponent>("res/map.json");
    loadCmp<PhysicsComponent>("res/map.json");
    loadCmp<AreaComponent>("res/map.json");

    init(); // reservar memoria para el area event system

    Player* player = new Player();
    addListener(player, 50);

    auto& phyCmp = getComponent<PhysicsComponent>(50);

    while(run)
    {
        Renderer2D::PollEvents();

        if (Renderer2D::GetEvent().type == SDL_QUIT || Keyboard::KeyPress(VK_ESCAPE))
        {
            run = false;
        }

        phyCmp.vx = Keyboard::KeyPress('D') - Keyboard::KeyPress('A');
        phyCmp.vy = Keyboard::KeyPress('S') - Keyboard::KeyPress('W');

        Renderer2D::Clear();
        updateAllSystems();
        callEvents();
        Renderer2D::Refresh();
    }

    Renderer2D::DestroyWindow();
}
#include "example_script.hpp"
#include <EngiNL.hpp>

using namespace EngiNL;
int main(int argc, char **argv) {
    Engine engine;
    auto& scene1 = engine.PushScene();
    auto entity = scene1.AddEntity();
    entity.AddComponents(
        Component::Transform{
            Math::Vector2{0, 0},
            Math::Vector2{50, 50},
            0},
        Component::SpriteRenderer{
            .id = 0,
            .texture = engine.GetAssetManager().GetTexture("test", "resources/test.bmp")
            }
    );
    entity.AddComponent<Script>();
    engine.Run();
    return 0;
}

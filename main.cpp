#include <EngiNL.hpp>
#include <random>

struct ExampleScript : EngiNL::IScript{
    using IScript::IScript;

    const float m_speed = 10.0f;

    void start() override {

    }

    void update() override {
        self().GetComponent<EngiNL::Component::Transform>()->position.x += m_speed*(static_cast<float>(self().GetScene()->DeltaTime()) / 1000.0f);
        if(self().GetComponent<EngiNL::Component::Transform>()->position.x > 1000) {
            self().GetComponent<EngiNL::Component::Transform>()->position.x = -1000;
        }
    }
};

using namespace EngiNL;
int main(int argc, char **argv) {
    Engine engine;
    auto& scene1 = engine.PushScene();

    std::random_device rd;
    std::mt19937 re(rd());
    std::uniform_real_distribution<float> dis_pos(-1000.0, 1000.0);
    std::uniform_real_distribution<float> dis_siz(1, 50);
    for(auto i = 0u; i < 10000; i++) {
        auto entity = scene1.AddEntity();
        entity.AddComponents(
            Component::Transform{
                Math::Vector2{dis_pos(re), dis_pos(re)},
                Math::Vector2{dis_siz(re), dis_siz(re)},
                0},
            Component::SpriteRenderer{
                .id = 0,
                .texture = engine.GetAssetManager().GetTexture("test", "resources/test.bmp")
                },
            ExampleScript{}
    );
    }
    engine.Run();
    return 0;
}

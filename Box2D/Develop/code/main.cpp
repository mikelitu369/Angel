//
// Este código es de dominio público.
// angel.rodriguez@esne.edu
// 2021.03+
//
// Controles:
//
//   Espacio: aplicar impulso hacia arriba.
//   Izquierda/derecha: aplicar fuerza de giro.
//   Click->Arrastrar->soltar: aplicar impulso en la dirección seleccionada.
//

#include <ciso646>
#include <memory>
#include <vector>
#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <circle.hpp>
#include <cube.hpp>
#include <car.hpp>

#include<render.hpp>

using namespace sf;
using namespace std;
using namespace MKbox2D;

#undef main

namespace
{

    b2Body* create_edge(b2World& physics_world, b2BodyType body_type, float x0, float y0, float x1, float y1)
    {
        // Se crea el body:

        b2BodyDef body_definition;

        body_definition.type = body_type;
        body_definition.position.Set(0.f, 0.f);                        // Posición inicial absoluta

        b2Body* body = physics_world.CreateBody(&body_definition);

        // Se añande una fixture:

        b2EdgeShape body_shape;

        body_shape.SetTwoSided(b2Vec2(x0, y0), b2Vec2(x1, y1));        // Coordenadas locales respecto al centro del body

        b2FixtureDef body_fixture;

        body_fixture.shape = &body_shape;

        body->CreateFixture(&body_fixture);

        return body;
    }

    struct Input_Status
    {
        bool  mouse_was_clicked = false;
        float click_start_x = 0;
        float click_start_y = 0;
        float current_mouse_x = 0;
        float current_mouse_y = 0;
    };

    // ------------------------------------------------------------------------------------------ //

    bool process(Window& window)
    {
        Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::KeyPressed:
            {
                switch (event.key.code)
                {
                case Keyboard::Left:
                {
                    break;
                }
                case Keyboard::Right:
                {
                    break;
                }
                case Keyboard::Up:
                {
                    break;
                }
                case Keyboard::Down:
                {
                    break;
                }
                }

                break;
            }
            case Event::Closed:
            {
                return true;
            }
            }
        }

        return false;
    }
}


int main()
{
    constexpr auto window_width = 1800u;
    constexpr auto window_height = 900u;

    RenderWindow window(VideoMode(window_width, window_height), "Box2D Forces", Style::Titlebar | Style::Close, ContextSettings(32));

    window.setVerticalSyncEnabled(true);


    b2World physics_world{ b2Vec2{ 0, -10.f } };

    constexpr float left = 0.01f;
    constexpr float right = 18.0f;
    constexpr float top = 9.0f;
    constexpr float bottom = 0.01f;

    create_edge(physics_world, b2_staticBody, left, bottom, right, bottom);
    create_edge(physics_world, b2_staticBody, left, bottom, left, top);
    create_edge(physics_world, b2_staticBody, left, top, right, top);
    create_edge(physics_world, b2_staticBody, right, bottom, right, top);

    create_edge(physics_world, b2_staticBody, left, top/2, right, bottom);

    Car car(physics_world, b2_dynamicBody, 9, 4, 0.2f, 1, 0.1f);
    
    while (true)
    {
        physics_world.Step(1.0f / 60.0f, 8,4);

        window.clear();
        Render::render(physics_world, window, 100.0f);
        window.display();
    }
    return 0;
}

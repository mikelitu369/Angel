


#include <default_scene.hpp>
#include <car.hpp>
#include <input.hpp>
#include <edge.hpp>


namespace MKbox2D
{
    SceneDefault::SceneDefault()
    {
        constexpr auto window_width = 1800u;
        constexpr auto window_height = 900u;

        window = new RenderWindow(VideoMode(window_width, window_height), "Box2D Forces", Style::Titlebar | Style::Close, ContextSettings(32));

        window->setVerticalSyncEnabled(true);

        world = new b2World(b2Vec2{ 0, -10.f });

        constexpr float left = 0.01f;
        constexpr float right = 18.0f;
        constexpr float top = 9.0f;
        constexpr float bottom = 0.01f;

        //Margenes
        Add_object(new Edge(*world, b2_staticBody, left, bottom, left, top));
        Add_object(new Edge(*world, b2_staticBody, left, top, right, top));
        Add_object(new Edge(*world, b2_staticBody, right, bottom, right, top));

        //Primera plataforma
        Add_object(new Edge(*world, b2_staticBody, left, top / 2, left + 2.5, top/2));

        //Rampa
        Add_object(new Edge(*world, b2_staticBody, left + 2.5, top / 2, left + 4, top / 2 - 1));
        Add_object(new Edge(*world, b2_staticBody, left + 4, top / 2 - 1, left + 7, top / 2 - 2));
        Add_object(new Edge(*world, b2_staticBody, left + 7, top / 2 - 2, left + 9, top / 2 - 2));
        Add_object(new Edge(*world, b2_staticBody, left + 9, top / 2 - 2, left + 11, top / 2 - 1.5));

        //Plataforma 2
        Add_object(new Edge(*world, b2_staticBody, right, top / 5, right - 4, top / 5));


        Car* car = new Car(*world, b2_dynamicBody, 1.5, 7, 0.2f, 1, 0.1f);
        Add_object(car);
        

    }


    void SceneDefault::Proces()
    {
        Event event;

        while (window->pollEvent(event))
        {
            switch (event.type)
            {
            case Event::KeyPressed:
            {
                switch (event.key.code)
                {
                case Keyboard::Left:
                {
                    Input::instance().horizontal -= 1;
                    break;
                }
                case Keyboard::Right:
                {
                    Input::instance().horizontal += 1;
                    break;
                }
                case Keyboard::Up:
                {
                    Input::instance().vertical += 1;
                    break;
                }
                case Keyboard::Down:
                {
                    Input::instance().vertical -= 1;
                    break;
                }
                }

                break;
            }
            case Event::KeyReleased:
            {
                switch (event.key.code)
                {
                case Keyboard::Left:
                {
                    Input::instance().horizontal += 1;
                    break;
                }
                case Keyboard::Right:
                {
                    Input::instance().horizontal -= 1;
                    break;
                }
                case Keyboard::Up:
                {
                    Input::instance().vertical -= 1;
                    break;
                }
                case Keyboard::Down:
                {
                    Input::instance().vertical += 1;
                    break;
                }
                }

                break;
            }
            }
        }

        Input::instance().horizontal = Utils::clamp(Input::instance().horizontal, -1, 1);
        Input::instance().vertical = Utils::clamp(Input::instance().vertical, -1, 1);

    }


    void SceneDefault::Update()
    {
        for (Object* obj : objectos)
        {
            obj->Update();
        }
    }

    void SceneDefault::Run()
    {
        while (active)
        {
            Proces();
            Update();

            world->Step(1.0f / 60.0f, 8, 4);

            window->clear();
            render_system->render(*world, *window, 100.0f);
            window->display();
        }
    }

    void SceneDefault::Add_object(Object* new_object)
    {
        objectos.push_back(new_object);
    }
}
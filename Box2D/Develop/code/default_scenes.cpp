


#include <default_scene.hpp>


namespace MKbox2D
{
    void SceneDefault::Proces()
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
                    horizontal -= 1;
                    break;
                }
                case Keyboard::Right:
                {
                    horizontal += 1;
                    break;
                }
                case Keyboard::Up:
                {
                    vertical += 1;
                    break;
                }
                case Keyboard::Down:
                {
                    vertical -= 1;
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
                    horizontal += 1;
                    break;
                }
                case Keyboard::Right:
                {
                    horizontal -= 1;
                    break;
                }
                case Keyboard::Up:
                {
                    vertical -= 1;
                    break;
                }
                case Keyboard::Down:
                {
                    vertical += 1;
                    break;
                }
                }

                break;
            }
            }
        }
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

            world.Step(1.0f / 60.0f, 8, 4);

            window.clear();
            render_system->render(world, window, 100.0f);
            window.display();
        }

    }
}


#include <ciso646>
#include <memory>
#include <vector>
#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{
	constexpr auto window_width = 800u;
	constexpr auto window_height = 600u;

	RenderWindow window(VideoMode(window_width, window_height), "Box2D Forces", Style::Titlebar | Style::Close, ContextSettings(32));

	return 0;
}
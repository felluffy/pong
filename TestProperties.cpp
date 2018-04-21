/*
#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	sf::CircleShape shape;
	shape.setRadius(100.f);
	shape.setOrigin(100.f, 100.f);
	//shape.setPosition(1280 / 2.f, 720 / 2.f);
	shape.setFillColor(sf::Color::Green);

	std::cout << "RAadius " << shape.getRadius() << " ball position " << shape.getPosition().x << " " << shape.getPosition().y << std::endl;
	float x = 1.f, y = 1.f;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		shape.move(x, y);
		std::cout << "RAadius " << shape.getRadius() << " ball position " << shape.getPosition().x << " " << shape.getPosition().y << std::endl;
		window.clear(sf::Color::Red);
		if (shape.getPosition().x >= 720.f)
			system("pause");
		window.draw(shape);
		window.display();
	}

	return 0;
}
*/

/*#include "menu.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "diffSelection.hpp"


//GIMP image which is supposed to work...
static const struct {
	unsigned int 	 width;
	unsigned int 	 height;
	unsigned int 	 bytes_per_pixel; /* 3:RGB, 4:RGBA */
/*
unsigned char	 pixel_data[32 * 32 * 4 + 1];
} sfml_icon = {
32, 32, 4,
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\24\261'\15\15\255';\14\260)"
"j\15\257(\231\15\257(\240\14\257(\223\15\260(\207\14\256'{\16\256'n\16\260"
"(G\0\252\0\3\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\14\256#\26\15\260(t\15\256(\256\15\257(\335"
"\15\257(\376\15\257(\377\15\257(\377\15\257(\377\15\257(\377\15\257(\377"
"\15\257(\377\15\257(\377\15\257(\377\15\257(\377\15\256(\344\15\257(\206"
"\15\256(&\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\14\257(@\16\257'\250\15\257"
"(\371\15\257(\377\15\257(\377\15\257(\377\15\257(\371\16\257(\316\15\256"
"(\236\16\256'n\16\260)^\16\257(l\15\257(y\15\257(\206\16\257)\226\15\257"
")\334\15\257(\377\15\257(\377\15\257(\377\16\260)\252\0\266$\7\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\21\252\"\17\16\257)p\15\260(\327\15\257(\377"
"\15\257(\377\15\257(\372\16\260)\252\16\257)]\13\261'.\0\2313\5\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\0\377\0\1\14\261)>\15\257(\237\14\257(\365\15"
"\257(\377\16\257'\274\0\252\0\3\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\13\260)D\15\256(\344\15\257(\377"
"\15\257(\377\16\257'\342\14\257'|\13\252+\30\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\13\257+0\15\257(\351\15\257(\377\15\256"
"(_\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\0\237\40\10\14"
"\257'\217\15\257(\376\15\257(\377\15\260(\307\15\261'N\0\252\0\3\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\15\256(_\15\257(\377\14\257(\315\377\377\377\0\377"
"\377\377\0\377\377\377\0\13\256&/\15\256(\324\15\257(\377\15\257(\372\15"
"\260(z\0\252\0\3\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\14\252$\25\15\257(\377\15\257(\352\377\377\377\0\377\377\377\0\16\254"
")%\15\257(\362\15\257(\377\15\260(\327\17\257(3\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\17\257$#\15"
"\257(\377\15\257(\354\377\377\377\0\0\266$\7\16\257'\317\15\257(\377\15\257"
"(\262\0\252\34\11\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\15\260(z\15\257(\377\15\256"
"(\253\377\377\377\0\16\257)\226\15\257(\377\15\257(\335\21\252\"\17\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\17\255)2\15\257(\370\15\257(\377\15\256'O\15\260(M\15"
"\257(\377\15\257(\370\17\255)2\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\21\252\"\17\15"
"\257(\335\15\257(\377\15\260(\232\377\377\377\0\15\256(\253\15\257(\377\15"
"\260(z\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\0\252\34\11\15\257(\262\15\257(\377\15"
"\257(\320\0\237\40\10\377\377\377\0\15\257(\354\15\257(\377\17\257$#\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\17\257(3\15\260(\327\15\257(\377\15\257(\362\16\254)%\377\377"
"\377\0\377\377\377\0\15\257(\352\15\257(\377\14\252$\25\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\0\252\0\3\15\260(z\15\257(\372"
"\15\257(\377\15\256(\324\13\256&/\377\377\377\0\377\377\377\0\377\377\377"
"\0\14\257(\315\15\257(\377\15\256(_\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\0\252"
"\0\3\15\261'N\15\260(\307\15\257(\377\15\257(\376\14\257'\217\0\237\40\10"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\15\256(_\15\257"
"(\377\15\257(\351\13\257+0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\13\252+\30\14\257'|\16\257'\342\15\257(\377\15\257(\377"
"\15\256(\344\13\260)D\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\0\252\0\3\16\257'\274\15\257(\377\14\257("
"\365\15\257(\237\14\261)>\0\377\0\1\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\0\2313\5\13\261'.\16\257)]\16\260)\252\15\257(\372\15\257(\377\15\257(\377"
"\15\260(\327\16\257)p\21\252\"\17\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\0\266$\7\16\260)\252\15\257(\377\15\257(\377\15\257(\377\15\257)\334\16"
"\257)\226\15\257(\206\15\257(y\16\257(l\16\260)^\16\256'n\15\256(\236\16"
"\257(\316\15\257(\371\15\257(\377\15\257(\377\15\257(\377\15\257(\371\16"
"\257'\250\14\257(@\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\15\256(&\15\257"
"(\206\15\256(\344\15\257(\377\15\257(\377\15\257(\377\15\257(\377\15\257"
"(\377\15\257(\377\15\257(\377\15\257(\377\15\257(\377\15\257(\376\15\257"
"(\335\15\256(\256\15\260(t\14\256#\26\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\0\252\0\3\16\260"
"(G\16\256'n\14\256'{\15\260(\207\14\257(\223\15\257(\240\15\257(\231\14\260"
")j\15\255';\24\261'\15\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377"
"\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377"
"\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377"
"\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0"
"\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0\377\377\377\0",
};

const float pi = 3.14159;

const sf::Vector2f paddleDimensions = sf::Vector2f(10.f, 100.f);
const float width = 1280.f, height = 720.f;
const float offset = 10.f;
const float radius = 6.f;
const float speed = 300.f;

int main()
{

	//	enum difficulty{	easy = 0, not_noob = 1	};
	diffSelection diffs(width, height);
	Menu menu(width, height);
	std::srand(static_cast<unsigned> (std::time(NULL)));
	sf::RectangleShape top, mid, left, right, bottom;
	sf::RectangleShape leftPaddle, rightPaddle;
	sf::CircleShape ball;
	sf::Text leftScore;
	sf::Text rightScore;
	sf::SoundBuffer buff;
	bool isInMenu = true;
	if (!buff.loadFromFile(std::string("resources/ball.wav")))
	{
		std::cerr << "couldn't load sound";
	}
	sf::Sound sound(buff);
	sf::Vector2f prevLeftPaddlePos, prevRightPaddlePos;
	std::size_t scoreLeft = 0, scoreRight = 0;
	bool goingUp = false;
	bool goingDown = false;
	bool goingRight = false;
	bool goingLeft = false;


	leftPaddle.setSize(paddleDimensions);
	leftPaddle.setOrigin(paddleDimensions.x / 2.f, paddleDimensions.y / 2.f);
	leftPaddle.setPosition(offset + paddleDimensions.x / 2.f, height / 2.f);
	rightPaddle.setSize(paddleDimensions);
	rightPaddle.setOrigin(paddleDimensions.x / 2.f, paddleDimensions.y / 2.f);
	rightPaddle.setPosition(width - offset - paddleDimensions.x / 2.f, height / 2.f);

	prevLeftPaddlePos = leftPaddle.getPosition();
	prevRightPaddlePos = rightPaddle.getPosition();

	ball.setRadius(radius);
	ball.setOrigin(radius, radius);
	ball.setPosition(width / 2.f, height / 2.f);
	ball.setFillColor(sf::Color(255, 255, 255, 150));

	sf::Font font;
	if (!font.loadFromFile(std::string("red-october/Red-October-Regular.ttf")))
	{
		std::cerr << " Couldn't load font " << std::endl;
	}
	leftScore.setFont(font);
	rightScore.setFont(font);
	leftScore.setPosition(width / 2.f - 120.f, 100.f);
	rightScore.setPosition(width / 2.f + 100.f, 100.f);
	leftScore.setFillColor(sf::Color::Cyan);
	rightScore.setFillColor(sf::Color::Cyan);
	//mid.setSize(4.f, height);
	mid.setSize(sf::Vector2f(4.f, height));
	mid.setFillColor(sf::Color::White);
	mid.setOrigin(2.f, height / 2.f);
	mid.setPosition(width / 2.f, height / 2.f);

	std::cout << "mid pos x, y" << mid.getPosition().x << " " << mid.getPosition().y << std::endl;

	std::cout << "right paddle x, y = " << rightPaddle.getPosition().x << " " << rightPaddle.getPosition().y << std::endl;
	std::cout << "left paddle x, y = " << leftPaddle.getPosition().x << " " << leftPaddle.getPosition().y;
	sf::RenderWindow window(sf::VideoMode(width, height), std::string("shitty pong v2"), 32U);
	//window.setVerticalSyncEnabled(true);
	//	window.setFramerateLimit(15);

	sf::Vector2f direction(speed, speed);

	float ballAngle;
	do
	{
		ballAngle = (std::rand() % 360) * 2 * pi / 360;
	} while (std::abs(std::cos(ballAngle) < 0.7f));
	if (ballAngle >= .7f)
		goingLeft = true;

	else
		goingRight = true;
	sf::Clock clock;
	clock.restart();
	window.setIcon(sfml_icon.width, sfml_icon.height, sfml_icon.pixel_data);
	std::cout << "Angles" << std::endl;
	std::cout << sin(pi) << std::endl;
	std::cout << cos(pi) << std::endl;
	std::cout << sin(0) << std::endl;
	std::cout << cos(0) << std::endl;
	std::cout << sin(pi / 6.f) << std::endl;
	std::cout << cos(pi / 3.f) << std::endl;

	while (window.isOpen())
	{
		sf::Time time = clock.getElapsedTime();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			//	window.close();
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
					if (isInMenu)
					{
				case sf::Keyboard::Up:		menu.MoveUp();
					break;
				case sf::Keyboard::Down:	menu.MoveDown();
					break;
				case sf::Keyboard::Return:	switch (menu.GetPressedItem())
				{
				case 0:				isInMenu = false;
					std::cout << "Play pressed" << std::endl;
					break;
				case 1:				std::cout << "options pressed" << std::endl;
					break;
				case 2:				std::cout << "Exit pressed" << std::endl;
					window.close();
					break;

				}
					}
					else
					{
				case sf::Keyboard::Escape:  isInMenu = true;
					break;
					}
				default:					break;
				}
			}
			/*
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up))
			goingUp = true;
			else if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Up))
			goingUp = false;
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down))
			goingUp = true;
			else if ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Down))
			goingUp = false;
			*/
	//	}
		/*
		if (!isInMenu)
		{
			float factor = speed * 3 * time.asSeconds();
			ball.move(std::cos(ballAngle) * factor, std::sin(ballAngle) * factor);

			//user move
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (leftPaddle.getPosition().y - leftPaddle.getSize().y / 2.f > offset))
			{
				leftPaddle.move(0.f, -speed * 2 * time.asSeconds());
				goingUp = false;
				if (leftPaddle.getPosition().y - leftPaddle.getSize().y / 2.f < offset)
					leftPaddle.setPosition(leftPaddle.getPosition().x, offset + (paddleDimensions.y / 2.f));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (leftPaddle.getPosition().y + leftPaddle.getSize().y / 2.f < height - offset))
			{
				leftPaddle.move(0.f, speed * 2 * time.asSeconds());
				goingDown = false;
				if ((leftPaddle.getPosition().y + leftPaddle.getSize().y / 2.f > height - offset))
					leftPaddle.setPosition(leftPaddle.getPosition().x, height - offset - paddleDimensions.y / 2.f);
			}
			//cpu move 
			//workes quite badly....
			//if (ball.getPosition().x > width / 2.f)
			if (goingRight)
			{
				if ((rightPaddle.getPosition().y - paddleDimensions.y / 2.f > ball.getPosition().y) && (rightPaddle.getPosition().y - paddleDimensions.y / 2.f > offset))
				{
					rightPaddle.move(0.f, -speed * 2 * time.asSeconds());
					if (rightPaddle.getPosition().y - paddleDimensions.y / 2.f < offset)
						rightPaddle.setPosition(rightPaddle.getPosition().x, offset + (paddleDimensions.y / 2.f));
				}
				else if ((rightPaddle.getPosition().y + paddleDimensions.y / 2.f < ball.getPosition().y) && (rightPaddle.getPosition().y + paddleDimensions.y / 2.f < height - offset))
				{
					rightPaddle.move(0.f, speed * 2 * time.asSeconds());
					if ((rightPaddle.getPosition().y + paddleDimensions.y / 2.f > height - offset))
						rightPaddle.setPosition(rightPaddle.getPosition().x, height - offset - paddleDimensions.y / 2.f);
				}
			}

			if (ball.getPosition().y - ball.getRadius() <= 0.f)
			{
				ballAngle = -ballAngle;
				sound.play();
				ball.setPosition(ball.getPosition().x, ball.getRadius() + 1.f);
			}

			if (ball.getPosition().y + ball.getRadius() >= height)
			{
				ballAngle = -ballAngle;
				sound.play();
				ball.setPosition(ball.getPosition().x, height - ball.getRadius() - 1.f);
			}

			if (ball.getPosition().x - radius <= 0.f)
			{
				scoreRight++;
				leftPaddle.setPosition(offset + paddleDimensions.x / 2.f, height / 2.f);
				rightPaddle.setPosition(width - offset - paddleDimensions.x / 2.f, height / 2.f);
				ball.setPosition(width / 2.f, height / 2.f);
				do
				{
					ballAngle = (std::rand() % 360) * 2 * pi / 360;
				} while (std::cos(ballAngle) < 0.7f);
				goingRight = true;
				goingLeft = false;
			}
			if (ball.getPosition().x + radius >= width)
			{
				scoreLeft++;
				leftPaddle.setPosition(offset + paddleDimensions.x / 2.f, height / 2.f);
				rightPaddle.setPosition(width - offset - paddleDimensions.x / 2.f, height / 2.f);
				ball.setPosition(width / 2.f, height / 2.f);
				do
				{
					ballAngle = (std::rand() % 360) * 2 * pi / 360;
				} while (std::cos(ballAngle) > -0.7f);
				goingRight = false;
				goingLeft = true;
			}
			float temp = 0.f;
			if (ball.getGlobalBounds().intersects(leftPaddle.getGlobalBounds()))
			{
				/*
				do
				{
				ballAngle = (std::rand() % 360) * 2 * pi / 360;
				} while (std::cos(ballAngle) < 0.6f);
				*/
		/*
				if (ball.getPosition().y > leftPaddle.getPosition().y)
					//				ballAngle = pi - ballAngle + (std::rand() % 50) * pi / 180;
					ballAngle = pi - (ballAngle - (std::rand() % 30) * pi / 180);
				else
					//				ballAngle = pi - ballAngle - (std::rand() % 50) * pi / 180;
					ballAngle = pi - (ballAngle + (std::rand() % 30) * pi / 180);
				//			ballAngle = pi - ballAngle + temp;
				goingRight = true;
				goingLeft = false;
				ball.setPosition(sf::Vector2f(offset + paddleDimensions.x + ball.getRadius() + 1.f, ball.getPosition().y));
			}
			/*
			if (ball.getPosition().x - radius < leftPaddle.getPosition().x + paddleDimensions.x / 2 &&
			ball.getPosition().x - radius > leftPaddle.getPosition().x &&
			ball.getPosition().y + radius >= leftPaddle.getPosition().y - paddleDimensions.y / 2 &&
			ball.getPosition().y - radius <= leftPaddle.getPosition().y + paddleDimensions.y / 2)
			{
			if (ball.getPosition().y > leftPaddle.getPosition().y)
			ballAngle = pi - ballAngle + (std::rand() % 20) * pi / 180;
			else
			ballAngle = pi - ballAngle - (std::rand() % 20) * pi / 180;


			ball.setPosition(sf::Vector2f(offset + paddleDimensions.x / 2.f + ball.getRadius() + 0.1f, ball.getPosition().y));
			}
			*//*
			if (ball.getGlobalBounds().intersects(rightPaddle.getGlobalBounds()))
			{
				/*
				do
				{
				temp = (std::rand() % 360) * 2 * pi / 360;
				} while (std::cos(ballAngle) > -0.5f);
				*//*
				//ballAngle = pi - (std::rand() % 360) * 2 * pi / 360; //+ (std::rand() % 20) * pi / 180;
				if (ball.getPosition().y > rightPaddle.getPosition().y)
					//ballAngle = pi - ballAngle + (std::rand() % 20) * pi / 180;
					ballAngle = pi - (ballAngle + (std::rand() % 30) * pi / 180);
				else
					//	ballAngle = pi - ballAngle - (std::rand() % 20) * pi / 180;
					ballAngle = pi - (ballAngle - (std::rand() % 30) * pi / 180);
				//ballAngle = pi - ballAngle - temp;
				goingRight = false;
				goingLeft = true;

				ball.setPosition(sf::Vector2f(width - ball.getRadius() - 1.f - offset - paddleDimensions.x, ball.getPosition().y));
			}
			leftScore.setString(std::to_string(scoreLeft));
			rightScore.setString(std::to_string(scoreRight));

			clock.restart();

			prevLeftPaddlePos = leftPaddle.getPosition();
			prevRightPaddlePos = rightPaddle.getPosition();

			window.clear(sf::Color::Black);
			window.draw(mid);
			window.draw(leftPaddle);
			window.draw(rightPaddle);
			window.draw(ball);
			window.draw(leftScore);
			window.draw(rightScore);
			window.display();
		}
		else
		{
			/*
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
			menu.MoveUp();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
			menu.MoveDown();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
			switch (menu.GetPressedItem())
			{
			case 0:				isInMenu = false;
			std::cout << "Play pressed" << std::endl;
			break;
			case 1:				std::cout << "options pressed" << std::endl;
			break;
			case 2:				std::cout << "Exit pressed" << std::endl;
			window.close();
			break;
			default:			break;
			}
			}
			*//*
			window.clear(sf::Color::Black);
			menu.draw(window);
			window.display();
		}
		//	std::cout << 1.f / time.asSeconds() << std::endl;
	}
	system("pause");

}
*/
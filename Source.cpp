#include "menu.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "diffSelection.hpp"
#include "playerScreen.h"
#include <windows.h>
#include "Scores.h"


//GIMP image which is supposed to work...
static const struct {
	unsigned int 	 width;
	unsigned int 	 height;
	unsigned int 	 bytes_per_pixel; /* 3:RGB, 4:RGBA */
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
	diffSelection difficulties(width, height);
	Menu menu(width, height);
	PlayerScreen players(width, height);
	std::srand(static_cast<unsigned> (std::time(NULL)));
	sf::RectangleShape top, mid, left, right, bottom;
	sf::RectangleShape leftPaddle, rightPaddle;
	sf::CircleShape ball, invisiball;
	sf::Text leftScore;
	sf::Text rightScore;
	sf::SoundBuffer buff;
	bool isInMenu = true;
	bool inDiff = false;
	if (!buff.loadFromFile(std::string("resources/Ball_Bounce.wav")))
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

	invisiball.setRadius(radius);
	invisiball.setOrigin(radius, radius);
	invisiball.setPosition(width / 2.f, height / 2.f);

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
	
	/*
	std::cout << "mid pos x, y" << mid.getPosition().x << " " << mid.getPosition().y << std::endl;
	std::cout << "right paddle x, y = " << rightPaddle.getPosition().x << " " << rightPaddle.getPosition().y << std::endl;
	std::cout << "left paddle x, y = " << leftPaddle.getPosition().x << " " << leftPaddle.getPosition().y;
	*/

	sf::RenderWindow window(sf::VideoMode(width, height), std::string("shitty pong v2"), sf::Style::Default);
	//window.setVerticalSyncEnabled(true)
	//window.setVerticalSyncEnabled(true);
	//	window.setFramerateLimit(15);

	sf::Vector2f direction(speed, speed);

	float ballAngle;

	bool precalc;
	sf::Clock clock;
	clock.restart();
	window.setIcon(sfml_icon.width, sfml_icon.height, sfml_icon.pixel_data);
	sf::Image icon;
	sf::Text message;
	message.setFont(font);
	message.setPosition(width / 2.f - 70, height / 2.f);
	
	if(!icon.loadFromFile("resources/cc.png"))
	{
		std::cerr << " Couldn't load image ";
	}
	//window.setIcon(32U, 32U, icon.getPixelsPtr());
	/*
	std::cout << "Angles" << std::endl;
	std::cout << sin(pi) << std::endl;
	std::cout << cos(pi) << std::endl;
	std::cout << sin(0) << std::endl;
	std::cout << cos(0) << std::endl;
	std::cout << sin(pi / 6.f) << std::endl;
	std::cout << cos(pi / 3.f) << std::endl;
	*/
	bool difficultyHard = false;
	float sp = 1.8f;
	short unsigned int trans = 0;
	sf::Text *contribution = new sf::Text();
	contribution->setFont(font);
	contribution->setPosition(100.f, 100.f);
	contribution->setFillColor(sf::Color::Yellow);
	contribution->setString(std::string("Credits to SFML for their library and sonarsystems for\n \t\t\t\t\t\t\t\tsome of their sources"));
	message.move(-100.f, 0.f);
	//message.setString(std::string("Made by a huge fag\nRoll: 1610776129\nFor university project class"));
	message.setString(std::string("Made by Nasif Ahmed\nRoll: 1610776129\nFor university project class"));
	window.setVerticalSyncEnabled(true);

	
	FreeConsole();
	
	
	while (trans < UCHAR_MAX - 2)
	{
		contribution->setFillColor(sf::Color(255, 255, 0, trans));
		message.setFillColor(sf::Color(255, 255, 255, trans));
		trans += 2;
		window.clear();
		window.draw(message);
		window.draw(*contribution);
		window.display();
	}
	sf::sleep(sf::seconds(.5));
	while (trans >= 2)
	{
		contribution->setFillColor(sf::Color(255, 255, 0, trans));
		message.setFillColor(sf::Color(255, 255, 255, trans));
		trans -= 2;
		window.clear();
		window.draw(message);
		window.draw(*contribution);
		window.display();
	}
	
	
	message.setFillColor(sf::Color::White);
	delete contribution;
	
	message.move(100.f, 0.f);
	window.setVerticalSyncEnabled(false);
	window.clear();
	bool againstWall = false;
	bool inPlayerSelection = false;
	bool player2 = false;
	bool gamePaused = false;
	bool isFullscreen = false;
	bool wasPlaying = false;
	/*
	sf::Texture t1;
	t1.loadFromFile("resources/paddle.png");
	leftPaddle.setTexture(&t1);
	rightPaddle.setTexture(&t1);
	*/
	short paddleoffset = 0;
	float ballspeed = 2.5f;
	int i = -2;

	//////////////////////////////////////////////////////////
	//
	/*			  OPEN FILE FOR SCORES IF AVAILABLE			*/	
	//
	//////////////////////////////////////////////////////////

	Score Scores(std::string("resources/High Scores"), height, width);
//	bool fileState = Scores.checkValidity();
	bool inScorePage = false;
	Scores.read();
	Scores.update(0);



	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
		//	if (event.type == sf::Event::Closed)
		//		window.close();
			//if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			//	window.close();
			switch (event.type)
			{
			case sf::Event::Closed:		
				window.close();
				break;
			case sf::Event::GainedFocus:
				gamePaused = false;
				break;
			case sf::Event::LostFocus:
				gamePaused = true;
				break;
			case sf::Event::KeyReleased:
			{

				if (isInMenu)
				{
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						menu.MoveUp();
						break;
					case sf::Keyboard::Down:
						menu.MoveDown();
						break;
					case sf::Keyboard::Return:
						switch (menu.GetPressedItem())
						{
						case 0:
							leftPaddle.setPosition(offset + paddleDimensions.x / 2.f, height / 2.f);
							rightPaddle.setPosition(width - offset - paddleDimensions.x / 2.f, height / 2.f);
							ball.setPosition(width / 2.f, height / 2.f);
							sp = 1.8f;
							do
							{
								ballAngle = (std::rand() % 360) * 2 * pi / 360;
							} while (std::abs(std::cos(ballAngle)) < 0.7f);
							//	std::cout << "angle " << std::cos(ballAngle) << std::endl;
							//	bool precalc;
							if (std::cos(ballAngle) <= -.7f)
							{
								goingLeft = true;
								precalc = false;
							}
							else
							{
								goingRight = true;
								precalc = true;
							}
							isInMenu = false;
							//		clock.restart();
							inPlayerSelection = true;
							std::cout << "Play pressed" << std::endl;
							wasPlaying = true;
							break;
						case 1:
							std::cout << "options pressed" << std::endl;
							inDiff = true;
							isInMenu = false;
							break;
						case 4:
							std::cout << "Exit pressed" << std::endl;
							window.close();
							break;
						case 3:
							if (!isFullscreen)
							{
								window.create(sf::VideoMode(width, height), std::string("shitty pong v2"), sf::Style::Fullscreen);
								isFullscreen = true;
							}
							else
							{
								window.create(sf::VideoMode(width, height), std::string("shitty pong v2"), sf::Style::Default);
								isFullscreen = false;
							}
							break;
						case 2:
							inDiff = false;
							isInMenu = false;
							inScorePage = true;
							break;
						}
					default:
						break;
					}
				}
				else if (inDiff)
				{
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						difficulties.MoveUp();
						break;
					case sf::Keyboard::Down:
						difficulties.MoveDown();
						break;
					case sf::Keyboard::Return:
						switch (difficulties.GetPressedItem())
						{
						case 0:
							difficultyHard = false;
							precalc = false;
							break;
						case 1:
							difficultyHard = true;
							precalc = true;
							break;
						default:
							break;
						}
					}
				}
				else if (inPlayerSelection)
				{
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						players.MoveUp();
						break;
					case sf::Keyboard::Down:
						players.MoveDown();
						break;
					case sf::Keyboard::Return:
						switch (players.GetPressedItem())
						{
						case 0:
							if (player2)
								scoreLeft = scoreRight = 0;
							player2 = false;
							message.setPosition(width / 2.f - 70, height / 2.f);
						//	message.setCharacterSize(30);
							inPlayerSelection = false;
							againstWall = false;
							clock.restart();
							break;
						case 1:
							if(!player2)
								scoreLeft = scoreRight = 0;
							message.setPosition(width / 2.f - 165, height / 2.f);
						//	message.setCharacterSize(26);
							player2 = true;
							againstWall = false;
							inPlayerSelection = false;
							clock.restart();
							break;
						case 2:
							againstWall = true;
							inPlayerSelection = false;
							player2 = false;
							clock.restart();
						default:
							break;
						}
					default:
						break;
					}
				}
				if (event.key.code == sf::Keyboard::Escape)
				{
					isInMenu = true;
					inPlayerSelection = false;
					inDiff = false;
					inScorePage = false;
					if (wasPlaying && !player2)
						Scores.update(scoreLeft);
					scoreLeft = 0;
					scoreRight = 0;
					againstWall = false;
					wasPlaying = false;
				}
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
		}
		sf::Time time = clock.getElapsedTime();

		/////////////////////////////////////////
		//			   SINGLE PLAYER AGAINST WALL
		/////////////////////////////////////////
		if (!isInMenu && !inDiff && !inScorePage && againstWall)
		{
			if (ball.getGlobalBounds().intersects(leftPaddle.getGlobalBounds()))
			{
				if (ball.getPosition().y > leftPaddle.getPosition().y)
					ballAngle = pi - (ballAngle - (std::rand() % 10) * pi / 180);
				else
					ballAngle = pi - (ballAngle + (std::rand() % 10) * pi / 180);
				sound.play();
				ball.setPosition(sf::Vector2f(offset + paddleDimensions.x + ball.getRadius() + 1.f, ball.getPosition().y));
			}
			float factor = speed * 3 * time.asSeconds();
			ball.move(std::cos(ballAngle) * factor, std::sin(ballAngle) * factor);
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

			//user move
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (leftPaddle.getPosition().y - leftPaddle.getSize().y / 2.f > offset))
			{
				leftPaddle.move(0.f, -speed * 2 * time.asSeconds());
				//	goingUp = false;
				if (leftPaddle.getPosition().y - leftPaddle.getSize().y / 2.f < offset)
					leftPaddle.setPosition(leftPaddle.getPosition().x, offset + (paddleDimensions.y / 2.f));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (leftPaddle.getPosition().y + leftPaddle.getSize().y / 2.f < height - offset))
			{
				leftPaddle.move(0.f, speed * 2 * time.asSeconds());
				//	goingDown = false;
				if ((leftPaddle.getPosition().y + leftPaddle.getSize().y / 2.f > height - offset))
					leftPaddle.setPosition(leftPaddle.getPosition().x, height - offset - paddleDimensions.y / 2.f);
			}

			if (ball.getPosition().x - ball.getRadius() <= 0.f)
			{
				ball.setPosition(offset + paddleDimensions.x * 3, 10 + std::rand() % int(height - 20));
				do
				{
					ballAngle = (std::rand() % 360) * 2 * pi / 360;
				} while (std::cos(ballAngle) < 0.7f);
			}

			if (ball.getPosition().x + ball.getRadius() >= width)
			{
				sound.play();
				ball.setPosition(sf::Vector2f(width - ball.getRadius() - 1.f, ball.getPosition().y));
				if (ball.getPosition().y > rightPaddle.getPosition().y)
					ballAngle = pi - (ballAngle + (std::rand() % 10) * pi / 180);
				else
					ballAngle = pi - (ballAngle - (std::rand() % 10) * pi / 180);
			}
			clock.restart();
			window.clear(sf::Color::Black);
			window.draw(ball);
			window.draw(leftPaddle);
			window.display();
		}
		//////////////////////////////////
		//  MP AND SP
		//////////////////////////////////
		else if (!isInMenu && !inDiff & !inPlayerSelection && !inScorePage)
		{
			if (!gamePaused)
			{
				float factor = speed * 3 * time.asSeconds();
				if (ball.getGlobalBounds().intersects(leftPaddle.getGlobalBounds()))
				{
					/*
					do
					{
					ballAngle = (std::rand() % 360) * 2 * pi / 360;
					} while (std::cos(ballAngle) < 0.6f);
					*/
					if (ball.getPosition().y > leftPaddle.getPosition().y)
						//				ballAngle = pi - ballAngle + (std::rand() % 50) * pi / 180;
						ballAngle = pi - (ballAngle - (std::rand() % 10) * pi / 180);
					else
						//				ballAngle = pi - ballAngle - (std::rand() % 50) * pi / 180;
						ballAngle = pi - (ballAngle + (std::rand() % 10) * pi / 180);
					//			ballAngle = pi - ballAngle + temp;
					goingRight = true;
					precalc = true;
					goingLeft = false;
					//		sp += .1f;
					sound.play();
					ball.setPosition(sf::Vector2f(offset + paddleDimensions.x + ball.getRadius() + 1.f, ball.getPosition().y));
				}

				if (ball.getGlobalBounds().intersects(rightPaddle.getGlobalBounds()))
				{
					/*
					do
					{
					temp = (std::rand() % 360) * 2 * pi / 360;
					} while (std::cos(ballAngle) > -0.5f);
					*/
					//ballAngle = pi - (std::rand() % 360) * 2 * pi / 360; //+ (std::rand() % 20) * pi / 180;
					if (ball.getPosition().y > rightPaddle.getPosition().y)
						//ballAngle = pi - ballAngle + (std::rand() % 20) * pi / 180;
						ballAngle = pi - (ballAngle + (std::rand() % 10) * pi / 180);
					else
						//	ballAngle = pi - ballAngle - (std::rand() % 20) * pi / 180;
						ballAngle = pi - (ballAngle - (std::rand() % 10) * pi / 180);
					//ballAngle = pi - ballAngle - temp;
					goingRight = false;
					goingLeft = true;
					precalc = false;
					if(sp < 3.f)
						sp += .1f;
					sound.play();
					ball.setPosition(sf::Vector2f(width - ball.getRadius() - 1.f - offset - paddleDimensions.x, ball.getPosition().y));
					ballspeed += .1f;
				}
				if (!difficultyHard)
					ball.move(std::cos(ballAngle) * factor, std::sin(ballAngle) * factor);
				else
					ball.move(std::cos(ballAngle) * speed * ballspeed * time.asSeconds(), std::sin(ballAngle) * speed * ballspeed * time.asSeconds());
				//user move
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (leftPaddle.getPosition().y - leftPaddle.getSize().y / 2.f > offset))
				{
					leftPaddle.move(0.f, -speed * 2 * time.asSeconds());
					//	goingUp = false;
					if (leftPaddle.getPosition().y - leftPaddle.getSize().y / 2.f < offset)
						leftPaddle.setPosition(leftPaddle.getPosition().x, offset + (paddleDimensions.y / 2.f));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (leftPaddle.getPosition().y + leftPaddle.getSize().y / 2.f < height - offset))
				{
					leftPaddle.move(0.f, speed * 2 * time.asSeconds());
					//	goingDown = false;
					if ((leftPaddle.getPosition().y + leftPaddle.getSize().y / 2.f > height - offset))
						leftPaddle.setPosition(leftPaddle.getPosition().x, height - offset - paddleDimensions.y / 2.f);
				}
				//cpu move 
				//workes quite badly....
				//if (ball.getPosition().x > width / 2.f)
				paddleoffset = (std::rand() % 20) - (std::rand() % 20);
				//std::cout << paddleoffset << std::endl;
				if (!player2 && goingRight && !difficultyHard)
				{
					//paddleoffset = std::rand() % 10; //- std::rand() % 50;
					if (rightPaddle.getPosition().y - paddleDimensions.y / 2.f > ball.getPosition().y - float(paddleoffset) + offset) //&& (rightPaddle.getPosition().y - paddleDimensions.y / 2.f > offset))
					{
						rightPaddle.move(0.f, -speed * 2 * time.asSeconds());

					}
					else if (rightPaddle.getPosition().y + paddleDimensions.y / 2.f < ball.getPosition().y + float(paddleoffset) - offset) //&& (rightPaddle.getPosition().y + paddleDimensions.y / 2.f < height - offset ))
					{
						rightPaddle.move(0.f, speed * 2 * time.asSeconds());
						//	if ((rightPaddle.getPosition().y + paddleDimensions.y / 2.f > height - offset))
						//		rightPaddle.setPosition(rightPaddle.getPosition().x, height - offset - paddleDimensions.y / 2.f);
					}
				}
				else if (!player2 && goingRight && difficultyHard)
				{
					if (precalc)
					{
						float tempAngle = ballAngle;
						invisiball.setPosition(ball.getPosition());
						while (invisiball.getPosition().x - radius <= width - offset - paddleDimensions.x)
						{
							invisiball.move(std::cos(tempAngle) * factor, std::sin(tempAngle) * factor);

							if (invisiball.getPosition().y - invisiball.getRadius() <= 0.f)
							{
								tempAngle = -tempAngle;
								//sound.play();
								invisiball.setPosition(invisiball.getPosition().x, invisiball.getRadius() + 1.f);
							}

							if (invisiball.getPosition().y + invisiball.getRadius() >= height)
							{
								tempAngle = -tempAngle;
								//sound.play();
								invisiball.setPosition(invisiball.getPosition().x, height - invisiball.getRadius() - 1.f);
							}
						}
						precalc = false;
					}
					if (ball.getPosition().x <= width / 3.f)
					{
						//int i = -2;
						if (i == -2)
							i = 2;
						else if ( i == 2)
							i = -2;
				//		std::cout << i << std::endl;

						rightPaddle.move(0.f, float(std::rand() % 500 - std::rand() % 500) * i * time.asSeconds());

					}
					if (ball.getPosition().x - width / 8.f >= width / 2.f)
					{
						if ((rightPaddle.getPosition().y - paddleDimensions.y / 2.f + offset * 1.5f > invisiball.getPosition().y) && (rightPaddle.getPosition().y - paddleDimensions.y / 2.f > offset))
						{
							rightPaddle.move(0.f, -speed * sp * time.asSeconds());
							//		if (rightPaddle.getPosition().y - paddleDimensions.y / 2.f < offset)
							//			rightPaddle.setPosition(rightPaddle.getPosition().x, offset + (paddleDimensions.y / 2.f));
						}
						else if ((rightPaddle.getPosition().y + paddleDimensions.y / 2.f - offset * 1.5f < invisiball.getPosition().y) && (rightPaddle.getPosition().y + paddleDimensions.y / 2.f < height - offset))
						{
							rightPaddle.move(0.f, speed * sp * time.asSeconds());
							//		if ((rightPaddle.getPosition().y + paddleDimensions.y / 2.f > height - offset))
							//			rightPaddle.setPosition(rightPaddle.getPosition().x, height - offset - paddleDimensions.y / 2.f);
						}
					}
				}
				else if (player2)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (rightPaddle.getPosition().y - rightPaddle.getSize().y / 2.f > offset))
					{
						rightPaddle.move(0.f, -speed * 2 * time.asSeconds());
						//	goingUp = false;
						//	if (rightPaddle.getPosition().y - rightPaddle.getSize().y / 2.f < offset)
						//		rightPaddle.setPosition(rightPaddle.getPosition().x, offset + (paddleDimensions.y / 2.f));
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (rightPaddle.getPosition().y + rightPaddle.getSize().y / 2.f < height - offset))
					{
						rightPaddle.move(0.f, speed * 2 * time.asSeconds());
						//	goingDown = false;

					}
				}

				if (rightPaddle.getPosition().y - paddleDimensions.y / 2.f < offset)
					rightPaddle.setPosition(rightPaddle.getPosition().x, offset + (paddleDimensions.y / 2.f));
				else if ((rightPaddle.getPosition().y + rightPaddle.getSize().y / 2.f > height - offset))
					rightPaddle.setPosition(rightPaddle.getPosition().x, height - offset - paddleDimensions.y / 2.f);

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
					ball.setPosition(offset * 3 + paddleDimensions.x, height / 2.f);
					do
					{
						ballAngle = (std::rand() % 360) * 2 * pi / 360;
					} while (std::cos(ballAngle) < 0.7f);
					goingRight = true;
					precalc = true;
					goingLeft = false;
					sp = 1.7f;
					if (player2)
						message.setString(std::string("Player 2 wins!"));
					else
						message.setString(std::string("You Lost!"));
					window.draw(message);
					window.display();
					sf::sleep(sf::seconds(1.5));
					ballspeed = 2.5f;
				}
				if (ball.getPosition().x + radius >= width)
				{
					scoreLeft++;
					leftPaddle.setPosition(offset + paddleDimensions.x / 2.f, height / 2.f);
					rightPaddle.setPosition(width - offset - paddleDimensions.x / 2.f, height / 2.f);
					ball.setPosition(width - offset * 3 - paddleDimensions.x, height / 2.f);
					do
					{
						ballAngle = (std::rand() % 360) * 2 * pi / 360;
					} while (std::cos(ballAngle) > -0.7f);
					goingRight = false;
					precalc = false;
					goingLeft = true;
					if (player2)
						message.setString(std::string("Player 1 wins!"));
					else
						message.setString(std::string("You Won!"));
					window.draw(message);
					window.display();
					if(sp <= 3.f)
						sp += .1f;
					sf::sleep(sf::seconds(1.5));
					ballspeed = 2.5f;
				}
				float temp = 0.f;
				
				
				leftScore.setString(std::to_string(scoreLeft));
				rightScore.setString(std::to_string(scoreRight));

	

		//		prevLeftPaddlePos = leftPaddle.getPosition();
		//		prevRightPaddlePos = rightPaddle.getPosition();
			}
			clock.restart();
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
			window.clear(sf::Color::Black);
			if (!inDiff && !inPlayerSelection && !inScorePage)
				menu.draw(window);
			else if (inPlayerSelection && !inScorePage)
				players.draw(window);
			else if (inScorePage)
				Scores.draw(window);
			else
				difficulties.draw(window);
			window.display();
		}
	//	sf::Time mSleepTime  = sf::microseconds(clock.getElapsedTime().asMicroseconds() - time.asMicroseconds());
	//	sf::sleep(mSleepTime);
	//	clock.restart();
		//	std::cout << 1.f / time.asSeconds() << std::endl;
	}
	//system("pause");
	Scores.write();
}

#include "arena.h"
#include "case.h"
#include "snake.h"
#include "fruit.h"
#include <windows.h>



int main()
{
    std::rand();
    Arena arena{};
    arena.printArena();
    std::cout << "La pause commence\n";
    Sleep(1000);
    std::cout << "Fin de la pause\n";
    
    arena.play();
    
    /*
    for (auto runUntil = std::chrono::system_clock::now() + std::chrono::milliseconds(timeGame);
	std::chrono::system_clock::now() < runUntil;)
	*/

    return 0;
}


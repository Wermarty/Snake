#ifndef CONSTANTS_H
#define CONSTANTS_H

//Dimension for the arena
extern constexpr int g_numCol{ 50 };
extern constexpr int g_numRow{ 20 };

//Frame per second
extern constexpr int FPS{ 60 };
extern constexpr int timeGame{ static_cast<int>(1000 / FPS) };

//Snake initial dimension
extern constexpr int g_initialLengh{ 3 };
#endif

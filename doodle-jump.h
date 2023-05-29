#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

struct Point {
    int x, y;
};

class Game {
private:
    RenderWindow app;
    Texture t1, t2, t3;
    Sprite sBackground, sPlat, sPers;
    Point plat[20];
    int x, y, h;
    float dx, dy;
    int score;
    Font font;
    Text text;
    Text gameOverText;
    bool gameOver;
    int lastPlatform;
public:
    Game();
    void run();
};

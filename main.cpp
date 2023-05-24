#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

struct point
{ int x,y;};

int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(400, 533), "Doodle Game!");
    app.setFramerateLimit(60);

    Texture t1,t2,t3;
    t1.loadFromFile("../background.png");
    t2.loadFromFile("../platform.png");
    t3.loadFromFile("../doodle.png");

    Sprite sBackground(t1), sPlat(t2), sPers(t3);

    point plat[20];

    for (int i=0;i<10;i++)
      {
       plat[i].x=rand()%400;
       plat[i].y=rand()%533;
      }

	int x=100,y=100,h=200;
    float dx=0,dy=0;

    // Initialize the score
    int score = 0;

    // Create a text object to display the score
    sf::Font font;
    font.loadFromFile("../arial.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(10, 10);

    // Create a text object to display Game Over
    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(32);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(120, 250);
    gameOverText.setString("Game Over");

    bool gameOver = false;

    // Keep track of the last platform
    int lastPlatform = -1;

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }

    if (Keyboard::isKeyPressed(Keyboard::Right)) x+=3;
    if (Keyboard::isKeyPressed(Keyboard::Left)) x-=3;

    // Wrap-around walls
    if (x > 400) x = 0;
    if (x < 0) x = 400;

    dy+=0.2;
    y+=dy;
    if (y > 500) dy = 0;

	if (y<h)
    for (int i=0;i<10;i++)
    {
      y=h;
      plat[i].y=plat[i].y-dy;
      if (plat[i].y>533) {plat[i].y=0; plat[i].x=rand()%400;}
    }

	for (int i=0;i<10;i++)
    if ((x+50>plat[i].x) && (x+20<plat[i].x+68)
    && (y+70>plat[i].y) && (y+70<plat[i].y+14) && (dy>0))
    {
      dy=-10;
      // Increase score only when the player jumps off a new platform
      if (i != lastPlatform)
      {
        score++;
        lastPlatform = i;
      }
    }

    // Game Over when player hits the ground
    if (dy > 11)
        gameOver = true;

	sPers.setPosition(x,y);

    app.draw(sBackground);
    app.draw(sPers);
    for (int i=0;i<10;i++)
    {
    sPlat.setPosition(plat[i].x,plat[i].y);
    app.draw(sPlat);
    }

    // Draw the score
    text.setString("Score: " + std::to_string(score));
    app.draw(text);

    // Draw Game Over text
    if(gameOver){
        app.draw(gameOverText);
    }

    app.display();

    // Exit the game if it's over
    if(gameOver){
        sf::sleep(sf::seconds(2)); // wait for a while before closing
        app.close();
    }
}

    return 0;
}

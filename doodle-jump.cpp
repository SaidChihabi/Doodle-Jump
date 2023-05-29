#include "doodle-jump.h"

Game::Game() : app(VideoMode(400, 533), "Doodle Game!") {
    srand(time(0));
    app.setFramerateLimit(60);
    
    t1.loadFromFile("../background.png");
    t2.loadFromFile("../platform.png");
    t3.loadFromFile("../doodle.png");

    sBackground = Sprite(t1);
    sPlat = Sprite(t2);
    sPers = Sprite(t3);

    for (int i=0;i<10;i++) {
        plat[i].x=rand()%400;
        plat[i].y=rand()%533;
    }

    x = 100;
    y = 100;
    h = 200;
    dx = 0;
    dy = 0;

    score = 0;
    font.loadFromFile("../arial.ttf");
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(10, 10);

    gameOverText.setFont(font);
    gameOverText.setCharacterSize(32);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(120, 250);
    gameOverText.setString("Game Over");

    gameOver = false;
    lastPlatform = -1;
}

void Game::run() {
    while (app.isOpen()) {
        Event e;
        while (app.pollEvent(e)) {
            if (e.type == Event::Closed)
                app.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) x+=3;
        if (Keyboard::isKeyPressed(Keyboard::Left)) x-=3;

        if (x > 400) x = 0;
        if (x < 0) x = 400;

        dy += 0.2;
        y += dy;
        if (y > 500) dy = 0;

        if (y < h)
            for (int i=0;i<10;i++) {
                y = h;
                plat[i].y = plat[i].y - dy;
                if (plat[i].y > 533) {
                    plat[i].y = 0; 
                    plat[i].x = rand() % 400;
                }
            }

        for (int i=0;i<10;i++) {
            if ((x+50 > plat[i].x) && (x+20 < plat[i].x+68)
                && (y+70 > plat[i].y) && (y+70 < plat[i].y+14) && (dy > 0)) {
                dy = -10;
                if (i != lastPlatform) {
                    score++;
                    lastPlatform = i;
                }
            }
        }

        if (dy > 11) gameOver = true;

        sPers.setPosition(x,y);

        app.draw(sBackground);
        app.draw(sPers);
        for (int i=0;i<10;i++) {
            sPlat.setPosition(plat[i].x,plat[i].y);
            app.draw(sPlat);
        }

        text.setString("Score: " + std::to_string(score));
        app.draw(text);

        if(gameOver){
            app.draw(gameOverText);
        }

        app.display();

        if(gameOver){
            sf::sleep(sf::seconds(2));
            app.close();
        }
    }
}

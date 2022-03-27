#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include<stdlib.h>
#include<unistd.h>

using namespace std;
using namespace sf;

float clamp(float value,float minn,float maxx)
{
    if(value<minn) return minn;
    else if(value>maxx) return maxx;
    else return value;
}

int checkCollision(RectangleShape &R1, CircleShape &C1)
{
    float closestX = clamp(C1.getPosition().x, R1.getPosition().x, R1.getPosition().x+R1.getSize().x);
    float closestY = clamp(C1.getPosition().y, R1.getPosition().y, R1.getPosition().y+R1.getSize().y);

    float distanceX= C1.getPosition().x-closestX;
    float distanceY= C1.getPosition().y-closestY;

    float distanceSquared = (distanceX*distanceX)+(distanceY*distanceY);
    if(distanceSquared< C1.getRadius()* C1.getRadius()&& closestX!=C1.getPosition().x&&closestY != C1.getPosition().y)
    {
        return 3;
    }
    else if(distanceSquared< C1.getRadius()* C1.getRadius()&& closestX == C1.getPosition().x)
    {
        return 2;
    }
     else if(distanceSquared< C1.getRadius()* C1.getRadius()&& closestY == C1.getPosition().y)
    {
        return 1;
    }
    else return 0;


}
int main()
{
   RenderWindow window(VideoMode(800, 600), "Menu");
    window.setFramerateLimit(60);
    Music music;
     if ( !music.openFromFile( "music.ogg" ) )
    {
        std::cout << "ERROR: Loading Music File" << std::endl;
    }
    sf::Texture mushroomTexture;
    mushroomTexture.loadFromFile("menu1.jpg");
    sf::Sprite mushroom(mushroomTexture);
    sf::Vector2u size = mushroomTexture.getSize();

  Font font;
  if (!font.loadFromFile("C:\\Users\\User\\Documents\\C++projects\\курсач\\fonts\\Roboto-Bold.ttf"))
{
    cout<<"error"<<endl;
}
    RectangleShape button1(Vector2f(150,60));
    button1.setPosition(325,50);
    button1.setFillColor(Color::Black);

    RectangleShape button2(Vector2f(500,60));
    button2.setPosition(160,245);
    button2.setFillColor(Color::Black);

    RectangleShape button3(Vector2f(150,60));
    button3.setPosition(325,365);
    button3.setFillColor(Color::Black);

    RectangleShape button01(Vector2f(100,35));
    button01.setPosition(105,145);
    button01.setFillColor(Color::Black);

    RectangleShape button02(Vector2f(110,40));
    button02.setPosition(345,145);
    button02.setFillColor(Color::Black);

    RectangleShape button03(Vector2f(100,35));
    button03.setPosition(610,145);
    button03.setFillColor(Color::Black);

    Text text0;
    text0.setString("Easy");
    text0.setPosition(125,145);
    text0.setColor(Color::Green);
    text0.setFont(font);

    Text text01;
    text01.setString("Normal");
    text01.setPosition(350,145);
    text01.setColor(Color::Yellow);
    text01.setFont(font);

    Text text02;
    text02.setString("Hard");
    text02.setPosition(630,145);
    text02.setColor(Color::Red);
    text02.setFont(font);

    Text text;
    text.setString("Play");
    text.setPosition(370,55);
    text.setColor(Color::White);
    text.setFont(font);

    Text text1;
    text1.setString("Play with computer");
    text1.setPosition(280,260);
    text1.setColor(Color::White);
    text1.setFont(font);

    Text text2;
    text2.setString("Exit");
    text2.setPosition(375,375);
    text2.setColor(Color::Red);
    text2.setFont(font);

    while (window.isOpen()&&!Keyboard::isKeyPressed(Keyboard::Escape))
    {

        sf::Event event;
     Vector2i mousePoz=Mouse::getPosition(window);

        while (window.pollEvent(event))
        {
             switch ( event.type )
            {
                case sf::Event::Closed:
                    window.close( );
                    break;
                case sf::Event::KeyReleased:
                    if ( sf::Keyboard::Key::P == event.key.code )
                    {
                        music.play( );
                    }
                    else if ( sf::Keyboard::Key::S == event.key.code )
                    {
                        music.stop( );
                    }
                    else if ( sf::Keyboard::Key::F == event.key.code )
                    {
                        music.pause( );
                    }
       break;
        }

        if(Mouse::isButtonPressed(Mouse::Left)){

            if(button2.getGlobalBounds().contains(mousePoz.x,mousePoz.y))
            {
                cout<<"Auto"<<endl;

    RenderWindow window(sf::VideoMode(800, 600), "Auto");
    window.setFramerateLimit(60);

    Texture auto1Texture;
    auto1Texture.loadFromFile("auto1.jpg");
    Sprite auto1(auto1Texture);
    Vector2u size = auto1Texture.getSize();

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(150, 20));
    rectangle.setPosition(350, 100);

  CircleShape shape;
    shape.setRadius(15.0);
    shape.setOrigin(15,15);
    shape.setPosition(150,300);
    shape.setFillColor(Color::Magenta);

    RectangleShape paddle;
    paddle.setSize(Vector2f(150,20));
    paddle.setPosition(350,500);

float _xstep=36;
float xstep=2;
float ystep=2;

    while (window.isOpen()&&!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        shape.move(xstep,ystep);
        if(shape.getPosition().x>800-shape.getRadius())
        {
            xstep=-xstep;
        }
        if(shape.getPosition().y>600-shape.getRadius())
        {
 RenderWindow window(sf::VideoMode(600, 400), "GameOver");
    window.setFramerateLimit(60);

    Font font;
  if (!font.loadFromFile("C:\\Users\\User\\Documents\\C++projects\\курсач\\fonts\\Roboto-Bold.ttf"))
{
    cout<<"error"<<endl;
}

    Text text4;
    text4.setString("White lose!");
    text4.setPosition(225,145);
    text4.setColor(Color::White);
    text4.setFont(font);


    while (window.isOpen()&&!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text4);
        window.display();
    }
        }
        if(shape.getPosition().x < shape.getRadius())
        {
            xstep=-xstep;
        }
        if(shape.getPosition().y < shape.getRadius())
        {
 RenderWindow window(sf::VideoMode(600, 400), "GameOver");
    window.setFramerateLimit(60);

    Font font;
  if (!font.loadFromFile("C:\\Users\\User\\Documents\\C++projects\\курсач\\fonts\\Roboto-Bold.ttf"))
{
    cout<<"error"<<endl;
}
Text text5;
    text5.setString("Computer lose");
    text5.setPosition(225,145);
    text5.setColor(Color::White);
    text5.setFont(font);

    while (window.isOpen()&&!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text5);
        window.display();

    }
        }

        if(Keyboard::isKeyPressed(Keyboard::D))
            paddle.move(5,0);
        if(Keyboard::isKeyPressed(Keyboard::A))
            paddle.move(-5,0);


        if(rectangle.getPosition().x>650)
        {
            _xstep=-5;
        }
        else if(rectangle.getPosition().x<0)
        {
            _xstep=5;
        }

        //paddle collision 1
        if(checkCollision(paddle,shape)==2)
        {
            ystep=-ystep;
        }
        else if(checkCollision(paddle,shape)==1)
        {
            xstep=-xstep;
        }
        else if(checkCollision(paddle,shape)==3)
        {
            ystep=-ystep;
            xstep=-xstep;
        }
//paddle collision 2
         if(checkCollision(rectangle,shape)==2)
        {
            ystep=-ystep;
        }
        else if(checkCollision(rectangle,shape)==1)
        {
            xstep=-xstep;
        }
        else if(checkCollision(rectangle,shape)==3)
        {
            ystep=-ystep;
            xstep=-xstep;
        }
        rectangle.move(_xstep,0);

        window.clear();
        window.draw(auto1);
        window.draw(shape);
        window.draw(paddle);
        window.draw(rectangle);
        window.display();
    }
            }

            if(button3.getGlobalBounds().contains(mousePoz.x,mousePoz.y))
            {
                cout<<"Exit"<<endl;
                window.close();
                return 0;
            }

            if(button01.getGlobalBounds().contains(mousePoz.x,mousePoz.y))
            {
                cout<<"Easy"<<endl;
    sf::RenderWindow window(VideoMode(800, 600), "Easy");
    window.setFramerateLimit(60);

    Texture easyTexture;
    easyTexture.loadFromFile("easy.png");
    Sprite easy(easyTexture);
    Vector2u size = easyTexture.getSize();

     CircleShape shape;
    shape.setRadius(15.0);
    shape.setOrigin(15,15);
    shape.setPosition(250,300);
    shape.setFillColor(Color::Magenta);

    RectangleShape paddle;
    paddle.setSize(Vector2f(150,20));
    paddle.setPosition(350,500);

    RectangleShape paddle1;
    paddle1.setSize(Vector2f(150,20));
    paddle1.setPosition(350,100);
    paddle1.setFillColor(Color::Green);

    float xstep=3;
    float ystep=3;


    while (window.isOpen()&&!Keyboard::isKeyPressed(Keyboard::Escape))
    {

        Event event;


        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        shape.move(xstep,ystep);
        if(shape.getPosition().x>800-shape.getRadius())
        {
            xstep=-xstep;
        }
        if(shape.getPosition().y>600-shape.getRadius())
        {
    RenderWindow window(sf::VideoMode(600, 400), "GameOver");
    window.setFramerateLimit(60);

    Font font;
  if (!font.loadFromFile("C:\\Users\\User\\Documents\\C++projects\\курсач\\fonts\\Roboto-Bold.ttf"))
{
    cout<<"error"<<endl;
}

    Text text4;
    text4.setString("White lose!");
    text4.setPosition(225,145);
    text4.setColor(Color::White);
    text4.setFont(font);

    while (window.isOpen()&&!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        sf::Event event;
        Vector2i mousePoz=Mouse::getPosition(window);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text4);
        window.display();
    }//ystep=-ystep;
        }
        if(shape.getPosition().x < shape.getRadius())
        {
            xstep=-xstep;
        }
        if(shape.getPosition().y < shape.getRadius())
        {
    RenderWindow window(sf::VideoMode(600, 400), "GameOver");
    window.setFramerateLimit(60);

    Font font;
  if (!font.loadFromFile("C:\\Users\\User\\Documents\\C++projects\\курсач\\fonts\\Roboto-Bold.ttf"))
{
    cout<<"error"<<endl;
}
    Text text5;
    text5.setString("Green lose");
    text5.setPosition(225,145);
    text5.setColor(Color::Green);
    text5.setFont(font);

    while (window.isOpen()&&!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        sf::Event event;
        Vector2i mousePoz=Mouse::getPosition(window);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text5);
        window.display();
    }
        }

        if(Keyboard::isKeyPressed(Keyboard::D))
            paddle.move(5,0);
        if(Keyboard::isKeyPressed(Keyboard::A))
            paddle.move(-5,0);

        if(Keyboard::isKeyPressed(Keyboard::Right))
            paddle1.move(5,0);
        if(Keyboard::isKeyPressed(Keyboard::Left))
            paddle1.move(-5,0);



//paddle collision 1
        if(checkCollision(paddle,shape)==2)
        {
            ystep=-ystep;
        }
        else if(checkCollision(paddle,shape)==1)
        {
            xstep=-xstep;
        }
        else if(checkCollision(paddle,shape)==3)
        {
            ystep=-ystep;
            xstep=-xstep;
        }
//paddle collision 2
         if(checkCollision(paddle1,shape)==2)
        {
            ystep=-ystep;
        }
        else if(checkCollision(paddle1,shape)==1)
        {
            xstep=-xstep;
        }
        else if(checkCollision(paddle1,shape)==3)
        {
            ystep=-ystep;
            xstep=-xstep;
        }

        window.clear();
        window.draw(easy);
        window.draw(shape);
        window.draw(paddle1);
        window.draw(paddle);
        window.display();
    }


            }


if(button02.getGlobalBounds().contains(mousePoz.x,mousePoz.y))
            {
                cout<<"Normal"<<endl;
    sf::RenderWindow window(VideoMode(800, 600), "Normal");
    window.setFramerateLimit(60);

  Texture normalTexture;
  normalTexture.loadFromFile("normal.jpg");
  sf::Sprite normal(normalTexture);
  sf::Vector2u size = normalTexture.getSize();

    CircleShape shape;
    shape.setRadius(15.0);
    shape.setOrigin(15,15);
    shape.setPosition(250,300);
    shape.setFillColor(Color::Magenta);

    RectangleShape paddle;
    paddle.setSize(Vector2f(150,20));
    paddle.setPosition(350,500);

    RectangleShape paddle1;
    paddle1.setSize(Vector2f(150,20));
    paddle1.setPosition(350,100);
    paddle1.setFillColor(Color::Green);


    float xstep=4;
    float ystep=4;


    while (window.isOpen()&&!Keyboard::isKeyPressed(Keyboard::Escape))
    {

        Event event;


        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        shape.move(xstep,ystep);
        if(shape.getPosition().x>800-shape.getRadius())
        {
            xstep=-xstep;
        }
        if(shape.getPosition().y>600-shape.getRadius())
        {
            RenderWindow window(sf::VideoMode(600, 400), "GameOver");
    window.setFramerateLimit(60);

    Font font;
  if (!font.loadFromFile("C:\\Users\\User\\Documents\\C++projects\\курсач\\fonts\\Roboto-Bold.ttf"))
{
    cout<<"error"<<endl;
}

    Text text4;
    text4.setString("White lose!");
    text4.setPosition(225,145);
    text4.setColor(Color::White);
    text4.setFont(font);

    while (window.isOpen()&&!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text4);
        window.display();
    }
        }
        if(shape.getPosition().x < shape.getRadius())
        {
            xstep=-xstep;
        }
        if(shape.getPosition().y < shape.getRadius())
        {
RenderWindow window(sf::VideoMode(600, 400), "GameOver");
    window.setFramerateLimit(60);

    Font font;
  if (!font.loadFromFile("C:\\Users\\User\\Documents\\C++projects\\курсач\\fonts\\Roboto-Bold.ttf"))
{
    cout<<"error"<<endl;
}

    Text text5;
    text5.setString("Green lose");
    text5.setPosition(225,145);
    text5.setColor(Color::Green);
    text5.setFont(font);

    while (window.isOpen()&&!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        sf::Event event;
        Vector2i mousePoz=Mouse::getPosition(window);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text5);
        window.display();
    }
        }

        if(Keyboard::isKeyPressed(Keyboard::D))
            paddle.move(7,0);
        if(Keyboard::isKeyPressed(Keyboard::A))
            paddle.move(-7,0);

        if(Keyboard::isKeyPressed(Keyboard::Right))
            paddle1.move(7,0);
        if(Keyboard::isKeyPressed(Keyboard::Left))
            paddle1.move(-7,0);



//paddle collision 1
        if(checkCollision(paddle,shape)==2)
        {
            ystep=-ystep;
        }
        else if(checkCollision(paddle,shape)==1)
        {
            xstep=-xstep;
        }
        else if(checkCollision(paddle,shape)==3)
        {
            ystep=-ystep;
            xstep=-xstep;
        }
//paddle collision 2
         if(checkCollision(paddle1,shape)==2)
        {
            ystep=-ystep;
        }
        else if(checkCollision(paddle1,shape)==1)
        {
            xstep=-xstep;
        }
        else if(checkCollision(paddle1,shape)==3)
        {
            ystep=-ystep;
            xstep=-xstep;
        }


        window.clear();
        window.draw(normal);
        window.draw(shape);
        window.draw(paddle1);
        window.draw(paddle);
        window.display();
    }
            }


            if(button03.getGlobalBounds().contains(mousePoz.x,mousePoz.y))
            {
                cout<<"Hard"<<endl;
                 sf::RenderWindow window(VideoMode(800, 600), "Hard");
    window.setFramerateLimit(60);

    Texture hardTexture;
    hardTexture.loadFromFile("hard.jpg");
    Sprite hard(hardTexture);
    Vector2u size = hardTexture.getSize();

    CircleShape shape;
    shape.setRadius(15.0);
    shape.setOrigin(15,15);
    shape.setPosition(250,300);
    shape.setFillColor(Color::Magenta);

    RectangleShape paddle;
    paddle.setSize(Vector2f(150,20));
    paddle.setPosition(350,500);

    RectangleShape paddle1;
    paddle1.setSize(Vector2f(150,20));
    paddle1.setPosition(350,100);
    paddle1.setFillColor(Color::Green);



    float xstep=5;
    float ystep=5;


    while (window.isOpen()&&!Keyboard::isKeyPressed(Keyboard::Escape))
    {

        Event event;


        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        shape.move(xstep,ystep);
        if(shape.getPosition().x>800-shape.getRadius())
        {
            xstep=-xstep;
        }
        if(shape.getPosition().y>600-shape.getRadius())
        {
            RenderWindow window(sf::VideoMode(600, 400), "GameOver");
    window.setFramerateLimit(60);

    Font font;
  if (!font.loadFromFile("C:\\Users\\User\\Documents\\C++projects\\курсач\\fonts\\Roboto-Bold.ttf"))
{
    cout<<"error"<<endl;
}

    Text text4;
    text4.setString("White lose!");
    text4.setPosition(225,145);
    text4.setColor(Color::White);
    text4.setFont(font);

    while (window.isOpen()&&!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        sf::Event event;
        Vector2i mousePoz=Mouse::getPosition(window);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text4);
        window.display();
    }
        }
        if(shape.getPosition().x < shape.getRadius())
        {
            xstep=-xstep;
        }
        if(shape.getPosition().y < shape.getRadius())
        {
RenderWindow window(sf::VideoMode(600, 400), "GameOver");
    window.setFramerateLimit(60);

    Font font;
  if (!font.loadFromFile("C:\\Users\\User\\Documents\\C++projects\\курсач\\fonts\\Roboto-Bold.ttf"))
{
    cout<<"error"<<endl;
}

    Text text5;
    text5.setString("Green lose");
    text5.setPosition(225,145);
    text5.setColor(Color::Green);
    text5.setFont(font);

    while (window.isOpen()&&!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        sf::Event event;
        Vector2i mousePoz=Mouse::getPosition(window);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text5);
        window.display();
    }
        }

        if(Keyboard::isKeyPressed(Keyboard::D))
            paddle.move(8,0);
        if(Keyboard::isKeyPressed(Keyboard::A))
            paddle.move(-8,0);

        if(Keyboard::isKeyPressed(Keyboard::Right))
            paddle1.move(8,0);
        if(Keyboard::isKeyPressed(Keyboard::Left))
            paddle1.move(-8,0);



//paddle collision 1
        if(checkCollision(paddle,shape)==2)
        {
            ystep=-ystep;
        }
        else if(checkCollision(paddle,shape)==1)
        {
            xstep=-xstep;
        }
        else if(checkCollision(paddle,shape)==3)
        {
            ystep=-ystep;
            xstep=-xstep;
        }
//paddle collision 2
         if(checkCollision(paddle1,shape)==2)
        {
            ystep=-ystep;
        }
        else if(checkCollision(paddle1,shape)==1)
        {
            xstep=-xstep;
        }
        else if(checkCollision(paddle1,shape)==3)
        {
            ystep=-ystep;
            xstep=-xstep;
        }


        window.clear();
        window.draw(hard);
        window.draw(shape);
        window.draw(paddle1);
        window.draw(paddle);
        window.display();
    }
            }
         }

        window.clear();
        window.draw(mushroom);
        window.draw(button1);
        window.draw(text);
        window.draw(button2);
        window.draw(text1);
        window.draw(button3);
        window.draw(text2);
        window.draw(button01);
        window.draw(text0);
        window.draw(button02);
        window.draw(text01);
        window.draw(button03);
        window.draw(text02);
        window.display();

    }


}
}


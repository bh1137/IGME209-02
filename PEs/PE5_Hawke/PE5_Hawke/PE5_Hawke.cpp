// PE5_Hawke.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define SFML_STATIC
#include<SFML\Window.hpp>
#include<SFML\Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Brandon Hawke window");
    

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //screen color
        window.clear(sf::Color::Black);

        //shapes   
        //circle
        sf::CircleShape circle(50,50);
        circle.setFillColor(sf::Color(300, 200, 50));
        circle.move(350, 150);
        window.draw(circle);

        //triangle
        sf::CircleShape triangle(80.f, 3);
        triangle.scale(.50,.75);
        triangle.setFillColor(sf::Color(0, 0, 60));
        triangle.move(25, 290);
        window.draw(triangle);
        

        //octagon 
        sf::CircleShape octagon(80.f, 8);
        octagon.setFillColor(sf::Color(244, 147, 242));
        octagon.move(200, 10);
        octagon.scale(.50, 1);
        window.draw(octagon);

        //square
        sf::CircleShape square(50.f, 4);
        square.setFillColor(sf::Color(65, 59, 103));
        square.move(60, 20);
        square.rotate(45);
        window.draw(square);

        //pentagon 
        sf::CircleShape pentagon(35.f, 5);
        pentagon.setFillColor(sf::Color(0, 181, 236));
        pentagon.move(300, 260);
        pentagon.scale(.50, .50);
        window.draw(pentagon);


        window.display();
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

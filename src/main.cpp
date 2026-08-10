#include <SFML/Graphics.hpp>
#include <iostream>
#include "board.hpp"
#include "game.hpp"

int     main(){

        sf::RenderWindow window(sf::VideoMode(512, 512), "Xadrez Do Saladas", sf::Style::Close | sf::Style::Titlebar);
        Board board;
        Game game(board);

        while(window.isOpen())
        {
                sf::Event evnt;
                while (window.pollEvent(evnt))
                {
                        switch (evnt.type)
                        {
                                case sf::Event::Closed:
                                        window.close();
                                        break;
                                case sf::Event::Resized:
                                        std::cout       << "New window width: " << evnt.size.width 
                                                        << "New window height: " << evnt.size.height 
                                                        << std::endl;
                                        break;
                                case sf::Event::TextEntered:
                                        if (evnt.text.unicode < 128)
                                                printf("%c", evnt.text.unicode);
                                        break;
                                case sf::Event::MouseButtonPressed:
                                        game.mouseButtonPressedHandler(evnt.mouseButton);
                                        printf("%d\n", static_cast<int>(game.getSelectedPiece().type));
                                        break;
                                default:
                                        break;
                        }
                }

                window.clear();

                board.drawBoard(window);

                board.drawPieces(window);

                window.display();
        }

        return (0);
}
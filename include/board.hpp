#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "piece.hpp"

class Board
{
        private:
                sf::RectangleShape square;
                Piece boardMap[8][8];

                sf::Texture pieceTextures[12];
                sf::Sprite pieceSprite;

                void    setupInitialPosition();
                bool    loadTextures();
        
        public:
                Board();
                void    drawBoard(sf::RenderWindow &window);
                void    drawPieces(sf::RenderWindow &window);
};

#endif
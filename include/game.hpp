#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "board.hpp"

class Game
{
        private:
                Board& board;

                bool pieceSelected;
                Piece selectedPiece;
                int selectedRow;
                int selectedColumn;

        public:
                Game(Board& board);

                void mouseButtonPressedHandler(
                        const sf::Event::MouseButtonEvent& mouseEvent
                );
                const Piece& getSelectedPiece() const;
};

#endif
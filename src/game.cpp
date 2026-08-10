#include "game.hpp"

Game::Game(Board& board)
        : board(board),
          pieceSelected(false),
          selectedRow(-1),
          selectedColumn(-1)
{
}

const Piece& Game::getSelectedPiece() const
{
        return selectedPiece;
}

void Game::mouseButtonPressedHandler(const sf::Event::MouseButtonEvent& mouseEvent)
{
        int coluna = mouseEvent.x / 64;
        int linha = mouseEvent.y / 64;

        if (!((linha >= 0 && coluna >= 0) && (linha < 8 && coluna < 8)))
                return;

        const Piece& piece = board.getPiece(linha, coluna);

        if (piece.type == PieceType::Empty)
                return;

        selectedPiece = piece;
        pieceSelected = true;
        selectedRow = linha;
        selectedColumn = coluna;
}


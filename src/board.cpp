#include "board.hpp"
#include <cstdio>
#include <cctype>

Board::Board()
        : square(sf::Vector2f(64.0f, 64.0f))
{
        setupInitialPosition();

        if (!loadTextures())
        {
                std::fprintf(stderr, "Erro ao carregar texturas\n");
        }
}

// Draws the checkered pattern for the chess board

void     Board::drawBoard(sf::RenderWindow &window)
{
        int linha = 0;
        int coluna = 0;

        sf::Color whiteSquares(240, 217, 181);
        sf::Color blackSquares(181, 136, 99);

        for(linha = 0; linha < 8; linha++)
        {
                for(coluna = 0; coluna < 8; coluna++)
                {
                        if ((linha + coluna) %  2 == 0)
                                square.setFillColor(whiteSquares);
                        else
                                square.setFillColor(blackSquares);
                        
                        square.setPosition({coluna * 64.0f, linha * 64.0f});

                        window.draw(square);
                }
        }
}

// Hardcode the initial location for all the pieces by atributing a
// value to a matrix called boardMap[8][8] that is later used to draw all the pieces

// boardMap[linha][coluna] --> y = linha ; x = coluna

void    Board::setupInitialPosition()
{
        int     coluna = 0;
        int     linha = 0;

        const PieceType backRank[8] =
        {
                PieceType::Rook,
                PieceType::Knight,
                PieceType::Bishop,
                PieceType::Queen,
                PieceType::King,
                PieceType::Bishop,
                PieceType::Knight,
                PieceType::Rook
        };

        //Updates backrank black pieces position 

        for(coluna = 0; coluna < 8; coluna++)
        {
                boardMap[0][coluna].type = backRank[coluna];
                boardMap[0][coluna].color = PieceColor::Black;
        }

        coluna = 0;

        //Updates backrank white pieces position 

        for(coluna = 0; coluna < 8; coluna++)
        {
                boardMap[7][coluna].type = backRank[coluna];
                boardMap[7][coluna].color = PieceColor::White;
        }

        coluna = 0;

        //Updates both black and white pawns      

        for(coluna = 0; coluna < 8; coluna++)
        {
                boardMap[1][coluna].type = PieceType::Pawn;
                boardMap[1][coluna].color = PieceColor::Black;

                boardMap[6][coluna].type = PieceType::Pawn;
                boardMap[6][coluna].color = PieceColor::White;
        }

        coluna = 0;

        //Updates de empty space in the board

        for(linha = 2; linha < 6; linha++)
        {
                for(coluna = 0; coluna < 8; coluna++)
                {
                        boardMap[linha][coluna].type = PieceType::Empty;
                        boardMap[linha][coluna].color = PieceColor::None;
                }
        }
}

//Loads the textures into the pieceTextures array

bool Board::loadTextures()
{
        if (!pieceTextures[0].loadFromFile("assets/b-bishop.png"))
                return false;

        if (!pieceTextures[1].loadFromFile("assets/b-king.png"))
                return false;

        if (!pieceTextures[2].loadFromFile("assets/b-knight.png"))
                return false;

        if (!pieceTextures[3].loadFromFile("assets/b-pawn.png"))
                return false;

        if (!pieceTextures[4].loadFromFile("assets/b-queen.png"))
                return false;

        if (!pieceTextures[5].loadFromFile("assets/b-rook.png"))
                return false;

        if (!pieceTextures[6].loadFromFile("assets/w-bishop.png"))
                return false;

        if (!pieceTextures[7].loadFromFile("assets/w-king.png"))
                return false;

        if (!pieceTextures[8].loadFromFile("assets/w-knight.png"))
                return false;

        if (!pieceTextures[9].loadFromFile("assets/w-pawn.png"))
                return false;

        if (!pieceTextures[10].loadFromFile("assets/w-queen.png"))
                return false;

        if (!pieceTextures[11].loadFromFile("assets/w-rook.png"))
                return false;

        return true;
}

//Here we go through the boardMap matrix that was done earlier
//Basically, we check which PieceType we have and based on that
//we change the index which will allow us to choose the correct
//texture to be drawn on the board

void    Board::drawPieces(sf::RenderWindow &window)
{
        float   scaleFactor = 64.0f/480.0f;

        for(int linha = 0; linha < 8; linha++)
        {
                for(int coluna = 0; coluna < 8; coluna++)
                {
                        if (boardMap[linha][coluna].type == PieceType::Empty)
                                continue;

                        int     indice = -1;
                        
                        switch (boardMap[linha][coluna].type)
                        {
                                case PieceType::Bishop:
                                        if (boardMap[linha][coluna].color == PieceColor::Black)
                                                indice = 0;
                                        else if (boardMap[linha][coluna].color == PieceColor::White)
                                                indice = 6;
                                        break;

                                case PieceType::King:
                                        if (boardMap[linha][coluna].color == PieceColor::Black)
                                                indice = 1;
                                        else if (boardMap[linha][coluna].color == PieceColor::White)
                                                indice = 7;
                                        break;

                                case PieceType::Knight:
                                        if (boardMap[linha][coluna].color == PieceColor::Black)
                                                indice = 2;
                                        else if (boardMap[linha][coluna].color == PieceColor::White)
                                                indice = 8;
                                        break;

                                case PieceType::Pawn:
                                        if (boardMap[linha][coluna].color == PieceColor::Black)
                                                indice = 3;
                                        else if (boardMap[linha][coluna].color == PieceColor::White)
                                                indice = 9;
                                        break;

                                case PieceType::Queen:
                                        if (boardMap[linha][coluna].color == PieceColor::Black)
                                                indice = 4;
                                        else if (boardMap[linha][coluna].color == PieceColor::White)
                                                indice = 10;
                                        break;

                                case PieceType::Rook:
                                        if (boardMap[linha][coluna].color == PieceColor::Black)
                                                indice = 5;
                                        else if (boardMap[linha][coluna].color == PieceColor::White)
                                                indice = 11;
                                        break;

                                case PieceType::Empty:
                                        break;
                        }

                        if (indice == -1)
                        {
                                continue;
                        }

                        pieceSprite.setTexture(pieceTextures[indice]);

                        pieceSprite.setPosition({
                                coluna * 64.0f,
                                linha * 64.0f
                        });

                        pieceSprite.setScale(scaleFactor, scaleFactor);

                        window.draw(pieceSprite);
                }
        }
}
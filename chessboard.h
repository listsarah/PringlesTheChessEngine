#include <iostream>
#include <string>
#include <list>
#include <vector>
class Chessboard {
    public:
        u_int64_t whiteKingBoard;
        u_int64_t whiteQueenBoard;
        u_int64_t whiteRookBoard;   
        u_int64_t whiteBishopBoard;
        u_int64_t whiteKnightBoard;
        u_int64_t whitePawnBoard;
        u_int64_t blackKingBoard;
        u_int64_t blackQueenBoard;
        u_int64_t blackRookBoard;   
        u_int64_t blackBishopBoard;
        u_int64_t blackKnightBoard;
        u_int64_t blackPawnBoard;

        u_int64_t enemyPeices;
        u_int64_t yourPeices;
        u_int64_t allPeices;

        u_int64_t yourKing;
        u_int64_t yourQueen;
        u_int64_t yourRooks;
        u_int64_t yourBishops;
        u_int64_t yourKnights;
        u_int64_t yourPawns;

        u_int8_t yourKingIndex;

        bool colorToPlay;

        u_int8_t pawnsElegibleForDoubleMove;
        int enemyRank;

        std::vector<int> straightLeftMoves = {-1, -2, -3, -4, -5, -6, -7};
        std::vector<int> straightRightMoves = {1, 2, 3, 4, 5, 6, 7};
        std::vector<int> straightUpMoves = {-8, -16, -24, -32, -40, -48, -56};
        std::vector<int> straighDownMoves = {8, 16, 24, 32, 40, 48, 56};
        std::vector<int> diagonalLeftDownMoves = {7, 14, 21, 28, 35, 42, 49};
        std::vector<int> diagonalRightDownMoves = {9, 18, 27, 36, 45, 54, 63};
        std::vector<int> diagonalLeftUpMoves = {7, 14, 21, 28, 35, 42, 49};
        std::vector<int> diagonalRightUpMoves = {9, 18, 27, 36, 45, 54, 63};

        std::vector<std::vector<int>> pawnMovesWhite = {{-16}, {-8}, {-7, -9}};
        std::vector<std::vector<int>> pawnMovesBlack = {{-16}, {-8}, {-7, -9}};

        std::vector<std::vector<int>> kingMoves = {{-9, -8, -7, -1, 1, 7, 8, 9}};
        std::vector<std::vector<int>> queenMoves = {straightLeftMoves, straightRightMoves, straightUpMoves, straighDownMoves, diagonalLeftDownMoves, diagonalRightDownMoves, diagonalLeftUpMoves, diagonalRightUpMoves};
        std::vector<std::vector<int>> rookMoves = {straightLeftMoves, straightRightMoves, straightUpMoves, straighDownMoves};
        std::vector<std::vector<int>> bishopMoves = {diagonalLeftDownMoves, diagonalRightDownMoves, diagonalLeftUpMoves, diagonalRightUpMoves};
        std::vector<std::vector<int>> knightMoves = {{15, 17, 6, 10, -15, -17, -6, -10}};
        std::vector<std::vector<int>> pawnMoves;
        

        void configureBoards(std::string fen);
        void prettyPrint();
        
        std::vector<std::vector<u_int16_t>> getLegalMoves();
        std::vector<u_int16_t> getLegalMovesKing(int currIndex);
        std::vector<u_int16_t> getLegalMovesQueen(int currIndex);
        std::vector<u_int16_t> getLegalMovesRook(int currIndex);
        std::vector<u_int16_t> getLegalMovesBishop(int currIndex);
        std::vector<u_int16_t> getLegalMovesKnight(int currIndex);
        std::vector<u_int16_t> getLegalMovesPawn(int currIndex);

        std::vector<std::vector<u_int16_t>> removeCheckMoves(std::vector<std::vector<u_int16_t>> fullMoveList);
        std::vector<Chessboard> movesToBoards(Chessboard oldBoard, std::vector<std::vector<u_int16_t>> moves);

        int main();
        Chessboard(bool blackPeicesHuh);
};
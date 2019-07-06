/*
Queen Movement Code
    Project supports the Queen's movement pattern
    -Diagonal
    -Horizontal
    -Vertical
    -Any Distance
    -Cannot Jump over pieces

    Plan
    -Determine if destination is a valid location
    -Determine if destination is horizontal, vertical, or diagonal of Queen
    -Check for any pieces in the way of the movement
*/

#include "chessEngine.h"
#include <iostream>
#include <string>

using namespace std;

bool chessEngine::checkForPositiveDiagonal(int originX, int originY, int destinationX, int destinationY)
{
    if (originX > destinationX)
    {
        for (int i = 1; originX + i < destinationX ; i++)
        {
            if (board[originX + i][originY + i].find("37;1;") != string::npos) // Checks if space in the way is empty
                return false;
            else if (board[originX + i][originY + i].find("30;1;") != string::npos)
                return false;
        }
    }

    else
    {
        for (int i = 1; originX - i > destinationX ; i++)
        {
            if (board[originX - i][originY - i].find("37;1;") != string::npos) // Checks if space in the way is empty
                return false;
            else if (board[originX - i][originY - i].find("30;1;") != string::npos) // Checks if space in the way is empty
                return false;
        }
    }

    return true;
}

bool chessEngine::checkForNegativeDiagonal(int originX, int originY, int destinationX, int destinationY)
{
    if (originX > destinationX)
    {
        for (int i = 1; originX + i < destinationX ; i++)
        {
            if (board[originX + i][originY - i].find("37;1;") != string::npos) // Checks if space in the way is empty
                return false;
            else if (board[originX + i][originY - i].find("30;1;") != string::npos) // Checks if space in the way is empty
                return false;
        }
    }

    else
    {
        for (int i = 1; originX - i > destinationX ; i++)
        {
            if (board[originX - i][originY + i].find("37;1;") != string::npos) // Checks if space in the way is empty
                return false;
            else if (board[originX - i][originY + i].find("30;1;") != string::npos) // Checks if space in the way is empty
                return false;
        }
    }

    return true;
}

bool chessEngine::checkForHorizontal(int originX, int originY, int destinationX)
{
    if (originX > destinationX)
    {
        for (int i = 1; originX + i < destinationX ; i++)
        {
            if (board[originX + i][originY].find("37;1;") != string::npos) // Checks if space in the way is empty
                return false;
            else if (board[originX + i][originY].find("30;1;") != string::npos) // Checks if space in the way is empty
                return false;
        }   
    }

    else
    {
        for (int i = 1; originX - i > destinationX ; i++)
        {
            if (board[originX + i][originY].find("37;1;") != string::npos) // Checks if space in the way is empty
                return false;
            else if (board[originX + i][originY].find("30;1;") != string::npos) // Checks if space in the way is empty
                return false;
        } 
    }

    return true;
}

bool chessEngine::checkForVertical(int originX, int originY, int destinationY)
{
    if (originY < destinationY) // Checks if move goes up or down
    {
        for (int i = 1; originY + i < destinationY ; i++)
        {
            if (board[originX][originY + i].find("37;1;") != string::npos) // Checks if space in the way is empty
                return false;
            else if (board[originX][originY + i].find("30;1;") != string::npos) // Checks if space in the way is empty
                return false;
        }
    }  

    else
    {
        for (int i = 1; originY - i > destinationY ; i++)
        {
            if (board[originX][originY - i].find("37;1;") != string::npos) // Checks if space in the way is empty
                return false;
            else if (board[originX][originY - i].find("30;1;") != string::npos) // Checks if space in the way is empty
                return false;

        }
    }
}


// [NOTE] Convert Coordinates into int prior to using function
bool chessEngine::queenMove(bool whiteTurn, int originX, int originY, int destinationX, int destinationY)
{
    //Variable Declaration and Initalization/////////////////////////
    int distanceX, distanceY;
    bool legalMove;

    distanceX = destinationX - originX;
    distanceY = destinationY - originY;
    
    //Main Body//////////////////////////////////////////////////////
    if (distanceX == distanceY) // If the X and Y Distances are the same, the move is positve diagonal
        legalMove = chessEngine::checkForPositiveDiagonal(originX, originY, destinationX, destinationY);
    else if (-(distanceX) == distanceY) // If the X and Y distances are the same value but different parity, the move is negative diagonal
        legalMove = chessEngine::checkForNegativeDiagonal(originX, originY, destinationX, destinationY);
    else if (originX == destinationX) // If X coordinate of both origin and destination are the same, then the move is horizontal
        legalMove = chessEngine::checkForHorizontal(originX, originY, destinationX);
    else if (originY == destinationY) // If Y coordinate of both origin and destination are the same, then the move is vertical
        legalMove = chessEngine::checkForVertical(originX, originY, destinationY);
    else // All other cases, the move is not legal for the Queen
        legalMove = false;

    //Consequent/////////////////////////////////////////////////////
    if (legalMove)
        cout << "Queen " << originX << originY << " move to " << destinationX << destinationY << endl;
    else
        cout << "Illegal Move" << endl;

    return legalMove;
}
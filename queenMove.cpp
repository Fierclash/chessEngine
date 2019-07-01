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

bool legalMoveSpace (int originX, int originY, int destinationX int destinationY)
{
    if ((originX == destinationX && originY == destinationY) ||
        !(originX >= 1 && originX <= 8) ||
        !(originY >= 1 && originY <= 8) ||
        !(destinationX >= 1 && destinationX <= 8) ||
        !(destinationY >= 1 && destinationY <= 8))
        return false;
    /*else if (if piece is the same color as the current player)
        return false;*/
    else
        return true;
}

bool checkForPositiveDiagonal(int originX, int originY, int destinationX, int destinationY)
{
    if (originX > destinationX)
    {
        for (int i = 1; originX + i < destinationX ; i++)
        {
            if (board[originX + i][originY + i] != "") // Checks if space in the way is empty
                return false;
        }
    }

    else
    {
        for (int i = 1; originX - i > destinationX ; i++)
        {
            if (board[originX - i][originY - i] != "") // Checks if space in the way is empty
                return false;
        }
    }

    return true;
}

bool checkForNegativeDiagonal(int originX, int originY, int destinationX, int destinationY)
{
    if (originX > destinationX)
    {
        for (int i = 1; originX + i < destinationX ; i++)
        {
            if (board[originX + i][originY - i] != "") // Checks if space in the way is empty
                return false;
        }
    }

    else
    {
        for (int i = 1; originX - i > destinationX ; i++)
        {
            if (board[originX - i][originY + i] != "") // Checks if space in the way is empty
                return false;
        }
    }

    return true;
}

bool checkForHorizontal(int originX, int originY, int destinationX)
{
    if (originX > destinationX)
    {
        for (int i = 1; originX + i < destinationX ; i++)
        {
            if (board[originX + i][originY] != "") // Checks if space in the way is empty
                return false;
        }   
    }

    else
    {
        for (int i = 1; originX - i > destinationX ; i++)
        {
            if (board[originX + i][originY] != "") // Checks if space in the way is empty
                return false;
        } 
    }

    return true;
}

bool checkForVertical(int originX, int originY, int destinationY)
{
    if (originY < destinationY) // Checks if move goes up or down
    {
        for (int i = 1; originY + i < destinationY ; i++)
        {
            if (board[originX][originY + i] != "") // Checks if space in the way is empty
                return false;
        }
    }  

    else
    {
        for (int i = 1; originY - i > destinationY ; i++)
        {
            if (board[originX][originY - i] != "") // Checks if space in the way is empty
                return false;
        }
    }
}


// [NOTE] Convert Coordinates into int prior to using function
void chessEngine::queenMove(int originX, int originY, int destinationX int destinationY)
{
    //Variable Declaration and Initalization/////////////////////////
    int distanceX, distanceY;
    bool legalMove;

    distanceX = destinationX - originX;
    distanceY = destinationY - originY;
    
    //Main Body//////////////////////////////////////////////////////
    if (distanceX == distanceY) // If the X and Y Distances are the same, the move is positve diagonal
        legalMove = checkForDiagonal();
    else if (-(distanceX) == distanceY) // If the X and Y distances are the same value but different parity, the move is negative diagonal
        legalMove = checkForNegativeDiagonal();
    else if (originX == destinationX) // If X coordinate of both origin and destination are the same, then the move is horizontal
        legalMove = checkForHorizontal();
    else if (originY == destinationY) // If Y coordinate of both origin and destination are the same, then the move is vertical
        legalMove = checkForVertical();
    else // All other cases, the move is not legal for the Queen
        legalMove = false;

    //Consequent/////////////////////////////////////////////////////
    if (legalMove)
    {
        board[originX][originY] = "";
        board[endX]][endY] = queen;
        cout << "Queen " << originX << originY << " move to " destinationX << destinationY << endl;
    }
    else
        cout << "Illegal Move" << endl;
}
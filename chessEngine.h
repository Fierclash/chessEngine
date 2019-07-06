#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class chessEngine {
	public:
		static const int SIZE = 8;
		// object
		chessEngine();

		// chess piece moves
		void pieceMove(bool&, char, char, char, char);
		bool checkForPositiveDiagonal(int, int, int, int);
		bool checkForNegativeDiagonal(int , int , int , int );
		bool checkForHorizontal(int , int , int );
		bool checkForVertical(int , int , int );
		bool pawnMove(bool,bool, int, int, int, int);
		bool kingMove(bool,int, int, int, int);
		bool queenMove(bool,int, int, int, int);
		bool knightMove(bool,int, int, int, int);
		bool rookMove(bool,int, int, int, int);
		bool bishopMove(bool,int, int, int, int);
		//Switch spaces (For movement function)
		void changeSpace(string,bool,int, int, int, int);

		// win/lose
		bool over() const;
		// outputs the board
		void output() const;

	private:
		string board[SIZE][SIZE];
		string pawn, rook, knight, bishop, king, queen;
		
};

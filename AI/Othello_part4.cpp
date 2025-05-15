//NTOU 2025/5/15 Othello part 4
//Minimax search
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<limits.h>
using namespace std;

const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int countFlipPieces(string board,int playercolor,int position,int direction){
	int flipCount=0;
	int x=position%6;
	int y=position/6;
	bool canFlip=false;
	char me,opponent;
	opponent=(playercolor == 1) ? 'O' : 'X';
    me=(playercolor == 1) ? 'X' : 'O';
	int nextX=x+dx[direction];
    int nextY=y+dy[direction];
    
    while(nextX>=0 && nextX<=5 && nextY>=0 && nextY<=5 && board[nextY*6 +nextX]==opponent){
    	flipCount++;
    	nextX+=dx[direction];
    	nextY+=dy[direction];
    	canFlip=true;
	}
	if(!(nextX>=0 && nextX<=5 && nextY>=0 && nextY<=5 && board[nextY*6 +nextX]==me && canFlip)){
		flipCount=0;
	}
	//printTable(table);
	return flipCount;
}

string flipPieces(string board,int playercolor,int position){
	int x=position%6;
	int y=position/6;
	int nextX;
    int nextY;  
    int num=0;
	char fillColor=(playercolor==1)?'X':'O';//黑子填X
	board[y*6+x]=fillColor;//放自己的棋子 
  	for(int dir=0;dir<8;dir++){
		int nextX=x+dx[dir];
    	int nextY=y+dy[dir];
		num=countFlipPieces(board,playercolor,position,dir);
		for(int i=0;i<num;i++){
			board[nextY*6+nextX]=fillColor;
			nextX+=dx[dir];
    		nextY+=dy[dir];	
		}
	}
	return board;
}

int countColorPieces(string board,int playercolor){
	int blackcount=0,whitecount=0;	
	for(int i=0;i<board.length();i++){
		if(board[i]=='X')		blackcount++;
		else if(board[i]=='O') 	whitecount++;	
	}
	if(playercolor==1)//黑子 
		return blackcount;
	else if(playercolor==2)
		return whitecount;
	else
		return 0;
}

int heuristicScore(string gameboard,int playercolor){
	int opponentcolor=(playercolor==1) ? 2 : 1;
	return countColorPieces(gameboard,playercolor) - countColorPieces(gameboard,opponentcolor);
}

vector<int> getValidMoves(string board, int playercolor) {
    vector<int> validMoves;
    char opponent,me;
    for (int i=0;i<36;i++) {
        int x=i%6;
        int y=i/6;
        //1是黑 2 是白 playercolor =1的話，對手是白棋(O) 
        opponent=(playercolor == 1) ? 'O' : 'X';
        me=(playercolor == 1) ? 'X' : 'O';
        if (board[i] != '+') continue;//不是空白，不能下棋 

        bool isValid = false;
        for (int dir=0; dir<8;dir++) {
            int nextX=x+dx[dir];
            int nextY=y+dy[dir];
            bool canFlip=false;

            while (nextX>=0 && nextX<6 && nextY>=0 && nextY<6 && board[nextY*6 +nextX] !='+'&& board[nextY*6+nextX]==opponent) {
                canFlip = true;
                nextX += dx[dir];
                nextY += dy[dir];
            }
            //如果下一個是我方棋子才可以包夾 
            if (canFlip && nextX>=0 && nextX<6 && nextY>=0 && nextY<6 && board[nextY*6 +nextX] == me) {
                isValid = true;
                break;
            }
        }
        if (isValid) {
            validMoves.push_back(i);
        }
    }
    return validMoves;
}

int minimaxSearch(string gameboard,int originalplayercolor,int depth,int currentPlayerColor){
	int bestscore,score;
	int nextPlayerColor = (currentPlayerColor == 1) ? 2 : 1;
	string newboard;
	vector<int> currentValidMoves=getValidMoves(gameboard, currentPlayerColor);
    vector<int> nextValidMoves=getValidMoves(gameboard, nextPlayerColor);

	if(depth==0||(nextValidMoves.empty() && currentValidMoves.empty()))
		return heuristicScore(gameboard,originalplayercolor);
	
	if (currentValidMoves.empty()) {//當前玩家無棋可下但對手有棋可下，pass 
		//注意depth-1 因為當前玩家沒有下棋，浪費一回合，因此要往下一層搜尋 
        return minimaxSearch(gameboard,originalplayercolor,depth-1,nextPlayerColor);
    }
    
	if(currentPlayerColor==originalplayercolor){//maxnode 
		bestscore=-INT_MAX;
		for(int i=0;i<currentValidMoves.size();i++){
			newboard=flipPieces(gameboard,currentPlayerColor,currentValidMoves[i]);
			//換min player 
			score=minimaxSearch(newboard, originalplayercolor, depth-1,nextPlayerColor);
			bestscore=max(bestscore,score);
		}
	}
	else{
		bestscore=INT_MAX;
		for(int i=0;i<currentValidMoves.size();i++){
			newboard=flipPieces(gameboard,currentPlayerColor,currentValidMoves[i]);
			//換max player 
			score=minimaxSearch(newboard, originalplayercolor, depth-1,nextPlayerColor);
			bestscore=min(bestscore,score);
		}
	}
	return bestscore;
}

void findBestMove(string board, int playercolor, int depth) { 
    vector<int> validMoves = getValidMoves(board, playercolor);
    vector<int> scores;
    int bestScore = -INT_MAX;
    int bestMove = -1;
	int nextPlayerColor = (playercolor == 1) ? 2 : 1;
    for (int move : validMoves) {
        string newBoard = flipPieces(board, playercolor,move);
        int score = minimaxSearch(newBoard, playercolor, depth - 1, nextPlayerColor);
        scores.push_back(score);
    	if (score > bestScore) {
            bestScore = score;
            bestMove = move;
        }
        
    }

    if (bestMove != -1) {
    	for(int i=0;i<scores.size();i++){
    		int move=validMoves[i];
    		char rowChar = 'A' + (move / 6);
		    char colChar = 'a' + (move % 6);
		    //cout << rowChar << colChar <<" "<< scores[i] << endl;
		    
		}
		//cout<<"["<<char('A'+(bestMove/6))<<char('a'+(bestMove%6))<<"]"<<endl;
        cout<<char('A'+(bestMove/6))<<char('a'+(bestMove%6))<<endl;
    }
}
int main(){
	string board;
	int datacount,playercolor,depth;
	cin>>datacount;
	for(int i=0;i<datacount;i++){
		cin>>board;
		cin>>playercolor;
		cin>>depth;
		findBestMove(board,playercolor,depth);
	}	
	
	return 0;
}
/*
in:
6
OO++++XOOXXX+XOXX++OXXOO+XXOX++XXXX+
2
4
OO++++XOOXXX+XOXX++OXXOO+XXOX++XXXX+
2
6
OO++++XOOXXX+XOXX++OXXOO+XXOX++XXXX+
2
8
++++XOX+X+X+OOOOX+XOOOXOXOOOOXXO++++
1
4
++++XOX+X+X+OOOOX+XOOOXOXOOOOXXO++++
1
6
++++XOX+X+X+OOOOX+XOOOXOXOOOOXXO++++
1
8
out:
Ad
Ff
Ca
Fc
Cf
Bd

額外測資
in:
1
OXXO+++OXOO+OOOOOX+OXXX++XXXX+X+XXXX
2
6
out:
Df -18
Ef -16
Fb -18
*/

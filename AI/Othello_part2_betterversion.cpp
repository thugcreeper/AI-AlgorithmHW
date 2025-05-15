//NTOU 2025/5/04 Othello part 2 Flip pieces
//the state of a new board where all pissible flippings are performed 
//(NOTE that the original board is not modified)
#include<iostream>
#include<vector>
#include<string>

using namespace std;

const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

//Direction ID 0 ~ 7 denote the eight directions,
// i.e. 上 up, 右上 up-right, 右 right, 右下 down-right, 下 down, 左下 down-left, 左 left, and 左上 up-left.
int countFlipPieces(string board,int playercolor,vector<char> position,int direction){
	int flipCount=0;
	int x=position[1]-'a';
	int y=position[0]-'A';
	//cout<<"x="<<x<<"y="<<y<<endl;
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


void flipPieces(string board,int playercolor,vector<char>position){
	string newboard=board;
	int num;
	int y=position[0]-'A';
	int x=position[1]-'a';
	int nextX;
    int nextY;
	char fillColor=(playercolor==1)?'X':'O';//黑子填X 
	for(int dir=0;dir<8;dir++){
		int nextX=x+dx[dir];
    	int nextY=y+dy[dir];
		num=countFlipPieces(newboard,playercolor,position,dir);
		newboard[y*6+x]=fillColor;
		for(int i=0;i<num;i++){
			newboard[nextY*6+nextX]=fillColor;
			nextX+=dx[dir];
    		nextY+=dy[dir];
		}
		
	}
	cout<<"board after flipped: "<<newboard<<endl;
	//printTable(table);
}
int main(){
	string board;
	int datacount,playercolor,direction;
	vector<char> position(2);
	cin>>datacount;
	for(int i=0;i<datacount;i++){
		cin>>board;
		cin>>playercolor;
		cin>>position[0]>>position[1];
		flipPieces(board,playercolor,position);
	}
	
	
	return 0;
}
/*
in:
3
+++++++++XX++OOOX+++OXOO++X+XX++++++
2
Ae
+++++++++XX++OOOX+++OXOO++X+XX++++++
2
Cf
+++++++++XX++OOOX+++OXOO++X+XX++++++
1
Cf
out:
++++O++++OO++OOOO+++OXOO++X+XX++++++
+++++++++XX++OOOOO++OXOO++X+XX++++++
+++++++++XX++OOOXX++OXOX++X+XX++++++
*/

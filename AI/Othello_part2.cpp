//NTOU 2025/5/04 Othello part 2 Flip pieces
//the state of a new board where all pissible flippings are performed 
//(NOTE that the original board is not modified)
#include<iostream>
#include<vector>
#include<string>

using namespace std;

const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

vector<vector<char>> convertToTable(string board){
	vector<vector<char>> table(6, vector<char>(6, 0));
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			table[i][j]=board[i*6+j];
		}
	}	
	return table;
}

void printTable(vector<vector<char>> table){
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}	
}

//Direction ID 0 ~ 7 denote the eight directions,
// i.e. 上 up, 右上 up-right, 右 right, 右下 down-right, 下 down, 左下 down-left, 左 left, and 左上 up-left.
int countFlipPieces(string board,int playercolor,vector<char> position,int direction){
	vector<vector<char>> table=convertToTable(board);
	int flipCount=0;
	int y=position[0]-'A';
	int x=position[1]-'a';
	bool canFlip=false;
	char me,enemy;
	if(playercolor==1){//黑子 
		me='X';
		enemy='O';
		table[y][x]='X';
	}
	else if(playercolor==2){//白子
		me='O';
		enemy='X';
	 	table[y][x]='O';	
	}
	else{
		cout<<"illegal player color"<<endl;
	}
	int nextX=x+dx[direction];
    int nextY=y+dy[direction];
    
    while(nextX>=0 && nextX<=5 && nextY>=0 && nextY<=5 && table[nextY][nextX]==enemy){
    	flipCount++;
    	nextX+=dx[direction];
    	nextY+=dy[direction];
    	canFlip=true;
	}
	if(!(nextX>=0 && nextX<=5 && nextY>=0 && nextY<=5 && table[nextY][nextX]==me && canFlip)){
		flipCount=0;
	}
	//printTable(table);
	return flipCount;
}

void flipPieces(string board,int playercolor,vector<char>position){
	vector<vector<char>> table=convertToTable(board);
	int num;
	int y=position[0]-'A';
	int x=position[1]-'a';
	int nextX;
    int nextY;
	char fillColor=(playercolor==1)?'X':'O';//黑子填X 
	for(int dir=0;dir<8;dir++){
		int nextX=x+dx[dir];
    	int nextY=y+dy[dir];
		num=countFlipPieces(board,playercolor,position,dir);
		table[y][x]=fillColor;
		for(int i=0;i<num;i++){
			table[nextY][nextX]=fillColor;
			nextX+=dx[dir];
    		nextY+=dy[dir];
		}
		
	}
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			cout<<table[i][j];
		}
	}
	cout<<endl;
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

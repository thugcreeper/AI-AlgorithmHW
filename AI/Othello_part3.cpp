//NTOU 2025/5/04 Othello part 3
//Count pieces in the same color
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int countColorPieces(string board,int playercolor){
	int blackcount=0,whitecount=0;	
	for(int i=0;i<board.length();i++){
		if(board[i]=='X')		blackcount++;
		else if(board[i]=='O') 	whitecount++;	
	}
	if(playercolor==1)//¶Â¤l 
		return blackcount;
	else if(playercolor==2)
		return whitecount;
	else
		return 0;
}

int main(){
	string board;
	int datacount,playercolor;
	cin>>datacount;
	for(int i=0;i<datacount;i++){
		cin>>board;
		cin>>playercolor;
		cout<<countColorPieces(board,playercolor)<<endl;
	}
	
	
	return 0;
}
/*
in:
2
+++++++++XX++OOOX+++OXOO++X+XX++++++
1
+++++++++XX++OOOX+++OXOO++X+XX++++++
2
out:
7
6
*/

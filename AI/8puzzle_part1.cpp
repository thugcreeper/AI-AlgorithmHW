//NTOU 2025/3/19 N puzzle part 1
#include <iostream> 
#include <vector>
#include <cmath>
#include <string>
using namespace std;

void convertInt(vector<int> &board,string puzzle,int len){
	for(int i=0;i<len;i++){
		board[i]=int(puzzle[i])-'0';
	}
}

void printboard(vector<int> board){
	for(auto &v:board){
		cout<<v<<" ";
	}
}

bool isSolvable(vector<int> &board,int len){
	int i,j,count=0;//disorder digits
	for(i=0;i<len;i++){
		for(j=i+1;j<len;j++){
			if(board[i]>board[j] && board[i]>0 && board[j]>0)
				count++;
		}
	}
	int n=sqrt(len);
	/*If n is even, and the index of the row containing the empty tile 
	plus the number of disorder digits is even, the problem is solvable.*/
	if(n%2==0){
		for(i=0;i<len;i++){
			if(board[i]==0){
				count+=i/n;
				break;
			}
		}	
	}
	if(count%2==0){
		cout<<"YES"<<endl;
		return true;
	}
	else{
		cout<<"NO"<<endl;
		return false;
	}
}

int main(){
	string puzzle;
	int datacount,i=0;
	cin>>datacount;
	for(i=0;i<datacount;i++){
		cin>>puzzle;
		int len=puzzle.length();
		vector<int> board(len);
		convertInt(board,puzzle,len);
		//printboard(board);
		isSolvable(board,len);
	}	
	return 0;
}
/*
in:
10
312457680
724506831
438126507
167352480
104782563
817365204
320685741
426031785
102345678
041235678
out:
NO
YES
NO
NO
YES
YES
NO
YES
YES
NO
*/

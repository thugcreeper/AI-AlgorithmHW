// NTOU 2025/3/20 N puzzle part 3
#include <iostream> 
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int manhattan_distance(const string& puzzle,int len){
	int i,n,distance=0;
	int xi,yi,x,y;
	vector<int> board(len);

	n=sqrt(len);
	for(i=0;i<len;i++){
		board[i]=int(puzzle[i])-'0';
		if(board[i]!=0){
			xi=i%n;//correct position
			yi=i/n;
			x=board[i]%n;//current position
			y=board[i]/n;
			distance+=abs(xi-x)+abs(yi-y);
		}
	}
	return distance;
}

int main(){
	int datacount;
    cin >> datacount; 
	int distance;
    string puzzle;
    for(int i = 0; i < datacount; ++i){
        cin >> puzzle;
        int len=puzzle.length();
        distance=manhattan_distance(puzzle,len);
        cout<<distance<<endl;      
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
6
18
17
12
15
15
10
13
1
6
*/ 

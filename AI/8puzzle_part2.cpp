// NTOU 2025/3/19 N puzzle part 2
#include <iostream> 
#include <vector>
#include <cmath>
#include <string>
using namespace std;
void printboard(vector<vector<int>> &board,int n){
	for(int i = 0; i < n; i++){
        for(int j = 0; j < n; ++j){
            cout<<board[i][j];
        }
    }
    cout<<""<<endl;
}
void possibleStep(const string& puzzle,int len){
	int x0,y0,i,j;
	int n = sqrt(len);
    vector<vector<int>> matrix(n, vector<int>(n));

    int idx = 0;
    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            matrix[i][j] = puzzle[idx++]-'0';
        }
    }
    //find '0' 's position
	for(i = 0; i < n; i++){
        for(j = 0; j < n; ++j){
            if(matrix[i][j] == 0){
            	x0=i;y0=j;
			}
        }
    }
    int step=0;//possible step count
    if(x0==1) step+=2;
    else step+=1;
    if(y0==1) step+=2;
    else step+=1;
    cout<<step<<endl;
    if(x0>0){
    	cout <<"move 0 to up"<< endl;
    	swap(matrix[x0][y0],matrix[x0-1][y0]);
    	printboard(matrix,n);
    	swap(matrix[x0][y0],matrix[x0-1][y0]);
    	
	}
	if(x0<n-1){
    	cout <<"move 0 to down"<< endl;
    	swap(matrix[x0][y0],matrix[x0+1][y0]);
    	printboard(matrix,n);
    	swap(matrix[x0][y0],matrix[x0+1][y0]);
	}
	if(y0>0){
    	cout <<"move 0 to left"<< endl;
    	swap(matrix[x0][y0],matrix[x0][y0-1]);
    	printboard(matrix,n);
		swap(matrix[x0][y0],matrix[x0][y0-1]);	
	}
	if(y0<n-1){
    	cout <<"move 0 to right"<< endl;
    	swap(matrix[x0][y0],matrix[x0][y0+1]);
    	printboard(matrix,n);
		swap(matrix[x0][y0],matrix[x0][y0+1]);	
	}
	
    //cout<<x0<<" "<<y0<<endl; 
}

int main(){
    int step;
    cin >> step; 

    string puzzle;
    for(int i = 0; i < step; ++i){
        cin >> puzzle;
        int len=puzzle.length();
        possibleStep(puzzle,len);
    }   
    return 0;
}

/*
in:
7
312457680
724506831
438126507
104782563
320685741
426031785
041235678
out:
2
move 0 to up
312450687
move 0 to left
312457608
4
move 0 to up
704526831
move 0 to down
724536801
move 0 to left
724056831
move 0 to right
724560831
3
move 0 to up
438106527
move 0 to left
438126057
move 0 to right
438126570
3
move 0 to down
184702563
move 0 to left
014782563
move 0 to right
140782563
2
move 0 to down
325680741
move 0 to left
302685741
3
move 0 to up
026431785
move 0 to down
426731085
move 0 to right
426301785
2
move 0 to down
241035678
move 0 to right
401235678
*/

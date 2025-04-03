// NTOU 2025/3/19 N puzzle part 2
//Successor function O(datacount * n^2) 
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
            if(matrix[i][j] == 0)	{x0=i;y0=j;	}
        }
    }

    int step=((x0==1) ?2:1)+((y0==1) ?2:1);//possible step count
    cout<<step<<endl;
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};
    const string directions[] = {"up", "down", "left", "right"};
    
    for (int dir = 0; dir < 4; dir++) {
        int nx = x0 + dx[dir];
        int ny = y0 + dy[dir];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            cout << "Move 0 to " << directions[dir] << endl;
            swap(matrix[x0][y0], matrix[nx][ny]);
            printboard(matrix, n);
            swap(matrix[x0][y0], matrix[nx][ny]);
        }
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

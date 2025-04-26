//2025/4/26 NTOU Algorithm pratice3_1_knapsack_problem
//O(itemcount*backpacksize) 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knapsack(vector<int> &weight,vector<int> &value,int itemcount,int backpacksize){
	//原本用array會TLE 用vector快很多 
	//=c[itemcount+1][backpacksize+1]
	vector<vector<int>> c(itemcount+1,vector<int>(backpacksize+1));
	for(int i=0;i<itemcount;i++){
		for(int j=0;j<=backpacksize;j++){
			if(j-weight[i]<0){//裝不下 
				c[i+1][j]=c[i][j];
			}
			else{
				c[i+1][j]=max(c[i][j],c[i][j-weight[i]]+value[i]);
			}
		}
	}
	int maxprice=c[itemcount][backpacksize];
	return maxprice;
}
int main(){
	int itemcount,backpacksize;
	cin>>itemcount>>backpacksize;
	vector<int> weight(itemcount);
	vector<int> value(itemcount);
	for(int i=0;i<itemcount;i++){
		cin>>weight[i]>>value[i];
	}
	cout<<knapsack(weight,value,itemcount,backpacksize)<<endl;
	return 0;
}
/*
in:
6 100
10 8
25 25
65 75
25 29
25 17
15 20
out:
112

in:
3 10
1 10
2 10
3 20
out:
40
*/

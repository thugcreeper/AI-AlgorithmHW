//2025/3/16 NTOU Algorithm pratice2-2:Fractional_knapsack_problem
//O(nlogn)
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

typedef struct{
	int value;
	int weight;	
}item;

void printvector(vector<item> &vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i].value<<" "<<vec[i].weight<<endl;
	}
}

bool vdivideW(item a,item b){//value/weight
	return ((double)a.value/a.weight)>((double)b.value/b.weight);
} 

double knapsack_problem(vector<item> &treasure,double capacity){
	double load=0,value=0;
	int i=0;
	while(load<capacity && i<treasure.size()){
		if(treasure[i].weight<=(capacity-load)){
			value+=treasure[i].value;//take all of the item
			load+=treasure[i].weight;
		}
		else{
			value+=((capacity-load)/treasure[i].weight)*treasure[i].value;
			load+=(capacity-load);
		}
		i++;
	}
	return value;
}
int main(){
int item_count;
double capacity;
	cin>>item_count>>capacity;
	vector<item> treasure(item_count);
	for(int i=0;i<item_count;i++){
		cin>>treasure[i].value>>treasure[i].weight;
	}
	//sort by value/weight
	sort(treasure.begin(),treasure.end(),vdivideW);
	double total_value=knapsack_problem(treasure,capacity);
	cout<<fixed<<setprecision(6)<<total_value<<endl;
	//printvector(treasure);
	return 0;
}
/*
homo特有的無處不在哼哼哼啊啊啊啊啊(全惱 
in:
3 931
114 514
1919 810
364 364

out:
2040.000000

in:
11 75
33 38
80 87
3 38
77 29
52 51
82 7
51 43
27 34
39 89
32 13
44 66

out:
221.837209
*/

//2025/3/25 NTOU Algorithm pratice2-3:Baker¡¦s_Dilemma
//O(nlogn)
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct{
	int day;
	int penalty;
	int number;//¬y¤ô½s¸¹ 
}order;

//If there is more than one set of answers, 
//print the one with the smallest dictionary order
bool compare(order &a,order &b){
	double weightA=(double)a.penalty/a.day;
	double weightB=(double)b.penalty/b.day;
	if(weightA==weightB)
		return a.number<b.number;
	return weightA>weightB;
} 

void printOrders(vector<order> &orders,int len){
	for(int i=0;i<len;i++){
		cout<<orders[i].number<<" ";		
	}
	cout<<endl;
}

int main(){
	int datacount,i;
	cin>>datacount;
	vector<order> work(datacount);
	for(i=0;i<datacount;i++){
		cin>>work[i].day>>work[i].penalty;
		work[i].number=i+1;
	}
	sort(work.begin(),work.end(),compare);
	printOrders(work,datacount);
	return 0;
}
/*
in:
4
3 4
1 1000
2 2
5 5

out:
2 1 3 4

in:
5
3 4
1 1000
8 8
2 2
5 6

out:
2 1 5 3 4 

in:
17
34 8
7 12
7 4
63 2
5 5
27 96
70 4
60 60
29 29
20 75
55 33
25 61
87 99
54 28
59 34
39 22
72 67
out:
10 6 12 2 13 5 8 9 17 11 15 3 16 14 1 7 4 
*/

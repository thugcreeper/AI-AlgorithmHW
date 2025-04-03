//2025/3/16 NTOU Algorithm pratice2-1:greedy_activity_selector
//O(nlogn)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct{
	int start;
	int end;
}activity;

void printvector(vector<activity> &vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i].start<<" "<<vec[i].end<<endl;
	}
}

bool compareByEndTime(const activity &a, const activity &b){
	return a.end < b.end;
}

int greedy_activity_selector(vector<activity> &activity){
	int i=0;
	int m;
	vector<int> compatible;
	compatible.push_back(i);
	int count=1;//available activity count
	for(m=1;m<activity.size();m++){
		if(activity[m].start>=activity[i].end){
			compatible.push_back(m);
			count++;
			i=m;
		}
	}
	return count;
}
int main(){
	int data_count;
	int start,end;
	int available=0;
	cin>>data_count;
	vector<activity> vec(data_count);
	for(int i=0;i<data_count;i++){
		cin>>start>>end;
		vec[i].start=start;
		vec[i].end=end;
	}

	sort(vec.begin(),vec.end(), compareByEndTime);
	available=greedy_activity_selector(vec);
	cout<<available<<endl;
	//printvector(vec);
	return 0;
}
/*
in:
10
2 3
0 7
3 8
3 8
6 11
4 13
4 13
5 14
10 20
10 21
out:
3

in:
4
1 7
1 3
3 5
5 7
out:
3
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int partition(vector<int> &vec,int l,int r){
	int x=vec[r];
	int i=l-1;
	for(int j=l;j<r;j++){
		if(vec[j]<=x){
			i+=1;
			swap(vec[j],vec[i]);
		}
	}
	swap(vec[i+1],vec[r]);
	return i+1;
}

void qsort(vector<int> &vec,int l,int r){
	if(l<r){
		int mid=partition(vec,l,r);
		qsort(vec,l,mid-1);
		qsort(vec,mid+1,r);
	}
}

int main(){
	vector<int> vec={-12, 0, 7, -3, -7, 0, 14, -5, 8, 7, -8, -3, 3, -12, 6, 0, 14, -10, 2, 7};
	qsort(vec,0,vec.size()-1);
	for(auto &v:vec){
		cout<<v<<" ";
	}
	cout<<endl;
	return 0;
}

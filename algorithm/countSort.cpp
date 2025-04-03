#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print(vector<int> &vec){
	for(auto &v:vec){
		cout<<v<<" ";
	}
	cout<<endl;
}

void countSort(vector<int> &vec,vector<int> &ans){
	auto maxnum=max_element(vec.begin(),vec.end());//return a pointer
	vector<int> countArray(*maxnum+1);
	int i;
	for(i=0;i<vec.size();i++){
		countArray[vec[i]]++;
	}
	for(i=0;i<countArray.size()-1;i++){//cummulative sum
		countArray[i+1]+=countArray[i];
	}
	for(i=vec.size()-1;i>=0;i--){
		ans[--countArray[vec[i]]]=vec[i];
		print(ans);
	}
	
}


using namespace std;
int main(){
	vector<int> arr={8,5,1,4,7,6,4,2,1,3,6};
	int length=arr.size();
	vector<int> ans(length);
	countSort(arr,ans);
	cout<<"Sorted array: ";
	print(ans);
	//print(arr);
	return 0;
}

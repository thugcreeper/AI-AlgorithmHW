//2025/3/1 NTOU Algorithm pratice1:divide and conquer

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void merge(vector<int> &vec,int left,int mid,int right){
	int n1=mid-left+1;
	int n2=right-mid;
	int i,j;
	vector<int> vec1(n1+1),vec2(n2+1);//set vector's ength
	for(i=0;i<n1;i++){
		//previous error:vec1.push_back(vec[left+i]); 
		//this will cause vector too long and didn't place
		//number in correct place in vector
		vec1[i]=vec[left+i];//copy left vec to vec1
	}
	for(j=0;j<n2;j++){
		vec2[j]=vec[mid+j+1];//copy right vec to vec2
	}

	vec1[i]=INT_MAX;//use int max as border
	vec2[j]=INT_MAX;
	i=0;j=0;
	int k=left;
	while(k<=right){
		if(vec1[i]<=vec2[j]){
			vec[k]=vec1[i];//put the smaller number to original vector
			i++;
		}
		else{
			vec[k]=vec2[j];
			j++;
		}
		k++;
	}
}

void mergeSort(vector<int> &vec,int left,int right){
	if(left<right){
		int mid=(left+right)/2;
		mergeSort(vec,left,mid);//sort left array
		mergeSort(vec,mid+1,right);//sort right array
		merge(vec,left,mid,right);
	}
}

int main(){
	vector<int> arr;
	int i=0;
	int number;
	while(cin>>number){
		arr.push_back(number);
	}
	mergeSort(arr,0,arr.size()-1);
	for(i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<""<<endl;
}
/*
input:0 33 11 2 9 39 36 4 2 
output:0 2 2 4 9 11 33 36 39 
*/



//2025/3/3 NTOU Algorithm pratice3:Number_of_Inversions
#include<iostream>
#include<vector>
#include<climits>

using namespace std;
long int merge(vector<int> &vec,int left,int mid,int right){
	long int inv_num=0;
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
		else{//inversion:j>i and v[i]>v[j]
			inv_num+=(n1-i);//表示左子向量從i開始都會大於vec2[j] 
			vec[k]=vec2[j];
			j++;
		}
		k++;
	}
	return inv_num;
}

long int numOfInversion(vector<int> &vec,int left,int right){
	long int inv_num=0;
	if(left<right){
		int mid=(left+right)/2;
		inv_num+=numOfInversion(vec,left,mid);
		inv_num+=numOfInversion(vec,mid+1,right);
		inv_num+=merge(vec,left,mid,right);
	}
	return inv_num;
}

int main(){
	int i=0;
	int size;
	cin>>size;
	vector<int> vec(size);
	for(i=0;i<size;i++){
		cin>>vec[i];
	}
	long int num_inv=numOfInversion(vec,0,vec.size()-1);
	cout<<num_inv<<endl;
}
/*
in:
6
0 1 2 3 4 5
out:
0
in:
10
14 17 18 8 4 16 20 0 3 15
out:
27
*/ 

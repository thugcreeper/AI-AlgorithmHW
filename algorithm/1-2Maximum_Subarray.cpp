//2025/3/3 NTOU Algorithm pratice2:find maximum sub array
#include<iostream>
#include<vector>
#include<climits>

using namespace std;
//use reference instead copy
int find_max_cross_subarray(vector<int> &vec,int low,int mid,int high){
	int leftsum=INT_MIN;
	int rightsum=INT_MIN;
	int sum=0;
	for(int i=mid;i>=low;i--){
		sum+=vec[i];
		if(sum>leftsum){
			leftsum=sum;
		}
	}
	sum=0;
	for(int j=mid+1;j<=high;j++){
		sum+=vec[j];
		if(sum>rightsum){
			rightsum=sum;
		}
	}
	//cout<<leftsum<<" "<<rightsum<<endl;
	return leftsum+rightsum;
}

int max_subarray(vector<int> &vec,int low,int high){
	int leftsum=0;
	int rightsum=0;
	int sum=0;
	if(high==low){//base case
		return vec[low];
	}
	
	int mid=(low+high)/2;
	leftsum=max_subarray(vec,low,mid);
	rightsum=max_subarray(vec,mid+1,high);
	sum=find_max_cross_subarray(vec,low,mid,high);//2 3  -2
	if(leftsum>=rightsum && leftsum>=sum)
		return leftsum;
	else if(rightsum>=leftsum && rightsum>=sum){
		return rightsum;
	}
	else{
		return sum;
	}
}

int main(){
	//vector<int> vec={-9,6,3,7,-2,0,8,7,5};
	int size;
	int i=0;
	cin>>size;
	vector<int> vec(size);
	for(i=0;i<size;i++){
		cin>>vec[i];
	}
	int max;
	max=max_subarray(vec,0,size-1);
	cout<<max<<endl;
	//find_max_cross_subarray(vec,0,(size-1)/2,size-1);
	return 0;
}
/*
in:
10
10 -1 3 -12 11 -4 4 1 -10 6
out:
12
in:
5
-1 -1 -1 -1 -1
out:
-1
*/

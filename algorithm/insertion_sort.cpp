#include<iostream> 
using namespace std;
void printarr(int arr[],int len){
	for(int i=0;i<len;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void insertion_sort(int arr[],int len){
	int i,j;
	for(j=1;j<len;j++){
		int key=arr[j];
		i=j-1;
		while(i>=0 && arr[i]>key){
			arr[i+1]=arr[i];
			i-=1;
		}
		arr[i+1]=key;
		printarr(arr,len);
	}
}
int main(){
	int i,j,temp;
	int len=11;
	int arr[len] = {8,5,1,4,7,6,4,2,1,3,6};
	insertion_sort(arr,len);
	cout<<"final arr: ";
	for(j = 0;j<len;j++)
		cout<<arr[j]<<" ";
	return 0;
} 

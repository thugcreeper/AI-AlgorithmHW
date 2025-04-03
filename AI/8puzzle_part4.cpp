//NTOU 2025/3/23 N puzzle part 4
//Priority queue O(data_count*n) 
#include <iostream> 
#include <vector>
#include <cmath>
#include <string>
using namespace std;

typedef struct{
	string puzzle;
    int key; // key=g+h
    int order; // 進入的順序
}node;
vector<node> priority_queue;

bool isEmpty(){	return priority_queue.empty();}

int insert_order=0;

void enqueue(string puzzle,int key){
	node newnode={puzzle,key,insert_order++};//init a struct
	auto i=priority_queue.begin();//iterator
	while(i<priority_queue.end()){
		if(newnode.key<i->key){
			break;
		}
		if(i->order>newnode.order && i->key==newnode.key){//is tied,FIFO
			break;
		}
		i++;
	}
	priority_queue.insert(i,newnode);//O(n)
	cout<<"Insert OK!"<<endl;
}

void printqueue(){
	auto i=priority_queue.begin();
	while(i<priority_queue.end()){
		cout<<i->puzzle<<" "<<i->key;
		i++;
		cout<<endl;
	}
}

void dequeue(){
	if(!isEmpty()){
		//注意front()回傳第一個element 而begin() 回傳第一個iterator 
		node top=priority_queue.front();
		cout<<"Got "<<top.puzzle<<endl;
		//erase接 iterator作為參數 
		priority_queue.erase(priority_queue.begin());//O(n)
	}
	else{
		cout<<"Queue is empty!!"<<endl;
		return;
	}
}

int main(){
	int data_count,i=0,g,h;
	string actions,puzzle;
	cin>>data_count;
	for(i=0;i<data_count;i++){
		cin>>actions;
		if(actions=="enqueue"){
			cin>>puzzle>>g>>h;
			enqueue(puzzle,g+h);
		}
		else if(actions=="dequeue"){
			dequeue();
		}
		//printqueue();
	}
	return 0;
}

//2025/3/25 NTOU Algorithm pratice2-4:Kruskal's_Algorithm
//O(nlogn)
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct{
	int u;//頂點1 
	int v;//頂點2
	int w;//邊成本 
}node;


bool compareW(node &a,node &b){
	return a.w<b.w;
} 

void printNodes(vector<node> &nodes,int len){
	for(int i=0;i<len;i++){
		cout<<nodes[i].u<<" "<<nodes[i].v<<" "<<nodes[i].w<<endl;
	}
}
//The idea of path compression is to make the found root as parent of x
int find(vector<int> &parent,int i){//if:return find(parent,parent[i])->worst case:O(n) 
	if(parent[i]==i)
		return i;
	return parent[i]=find(parent,parent[i]);//path compression~=O(1)
}

void myunion(vector<int> &parent,vector<int> &rank,int a,int b){
	int a1=find(parent,a);
	int b1=find(parent,b);
	if(rank[a] < rank[b]){
		parent[a1]=b1;//a1 become b1's child
	}
	else if(rank[a] > rank[b]){
		parent[b1]=a1;//b1 become a1's child
	}
	else{
		parent[b1]=a1;
		rank[a1]+=1;
	}
} 

int kruskals(int v,int edgecount,vector<node> &nodes){
	vector<node> ans;
	sort(nodes.begin(),nodes.end(),compareW);
	int cost=0,i,count=0;
	int a,b;
	vector<int> parent(v),rank(v);//rank stand for tree's height
	
	for(int i=0;i<v;i++){
		parent[i]=i;
		rank[i]=0; 
	}
	for(i=0;i<edgecount;i++){//check all edges
		a=find(parent,nodes[i].u);
		b=find(parent,nodes[i].v);

		if(a!=b){//if a != b,it means there will be no cycle 
				//for the new edge and the trees are merged
		ans.push_back(nodes[i]);
		 myunion(parent,rank,a,b);
		 cost+=nodes[i].w;
		 if(++count==v-1) break;//到頂點數-1個邊時停止
		}
	}
	cout<<"MST:"<<endl;
	printNodes(ans,v-1);
	return cost;
}
int main(){
	int vertice,edge,i;//頂點、邊 
	cin>>vertice>> edge;
	vector<node> nodes(edge);

	for(i=0;i<edge;i++){
		cin>> nodes[i].u>>nodes[i].v>>nodes[i].w;
	}
	int cost=kruskals(vertice,edge,nodes);
	cout<<"The cost of minimum spanning tree: "<<cost<<endl;
	//printNodes(nodes,length);
	return 0;
}
/*
in:
7 9
0 1 28
0 5 10
1 2 16
1 6 14
2 3 12
3 4 22
3 6 18
4 5 25
4 6 24
out:
The cost of minimum spanning tree: 99

in:
5 7
0 1 88
0 2 58
0 4 10
1 2 82
1 3 92
2 4 67
3 4 7
out:
The cost of minimum spanning tree: 157
*/

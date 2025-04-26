//2025/4/26 NTOU Algorithm pratice3_2_Longest_common_subsequence
//O(m*n)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_lcs(vector<vector<int>> &b,vector<int> &vec,int i,int j){//O(m+n)
	if(i==0 || j==0)
		return;
	if(b[i][j]==1){
		print_lcs(b,vec,i-1,j-1);
		cout<<vec[i-1];
	}
	else if(b[i][j]==2){
		print_lcs(b,vec,i-1,j);
	}
	else{
		print_lcs(b,vec,i,j-1);
	}
}
int lcs_length(vector<int> &vec1,vector<int> &vec2){//O(m*n)
	int m=vec1.size(),n=vec2.size();
	vector<vector<int>> c(m+1,vector<int>(n+1));
	vector<vector<int>> b(m+1,vector<int>(n+1));
	int i,j;
	for(i=1;i<=m;i++){
		c[i][0]=0;
	}
	for(i=0;i<=n;i++){
		c[0][i]=0;
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(vec1[i-1]==vec2[j-1]){
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}
			else if(c[i-1][j]>=c[i][j-1]){
				c[i][j]=c[i-1][j];
				b[i][j]=2;
			}
			else{
				c[i][j]=c[i][j-1];
				b[i][j]=3;
			}
			
		}
	}
	print_lcs(b,vec1,m,n);
	cout<<endl;
	return c[m][n];
}
void printvector(vector<int> &vec){
	for(auto &v:vec){
		cout<<v<<" ";
	}
	cout<<endl;
}
int main(){
	int n,m,i;
	cin>>n>>m;
	vector<int> vec1(n);
	vector<int> vec2(m);
	for(i=0;i<n;i++){
		cin>>vec1[i];
	}
	for(i=0;i<m;i++){
		cin>>vec2[i];
	}
	int len=lcs_length(vec1,vec2);
	cout<<len<<" "<<( (len>=(vec1.size()/2)) ? "Yes" : "No" )<<endl;
	return 0;
}
/*
in:
8 8
3 1 2 2 3 3 4 1
3 2 1 2 3 4 3 2
out:
5 Yes

in:
7 7
2 3 2 3 1 2 4 
4 4 3 4 4 1 1 
out:
2 No

*/

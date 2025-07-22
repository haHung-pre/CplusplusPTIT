#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		int a[n],b[m];
		set<int>se1,se2;
		map<int,int>mp;
		for(int i=0;i<n;i++){
			cin>>a[i];
			se1.insert(a[i]);
			mp[a[i]]=1;
		}
		for(int i=0;i<m;i++){
			cin>>b[i];
			se1.insert(b[i]);
			if(mp[b[i]]==1)se2.insert(b[i]);
		}
		for(int x:se1)cout<<x<<" ";
		cout<<endl;
		for(int x:se2)cout<<x<<" ";
		cout<<endl;
	}
}


#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;cin.ignore();
	while(t--){
	string s;getline(cin,s);
	stringstream ss(s);
	int x;
	int chan=0,le=0,c=0;
	while(ss>>x){
		c++;
		if(x%2==0)chan++;
		else le++;
	}
	if(c%2==0&&chan>le){
		cout<<"YES\n";
	}else if(c%2==1&&le>chan){
		cout<<"YES\n";
	}else cout<<"NO\n";
	}
}


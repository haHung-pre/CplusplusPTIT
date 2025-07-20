#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	cin.ignore();
	while(t--){
		string s;getline(cin,s);
		int x=0;
		for(int i=0;i<s.size();i++){
			x=(10*x+(s[i]-'0'))%11;
		}
		if(x%11==0)cout<<1<<endl;
		else cout<<0<<endl;
	}
}

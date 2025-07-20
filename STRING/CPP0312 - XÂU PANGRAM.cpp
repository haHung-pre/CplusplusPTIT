#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;cin.ignore();
	while(t--){
		string s;getline(cin,s);
		int k;cin>>k;cin.ignore();
		set<char>se;
		for(auto c:s){
			se.insert(c);
		}
		if(k<26-se.size())cout<<0<<endl;
		else cout<<1<<endl;
	}
}


#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;cin.ignore();
	while(t--){
		string s1,s2;
		getline(cin,s1);
		getline(cin,s2);
		set<string>se;
		stringstream ss2(s2);
		string x;
		while(ss2>>x){
			se.insert(x);
		}
		stringstream ss1(s1);
		set<string>se2;
		bool ok=true;
		while(ss1>>x){
			if(se.count(x)==0){
				se2.insert(x);
			}
		}
		for(auto x:se2)cout<<x<<" ";
		cout<<endl;
	}
}

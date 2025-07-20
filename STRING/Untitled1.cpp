#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	stringstream ss2(s2);
	stringstream ss1(s1);
	string x;
	set<string>se;
	while(ss2>>x){
		se.insert(x);
	}
	bool ok=true;
	while(ss1>>x){
		if(ok==false)cout<<" ";
		if(se.count(x)==0){
			cout<<x;
			ok=false;
		}
	}
}

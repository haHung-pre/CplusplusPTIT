#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;getline(cin,s);
	string s2;getline(cin,s2);
	set<string>se;
	stringstream ss(s2);
	string x;
	while(ss>>x){
		se.insert(x);
	}
	stringstream sss(s);
	bool ok=true;
	while(sss>>x){
		if(se.count(x)==0){
		if(!ok)cout<<" ";
		cout<<x;
		ok=false;
	}
	}
}


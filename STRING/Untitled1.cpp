#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;cin.ignore();
	set<string>se;
	while(n--){
		string s;getline(cin,s);
		se.insert(s);
	}
		cout<<se.size()<<endl;
}

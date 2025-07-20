#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;cin.ignore();
	while(t--){
		string s;getline(cin,s);
		map<char,int>m;
		for(char &c:s){
			m[c]++;
		}
		for(char &c:s){
			if(m[c]==1)cout<<c;
		}
		cout<<endl;
	}
}


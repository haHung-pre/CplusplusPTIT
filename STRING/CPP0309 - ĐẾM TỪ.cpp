#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;cin.ignore();
	while(t--){
		string s;getline(cin,s);
		stringstream ss(s);
		string x;
		int c=0;
		while(ss>>x){
			c++;
		}
		cout<<c<<endl;
	}
}


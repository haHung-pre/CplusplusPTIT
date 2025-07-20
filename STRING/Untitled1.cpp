#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	cin.ignore();
	while(t--){
		string s;getline(cin,s);
		int x=0;
		for(int i=0;i<s.size();i++){
			x=(2*x+(s[i]-'0'))%5;
		}
		if(x%5==0)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;cin.ignore();
	while(t--){
		string s;cin>>s;
		bool ok=true;
		for(int i=0;i<s.size();i++){
			if(s[i]!=s[s.size()-1-i]){
				ok=false;
				break;
			}
			if(int(s[i]-'0')%2==1){
				ok=false;
				break;
			}
		}
		if(ok==false)cout<<"NO\n";
		else cout<<"YES\n";
	}
}

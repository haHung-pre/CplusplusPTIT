#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int t;cin>>t;cin.ignore();
	while(t--){
		ll a,b;cin>>a>>b;
		string A=to_string(a);
		string B=to_string(b);
		for(char &c:A)if(c=='6')c='5';
		for(char &c:B)if(c=='6')c='5';
		ll x=stoll(A)+stoll(B);
		for(char &c:A)if(c=='5')c='6';
		for(char &c:B)if(c=='5')c='6';
		ll y=stoll(A)+stoll(B);
		cout<<x<<" "<<y<<endl;
	}
}

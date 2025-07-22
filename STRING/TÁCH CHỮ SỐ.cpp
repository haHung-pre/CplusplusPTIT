#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;cin.ignore();
	while(t--){
		string s;getline(cin,s);
		string res="";
		int sum=0;
		for(char c:s){
			if(isdigit(c))sum+=c-'0';
			else res+=(toupper(c));
		}
		sort(res.begin(),res.end());
		cout<<res<<sum<<endl;
	}
}

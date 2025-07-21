#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;cin.ignore();
	while(t--){
		string s;getline(cin,s);
		int c=0;
		for(int i=0;i<s.size();i++){
			for(int j=i;j<s.size();j++){
				if(s[i]==s[j])c++;
			}
		}
		cout<<c<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;cin.ignore();
	while(t--){
		string s;getline(cin,s);
		int c=1;
		string res="";
		for(int i=1;i<s.size();i++){
			if(s[i]==s[i-1])c++;
			else{
				res+=s[i-1]+to_string(c);
				c=1;
			}
		}
		res+=s[s.size()-1]+to_string(c);
		cout<<res<<endl;
	}
}


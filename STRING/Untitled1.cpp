#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;cin.ignore();
	while(t--){
		int n;cin>>n;cin.ignore();
		string s;getline(cin,s);
		transform(s.begin(),s.end(),
		s.begin(),::tolower);
		vector<string>v;
		stringstream ss(s);
		string x;
		while(ss>>x){
			v.push_back(x);
		}
		if(n==1){
			v[v.size()-1][0]=toupper(v[v.size()-1][0]);
			cout<<v[v.size()-1]<<" ";
			for(int i=0;i<v.size()-1;i++){
				v[i][0]=toupper(v[i][0]);
				cout<<v[i]<<" ";
			}
		}
		if(n==2){
			for(int i=1;i<=v.size()-1;i++){
				v[i][0]=toupper(v[i][0]);
				cout<<v[i]<<" ";
			}
			v[0].front()=toupper(v[0].front());
			cout<<v.front()<<" ";
		}
		cout<<endl;
	}
}

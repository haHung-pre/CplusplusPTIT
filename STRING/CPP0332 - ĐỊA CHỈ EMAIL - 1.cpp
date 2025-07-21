#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;getline(cin,s);
	transform(s.begin(),s.end(),s.begin(),::tolower);
	vector<string>v;
	stringstream ss(s);
	string x;
	while(ss>>x){
		v.push_back(x);
	}
	cout<<v.back();
	for(int i=0;i<v.size()-1;i++){
		cout<<v[i][0];
	}
	cout<<"@ptit.edu.vn";
}

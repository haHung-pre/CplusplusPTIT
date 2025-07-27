#include<bits/stdc++.h>
using namespace std;
struct SinhVien{
	string ma,ten,lop,email;
};


string check(string s){
	for(char &c:s)c=toupper(c);
	return s;
}

string nganh(string s){
	if(s=="KE TOAN")return "DCKT";
	if(s=="CONG NGHE THONG TIN")return "DCCN";
	if(s=="AN TOAN THONG TIN")return "DCAT";
	if(s=="VIEN THONG")return "DCVT";
	if(s=="DIEN TU")return "DCDT";
	else return "";
}

int main(){
	int n;cin>>n;cin>>ws;
	vector<SinhVien>v;
	for(int i=0;i<n;i++){
		
		SinhVien a;
		cin>>ws;
		cin>>a.ma;
		getline(cin>>ws,a.ten);
		cin>>a.lop>>a.email;
		v.push_back(a);
		
		
	}
	int q;cin>>q;cin>>ws;
	while(q--){
		string na;getline(cin>>ws,na);
		cout<<"DANH SACH SINH VIEN NGANH "<<check(na)<<":"<<endl;
		for(auto &a:v){
			if((nganh(check(na))=="DCCN"||nganh(check(na))=="DCAT")&&a.lop[0]=='E')continue;
			if(a.ma.substr(3,4)==nganh(check(na))){
				cout<<a.ma<<" "<<a.ten<<" "<<a.lop<<" "<<a.email<<endl; 
			}
		}
	}
}


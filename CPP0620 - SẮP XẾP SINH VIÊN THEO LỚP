#include<bits/stdc++.h>
using namespace std;
class SinhVien{
	public:
		string msv,ten,lop,email;
		friend istream& operator >> (istream& in,SinhVien &a);
		friend ostream& operator << (ostream& out,SinhVien a);
};
istream& operator >> (istream& in,SinhVien &a){
	in>>a.msv;
	scanf("\n");
	getline(in,a.ten);
	in>>a.lop>>a.email;
	return in;
}
ostream& operator << (ostream& out,SinhVien a){
	out<<a.msv<<" "<<a.ten<<" "<<a.lop<<" "<<a.email<<endl;
	return out;
}
bool cmp(SinhVien a,SinhVien b){
	if(a.lop<b.lop) return 1;
	if(a.lop==b.lop){
		if(a.msv<b.msv) return 1;
	}
	return 0;
}
void sapxep(SinhVien ds[],int n){
	sort(ds,ds+n,cmp);
}
int main(){
	SinhVien ds[1000];
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>ds[i];
	}
	sapxep(ds,n);
	for(int i=0;i<n;i++){
		cout<<ds[i];
	}
}

#include<bits/stdc++.h>
using namespace std;
int id=1;
class NhanVien{
	public:
		string mnv,ten,gtinh,nsinh,dchi,msthue,ngay;
		int d,m,y;
	public:
		friend istream& operator >> (istream& in,NhanVien &a);
		friend ostream& operator << (ostream& out,NhanVien a);
};
istream& operator >> (istream& in,NhanVien &a){
	scanf("\n");
	getline(in,a.ten);
	in>>a.gtinh;
	scanf("%d/%d/%d",&a.m,&a.d,&a.y);
	scanf("\n");
	getline(in,a.dchi);
	in>>a.msthue>>a.ngay;
	string s =to_string(id++);
	while(s.length()<5){
		s="0"+s;
	}
	a.mnv=s;
	return in;
}
ostream& operator << (ostream& out,NhanVien a){
	out<<a.mnv<<" "<<a.ten<<" "<<a.gtinh<<" ";
	printf("%.2d/%.2d/%.4d ",a.m,a.d,a.y);
	out<<a.dchi<<" "<<a.msthue<<" "<<a.ngay<<endl;
	return out;
}
bool cmp(NhanVien a,NhanVien b){
	if(a.y<b.y) return 1;
	if(a.y==b.y){
		if(a.m<b.m) return 1;
		if(a.m==b.m){
			if(a.d==b.d) return 1;
		}
	}
	return 0;
}
void sapxep(NhanVien ds[],int N){
	sort(ds,ds+N,cmp);
}
int main(){
	NhanVien ds[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ds[i];
	}
	sapxep(ds,n);
	for(int i=0;i<n;i++){
		cout<<ds[i];
	}
}



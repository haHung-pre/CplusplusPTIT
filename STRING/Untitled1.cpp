#include<bits/stdc++.h>
using namespace std;
string add(string a,string b){
    while(a.size()<b.size())a='0'+a;
    while(b.size()<a.size())b='0'+b;
    int carry=0;
    string res="";
    for(int i=a.size()-1;i>=0;i--){
        int sum=(a[i]-'0')+(b[i]-'0')+carry;
        res=char(sum%10+'0')+res;
        carry=sum/10;
    }
    if(carry)res='1'+res;
    return res;
}
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string x,y;
        getline(cin,x);
        getline(cin,y);
        cout<<add(x,y)<<'\n';
    }
}


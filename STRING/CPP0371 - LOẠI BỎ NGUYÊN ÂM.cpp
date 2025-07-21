#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;getline(cin,s);
	for(char &c:s){
		c=tolower(c);
		if(c!='u'&&c!='e'&&c!='o'&&c!='a'
		&&c!='i'&&c!='y')cout<<"."<<c;
	}
}

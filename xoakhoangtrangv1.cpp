#include <bits/stdc++.h>
using namespace std;
bool timkhoangtrang (char c){
	return c == ' ' || c ==  '\t' || c == '\n';
}
void demkhoangtrang(char *c)
{
	int ktrang = 0;
	int sokitu = strlen(c);
	for(int i=0;i<sokitu;i++){
		if(timkhoangtrang(c[i])){
			ktrang++;
		}
		else{
			break;
		}
	}
	for(int i =0 ;i<=sokitu-ktrang;i++){
		c[i]=c[i+ktrang];
	}
}

int main(){
	char x[100];
	cin.getline(x,100);
	demkhoangtrang(x);
	cout<<x<<endl;
}

#include <bits/stdc++.h> 
using namespace std;
int main(){
	int x,y;
	cout<<" chieu cao x :"<<endl;
	cin>>x;
	cout<<" chieu rong y :" << endl;
	cin >>y ; 
	for(int i=0;i<x;i++)
	{
		cout<<""<<endl; 
		for(int j=0;j<y;j++){
			if(i==0 || i==x-1){
				cout<<"*";
			}
			else{
				if (j==0 || j==y-1){
					cout<<"*";
				} 
				else{
					cout<<" ";
				}
			}

		}
	 } 
} 

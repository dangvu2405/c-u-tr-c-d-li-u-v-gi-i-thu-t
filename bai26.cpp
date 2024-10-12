#include <bits/stdc++.h>
using namespace std;
struct tailieu{
	int matl;
	string nametl;
	int namxb;
	float giaban;
};
void nhap(tailieu a[],int n){
	for(int i=0;i<n;i++){	
		cout<<"nhap ma tai lieu:"<<endl;
		cin>>a[i].matl;
		cin.ignore();
		cout<<"nhap ten tai lieu"<<endl;
		getline (cin,a[i].nametl);
		cout<<"nhap nam xuat ban:"<<endl;
		cin>>a[i].namxb;
		cout<<"nhap gia ban :"<<endl;
		cin>>a[i].giaban;
	}
}
void xuat(tailieu a[],int n){
	for(int i=0;i<n;i++){
			cout<<"	ID	"<< a[i].matl <<"	name	"<<a[i].nametl <<"	nam xb:"
	<< a[i].namxb 
	<< "gia :"<<a[i].giaban<<endl;
	}
}
void SelectionSort(tailieu a[],int n){
	int min;
	for(int i=0;i<n;i++){
		min = i;
		for(int j=n-1;j>i;j--){
			if(a[min].giaban > a[j].giaban){
				min=j;
			}
		}
		swap(a[min],a[i]);
	}
}
bool timnhiphan(tailieu a[],int n, float x){
	int l=0, r=n-1,m;
	while(l<=r){
		m=(l+r)/2;
		if(a[m].giaban == x){
			return true;
		}
		if(a[m].giaban < x){
			l=m+1;
		}
		else{
			r=m-1;
		}
	}
	return false;
}
int main (){
	int n;
	cout<<"nhap so luong tai lieu :"<<endl;
	do{
		cin>>n;
		if(n<0)
		cout<<"yeu cau nhap lai!"<<endl;
	}
	while(n<0);
	tailieu*a= new tailieu[n];
	cout<<"nhap thong tin tai lieu:"<<endl;
	nhap(a,n);
	cout<<"xuat thong tin tai lieu:"<<endl;
	xuat(a,n);
	cout<<" sap xep gia tai lieu :"<<endl;
	SelectionSort(a,n);
	xuat(a,n);
	int x;
	cout<<"nhap gia tai lieu can tim"<<endl;
	if(timnhiphan(a,n,x)){
		cout<<"ton tai"<<endl;
	}
	else{
		cout<<"khong ton tai"<<endl;
	}
}

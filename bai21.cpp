#include <bits/stdc++.h>
using namespace std;
struct monhoc{
	int mamh;
	string namemh;
	int sotinchi;
	int sotietday;
};
void nhap(monhoc a[], int n){
	for(int i=0; i<n; i++){
		cout<<"nhap ma mon hoc:"<<endl;
		cin>>a[i].mamh;
		cin.ignore();
		cout<<"nhap ten mon hoc:"<<endl;
		getline(cin,a[i].namemh);
		cout<<"nhap so tin chi :"<<endl;
		cin>>a[i].sotinchi;
		cout<<"nhap so tiet da day :"<<endl;
		cin>>a[i].sotietday;
	}
}
void xuat (monhoc a[], int n){
	for(int i=0;i<n;i++){
		cout<<"ID:"<< a[i].mamh<<"name:"<<a[i].namemh<<"so tin chi:"<<a[i].sotinchi
		<<"so tiet day:"<<a[i].sotietday<<endl;
	}
}
// insertion sort
void InsertionSort(monhoc a[], int n){
	int pos;
	monhoc x;
	for(int i=1;i<n;i++){
		pos=i-1;
		x=a[i];
		while((pos>=0)&&(a[pos].sotietday>x.sotietday)){
			a[pos+1]= a[pos];
			pos--;
		}
		a[pos+1]=x;
	}
}
bool sapxepnhiphan(monhoc a[], int n,int x){
	int l,r,m;
	l=0;
	r=n-1;
	while(l<=r){
		if(a[m].sotietday == x){
			return true;
		}
		if(a[m].sotietday < x){
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
	cout<<"nhap so luong mon hoc :"<<endl;
	do{
		cin>>n;
		if(n<0){
			cout<<"yeu cau nhap lai!"<<endl;
		}
	}
	while(n<0);
	monhoc*a = new monhoc [n];
	cout<<"nhap thong tin mon hoc :"<<endl;
	nhap(a,n);
	cout<<"xuat thong tin mon hoc :"<<endl;
	xuat(a,n);
	cout<<"sap xep mon hoc thu tu tang dan:"<<endl;
	InsertionSort(a,n);
	xuat(a,n);
	int z;
	cout<<"nhap cua mon hoc can tim:"<<endl;
	cin>>z;
	if(sapxepnhiphan(a,n,z)){
		cout<<" ton tai"<<endl;
	}
	else{
		cout<<"khong ton tai"<<endl;
	}
}

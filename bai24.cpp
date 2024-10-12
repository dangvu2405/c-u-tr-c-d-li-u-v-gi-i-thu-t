#include <bits/stdc++.h>
using namespace std;
struct khachhang{
	int makh;
	string namekh;
	string sdt;
	float total;
};
void nhap(khachhang a[], int n){
	for(int i=0;i<n;i++){
		cout<<"nhap ma khach hang:"<<endl;
		cin>>a[i].makh;
		cin.ignore();
		cout<<"nhap ten khach hang:"<<endl;
		getline (cin, a[i].namekh);
		cout<<"nhap so dien thoai :"<<endl;
		getline(cin , a[i].sdt);
		cout<<"tong thanh toan:"<<endl;
		cin>>a[i].total;
	}
}
void xuat(khachhang a[], int n){
	for(int i=0;i<n;i++){
				cout<<"ID:"<< a[i].makh<<"name:"<<a[i].namekh<<"so dien thoai:"<<a[i].sdt
		<<"total"<<a[i].total<<endl;
	}
}
void SelectionSort(khachhang a[], int n){
	for(int i=0;i<n;i++){
		int min=i;
		for(int j=n-1;j>i;j--){
			if(a[min].total > a[j].total){
				min =j;
			}
		}
		if(min!=i){
				swap(a[min],a[i]);
			}
	}
}
bool timnhiphan(khachhang a[],int n , float x){
	int r,l,m;
	l=n-1;
	r=0;
	while(l<=r){
		m = (l+r)/2 ;
		if(a[m].total == x){
			return true;
		}
		if(a[m].total < x){
			l=m+1;
		}
		else{
			r=m-1;
		}
	}
	return false;
}
int main(){
	int n;
	cout<<"nhap so luong khachhang :"<<endl;
	do{
		cin>>n;
		if(n<0){
			cout<<"yeu cau nhap lai!"<<endl;
		}
	}
	while(n<0);
	khachhang*a = new khachhang[n];
	cout<<"nhap thong tin khachhang :"<<endl;
	nhap(a,n);
	cout<<"xuat thong tin khachhang :"<<endl;
	xuat(a,n);
	cout<<"sap xep totat thanh toan thu tu tang dan:"<<endl;
	SelectionSort(a,n);
	xuat(a,n);
	float z;
	cout<<"nhap cua total khachhang can tim:"<<endl;
	cin>>z;
	if(timnhiphan(a,n,z)){
		cout<<" ton tai"<<endl;
	}
	else{
		cout<<"khong ton tai"<<endl;
	}
}

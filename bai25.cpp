#include <bits/stdc++.h>
using namespace std;
struct date{
	int ngay;
	int thang;
	int nam;
};
struct nhanvien {
	int manv;
	string tennv;
	date ngaysinh;
	float luong;
};
void nhap(nhanvien a[], int n){
	for(int i=0;i<n;i++){
		cout<<"nhap ma nhan vien :";
		cin>>a[i].manv;
		cin.ignore();
		cout<<"nhap ten nhavien :";
		getline(cin,a[i].tennv);
		cout<<"nhap birday :"; cin >> a[i].ngaysinh.ngay; 
		cout<<'/';cin>> a[i].ngaysinh.thang;
		cout<<'/';cin>> a[i].ngaysinh.nam;
		cout<<"nhap luong:";
		cin >> a[i].luong;
	}
}
void SelectionSort(nhanvien a[], int n){
	for(int i=0;i<n;i++){
		int min = i;
		for(int j=n-1; j>i;j--){
			if(a[min].luong > a[j].luong){
				min = j;
			}
		}
		if(min!=i){
			swap(a[min],a[i]);
		}
	}
}
bool timnhiphan(nhanvien a[], int n,float x){
	int r=n-1,l=0,m;
	while(l<=r){
		m=(l+r)/2;
		if(a[m].luong == x){
			return true;
		}
		if(a[m].luong < x){
			l=m+1;
		}
		else{
			r=m-1;
		}
	}
	return false;
}
void xuat(nhanvien a[], int n){
	for(int i=0;i<n;i++){
		cout<<"ID:"<< a[i].manv<<"name:"<<a[i].tennv<<"date:"<<a[i].ngaysinh.ngay;cout<<'/'<<a[i].ngaysinh.thang<<
		'/'<< a[i].ngaysinh.nam<<"gia xuat:"<<a[i].luong<<endl;
	}
}
int main(){
	int n;
	cout<<"nhap so luong nhanvien :"<<endl;
	do{
		cin>>n;
		if(n<0){
			cout<<"yeu cau nhap lai!"<<endl;
		}
	}
	while(n<0);
	nhanvien*a = new nhanvien[n];
	cout<<"nhap thong tin nhanvien :"<<endl;
	nhap(a,n);
	cout<<"xuat thong tin nhanvien :"<<endl;
	xuat(a,n);
	cout<<"sap xep nhanvien thu tu tang dan:"<<endl;
	SelectionSort(a,n);
	xuat(a,n);
	int z;
	cout<<"nhap cua nhanvien can tim:"<<endl;
	cin>>z;
	if(timnhiphan(a,n,z)){
		cout<<" ton tai"<<endl;
	}
	else{
		cout<<"khong ton tai"<<endl;
	}
}

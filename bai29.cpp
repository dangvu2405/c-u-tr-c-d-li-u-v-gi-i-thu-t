#include <bits/stdc++.h>
using namespace std;
struct vdv{
	int mavdv;
	string namevdv;
	long long luong;
};
void nhap(vdv a[], int n){
	for(int i=0;i<n;i++){
		cout<<"nhap ma van dong vien:"<<endl;
		cin>>a[i].mavdv;
		cout<<"nhap ten van dong vien:"<<endl;
		cin.ignore();
		getline(cin,a[i].namevdv);
		cout<<" nhap luong:"<<endl;
		float temp;
		cin>>temp;
		a[i].luong = static_cast<long long>(temp*1e9);
	}
}
void xuat(vdv a[], int n){
	for(int i=0;i<n;i++){
		cout<<"ID:"<<a[i].mavdv<<"name"<<a[i].namevdv<<"luong:"<<a[i].luong<<endl;
	}
}
void SelectionSort(vdv a[], int n){
	int min;
	for(int i=0;i<n;i++){
		min=i;
		for(int j=n-1;j>i;j--){
			if(a[min].luong>a[j].luong){
				min=j;
			}
		}
		swap(a[min],a[i]);
	}
}
bool timnhiphan(vdv a[], int n, float z){
	int r=n-1, l = 0 ,m;
	z = static_cast<long long> (z*1e9);
	while(l<=r){
		if(a[m].luong==z){
			return true;
		}
		if(a[m].luong<z){
			l=m+1;
		}
		else{
			r=m-1;
		}
	}
}
int main(){
	int n;
	cout<<"nhap so luong van dong vien:"<<endl;
	do{
		cin>>n;
		if(n<0){
			cout<<"yeu cau nhap lai!"<<endl;
		}
	}
	while(n<0);
	vdv*a= new vdv[n];
	cout<<"nhap thong tin :"<<endl;
	nhap(a,n);
	cout<<"xuat thong tin :"<<endl;
	xuat(a,n);
	cout<<"sap xep thong tin"<<endl;
	SelectionSort(a,n);
	cout<<"tim kiem:"<<endl;
	int z;
	cin>>z;
	if(timnhiphan(a,n,z)){
		cout<<"tontai";
	}
	else{
		cout<<" khong tontai";
	}
}

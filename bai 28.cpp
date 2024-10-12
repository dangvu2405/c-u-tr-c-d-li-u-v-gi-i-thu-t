#include<bits/stdc++.h>
using namespace std;
struct duan{
	int madn;
	string namedn;
	long long total;
};
void nhap(duan a[], int n){
	for(int i=0;i<n;i++){
		cout<<"nhap ma duan:"<<endl;
		cin>>a[i].madn;
		cout<<"nhap ten duan"<<endl;
		cin.ignore();
		getline(cin,a[i].namedn);
		cout<<"nhap tong kinh phi:"<<endl;
		float temp;
		cin>>temp;
		a[i].total = static_cast<long long>(temp*1e9);
	}
}
void xuat(duan a[], int n){
	for(int i=0; i<n;i++){
		cout<<"ID"<<a[i].madn<<"name"<<a[i].namedn<<"tong kinh phi:"<<a[i].total<<endl;
	}
}
void SelectionSort(duan a[], int n){
	int min;
	for(int i=0;i<n;i++){
		min=i;
		for(int j=n-1;j>i;j--){
			if(a[min].total > a[j].total){
				min=j;
			}
		}
		swap(a[min],a[i]);
	}
}
bool timnhiphan(duan a[], int n,float z){
	int l=0,r=n-1,m;
	z = static_cast<long long>(z*1e9);
	while(l<=r){
		m= (l+r)/2;
		if(a[m].total == z){
			return true;
		}
		if(a[m].total < z){
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
	cout<<" nhap so luong  du an :"<<endl;
	do{
		cin>>n;
		if(n<0){
			cout<<"yeu cau nhap lai!"<<endl;
		}
	}
	while(n<0);
	duan*a= new duan [n];
	cout<<"thong tin du an:"<<endl;
	nhap(a,n);
	cout<<" xuat thong tin dua an:"<<endl;
	xuat(a,n);
	cout<<"sap xep kinh phi du an theo thu tu tang dan:"<<endl;
	SelectionSort(a,n);
	xuat(a,n);
	cout<<"kinh phi cua du an can tim :"<<endl;
	int z;
	cin>>z;
	if(timnhiphan(a,n,z)){
		cout<<"ton tai";
	}
	else{
		cout<<"khong ton tai";
	}
}

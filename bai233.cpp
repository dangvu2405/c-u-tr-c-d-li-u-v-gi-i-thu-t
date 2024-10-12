#include <bits/stdc++.h>
using namespace std;
struct date{
	int ngay;
	int thang;
	int nam;
};
struct hanghoa {
	int mahh;
	string tenhh;
	date ngayxuat;
	float giaxuat;
};
void nhap(hanghoa a[],int n){
	for(int i=0;i<n;i++){
		cout<<"nhap ma hang hoa :";
		cin>>a[i].mahh;
		cin.ignore();
		cout<<"nhap ten hang hoa :";
		getline(cin,a[i].tenhh);
		cout<<"nhap date xuat :"; cin >> a[i].ngayxuat.ngay; 
		cout<<'/';cin>> a[i].ngayxuat.thang;
		cout<<'/';cin>> a[i].ngayxuat.nam;
		cout<<"nhap gia xuat:";
		cin >> a[i].giaxuat;
	}
}
void xuat(hanghoa a[],int n){
	for(int i=0;i<n;i++){
		cout<<"ID:"<< a[i].mahh<<"name:"<<a[i].tenhh<<"date:"<<a[i].ngayxuat.ngay;cout<<'/'<<a[i].ngayxuat.thang<<
		'/'<< a[i].ngayxuat.nam<<"gia xuat:"<<a[i].giaxuat<<endl;
	}
}
//select sort
void selectsort(hanghoa a[],int n){
	for(int i=0;i<n;i++){
		int min=i;
		for(int j=n-1;j>i;j--){
			if(a[min].giaxuat>a[j].giaxuat){
				min = j;
			}
			if(min!=i){
				swap(a[min],a[i]);
			}
		}
	}
}
bool timnhiphan(hanghoa a[],int n, float x){
	int l,r,m;
	l=0;
	r=n-1;
	while(l<=r){
		m=(l+r)/2;
		if(a[m].giaxuat == x){
			return true;
		}
		if(a[m].giaxuat < x){
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
	cout<<"nhap so luong hanghoa :"<<endl;
	do{
		cin>>n;
		if(n<0){
			cout<<"yeu cau nhap lai!"<<endl;
		}
	}
	while(n<0);
	hanghoa*a = new hanghoa[n];
	cout<<"nhap thong tin hanghoa :"<<endl;
	nhap(a,n);
	cout<<"xuat thong tin hanghoa :"<<endl;
	xuat(a,n);
	cout<<"sap xep giaxuat thu tu tang dan:"<<endl;
	selectsort(a,n);
	xuat(a,n);
	int z;
	cout<<"nhap cua hanghoa can tim:"<<endl;
	cin>>z;
	if(timnhiphan(a,n,z)){
		cout<<" ton tai"<<endl;
	}
	else{
		cout<<"khong ton tai"<<endl;
	}
}

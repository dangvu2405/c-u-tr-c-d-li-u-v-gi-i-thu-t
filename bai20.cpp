#include <bits/stdc++.h>
using namespace std;
struct vdv{
	int mavdv;
	string tenvdv;
	int age;
	float luong;
};
void nhap(vdv a[], int n){
	for(int i=0; i<n;i++){
		cout<< " nhap ma van dong vien :"<<endl;
		cin>> a[i].mavdv;
		cin.ignore();
		cout<< " nhap ten van dong vien :"<<endl;
		getline(cin,a[i].tenvdv);
		cout<< " nhap tuoi van dong vien :"<<endl;
		cin>> a[i].age;
		cout<<" nhap luong van dong vien :"<<endl;
		cin>> a[i].luong;
	}
}
void xuat(vdv a[], int n){
	for(int i=0;i<n;i++){
		cout<<"ID:"<< a[i].mavdv<<"name:"<<a[i].tenvdv<<"age:"<<a[i].age
		<<"luong:"<<a[i].luong<<endl;
	}
}
// insertion sort 
void InsertionSort(vdv a[], int n){
	int pos;
	vdv x;
	for(int i=1;i<n;i++){
		pos=i-1;
		x=a[i];
		while((pos>=0)&&(x.luong<a[pos].luong)){
			a[pos+1]= a[pos];
			pos--;
		}
		a[pos+1]=x;
	}
}
bool sapxepnhiphan(vdv a[], int n, float x){
	int l,r,m;
	l=0;
	r=n-1;
	while(l<=r){
		m=(l+r)/2;
		if(a[m].luong==x){
			return true;
		}
		if(x>m){
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
	cout<<"nhap so luong van dong vien :"<<endl;
	do{
		cin>>n;
		if(n<0){
			cout<<"yeu cau nhap lai!"<<endl;
		}
	}
	while(n<0);
	vdv*a = new vdv [n];
	cout<<"nhap thong tin van dong vien :"<<endl;
	nhap(a,n);
	cout<<"xuat thong tin van dong vien :"<<endl;
	xuat(a,n);
	cout<<"sap xep van dong vien thu tu tang dan:"<<endl;
	InsertionSort(a,n);
	xuat(a,n);
	int z;
	cout<<"nhap cua van dong vien can tim:"<<endl;
	cin>>z;
	if(sapxepnhiphan(a,n,z)){
		cout<<" ton tai"<<endl;
	}
	else{
		cout<<"khong ton tai"<<endl;
	}
}

#include <bits/stdc++.h>
using namespace std;
struct sv{
	int masv;
	string namesv;
	string lop;
	float diemtk;
};
void nhap(sv a[], int n){
	for(int i=0; i<n; i++){
		fflush(stdin);
		cout<<"nhap ma sinhvien :"<<endl;
		cin>>a[i].masv;
		fflush(stdin);
		cout<<"nhap ten sinhvien :"<<endl;
		getline(cin,a[i].namesv);
		cout<<"nhap lop :"<<endl;
		getline(cin,a[i].lop);
		cout<<"nhap diem tong ket :"<<endl;
		cin>>a[i].diemtk;
	}
}

void xuat(sv a[], int n){
		for(int i=0;i<n;i++){
			cout<<"ID:"<< a[i].masv<<"name:"<<a[i].namesv<<"lop:"<<a[i].lop
			<<"diem tong ket:"<<a[i].diemtk<<endl;
	}
}
void SelectionSort(sv a[], int n){
	for(int i=0;i<n;i++){
		int min = a[i].diemtk;
		for(int j=n-1;j>i;j--){
			if(a[min].diemtk>a[j].diemtk){
				min = j;
			}
		}
		if(min!=i){
				swap(a[min],a[i]);
			}
	}
}
bool timnhiphan(sv a[], int n, float x){
	int l,r,m;
	l=0;
	r=n-1;
	while(l<=r){
		if(a[m].diemtk == x){
			return true ;
		}
		if(a[m].diemtk < x){
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
	cout<<"nhap so luong sinhvien :"<<endl;
	do{
		cin>>n;
		if(n<0){
			cout<<"yeu cau nhap lai!"<<endl;
		}
	}
	while(n<0);
	sv*a = new sv[n];
	cout<<"nhap thong tin sinhvien :"<<endl;
	nhap(a,n);
	cout<<"xuat thong tin sinhvien :"<<endl;
	xuat(a,n);
	cout<<"sap xep diemtk thu tu tang dan:"<<endl;
	SelectionSort(a,n);
	xuat(a,n);
	int z;
	cout<<"nhap cua sinhvien can tim:"<<endl;
	cin>>z;
	if(timnhiphan(a,n,z)){
		cout<<" ton tai"<<endl;
	}
	else{
		cout<<"khong ton tai"<<endl;
	}
}

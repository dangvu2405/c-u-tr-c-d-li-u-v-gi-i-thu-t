#include <bits/stdc++.h>
using namespace std;
struct sinhvien{
	int masv;
	string namesv;
	string nameclass;
	float pointk;
};
void nhap(sinhvien a[],int n);
void xuat(sinhvien a[],int n);
void Insertionsort(sinhvien a[],int n);
int seachnhiphan(sinhvien a[],int n,float x);

void nhap(sinhvien a[] ,int n){
	for(int i = 0;i<n;i++){
		fflush(stdin);
		cout<<"nhap ma sinh vien :";
		cin>>a[i].masv;
		fflush(stdin);
		cout<<"nhap name sinh vien :";
		getline(cin,a[i].namesv);
		cout<<"nhap name class :";
		getline(cin,a[i].nameclass);
		cout<<"nhap diem tong ket:";
		cin>>a[i].pointk;
		cout<<"---------------------"<<endl;
	}
}
void xuat(sinhvien a[] ,int n){
	for(int i = 0;i<n;i++){
		cout<<"ID:"<<a[i].masv<<"  name:"<<a[i].namesv<<"  class:"<<a[i].nameclass<<"  poin:"<<a[i].pointk<<endl;
	}
}
void Interchangesort(sinhvien a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].pointk<a[j].pointk){
				swap(a[i],a[j]);
			}
		}
	}
}
void Selectionsort(sinhvien a[],int n){
	for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=n+1;j<n;j++){
			if(a[j].pointk<a[min].pointk){
				min=j; // vi tri cua phan tu co gia tri nho nhat 
			}
			swap(a[min],a[i]);
		}
	}
}
void Bubblesort(sinhvien a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i;j--){
			if(a[j].pointk<a[j-1].pointk){ // neu sai vi tri doi cho
			/* vi du:
			[] = 1 2 3 4 5 6 7 8
			v1: a[j] = 8 a[j-1]=7 i=0 a[i]= 1
			*/
				swap(a[i],a[j-1]);
			}
		}
	}
}
void Shakersort(sinhvien a[],int n){
	int right = n-1,left =0,i,j,k;
	while(left>right){
		// luot di
		for(i=left;i<n;i++){
			if(a[i].pointk>a[i+1].pointk){
				swap(a[i],a[i+1]);
			}
			k=i;
		}
		right=k;
		// luot ve
		for(j=right;j>left;j--){// giai thich : j>left bo qua cac doan da sap xep
			if(a[j].pointk<a[j-1].pointk){
				swap(a[j],a[j-1]);
			}
			k=j;
		}
		left=k;
	}
}
 void Intertionsort(sinhvien a[],int n){
 	int i,pos;
 	sinhvien x;
 	for(i=1;i<n;i++){
 		x=a[i];// tranh bi gan mat gia tri
 		pos=i-1;
 		while((pos>=0)&&(a[pos].pointk>x.pointk)){
 			a[pos+1]=a[pos];
 			pos--;
		}
		a[pos+1]=x;// chuyen sang vi tri mang tiep theo de so sanh 
	 }
 }
void Binsertsort(sinhvien a[],int n);
int seachnhiphan(sinhvien a[],int n,float x){
	int l = 0, r = n-1;
	while(l<=r){
		int m = (l+r)/2;
		if(a[m].pointk==x){
			return m; // tim thay
		}
		else if(a[m].pointk < x){
			// tim kiem o ben phai
			l = m+1;
		}
		else{
			// tim kiem o ben trai
			r = m-1;
		}
	}
	return 0; //  l > r
}
int main(){
	int n;
	cout<<"nhap so luong sinh vien :";
	do{
		cin>>n;
		if(n<0){
			cout<<"yeu cau nhap lai!"<<endl;
		}
	}
	while(n<0);
	sinhvien*a= new sinhvien[n];
	nhap(a,n);
	xuat(a,n);
	cout<<"lua chon kieu sap xep:";
	int z;
	do{
		cin>>z;
		if(z==1){
			cout<<"Insertionsort:"<<endl;
			Interchangesort(a,n);
			xuat(a,n);
		}
		if(z==2){
			cout<<"Selectionsort:"<<endl;
			Selectionsort(a,n);
			xuat(a,n);
		}
		if(z==3){
			cout<<"Shakersort:"<<endl;
			Shakersort(a,n);
			xuat(a,n);
		}
		if(z==4){
			cout<<"Intertionsort:"<<endl;
			Intertionsort(a,n);
			xuat(a,n);
		}
	}
	while(n<0);
	float x;
	cout<<" nhap diem sinh vien :";
	do{
		cin>>x;
		if(n<0){
			cout<<"diem tong ket khong the am!"<<endl;
		}
	}
	while(n<0);
	cout<<"sinh vien can tim o vi tri :"<<seachnhiphan(a,n,x)<<endl;
}

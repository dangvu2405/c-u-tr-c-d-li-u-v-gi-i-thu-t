#include <bits/stdc++.h>
using namespace std;
 struct sinhvien{
 	int masv;
 	string tensv;
 	string lop;
 	float diemtk;
 }; 
 void nhap(sinhvien&x, int n){
 	fflush(stdin);
 	cout<<"nhap ma sinh vien "<<n<<" : "<<endl;
 	cin>>x.masv;
 	fflush(stdin);
 	cout<<"nhap ten sinh vien "<<n<<" : "<<endl;
 	getline(cin,x.tensv);
 	cout<<"nhap lop :"<<endl;
 	getline(cin,x.lop);
 	cout<<"nhap diem tong ket "<<n<<" : "<<endl;
 	cin >> x.diemtk;
 }
 void xuat(sinhvien&x, int n){
 	cout<<"thong tin sinh vien "<<n<<" : "<<endl;
	 cout<< x.masv <<"\t"<< x.tensv<<"\t"<< x.lop<<"\t"<<x.diemtk<<endl;
 }
 void InterchangeSort(sinhvien x[] , int n){
 	for(int i=0;i<n-1;i++){
 		for(int j=i+1;j<n;j++){
 			if(x[i].diemtk > x[j].diemtk){
 				swap(x[i],x[j]);
			 }
 			
		 }
	 }
 }
 void SelectionSort(sinhvien x[] , int n){
 	for(int i=0;i<n-1;i++){
 		int min =  i ;
 		for(int j=i+1;j<n;j++){
 			if (x[j].diemtk < x[min].diemtk) {
 				min=j;
			 }
		 }
		swap(x[i],x[min]);
	}
 }
 void bubblesort (sinhvien x[] , int n) {
 	 	for(int i=0;i<n-1;i++){
 		for(int j=n-1;j>i;j--){
 			if(x[j].diemtk>x[j-1].diemtk){
 				swap(x[j],x[j-1]);
			 }
		 }
	 }
 }
 int timkiemnhiphan(sinhvien x[], int n,int x){
    int l = 0, r = n - 1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == x){
            return 1; 
        }
        else if(a[m] < x){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return 0; 
}
int main (){ 
	int n; 
	cout<<"nhap so luong sinh vien :"<<endl;
	do{
		cin>> n;
		if(n<0){
			cout<<"yeu cau nhap lai !"<<endl;
		}
	}
	while(n<0);
	sinhvien*x=new sinhvien[n];
	cout<<"nhap thong tin sinh vien :"<<endl;
	for(int i=0;i<n;i++){
		nhap(x[i],i);
	}
	cout<<"xuat thong tin sinh vien :"<<endl;
	for(int i=0;i<n;i++){
		xuat(x[i],i);
	}
	int x1;
	cout<<"nhap de su dung kieu sap xep(1/2/3 va 0 huy) : "<<endl;
	do {
		cin>> x1;
		if(x1==1){
			cout<<" InterchangeSort :"<<endl;
			InterchangeSort(x , n);
			for(int i=0;i<n;i++){
				xuat(x[i],i);
			}
		}
		if(x1==2){
			cout<<" SelectionSort :"<<endl;
			SelectionSort(x , n);
			for(int i=0;i<n;i++){
				xuat(x[i],i);
			}
		}
		if(x1==3){
			cout<<" bubblesort :"<<endl;
			bubblesort (x , n);
			for(int i=0;i<n;i++){
				xuat(x[i],i);
			}
		}
	}
	while(x1==1||x1==2||x1==3);
} 

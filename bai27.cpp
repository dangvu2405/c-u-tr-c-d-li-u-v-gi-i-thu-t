 #include <bits/stdc++.h>
 using namespace std;
 struct vemb{
 	int mave;
	string khoihanh;
	string den;
	float gia;
 };
 void nhap(vemb a[],int n){
 	for(int i=0;i<n;i++){
	 	cout<<"nhap ma ve may bay:"<<endl;
	 	cin >> a[i].mave;
	 	cin.ignore();
	 	cout<<"khoi hanh tu:"<<endl;
	 	getline(cin,a[i].khoihanh);
	 	cout<<"diem den:"<<endl;
	 	getline(cin,a[i].den);
	 	cout<<"gia ve:"<<endl;
	 	cin>> a[i].gia;
	 }
 }
 void xuat(vemb a[],int n){
 	for(int i=0; i<n;i++){
 		cout<<"ID:"<<a[i].mave<<"khoi hanh:"<<a[i].khoihanh<<"den:"
		 <<a[i].den<<"gia ve:"<<a[i].gia<<endl;
	 }
 }
 void SelectionSort(vemb a[],int n){
 	int min;
 	for(int i=0;i<n;i++){
 		min = i;
 		for(int j=n-1;j>i;j--)
 		{
 			if(a[min].gia>a[j].gia){
 				min=j;
			}
		}
		if(min!=i){
			swap(a[min],a[i]);
		}
	}
 }
 bool timnhiphan(vemb a[],int n,float x){
 	int l,r,m;
 	l=0;
 	r=n-1;
 	while(l<=r){
 		m=(l+r)/2;
 		if(a[m].gia==x){
 			return true;
		}
		if(a[m].gia < x){
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
 	cout<<"nhap so luong ve:"<<endl;
 	do{
 		cin>>n;
 		if(n<0){
 			cout<<"yeu cau nhap lai !"<<endl;
		}
	}
	while(n<0);
	vemb*a= new vemb[n];
	cout<<"nhap thong tin ve may bay :"<<endl;
	nhap(a,n);
	cout<<"xuat thong tin ve may bay :"<<endl;
	xuat(a,n);
	cout<<"sap xep ve may bay theo tang dan :"<<endl;
	SelectionSort( a, n);
	xuat(a,n);
	int z;
	cout<<" gia ve can tim :"<<endl;
	cin >>z;
	if(timnhiphan(a,n,z)){
		cout<<"ton tai";
	}
	else{
		cout<<"khong ton tai";
	}
 }
 
 

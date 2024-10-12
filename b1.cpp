#include <bits/stdc++.h>
using namespace std;
struct sinhvien {
	int masv;
	string ten;
	string lop;
	float diem;
	string hk;
};
struct node{
	sinhvien data;
	node*next;
};
struct List{
	node*pHead;
	node*pTail;
};
void khoitao(List&ds){
	ds.pHead==NULL;
	ds.pTail==NULL;
}
node*makenode(sinhvien x){
	node*p=new node();
	if(p==NULL){
		cout<<"cap phat khong thanh cong "<<endl;
	}
	else{
		p->data=x;
		p->next=NULL;
	}
	return p;
}
void nhap(sinhvien&n){
	cout<<"nhap ma sinh vien:"<<endl;
	cin>>n.masv;
	cin.ignore();
	cout<<"nhap ten sinh vien:"<<endl;
	getline (cin,n.ten);
	cout<<"nhap lop:"<<endl;
	getline(cin,n.lop);
	cout<<"nhap diem:"<<endl;
	cin>> n.diem;
	cout<<"nhap hanh kiem:"<<endl;
	cin>>n.hk; 
}
void xuat(sinhvien&n,int x){
	cout<<"thong tin sinh vien "<<x<<" :"<<endl;
	cout<<n.masv<<"\t"<<n.ten<<"\t"<<n.lop<<"\t"<<n.diem<<"\t"<<n.hk<<endl;
}
void chendau(List&ds, node*p){
	if(ds.pHead==NULL){
		ds.pHead=ds.pTail=p;
	}
	else{
		p->next =ds.pHead;
		ds.pHead= p;
	}
}
void chencuoi(List&ds, node*p){
	if(ds.pHead==NULL){
		ds.pHead=ds.pTail=p;
	}
	else{
		ds.pTail->next=p;
		ds.pTail=p;
	}
}
void nhapthongtinsinhvien(List&ds,int n){
	for(int i=0;i<n;i++){
		sinhvien a;
		nhap(a);
		chencuoi(ds,makenode(a));
	}
}
void xuatthongtinsinhvien(List &ds){
	node*p=ds.pHead;
	int n=1;
	while (p!=NULL){
		xuat(p->data,n);
		n++;
		p=p->next;
	}
}
//void xoacuoi(List&ds){
//	
//}
int main (){
	int n;
	List ds;
	cout<<"nhap so sinh vien:"<<endl;
	do{
		cin>>n;
		if(n<0){
			cout<<"yeu cau nhap lai:"<<endl;
		}
	}
	while(n<0);
	nhapthongtinsinhvien(ds,n);
	xuatthongtinsinhvien(ds);
}

#include <bits/stdc++.h>
using namespace std;
struct hocsinh{
	int age;
};
struct node{
	hocsinh data;
	node*next;
};
struct List{
	node*pHead;
	node*pTail;
};
void khoitao(List&ds){
	ds.pHead =NULL;
	ds.pTail =NULL;
}
node*makenode(hocsinh x){
	node*p=new node();
	if(p==NULL){
		cout<< " cap phat khong thanh cong "<<endl;
	}
	p->data =x;
	p->next =NULL;
	return p;
}
void nhap(hocsinh&x){
	cout<<"nhap tuoi hoc sinh:"<<endl;
	cin>> x.age;
}
void xuat(hocsinh&x){
	cout<<"tuoi hoc sinh:"<<endl;
	cout<< x.age;
}
void chendau(List&ds,node*p){
	if(ds.pHead==NULL){
		ds.pHead = ds.pTail =p;
	}
	else{
		p -> next = ds.pHead;
		ds.pHead = p;
	}
}
void chencuoi(List&ds, node*p){
	if(ds.pHead==NULL){
		ds.pHead = ds.pTail =p;
	}
	else{
		ds.pTail ->next = p;
		ds.pTail =p;
	}
}
void chensau(List&ds,node*q,node*p){
	if(q!=NULL){
		p->next = q->next;
		q->next = p;
		if(ds.pTail==q){
			ds.pTail = p;
		}	
	}
	else{
		chendau(ds,p);
	}
}
void xoadau(List&ds){
	if(ds.pHead==NULL){
		return;
	}
	else{
		node*p = ds.pHead;
		ds.pHead=ds.pHead->next; 
		delete p;
	}
}
void xoacuoi(List&ds){
	if(ds.pHead==NULL){
		return;
	}
	else if(ds.pHead == ds.pTail){
		xoadau(ds);
	}
	else{
		node*p=ds.pHead;
		while(p->next!=ds.pTail){
			p=p->next;
		}
		delete p->next;
		ds.pTail =p;
		ds.pTail->next = NULL; 
	}
}
void nhapthongtin(List&ds,int n){
	for(int i=0; i<n;i++){
		hocsinh x;
		nhap(x);
		node*p= makenode(x);
		if(p==NULL){
			cout<<"cap phat khong thanh cong "<<endl;
			return;
		}
		chencuoi(ds,p);
	}
}
void xuatthongtin(List&ds){
	node*p = ds.pHead;
	cout<<"thong tin hoc vien:"<<endl;
	while(p!=NULL){
		cout<< p->data.age<<" ";
		p=p->next;
	}
}
node*timkiem(List&ds ,int k){
	node*p=ds.pHead;
	while(p!=NULL && p -> data.age != k ){
		p=p->next;
	}
	return p;
} 
 int main(){
 	List ds;
 	khoitao(ds);
 	int n;
 	cout<<" so luong hoc sinh:"<<endl;
 	cin>>n;
 	nhapthongtin(ds,n);
 	xuatthongtin(ds);
 	int v1;
 	do{
 		cout<<"lua chon 1/2:"<<endl;
 		cin>>v1;
 		if(v1==1){
 			xoacuoi(ds);
 			cout<<"da xoa cuoi"<<endl;
 			xuatthongtin(ds);
		 }
		if(v1==2){
 			xoadau(ds);
 			cout<<"da xoa dau"<<endl;
 			xuatthongtin(ds);
		 }
	 	}
	while(v1<3);
	int x2;
	cout<< "  phan tu can chen sau "<<endl;
	cin>>x2;
	hocsinh x1;
	cout<<"gia tri chen:"<<endl;
	nhap(x1);
	node*x= makenode(x1);
	chensau(ds,timkiem(ds,x2),x);
	xuatthongtin(ds);
 }

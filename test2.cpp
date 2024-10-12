#include <bits/stdc++.h>
using namespace std;
 struct hocsinh{
 	int age;
 };
 struct node {
 	hocsinh data;
 	node*prev;
 	node*next;
 };
 struct List {
 	node*pHead;
 	node*pTail;
 };
 void khoitao(List&ds){
 	ds.pHead = NULL;
 	ds.pTail = NULL;
 }
 node*makenode(hocsinh x){
 	node*p= new node();
 	if(p==NULL){
 		cout<< " cap phat khong thanh cong !"<<endl;
	 }
	p->data = x;
	p->prev = NULL;
	p->next =NULL;
	return p;
 }
 void chendau(List&ds , node*p){
 	if(ds.pHead==NULL){
 		ds.pHead = ds.pTail=p;
	 }
	 else{
	 	p->next = ds.pHead;
	 	ds.pHead = p;
	 }
 }
 void chencuoi(List&ds, node*p){
 	if(ds.pHead==NULL){
 		ds.pHead = ds.pTail=p;
	 }
	 else{
	 	ds.pTail->next = p;
	 	p->prev = ds.pTail;
	 	ds.pTail = p;
	 }
 }
 void xoadau(List&ds){
 	if(ds.pHead==NULL){
 		return;
	 }
	 else{
	 	node*p = ds.pHead;
	 	ds.pHead = ds.pHead->next;
		delete p;
		ds.pHead ->prev = NULL;
	 }
 }
 void xoacuoi(List&ds){
 	if(ds.pHead==NULL){
 		return;
	 }
	 else if(ds.pHead==ds.pTail){
	 	xoadau(ds);
	 }
	 else{
	 	node*p= ds.pTail;
	 	ds.pTail=ds.pTail->prev ;
		delete p;
		ds.pTail->next = NULL; 
	 }
 }
 void nhapthongtin(List&ds, int n){
 	for(int i=0;i<n;i++){
 		hocsinh x;
 		cout<<"nhap tuoi sinh sinh vien "<< i+1 <<" :"<<endl;
 		cin >> x.age;
 		node*p= makenode(x);
 		if(p==NULL){
 			cout<<"cap phat khong thanh cong !"<<endl;
		 }
		 chencuoi(ds,p);
	 }
 }
 void xuatthongtin(List&ds){
 	node*p = ds.pHead;
 	while(p!=NULL){
 		cout<<" tuoi :" << p->data.age <<endl;
 		p=p->next;
	 }
 }
int main(){
	List ds;
	int n;
	cout<<"nhap so luong sinh vien :"<<endl;
	cin >> n;
	nhapthongtin(ds,n);
	xuatthongtin(ds);
	int i;
	
	do{
		cout<< " chon xoa dau/cuoi:"<<endl;
		cin >>i;
		if(i==1){
			xoadau(ds);
			xuatthongtin(ds);
			cout<<"da xoa dau"<<endl;
		}
		if(i==2){
			xoacuoi(ds);
			xuatthongtin(ds);
			cout<<"da xoa cuoi"<<endl;
		}
	}
	while(i==1||i==2);
	
}

#include <bits/stdc++.h>
using namespace std;
struct khachhang {
	int makh;
	string namekh;
	string sdt;
	float total;
};
struct node{
	khachhang data;
	node*left;
	node*right;
};
struct bin{
	node*goc;
};
void khoitao(bin&ds){
	node*left=NUll;
	node*right= NULL;
}
node* taonode(khachhang a){
	node*p = new node();
	if(p==NULL){
		cout<<"cap phat khong thanh cong"<<endl;
	}
	p->data = a;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void nhapthongtin(khachhang &a){
	    cout << "Nhap ma khach hang: ";
        cin >> a[i].makh;
        cin.ignore(); 
        cout << "Nhap ten khach hang: ";
        getline(cin, a[i].namekh);
        cout << "Nhap so dien thoai: ";
        getline(cin, a[i].sdt);
        cout << "Nhap hoa don: ";
        cin >> a[i].total;
        cout << "---------------------" << endl;
}
void xuatthongtin(node*p){
	
}
void insertnode(){
	
}
int main(){
}

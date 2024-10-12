#include <bits/stdc++.h>
using namespace std;

struct nhanvien{
    int age;
};

struct node{
    nhanvien data;
    node *next;
};

struct List{
    node *pHead;
    node *pTail;
};

void khoitao(List &ds){
    ds.pHead = NULL;
    ds.pTail = NULL;
}

node *makenode(nhanvien x){
    node *p = new node();
    if (p == NULL){
        cout << "Memory allocation failed" << endl;
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}

void addHead(List &ds, node *p){
    if (ds.pHead == NULL){
        ds.pHead = ds.pTail = p;
    } else {
        p->next = ds.pHead;
        ds.pHead = p;
    }
}

void addTail(List &ds, node *p){
    if (ds.pHead == NULL){
        ds.pHead = ds.pTail = p;
    } else {
        ds.pTail->next = p;
        ds.pTail = p;
    }
}

void deletenodefirst(List &ds){
    if (ds.pHead == NULL){
        return;
    } else {
        node *p = ds.pHead;
        ds.pHead = ds.pHead->next;
        if (ds.pHead == NULL) {
            ds.pTail = NULL;
        }
        delete p;
    }
}

void deletenodeend(List &ds){
    if (ds.pHead == NULL){
        return;
    } else if (ds.pHead == ds.pTail) { // Case with only one node
        delete ds.pHead;
        ds.pHead = ds.pTail = NULL;
    } else {
        node *p = ds.pHead;
        while (p->next != ds.pTail){
            p = p->next;
        }
        delete ds.pTail;
        ds.pTail = p;
        ds.pTail->next = NULL;
    }
}

void nhap(nhanvien &x){
    cout << "Enter age: ";
    cin >> x.age;
}

void xuat(List &ds){
    node *p = ds.pHead;
    while (p != NULL){
        cout << p->data.age << endl;
        p = p->next;
    }
}

int main(){
    List ds;
    khoitao(ds);
    int n;
    cout << "Enter number of employees: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        nhanvien x;
        nhap(x);
        node *p = makenode(x);
        if (p != NULL) {
            addTail(ds, p);  // Adding nodes to the tail
        }
    }
    cout << "Employee data:" << endl;
    xuat(ds);
    int xoa;
    cin >> xoa;
    switch(xoa){
    	case 1:
    		deletenodefirst(ds);
    		break;
    	case 2:
    		deletenodeend(ds);
    		break;
    	default:
    		break;
	}
	cout << "Employee data:" << endl;
    xuat(ds);
    return 0;
}


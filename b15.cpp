#include <bits/stdc++.h>
using namespace std;

struct khachhang {
    int makh;
    string namekh;
    string sdt;
    float total;
};
void nhap(khachhang a[], int n) {
    for (int i = 0; i < n; i++) {
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
}

// Heap sort  
void ShipDown(khachhang A[], int i, int n) {
    int left = 2 * i + 1; 
    int right = 2 * i + 2;
    int Max = i;

    if (left < n && A[left].total > A[Max].total) {
        Max = left;
    }
    if (right < n && A[right].total > A[Max].total) {
        Max = right;
    }
    if (Max != i) {
        swap(A[i], A[Max]);
        ShipDown(A, Max, n);
    }
}

void CreateHeap(khachhang A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        ShipDown(A, i, n);
    }
}

void Heapsort(khachhang a[], int n) {
    CreateHeap(a, n);
    for (int size = n - 1; size > 0; size--) {
        swap(a[0], a[size]);
        ShipDown(a, 0, size);
    }
}


int seachnhiphan(khachhang a[], int n, float x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m].total == x) { 
            return m; // Found
        }
        else if (a[m].total < x) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1; 
}
void IntertionSort(khachhang a[],int n){
	int i,j,pos;
	khachhang x;
	for(i=1;i<n;i++){
		pos=i-1;
		x=a[i];
		while((pos>=0)&&(a[pos]>a[x])){
			a[pos+1]=a[pos];
			pos--;
		}
		a[pos+1]=x;
	}
}
void xuat(khachhang a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "ID: " << a[i].makh << "  Ten: " << a[i].namekh
             << "  SDT: " << a[i].sdt << "  Hoa don: " << a[i].total << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so luong khach hang: ";
    do {
        cin >> n;
        if (n < 0) {
            cout << "Yeu cau nhap lai!" << endl;
        }
    } while (n < 0);

    khachhang* a = new khachhang[n]; 
    nhap(a, n);
    xuat(a, n);

    cout << "Lua chon kieu sap xep (1: HeapSort): ";
    int z;
    cin >> z;
    if (z == 1) {
        cout << "Sap xep bang HeapSort:" << endl;
        Heapsort(a, n);
        xuat(a, n);
    }

    float x;
    cout << "Nhap hoa don can tim: ";
    cin >> x;
    int index = seachnhiphan(a, n, x);
    if (index != -1) {
        cout << "Khach hang can tim o vi tri: " << index << endl;
    } else {
        cout << "Khong tim thay!" << endl;
    }

    delete[] a; 
    return 0;
}


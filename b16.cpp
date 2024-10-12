#include <bits/stdc++.h>
using namespace std;

struct ns {
    int nam;
    int thang;
    int ngay;
};

struct nhanvien {
    int manv;
    string namenv;
    ns ngaysinh;
    float luong;
};

// Input employee data
void nhap_nhanvien(nhanvien a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap ma nhan vien: ";
        cin >> a[i].manv;
        cin.ignore(); // Clear newline
        cout << "Nhap ten nhan vien: ";
        getline(cin, a[i].namenv);
        cout << "Nhap ngay sinh (dd/mm/yyyy): ";
        cin >> a[i].ngaysinh.ngay;
        cout << "/";
        cin >> a[i].ngaysinh.thang;
        cout << "/";
        cin >> a[i].ngaysinh.nam;
        cout << "Nhap luong: ";
        cin >> a[i].luong;
        cout << "---------------------" << endl;
    }
}

// Output employee data
void xuat_nhanvien(nhanvien a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "ID: " << a[i].manv << "  Ten: " << a[i].namenv 
             << "  Ngay sinh: " << a[i].ngaysinh.ngay << "/"
             << a[i].ngaysinh.thang << "/" << a[i].ngaysinh.nam
             << "  Luong: " << a[i].luong << endl;
    }
}

int partition(nhanvien arr[], int low, int high) {
    float pivot = arr[high].luong;
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j].luong < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(nhanvien arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int seachnhiphan(nhanvien a[], int n, float x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m].luong == x) { 
            return m; // Found
        }
        else if (a[m].luong < x) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1; 
}
void BubbleSort(nhanvien a[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>0;j++){
			if(a[j].luong < a[j-1].luong){
				swap(a[j],a[j-1]);
			}
		}
	}
}
void ShakerSort(nhanvien a[],int n){
	int l , r,k;
	l=0;
	r=n-1;
	while(l<r){
		for(int i=0;i<n;i++){
			if(a[i].luong > a[i+1].luong){
				swap(a[i],a[i+1]);
				k=i;
			}
		}
		r = k;
		for(int j=r;j>0;j++){
			if(a[j].luong<a[j-1].luong){
				swap(a[j],a[j-1]);
				k=j;
			}
		}
		l = k;
	}	
}
void InsertionSort(nhanvien a[], int n){
	int pos;
	int i,j;
	nhanvien x;
	for(i=1;i<n;i++){
		pos = i - 1;
		x=a[i];
		while((pos>=0) && (a[pos].luong < x.luong )){
			a[pos+1] = a[pos];
			pos--;
		}
		a[pos+1]=x;
	}
}
void BInsertionSort(nhanvien a[], int n){
	int l , r, m;
	nhanvien x;
	for(int i = 1;i<n;i++){
		x=a[i];
		l=0;
		r=i-1;
		while(l<=r){
			m = ( l + r ) / 2;
			if(a[i].luong>a[m].luong){
				l =  m +1;
			}
			else{
				r = m -1;
			}	
		}
		for(int j=i-1;j>=l;j--){
			a[j+1]= a[j];
		}
		a[l]=x;
	}
}

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    do {
        cin >> n;
        if (n < 0) {
            cout << "Yeu cau nhap lai!" << endl;
        }
    } while (n < 0);

    nhanvien* a = new nhanvien[n];
    nhap_nhanvien(a, n);
    cout << "Danh sach nhan vien:" << endl;
    xuat_nhanvien(a, n);

    cout << "Sap xep theo luong (QuickSort):" << endl;
    BInsertionSort(a,n);
    xuat_nhanvien(a, n);
	float x;
    cout << "Nhap luong can tim: ";
    cin >> x;
    int index = seachnhiphan(a, n, x);
    if (index != -1) {
        cout << "nhan vien co luong can tim o vi tri: " << index << endl;
    } else {
        cout << "Khong tim thay!" << endl;
    }
    delete[] a; 
    return 0;
}


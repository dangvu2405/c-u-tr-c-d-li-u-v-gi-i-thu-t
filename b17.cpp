#include <iostream>
#include <string>
using namespace std;

struct tailieu {
    int matl;        
    string nametl;   
    int namxp;      
    float giaban;   
};


void nhap(tailieu a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap ma tai lieu: ";
        cin >> a[i].matl;
        cin.ignore(); // Clear the newline character from the buffer
        cout << "Nhap ten tai lieu: ";
        getline(cin, a[i].nametl);
        cout << "Nhap nam xuat ban: ";
        cin >> a[i].namxp;
        cout << "Nhap gia ban: ";
        cin >> a[i].giaban;
        cout << "---------------------" << endl;
    }
}


void xuat(tailieu a[], int n) {
    cout << "Danh sach tai lieu:\n";
    for (int i = 0; i < n; i++) {
        cout << "ID: " << a[i].matl 
             << ", Ten: " << a[i].nametl 
             << ", Nam xuat ban: " << a[i].namxp 
             << ", Gia ban: " << a[i].giaban << endl;
    }
}


void merge(tailieu a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    tailieu* L = new tailieu[n1];
    tailieu* R = new tailieu[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].giaban <= R[j].giaban) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}


void mergeSort(tailieu a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

// Binary search function to find documents by price
int timKiemGiaBan(tailieu a[], int n, float x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m].giaban == x) {
            return m; // Found
        }
        else if (a[m].giaban < x) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1; // Not found
}

// Main function
int main() {
    int n;
    cout << "Nhap so luong tai lieu: ";
    do {
        cin >> n;
        if (n <= 0) {
            cout << "Yeu cau nhap lai!" << endl;
        }
    } while (n <= 0);

    tailieu* a = new tailieu[n];
    nhap(a, n);
    xuat(a, n);

    // Sort documents by price
    mergeSort(a, 0, n - 1);
    cout << "Danh sach tai lieu sau khi sap xep theo gia ban:\n";
    xuat(a, n);

    float x;
    cout << "Nhap gia ban can tim: ";
    cin >> x;
    int index = timKiemGiaBan(a, n, x);
    if (index != -1) {
        cout << "Tai lieu co gia ban " << x << " la:\n";
        cout << "ID: " << a[index].matl 
             << ", Ten: " << a[index].nametl 
             << ", Nam xuat ban: " << a[index].namxp 
             << ", Gia ban: " << a[index].giaban << endl;
    } else {
        cout << "Khong tim thay tai lieu co gia ban " << x << endl;
    }

    delete[] a; 
    return 0;
}


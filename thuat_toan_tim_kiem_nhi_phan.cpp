// thuat toan kim kiem va thuat toan tim kiem nhi phan dung trong thu vien algorithm 

#include <bits/stdc++.h>

using namespace std;

//linear search
// input 
// 10 3
// 1 2 8 9 0 7 6 5 3 4 
// output 
// true / 1

bool ls(int a[], int n, int x){
    int tmp;
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            cout << "vi tri xuat hien dau tien: " << i;
            return true;
            break;
        }
    }
    return false;   
}

//binary search
//dk: cac phan tu phai duoc sap xep tang dan/ giam dan
// input 
// 10 3
// 1 2 3 4 5 6 7 8 9 10 // dc sap xep


// tang dan
bool bs(int a[], int n, int x){
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        // tim vi tri mid 
        int m = (l+r)/2;
        if(a[m] == x){ // so sanh gia tri tai vi tri mid
            return true;
        }
        // gia tri can tim lon hon gia tri m
        else if(a[m] < x){
            l = m + 1;
        }
        // gia tri can tim nho hon gia tri m 
        else{
            r = m - 1;
        }
    }
    return false;   
}

// binary search viet ngan hon -> chieu giam dan
bool b_s(int a[], int l, int r, int x){
    if(l > r)
        return false;
    int m = (l + r) / 2;
    if(a[m] == x)
        return true;
    else if(a[m] < x)
        return b_s(a, l , m - 1, x);
    else
        return b_s(a, m + 1, r, x); 
}

// dung thuat toan co san 
// binary_search(a+x, a+y, key) => a[x] -> a[y-1]
// binary_search(a+1, a+4, key)
// binary_search(v.begin(), v.end(), key) // tim key trong toan bo vecto
// binary_search(v.begin() + x, v.begin() + y, key) => v[x] -> v[y-1] tim key trong khoang x y cua vecto

//tim vi tri dau tien cua 1 phan tu x trong 1 mang da sap xep
// input
// 10 3
// 1 2 2 3 3 3 3 7 8 9
// output 
// 3

int firstlook(int a[], int l, int r, int x){
    int res = -1;
    while(l <= r){
    int m = (l + r) / 2;
    if(a[m] == x){
        res = m;
        r = m - 1;}
    else if(a[m] < x)
        l = m + 1;
    else
        r = m - 1;
    }
    return res;
}

int lastlook(int a[], int l, int r, int x){
    int res = -1;
    while(l <= r){
    int m = (l + r) / 2;
    if(a[m] == x){
        res = m;
        l = m + 1;}
    else if(a[m] < x)
        l = m + 1;
    else
        r = m - 1;
    }
    return res;
}

//thuat toan lower_bound(iter1, iter2, key) : tim kiem vi tri, gia tri dau tien >= key
//thuat toan upper_bound(iter1, iter2, key) : tim vi tri, gia tri dau tien > key
//ap dung cho mang , vecto , set , map => duoc sap xep
// neu tat ca phan tu trong mang deu nhon hon key => iter2
void lower_upper_bound(){
    int n, x; cin >> n >> x;
    int a[n];
    for(int &y:a) cin >> y;
    auto it = lower_bound(a, a + n, x); // tim vi tri dau tien cua phan tu x >= a[] // vecto lower_bound(a.begin(), a.end(), key)
    if(it == (a+n)){
        cout << "khong co phan tu nao >= key = " << x << endl;
    }
    else{
        cout << *it << endl; // tro toi gia tri dau tien tai vi tri dau tien >= key vd key = 2 thi gia tri dau tien >= 2 se nhan (2,3,4,....)
        cout << it - a << endl; // tra ve vi tri dau tien >= key
    }
}
int main(){
    int n,x;
    cin >> n >> x;
    int a[n];
    for(int &y:a) cin >> y;
    //for(int b:a) cout << b << " ";
    if(bs(a, n, x)){
        cout << x <<  " found !\n";
    }
    else{
        cout << x << " not found !\n";
    }
    // if(binary_search(a, a + n, x)){
    //     cout << " found !";
    // }
    // else{
    //     cout << " not found !";
    // }
    
    if(firstlook(a, 0, n - 1, x) > 0){
        cout << "vi tri dau tien xuat hien x : \t" << firstlook(a, 0, n - 1, x) << endl;
        cout << "vi tri cuoi xuat hien x : \t" << lastlook(a, 0, n-1,x) << endl;
        cout << "so lan xuat hien : \t" << lastlook(a, 0, n - 1, x) - firstlook(a, 0, n - 1, x) + 1 << endl; 
        // co the dung distance de tim so lan xuat hien
    }
    else{
        cout << "0\n";
    }
    return 0;
    //lower_upper_bound();
}





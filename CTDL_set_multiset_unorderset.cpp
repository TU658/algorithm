//set duoc su dung khi muon luu phan tu rieng biet , dem phan tu khac nhau trong mang, tim kiem nhanh thi dung set, cac phan tu duoc sap xep tu nho den lon
#include <bits/stdc++.h>

using namespace std;
//// SET
void set_basic(){
    //ham set O(logn) set<datatype> bien;
    //bien.insert();
    //bien.size();
    //find() tim kiem trong set tra ve iterator
    //count() tim kiem trong set gia tri so luong phan tu co trong set
    //erase() xoa phan tu trong set
    set<int> s;
    s.insert(100);
    s.insert(200);
    s.insert(300);
    s.insert(100);
    s.insert(200);
    for(int i = 0; i <= 9; i++){
        s.insert(i);
    }
    // cout << s.size() << endl;
    // if(s.count(5) == 1){ // find // s.find(5) != s.end() // gia tri iterator tro toi gia tri khi tim thay 
    //     cout << " FOUND !\n";// khong tim thay se tro ve s.end()
    // }
    // else{
    //     cout << " NOT FOUND !\n";
    // }

    s.erase(s.find(5)); // s.erese(5)
    cout << s.size() << endl;
    for(int x : s) cout << x << " ";
    cout << *s.begin() << endl; // phan tu dau .rbegin = phan tu cuoi cung
}

void nhap_xuat_set(){
    int n; cin >> n;
    set<int> s; // datatype co the la long long , so am , string ,...
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        s.insert(x);
    }
    cout << "cac phan tu trong set la : " ;
    for(int x : s) cout << x << " ";
    cout << endl << "so phan tu cua set la : " << s.size();
}

void nhap_xuat_set_string(){
// spython
// java
// chode
// laptrinh
// python
    int n; cin >> n;
    set<string> s;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin,str);
        s.insert(str);
    }
    cout << "so phan tu trong set string : " << s.size() << endl;
    for(string x : s) cout <<"string : " << x << endl;
}

// Multiset cho phep cac phan tu giong nhau khai bao nhu set = multiset , sap xep van theo thu tu tu nho den be co trung lap
// cac lenh tuong tu trong set

// vd: cho mang co n phan tu va so nguyen k, doi voi moi day so con lien tiep co chieu k,
// in ra duoc phan tu lon nhat trong day so con do
// input 10 3
// input 1 2 3 1 4 5 1 8 9 10
// output 3 3 4 5 5 8 9 10

void set_multiset(){
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int &x : a) cin >> x; //&x nhap tung phan tu cua mang
    // for(int i = 0; i < n; i++){
    //     cout << a[i] << " ";
    // }
    cout << "cac so trong phan tu a[] la : ";
    for(int y : a) cout << y << " ";
    multiset<int> ms;
    for(int i = 0; i < k; i++){
        ms.insert(a[i]);
    }
    cout << endl << "cac phan tu lon nhat trong day so con la : ";
    for(int i = k; i < n; i++){
        cout << *ms.rbegin() << " "; // lay duoc phan tu lon nhat vd {1,2,3} -> rbegin = 3
        ms.erase(ms.find(a[i-k])); // xoa phan tu i - k vd {1,2,3} tai i = 3 thi xoa 1; 
        ms.insert(a[i]);// them phan tu a[i] de tap hop ms 3 phan tu k , lap den het n
    }
    cout << *ms.rbegin() << endl; // truong hop khi con 2 ms 9 10 thi lay rbegin de lay lon nhat 
    system("pause");
}


//unordered_set luu phan tu rieng biet nhung k sap xep thu tu
//cac ham tuong tu set
void set_unordered(){
    unordered_set<int> s;
    for(int i = 0; i < 10; i++){
        s.insert(i);
    }
    for(int x : s) cout << x << " ";
}

int main(){
    set_unordered();
    return 0;
}

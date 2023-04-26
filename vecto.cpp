#include <bits/stdc++.h>

using namespace std;

//vecto coi nhu la mang dong co the tu dong thay doi kich thuoc khi thay doi phan tu o trong
//vector<kieu_du_lieu> ten_vecto
//push_back() day phan tu vao cuoi vecto
//size() cho biet kich thuoc vecto
//truy cap phan tu trong vecto thong qua chi so
//duyet cac phan tu qua for / for each / iterator / auto

void nhap_xuat(){
    // nhap phan tu cua mang vecto khi c

    // int n;
    // cin >> n;
    // vector<int> v(n);
    // for(int i = 0; i < n; i++){
    //     cin >> v[i];
    // }
    // for(int i = 0; i < n; i++){
    //     cout << v[i] << " ";
    // }
    // int n;
    // cin >> n;
    // vector<int> v;
    // for(int i = 0; i < n; i++){
    //     int x; cin >> x;
    //     v.push_back(x);
    // }
    // for(int i = 0; i < n; i++){
    //     cout << v[i] << " ";
    // }

    // n la so phan tu 100 la gia tri phan tu cua tung phan tu 
    int n;
    cout << "nhap so phan tu: ";
    cin >> n;
    vector<int> v(n, 100);
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
}


//nhap chuoi string co dau space xuat ra tung tu trong chuoi string 
void nhap_xuat_string(){
    string a;
    cout << "nhap chuoi string : ";
    getline(cin,a);
    stringstream ss(a);
    string tmp;
    vector<string> v;
    while(ss >> tmp){
        v.push_back(tmp);
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}


//cach nhap va xuat vecto dung datatype so
void nhap_xuat_vecto(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout << v.size() << endl;
    cout << "phan tu dau tien trong vecto la : " << v[0] << endl;
    cout <<"phan tu thu cuoi cung trong vecto la : " << v[v.size() - 1] << endl;
    for(int i = 0; i < v.size(); i++){
        cout <<"phan tu " << i << " la : " << v[i] << endl;
    }
    for(int x : v){
        cout << "phan tu co la : " << x << endl;
    }
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        //duyet qua iterator
        cout << *it << endl;
    }
    for(auto it = v.begin(); it != v.end(); it++){
        // duyet qua auto
        cout << *it << endl;
    }
    cout << *(v.begin()+2) << endl; // tro toi dia tri trong iterator
}
int main(){
    nhap_xuat();
}
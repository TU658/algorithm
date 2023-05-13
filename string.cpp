// #include <iostream>
// #include <math.h>
#include <bits/stdc++.h> // add toan bo thu vien vao k can phai nho nao voi nao het
using namespace std;
// truy cap ki tu cua sau thong qua chi so
// bien_string length();
// bien_string size();
// cin, getline de bo qua dau cach va nhap duoc dau space 
// + cộng chuỗi 
// compare so sanh 
// substr cat chuoi
// stoi doi gia tri string -> int ( string to int)
// stoll doi gia tri string -> long long ( string to long long)
// to_string(bien_string) tu so chuyen thanh string ( so thuc so nguyen deu duoc)
// stringstream() tach tu
// bien_string.find(s) tim chuoi s trong chuoi bien_string, gia tri tra ve la vi tri bat dau xuat hiẹn
// s.erase(x,n) xoa n ki tu bat dau tai vi tri x
// s.replace(x,n,str) thay the n ki tu tai vi tri bat dau la x bang chuoi str
// s.swap(s2) hoan doi noi dung 2 chuoi
// s.insert(index,s2) them chuoi s2 vao s sau vi tri index
void check1(){
    int n,m;
    cin >> n >> m; // van con phim enter nen sau s la rong 
    cin.ignore(); // bo qua phim enter () = 1 , tranh troi lenh getline khi gap phim enter có nghia la duoc coi la chua an enter / space
    string s;
    cout << "nhap string mong muon : ";
    getline(cin,s); // nhap sau doc duoc ca dau space
    cout << "sau vua nhap la : " << s << endl;
    cout << "sau vua nhap la co tung phan tu  : " << endl; 
    for (int i = 0; i < s.length(); i++) // length & size la so luong ki tu trong string
    {
       cout << s[i] << " ";
    }
    cout << endl;
    for(char x : s){
        cout << x << endl;
    }  
}
void check2(){
    // cong 2 chuoi 
    string a = "nhin cai gi";
    string b = " ha may";
    string s = a + b;
    cout << s << endl;
}

void check3(string a , string b){
    //so sanh 2 string
    // if (a > b)
    // {
    //     cout << "a lon hon b \n";
    // }else {
    //     cout << "a nho hon b \n";
    // } 
    cout << a.compare(b) << endl;
        // a < b = -1
        // a > b = 1
        // a == b = 0
}

void check4(string a){
    //substr
    //cat chuoi tu dau den dau 
    string b = a.substr(2,4); // cat tu 2 den phan tu thu 4
    cout << b << endl;
}

void check5(string s){
    //tach tu trong string
    // stringstream ss(s);
    // string tmp;
    // while(ss >> tmp){ // tach ss tung tu ra gan vao tmp // theo dau cach space
    //     cout << tmp << endl;
    // }
    // tach theo dau hieu tach
    stringstream ss(s);
    string tmp;
    while(getline(ss,tmp,'.')){
        // tach theo dau .
        cout << tmp << endl;
    }
}

void check_6(string s){
    stringstream ss(s);
    string tmp;
    while(ss >> tmp){
        cout << tmp << endl;
    }
}
int main(){
    check5("v u .van.tu");
    return 0;
}
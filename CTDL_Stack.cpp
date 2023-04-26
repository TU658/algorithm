#include <bits/stdc++.h>
#include <stack>
using namespace std;


//stack LIFO vao cuoi cung nhung ra dau tien(lien quan mat thiet den de quy) //ngan xep
//push dua vao 
//pop xoa phan tu cuoi cung vao  ( dinh stack )
//top lay ra phan tu dau stack
//size
//empty check xem rong hay k
//phuc tap O(1)

void basic(){
    stack<int> st;
    st.push(1); // them data vao stack theo thu tu tu duoi len dinh stack
    st.push(2);
    st.push(3);
    cout << st.top() << endl; //in ra phan tu dinh cua stack
    st.pop(); //xoa phan tu dinh cua stack
    cout << st.top() << endl;
    cout << st.size() << endl; // in ra so luong phan tu trong stack
    if(st.empty()){ //ktra rong hay k 
        cout << "rong\n";
    }
    else    cout << "k rong\n";
}

//vd chuyen doi thap phan thanh binary dung stack de luu
int thapphan_binary(int n){
    stack<int> st; //khai bao stack
    while(n != 0){ //lap den khi n == 0
        st.push(n%2); // n chia du cho 2 de lay binary va push vao stack
        n/=2; //lay phan thuong tiep tuc chia 2
    }
    while(!st.empty()){ // lap den khi nao empty la rong 
        cout << st.top(); // in ra phan tu dinh
        st.pop();// xoa phan tu dinh de in ra dinh tiep theo
    }
    exit(0); // ket thuc chuong trinh
}

//vd co danh sach tu r in nguoc lai
//python java php c++ js
//-> js c++ php java python
void in_nguoc(string s){
    getline(cin, s);
    stringstream ss(s);
    string word;
    stack<string> st;
    while(ss >> word){
        st.push(word);
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

//ktra dau ngoac hop le
//()()()() hop le
//((())) hop le
// (((())(() khong hop le
void check_ngoac(string s){
    stack<char> st;
    for(char x:s){
        if(x == '(')
            st.push(x);
        else{
            if(st.empty()){
                cout << "khong hop le \n";
                return;
            }
            else
                st.pop();
        }
    }
    if(st.empty()){
        cout << "hop le \n";
    }
    else{
        cout << "khong hop le \n";
    }
}

//phan tu dau tien lon hon ben phai (Next greater element)
//3 4 2 5 1 6 2
//4 5 5 6 6 -1 -1
void next_greater(int a[], int n){
    for(int i = 0; i < n; i++){
        int res = -1;
        for(int j = i+1; j<n; j++){
            if(a[j] > a[i]){
                res = a[j];
                break;
            }
        }
        cout << res << " ";
    }
}

void next_greater_stack(int a[], int n){
    int b[n];
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(st.empty()){
            st.push(i);
        }
        else{
            while(!st.empty() && a[st.top()] < a[i]){
                b[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        b[st.top()] = -1;
        st.pop();
    }
    for(int x:b) cout << x << " "; 
}


//tinh dien tich lon nhat tren bieu do 


int main(){
    //basic();
    //cout << thapphan_binary(63);
    // string a;
    // in_nguoc(a);
    // int t; cin >> t;
    // while(t--){
    //     string a; cin >> a;
    //     check_ngoac(a);
    // }
    int n; cin >> n;
    int a[n];
    for(int &x:a) cin >> x;
    next_greater_stack(a,n);
    return 0;
}
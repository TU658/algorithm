#include <bits/stdc++.h>
#include <queue>
#include <set>

using namespace std;

//queue co cach thuc hoat dong FIFO: vao dau ra dau co 2 dau 1 dau vao 1 dau ra nen vao dau tien thi ra dau tien //hang doi
//push vao cuoi hang
//pop xoa dau hang
//front truy cap gia tri o dau hang 
//empty check rong
//size kich thuoc
//queue<datatype> bien;

void basic(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.front() << endl;
    q.pop(); // xoa phan tu dau hang doi la 1 
    cout << q.front() << endl;
    q.pop();
    q.pop();
    q.pop();
    if(q.empty())   cout << "true \n";
    else    cout << "false \n";
}

//vd:
//cho 1 so tu nhien n roi in ra cac so binary tu 1-n
vector<string> res; //chua cac gia tri top khi duoc gan cho front
void sinh_10000_binary(){
    queue<string> q; // khoi tao queue
    q.push("1"); // gia tri ba ban dau la 1 dua vao queue q
    res.push_back("1"); // gia tri ban dau la 1 dua vao vector res
    while(res.size() < 10000){ //lap den khi nao ra duoc 10000 binary duoc luu vao res
        string top = q.front(); //gan gia tri dau hang vao top de + dua vao vector res va queue q
        q.pop(); // roi xoa phan tu front do khi no da co trong du lieu top
        res.push_back(top + "0"); // dua no binary tiep theo dang string vao vecto 
        res.push_back(top + "1"); // binary tiep theo dang string vao vecto 
        q.push(top + "0"); // binary tiep theo dang string vao queue q
        q.push(top + "1"); // binary tiep theo dang string vao queue q
    }

}

void in_binary_n(){
    int t; cin >> t;
    sinh_10000_binary();
    while (t--)
    {
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            cout << res[i] << " "; // in ra phan tu trong vecto res ung voi de bai toan 
        }
        cout << endl;
    }
    

}

//tim so nguyen duong x nho nhat duoc tao boi so 0 va 9 chia het cho n
//vd: n = 5 -> x = 90;
// n = 7 -> x = 9009

void sinh_10000_tohop09(){
    queue<string> q;
    q.push("9");
    res.push_back("9");
    while(res.size() < 10000){
        string top = q.front();
        q.pop();
        res.push_back(top + "0");
        res.push_back(top + "9");
        q.push(top + "0");
        q.push(top + "9");
    }
}

void so_chia_n(){
    sinh_10000_tohop09();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 0; i < res.size(); i++){
            if(stoi(res[i]) % n == 0){
                cout << res[i] << endl;
                break;
            }
        }
    }
}


//cho 2 so n,k so thu n chuyen thanh k qua may thao tac
// thao tac 1: n = n - 1
// thao tac 2: n = n * 2
// vd n = 2, k = 5

// thao tac 1: n = n * 2 = 4
// thao tac 2: n = n - 1 = 3
// thao tac 3: n = n * 2 = 6
// thao tac 4: n = n - 1 = 5

set<int> tmp;
void sinh_thao_thao_tac(int n){
    queue<int> q;
    q.push(n);
    tmp.insert(n);
    while(tmp.size() < 100){
        int top = q.front();
        q.pop();
        tmp.insert(top * 2);
        tmp.insert(top - 1);
        q.push(top * 2);
        q.push(top - 1);
    }
}

void cnt_thao_tac(){
    int n; cin >> n;
    int k; cin >> k;
    int cnt = 0;
    sinh_thao_thao_tac(n);
    cout << tmp.size() << "dau" << endl;
    for(int x:tmp) cout << x << " ";
    cout << endl;
    for(auto it = tmp.begin(); it != tmp.end();){
        if(*it < 0){
            tmp.erase(it++);
        }
        else ++it;
    }
    cout << tmp.size() << "cuoi" << endl;
    // for(int x:tmp) cout << x << " ";
    // for(auto it = tmp.begin(); it != tmp.end(); it++){
    //     if(*it == k){
    //         cout << endl;
    //         cout << cnt++;           
    //         break;
    //     }
    //     cnt++;
    // }   
}

//queue 2 dau deque(double end queue)
//size()
//push_front() them dau
//push_back() them cuoi
//pop_front() xoa dau
//pop_back() xoa cuoi
//empty() check rong
//front() lay phan tu dau 
//back() lay phan tu cuoi

void basic_deque(){
    deque<int> dq;
    dq.push_front(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);
    dq.push_front(1);
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    cout << dq.size() << endl;
    cout << dq.empty() << endl;
    dq.pop_front();
    cout << dq.front() << endl;
    dq.pop_back();
    cout << dq.back() << endl;
}

//deque vd : cho mang n phan tu va so nguyen k
//tim phan tu lon nhat cua tung mang k con trong mang me n
//vd: 7 3 1 2 8 6 4 1 0
//output : 7 3 8 8 8 6 4

void find_max_k(int a[],int n, int k){
    for(int i = 0; i <= n - k; i++){
        int tmp = INT_MIN;
        for(int j = 0; j < k; j++){
            tmp = max(tmp,a[i+j]);
        }
        cout << tmp << " ";
    }
}

void find_max_k_multiset(int a[], int n, int k){
    multiset<int> ms;
    for(int i = 0; i < k; i++){
        ms.insert(a[i]);
    }
    cout << *ms.rbegin() << " ";
    for(int i = k; i <= n-1; i++){
        //xoa phan tu o i - k
        //them phan tu o chi so i
        ms.erase(ms.find(a[i - k])); //xoa phan tu ma iterator tro toi 
        ms.insert(a[i]);
        cout << *ms.rbegin() << " ";
    }
}

void find_max_k_deque(int a[], int n, int k){
    deque<int> dq; //khai bao deque
    for(int i = 0; i < k; i++){ //cho chay mang tu 0-k
        while(!dq.empty()  && a[i] > a[dq.back()]){ // check rong va dua phan tu lon nhat trong mang k len front deque
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << a[dq.front()] << " ";
    for(int i = k; i <= n-1; i++){
        if(dq.front() <= i-k){
            dq.pop_front();
        }
        while(!dq.empty() && a[i] >= a[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        cout << a[dq.front()] << " ";       
    }
}



//hang doi uu tien // priority_queue // mac dinh phan tu dau hang la top  
//lay so lon nhat trong queue va can bang hon multiset
//push
//size
//empty
//pop xoa phan tu o dau hang
//top lay ra phan tu o dau hang, mac dinh la lon nhat 

void basic_priority_queue(){
    priority_queue<int> pq; // mac dinh lon nhat o dau
    //priority_queue<int, vector<int>, greater<int>> pq; // mac dinh nho nhat o dau
    pq.push(1);
    pq.push(5);
    pq.push(3);
    pq.push(4);
    cout << pq.top() << endl;
    pq.push(100);
    pq.push(30);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
}

//vd noi day
//cho 4 phan tu noi lam sao cho chi phi la nho nhat 
// input 4 2 3 6 -> 2+3 = 5 -> 5+4 = 9 -> 9+6 = 15
// output 29 (5 + 9 + 15 = 29)
// 6
// 2 5 3 1 5 7
// 2 5 3 1 5 7
// 1
// 55

void noi_day(){
    vector<int> v; // khai bao vecto de luu hoac k dung cung dc dung mang
    int n; cin >> n;
    int a[n];
    for(int &x:a) {cin >> x; v.push_back(x);} // nhap mang va push back vao vector
    for(int x:v) cout << x << " ";
    priority_queue<int, vector<int>, greater<int>> pq; //mac dinh top nho nhat dau hang
    for(int x:v) pq.push(x); // push tung phan tu cua vecto vao pq
    long long sum = 0;
    cout << endl << pq.top() << " ";
    while(pq.size() > 1){
        //lay ra 2 soi dau ngan nhat
        long long top1 = pq.top(); //lay phan tu nho nhat 1  luu vao top1
        pq.pop(); // xoa phan tu nho nhat 1
        long long top2 = pq.top(); //lay phan tu nho nhat 2 luu vao top2
        pq.pop(); //xoa phan tu nho nhat 2
        sum += top1 + top2; // tong chi phi moi lan noi 
        pq.push(top1 + top2); // push gia tri vao priority 1 lan nua de noi
    }
    cout << endl << sum << endl;

}

//cho xau S gom cac chu viet hoa A B C D 
//in ra gia tri tong cac chu
//vd : AAABBCD -> 3^2 + 2^2 + 1^2 + 1^2 = 15
// 0
// ABCC
// 6
// 0
// AAABBCD
// 15 
void xau_s_tong(){
    //dung map de dem tan xuat xuat hien trong mang
    int k; cin >> k;
    string s; cin >> s;
    map<char, int> mp;
    for(char x:s){
        mp[x]++; 
    }
    
    priority_queue<int> pq;

    for(auto it:mp){
        pq.push(it.second);
    }
    while(k > 0){
        int top = pq.top();
        pq.pop();
        --top; --k;
        pq.push(max(top, 0));
    }
    long long tmp = 0;
    while(!pq.empty()){
        tmp += 1ll*pq.top() *pq.top();
        pq.pop();
    }
    cout << tmp << " ";
}




int main (){
    //basic();
    //in_binary_n();
    //so_chia_n();
    //cnt_thao_tac();
    //basic_deque();
    // int n,k;
    // cin >> n >> k;
    // int a[n];
    // for(int &x:a) cin >> x;
    // find_max_k_deque(a,n,k);
    //basic_priority_queue();
    //noi_day();
    // xau_s_tong();
    // return 0;
    basic_priority_queue();
}
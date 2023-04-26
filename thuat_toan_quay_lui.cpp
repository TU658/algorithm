#include <bits/stdc++.h>

using namespace std;

//thuat toan quay lui de giai bai toan liet ke cac cau hinh. moi cau hinh duoc xay dung bang cach xay dung tung phan tu, moi phan tu duoc chon bang cach thu tat ca cac kha nang
//nhu thuat toan sinh dung de sinh ra cac phan tu dua tren phan tu truoc do
int n;
int x[100];


//xay dung xau nhi phan co do dai n
// 3
// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111

void in_ket_qua(){
    for(int i = 1; i <= n; i++){
        cout << x[i];
    }
    cout << endl;
}

void Try(int i){
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        if(i == n){
            in_ket_qua();
        }
        else{
            Try(i+1);
        }
    }
}


//xay dung to hop chap k cua n
// 6
// 4
// 1234
// 1235
// 1236
// 1245
// 1246
// 1256
// 1345
// 1346
// 1356
// 1456
// 2345
// 2346
// 2356
// 2456
// 3456

int k;

void in_ket_qua_to_hop(){
    for(int i = 1; i <= k; i++){
        cout << x[i];
    }
    cout << endl;
}

void to_hop(int i){
    //duyet cac kha nang ma x[i] co the nhan duoc
    //cau hinh lon nhat co kha nang i = N - K + i
    //cau hinh nho nhat co kha nang i = X[i-1]+1
    for(int j = x[i - 1] + 1; j <= n - k + i; j++){
        x[i] = j;
        if(i == k){
            in_ket_qua_to_hop();
        }
        else{
            to_hop(i+1);
        }
    }
}


//quay lui sinh hoan vi cua n phan tu
// 3
// 123
// 132
// 213
// 231
// 312
// 321
int used[100];

void in_ket_qua_hoan_vi(){
    for(int i = 1; i <= n; i++){
        cout << x[i];
    }
    cout << endl;
}

void hoan_vi(int i){
    //duyet cac kha nang ma x[i] co the nhan duoc
    //them mang used dung de danh dau de khong duoc su dung lai gia tri khi da su dung , neu muon su dung lai thi tra ve 0
    for(int j = 1; j <= n; j++){
        if(used[j] == 0){
            x[i] = j;
            used[j] = 1; //danh dau phan tu da duoc su dung
            if(i == n){
                in_ket_qua_hoan_vi();
            }
            else{
                hoan_vi(i+1);
            }
            //backtrack
            used[j] = 0;
            //used duoc tra ve 0 de cac cau hinh sau su dung duoc j neu k tra thi k dung duoc nua 
        }
    }
}


//bai toan kinh dien ve quay lui la N quân hậu
//dung cot[] de danh dau cot, d1[] de danh dau duong cheo 1, d2[] de danh dau duong cheo 2
int cot[100], d1[100], d2[100];
int cnt = 0; //dem so cau hinh
void in_kq(){
    for(int i = 1; i <= n; i++){
        cout << "con hau o hang thu\t" << i << "\tnam o cot\t" << x[i] << endl; 
    }
}

int a[100][100];

void kq(){
    memset(a, 0, sizeof(a));//khoi tao cac phan tu trong mang a == 0
    for(int i = 1; i <= n; i++){
        a[i][x[i]] = 1; //vi tri cac quan hau
    }
    //in ra mang 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << a[i][j]<< " ";
        }
        cout << endl;
    }
    cout << endl;
}
void quan_hau(int i){
    //duyet cac kha nang ma x[i] co the nhan duoc
    for(int j = 1; j <= n; j++){
        //chuan bi han x[i] = j
        if(cot[j] == 1 && d1[i-j+n] == 1 && d2[i+j-1] == 1){ // == 1 la chua co / chua chiem
            x[i] = j;
            cot[j] = d1[i-j+n] = d2[i+j-1] = 0; // danh dau la cot, d1, d2 da co gia tri / da chiem
            if(i == n){
                in_kq();
                kq();
                ++cnt;
            }
            else{
                quan_hau(i+1);
            }
            //backtrack
            cot[j] = d1[i-j+n] = d2[i+j-1] = 1; // tra lai 
        }
    }
}

int main(){
    cin >> n;

    //try(1) duoc thuc hien dau tien nhung ket thuc cuoi cung vi trong de quy dung stack 
    //Try(1);

    //to_hop(1) duoc thuc hien dau tien nhung ket thuc la cuoi cung
    //to_hop(1);

    //hoan_vi(1);

    for(int i = 1; i <= 100; i++){
        //khoi tao cot, d1, d2 chua chiem
        cot[i] = d1[i] = d2[i] = 1;
    }
    quan_hau(1);
    cout << "so cau hinh:\t" << cnt << endl;
    return 0;
}
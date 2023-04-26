#include <bits/stdc++.h>

using namespace std;


// thuat toan sinh : sinh ra xau nhi phan co do dai n, sinh to hop con k cua n, sinh hoan vi, phan hoach cac so tu nhien n
// ap dung de liet ke to hop, chinh hop, hoan vi, liet ke co dieu kien -> tuong tu thuat toan quay lui

// //sinh ra xau nhi phan co do dai n
// cac buoc sinh ra cau hinh
// <ktao cau hinh dau tien >
// while(<khi chua phai la cau hinh cuoi cung>){
//     <in ra cau hinh hien tai>
//     <sinh ra cau hinh tiep theo>
// }
// cac bit cau hinh dau tien la 0
// cac bit cau hinh cuoi cung la 1
// vd n = 3
// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111
int n, k, a[100], ok;
void khoi_tao(){
    //khoi tao cac bit cau hinh dau tien la 0
    for(int i = 1; i <= n; i++){
        a[i] = 0;
    }
}

void sinh(){
    int i = n;
    while(i >= 1 && a[i] == 1){
        //xet cac bit tu n -> 1 xem bit nao == 1 thi xet tiep va biet tai 1 do se chuyen ve 0 va a-- den khi nao i-- < 1 thi dung
        a[i] = 0;
        i--;
    }
    //xet thu tu i xem == 0 chua neu co r thi chinh la cau hinh cau cung chi toan bit 1
    if(i == 0){
        ok = 0; // bien ok de xac nhan cau hinh cuoi cung
    }
    else{ //neu chua tiep tuc cho a[i] = 1
        a[i] = 1;
    }
}

//bai toan sinh nhi phan ( bien tau tu sinh nhi phan )
//vd : in ra sau nhi phan co k bit 1(xau nao co k bit thi moi in ra)
bool check(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt += a[i]; //xet cac bit trong xau tu 1 -> n co 2 bit = 1 thi cnt = 2 = k thi check dung cho qua va in ra ket qua 
    }
    return cnt == k; // check cnt = k thi dung trong ham check va ra kq la 1
}

int sinh_binary(){
    cin >> n >> k; 
    ok = 1; //chua la cau hinh cuoi cung de xet while chay den khi tim duoc cau hinh toan bit 1 cuoi cung 
    khoi_tao(); // khoi tao cau hinh dau tien
    // while(ok){// cau hinh chua phai la cuoi cung
    //     for(int i = 1; i <= n; i++){
    //         cout << a[i]; //in lan luot cac bit 
    //     }
    //     cout << endl;// xuong dong
    //     sinh(); // sinh ra cau hinh tiep theo
    // }
    //in ra xau co k bit = 1
    while(ok){// cau hinh chua phai la cuoi cung
        if(check()){
            for(int i = 1; i <= n; i++){
                cout << a[i]; //in lan luot cac bit 
            }
            cout << endl;// xuong dong
        }
        sinh(); // sinh ra cau hinh tiep theo
    }
    return 0;
}


// sinh ra to hop k cua n
// vd : n = 5, k = 3 
// 1,2,3 1,2,4 1,2,5 1,3,4 1,3,5 1,4,5 2,3,4 2,3,5.....
// cau hinh dau tien 1,2,3 cau hinh cuoi cung 3,4,5 (vd n = 10, k = 4 -> dau tien 1,2,3,4 cuoi cung 7,8,9,10)


int main(){
    sinh_binary();
    return 0;
}
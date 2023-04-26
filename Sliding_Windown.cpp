#include <bits/stdc++.h>

using namespace std;

//cua so truot 
//ap dung tinh tong cua to hop k lien tiep trong mang n
//vd. cho mang so nguyen n phan tu va so nguyen k. tim tong phan tu lon lon co trong day n, va in ra day con do, neu co cung gia tri lon nhat thi in ra to hop dau tien
// 1
// 10 3
// 1 2 3 1 5 2 7 8 9 1
// 24
// 7 8 9
void sliding_windown(){
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        int a[n];
        for(int &x:a) cin >> x;
        long long sum = 0;
        for(int i = 0; i < k; i++) sum += a[i]; //tinh tong k = 3
        long long res = sum, idx = 0;
        for(int i = k;i < n; i++){
            sum = sum - a[i-k] + a[i];
            if(sum > res){
                res = sum;
                idx = i - k + 1;
            }
        }
        cout << res << endl;
        for(int j = 0; j < k; j++){
            cout << a[idx +j] << " ";
        }
        cout << endl;
    }
}

//so nho hon k , tim so phep hoan vi toi thieu de dua cac so nho hon k dung canh nhau
// 2
// 5 3
// 2 1 5 6 3
// 2 so, lan hoan vi toi thieu la : 1
// 7 5
// 2 7 9 5 8 7 4
// 1 so, lan hoan vi toi thieu la : 2
void hoan_vi_k(){
    int t; cin >> t;
    while(t--){
         int n,k; cin >> n >> k;
        int a[n];
        for(int &x:a) cin >> x;
        int dem = 0;
        for(int i = 0; i < n; i++){// dem so lan xuat hien gtri <= k de tao cua so cho cac so <= k
            if(a[i] <= k)
                dem++;
        }
        int cnt = 0;
        for(int i = 0; i < dem; i++){//dem so lan xuat hien gtri <= k trong mang 0 - dem(da  tao o tren la cua so)
            if(a[i] <= k){
                cnt++;
            }
        }
        int tmp = cnt; // ki luc trog cua so dau tien co
        for(int j = dem; j < n; j++){//chay gia tri tu dem -> n-1 de cap nhat ki luc cho bien tmp 
            if(a[j-dem] <= k) --cnt;
            if(a[j] <= k) ++cnt;
            tmp = max(cnt,tmp);
        }    
        cout << "so lan hoan vi toi thieu la : " << dem - tmp << endl; // ra so lan hoan vi
    }
    
}

int main(){
    //sliding_windown();
    hoan_vi_k();
    return 0;
}
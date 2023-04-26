// truy van tren mang 1 chieu mang 2 chieu 
#include <bits/stdc++.h>

using namespace std;

// truy van trong mang 1 chieu vd tinh tong tu vi tri left den vi tri right
// truy van mang 1 chieu
void truy_van_array_1_chieu(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    //for(int x : a) cin >> x;
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    //for(int x : a) cout << x << " ";   
    int q; cin >> q;
    while (q--)
    {
        int l,r;
        cin >> l >> r;
        int sum = 0;
        for(int i = l; i <= r; i++){
            sum += a[i];
        }
        cout << sum << endl;
    }
} 
void truy_van_array_1_chieu_prefix_sum(){
    //dung thuat toan prefix sum de toi uu toc do
    int n; cin >> n;
    int a[n + 1]; // tao nhu vay de khi prefix sum 1 =[ 0 + 1] - 1 = 0 neu a[n] thi prefix sum 1 = [0] - 1
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int prefix[n + 1] = {0};
    for(int i = 1; i <= n; i++){
        //tao mang ao prefix de tinh tong cho de vi 2 3 8 6 4 1 -> 2 5 13 19 23 24
        prefix[i] = prefix[i-1] +a[i];
    }
    int q; cin >> q;
    while(q--){
        // dua vao mang prefix de truy van
        int l,r; cin >> l >> r;
        cout << prefix[r] - prefix[l-1] << endl; 
    }
}

//truy van trong mang 2 chieu vd tinh tong hinh chu nhat trong mang 2 chieu 
void truy_van_array_2_chieu(){
    int n,m;
    cout << "nhap so phan tu cua mang n.m : ";
    cin >> n >> m;
    int a[n+1][m+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int q;
    cout << "nhap so lan truy van : ";
    cin >> q;
    while(q--){
        int h1,h2,c1,c2;
        cout << "nhap theo thu tu h1, h2, c1, c2 : ";
        cin >> h1 >> h2 >> c1 >> c2;
        int sum = 0;
        for(int i = h1; i <= h2; i++){
            for(int j = c1; j <= c2; j++){
                sum += a[i][j];
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << sum << endl;
    }
    //toi uu hoa toc do dung prefix sum
}
int main(){
    truy_van_array_2_chieu();
}
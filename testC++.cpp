#include <bits/stdc++.h>

using namespace std;

int find(){
    int j;
    cin >> j;
    int a[j];
    int n;
    cin >> n;
    int tmp = 0;
    int c = -1;
    for(int i = 0; i < j; i++){
        a[i] = ++tmp;
    }
    int l = 0;
    int r = j - 1;
    while(r >= l){
        int m = (l+r)/2;
        if(n == a[m]){
            return m;
            exit(0);
        }
        else if(a[m] > n){
            r = m - 1;
        }
        else if(a[m] < n){
            l = m + 1;
        }
    }
    return false;
}

int toInt(string str) {
    int res = 0;
    for(char c : str) {
        res = res * 10 + (c - '0');
    }
    return res;
}

//in so lon nhat nho nhat trong mang
void find(int a[], int n){
    sort(a,a + n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "so lon nhat : " << a[n-1] << endl;
    cout << "so nho nhat : " << a[0] << endl;
}

int numIdenticalPairs() {
    vector<int> nums{1,2,3,1,1,3};
    int count = 0;  // Khởi tạo biến đếm
    vector<pair<int, int>> pairs;  // Khởi tạo vector để lưu trữ cặp số
    for (int i = 0; i < nums.size(); i++) {  // Duyệt từng phần tử trong mảng nums
        for (int j = i + 1; j < nums.size(); j++) {  // Duyệt các phần tử còn lại trong mảng nums
            if (nums[i] == nums[j]) {  // Kiểm tra điều kiện
                count++;  // Tăng biến đếm
                pairs.push_back(make_pair(i, j));  // Lưu trữ chỉ số của cặp số vào vector
            }
        }
    }
    for (auto p : pairs) {  // Duyệt từng cặp số trong vector
        cout << "Position: " << p.first << ", " << p.second << endl;  // In ra vị trí của các phần tử trong cặp số
    }
    return count;  // Trả về số lượng cặp số thỏa mãn điều kiện
}

int main(){
    // int tmp = find();
    // if(tmp == false){
    //     cout << " khong tim thay" << endl;
    // }  
    // else cout <<  "tim thay tai vi tri \t" << tmp << endl;
    // return 0;

    // string str;
    // cout << "Nhap chuoi ky tu: ";
    // cin >> str;
    // int num = toInt(str);
    // cout << "So nguyen tu chuoi ky tu la: " << num << endl;
    // return 0;

    // int n; 
    // cout << "nhap so phan tu";
    // cin >> n;
    // int a[n];
    // for(int &x : a){
    //     cin >> x;
    // }
    // for(int y : a){
    //     cout << y << " ";
    // }
    // cout << endl;
    // find(a,n);
    // return 0;

    numIdenticalPairs();
    return 0;

}
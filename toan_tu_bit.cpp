#include <bits/stdc++.h>

using namespace std;


// and or xor xnor not 
//  &   |  ^   ~^    ~
// dich << trai, >> phai
void in_binary(int n){  
    int tmp;
    for(int i = 1; i <= 31; i++){
        if(pow(2,i) <= n && n < pow(2,i+1)){
            tmp = i;
        }
    }
    cout << "binary converted : ";
    for(int i = tmp; i >= 0; i--)
    {
        if(n & (1 << i)) cout << "1" << " ";
        else cout << "0" << " ";
    }
    cout << endl;
}

void convert(){
    int t; cin >> t;
    while (t--)
    {
        int n;
        cout <<"number you want : "; 
        cin >> n;
        in_binary(n);
    }
}


//sinh so binary cho 1 mang n phan tu
int sinh_binary(int n){
    int tmp;
    if(n == 0){
        cout << "0" << "\t";
        return 0;
    }
    for(int i = 0; i < 32; i++){
        if(pow(2,i) <= n  && n < pow(2,i+1)){
            tmp = i;
        }
    }
    for(int i = tmp; i >= 0; i--){
        if(n & (1 << i)) cout << "1" << " ";
        else cout << "0" << " ";
    }
    cout << "\t";
}

void binary_array(){
    int n; cin >> n;
    int a[n];
    for(int &x:a) cin >> x;
    for(int i = 0; i < n; i++){
        sinh_binary(a[i]);
    }  
}



int main(){
    //convert();
    in_binary(10);
}
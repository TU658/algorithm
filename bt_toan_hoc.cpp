#include <bits/stdc++.h>

using namespace std;

//ktr so nguyen to tu 1 -> n roi in ra so nguyen do do while for deu dc
void nguyen_to_1_n(int n){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int dem = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                dem++;
            }
        }
        if(dem == 2){
            cnt++;
            cout << i << " ";
        }       
    }
    cout << endl << "tu 1 den n co : " << cnt << " so nguyen to " << endl;
}


//ktra so nguyen to tu x - n roi in ra so do dung while, for deu dc
void nguyen_to_x_n(int x, int n){
    int cnt = 0;
    for(int i = x; i <= n; i++){
        int j = 0, dem = 0; 
        while(j < i){
            j++;
            if(i % j == 0){
                dem++;
            }
        }
        if(dem == 2){
            cnt++;
            cout << i << " ";
        }
    }
    cout << "so nguyen to co trong x - n : " << cnt << endl;
}

//tim thua so nguyen to cua 1 so 
void thua_so_nguyen_to(int n){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int dem = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                dem++;
            }
        }     
        if(dem == 2){
            while(n%i == 0){  
                cout << i;        
                n/=i;
                if(n!=1){
                    cout << "x";
                }  
            }           
        }   
    }
}


//tim nguyen to trong 1-n roi tinh tong so nguyen to
void sum_nguyen_to(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        int dem = 0;
        for(int j = 1; j <= i; j++){
            if(i%j == 0){
                dem++;
            }
        }
        if(dem == 2){
            cout << i << " ";
            sum += i;
        }
    }
    cout << endl <<"tong so nguyen to ";
    cout << sum << endl;
}

//tim uoc chung lon nhat, boi chung lon nhat
int uoc_chung_lon_nhat(int a, int b){
    if(a == 0 || b == 0)
        return a+b;
    for(int i = min(a,b); i >= 1; i--){
        if(a % i == 0 && b % i == 0){
            return i;
        }
    }
}

//in ra cac phan tu trong string
void print_string(string a){
    for(int i = 0; i < a.length(); i++){
        cout << a[i] << " ";
    }
    sort(a.begin(), a.end(), greater<char>());
    for(char x:a) cout << x << " ";
    reverse(a.begin(), a.end());
    for(char x:a) cout << x << " ";
}
int main(){
    //nguyen_to_1_n(100);
    //nguyen_to_x_n(50,100);
    //thua_so_nguyen_to(140);
    //sum_nguyen_to(10);
    //uoc_chung_lon_nhat(20,30);
    print_string("vuvantu");
}
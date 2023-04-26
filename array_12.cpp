#include <iostream>
#include <stdio.h>

using namespace std;

void array_1_chieu(){
    //MANG 1 CHIEU 
    int n;
    cout << "so phan tu cua mang la : "; 
    cin >> n;
    int a[n];
    // for(int i = 0; i < n; i++){
    //     cin >> a[i];
    // }
    
    // for(int i = n - 1; i >=0 ; i--){
    //     cout <<"[" << i << "] : " << a[i] << endl;
    // }
    for(int &x : a) cin >> x;
    int i = 0;
    for(int y : a){
        cout << "[" << i++ << "] :" <<  y << endl;
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum +=a[i];
    }
    cout << "tong cac phan tu mang la : " << sum << endl;
}

    //MANG 2 CHIEU
void array_2_chieu_basic(){    
    int n,m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j]; 
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " "; 
        }
        cout << endl;
    }
}


// MANG 2 CHIEU CHAR
void array_2_chieu_char(){    
    int n,m;
    cin >> n >> m;
    char c[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << c[i][j];
        }
        cout << endl;
    }
}

//string each row
void array_2_chieu_by_string(){
    int n,m;
    cin >> n >> m;
    string a[n];
    cin.ignore();
    for(int i = 0; i < n; i++){
        getline(cin, a[i]);
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
}

int main(){
    array_2_chieu_by_string();
}

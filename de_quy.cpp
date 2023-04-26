#include <bits/stdc++.h>

using namespace std;

//ham de quy la ham goi lai chinh no dua vao cong thuc toan hoc
//CTDL stack  LIFO last in first out ( vao sau ra truoc )


//xay dung ham de quy, phai biet 2 dk: 1) dk dung 2) cong thuc truy hoi

//vd : S = 1+2+3+...+n
//tong chay tu n - 1 den khi nao n = 1 return 1 khi day ham tong ket thuc va return tung ket qua truoc khi tong(1)-tong(2)-tong(3)-tong(4)-tong(5) = kq la 
int tong(int n){
    if(n == 1) return 1; // dieu kien dung 
    else 
        return n + tong(n-1); // cong thuc truy hoi cong thuc truy hoi tu n den 1 tong(5)-tong(4)-tong(3)-tong(2)-tong(1) : cac ham tong nay chua ket thuc den khi dk dung hoat dong
        //khi diem dung hoat dong thi co tong(1) no tinh tiep o tong(2) va tong(3) tong(4) tong(5)
}


//vd tu nghi
// in ra chu hello voi so lan n dung de quy
int xinchao(int n){
    if(n == 1){
        cout << "xin chao! \nend ";
        exit(0); 
    }
    else{
        cout << "xin chao! \n";
        return xinchao(n-1);
    }
}

//vd tiep theo 
//tinh giai thua cua n // n! = n*(n-1)*(n-2)*....*1

int giaithua(int n){
    if(n == 0){ //tim ham nho nhat la 0! = 1 de dung chuong trinh de quy
        return 1;
    }
    //cong thuc truy hoi giaithua = n*giaithua(n-1)
    else{
        return n*giaithua(n-1);
    }

}

// vd a luy thua b a^b
int luythua(int a, int b){
    if(b == 0)
        return 1;
    else   
        return a*luythua(a,b-1);
}

//vd dem so luong chu so trong so
int dem_so_luong(long long n){
    if(n / 10 == 0)
        return 1;
    else{
        return 1 + dem_so_luong(n/10);
    }
}


//ktra mang co phai la doi xung hay k 
int check_array(int a[], int l, int r){
    if(l > r){
        return 1; // dk dung khi da xet het cac cap
    }  
    if(a[l] != a[r]){
        return 0;
    }
    else
        return check_array(a, l + 1, r - 1);
}

int main(){
    int n; cin >> n;
    int a[n];
    for(int &x:a) cin >> x;
    if(check_array(a, 0, n-1)){
        cout << "doi xung\n";
    }
    else
        cout << "khong doi xung \n";
    return 0;
}
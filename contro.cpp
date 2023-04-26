#include <bits/stdc++.h>

using namespace std;

//con tro tro toi la dia chi
//&a dia chi cua bien a 
//*ptr = a
//co the nhieu con tro tro ve 1 dia chi  


void basic(){
    int a = 100;
    int *ptr = &a;
    // int *ptr; 
    // ptr = &a
    if(ptr == &a){
        cout << "bang nhau \n";
    }
    cout << (*ptr) << "\t"; 
    (*ptr)++;
    cout << a << "\t";

    int *ptr2 = ptr; // = a;
    cout << (*ptr2) << "\ttro toi dia chi cua a\t" << ptr2 << " "<< ptr << " " << &a << endl;
}

//con tro trong function
void test1(int x){
    x *= 2;
}

void test2(int &x){
    x *= 2; //&x cho phep thay doi gia tri thuc su cua bien truyen vao 
}

void test3(int *x){ //*x la con tro , phai truyen vao dia chi cua bien can dua vao
    (*x) *= 2; //(*x) truy cap toi gia tri ma con tro x tro vao
}

void test4(int *x, int *y){
    //hoan vi
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

//vidu
struct SinhVien
{
    string ten, diachi;
    int tuoi;
};

//trong mang thi gia tri khi chua nhap gia tri cho tung phan tu thi gia tri cua tung phan == voi dia chi cua tung phan do int thi cach nhau 4 byte long long thi cach nhau 8 byte
void mang(){
    int n = 5;
    int a[n];
    cout << a << endl; // chua nhap thi in ra gia tri == dia chi cua phan tu dau tien trong mang
    for(int i = 0; i < n; i++){
        cout << a+i << "\t"; //vi mang la gom cac bo nho lien nhau + int = 4byte => moi dia chi se duoc cong 4 byte
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << &a[i] <<"\t";// in ra dia chi cua tung phan tu trong mang
    }
    
    //nhap mang
    cout << endl;
    for(int i = 0; i < n; i++){
        //cin >> a[i];
        cin >> *(a+i); // tro toi dia chi o phan tu dau tien + i , va nhap vao gia tri
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << "\t";
    }

    //con tro khac nhung truy cap dia chi cua phan tu dau tien trong mang a
    cout << endl;
    int *b = a; // con tro b tro toi gia tri cua a nay la dia chi cua phan tu dau tien trong mang a
    for(int i = 0; i < n; i++){
        cout << b[i] << "\t";
    }

}

//cap phat dong/ cap phat tinh
void cap_phat(){
    //cap phat tinh
        //int a[1000000]; //1000000 phan tu se bi tran bo nho
    //cap phat dong
    cout << endl << "cap phat dong bo nho co 10 phan tu : ";
    int *a = new int[1000000]; // co the cap phat len toi 1tr 10tr 100tr thoai mai //cac phan tu duoc cap phat khong nhat thiet phai gan nhau , cap phat den het ram thi thoi
    for(int i = 0; i < 10; i++){
        cin >> a[i];
    }

    //xin cap phat bang new, giai phong cap phat bang delete: delete []a;
}



int main(){
    basic();
    int n = 1000;
    test1(n);
    cout << n << "\t";
    test2(n);
    cout << n << "\t"; 
    int m = 1000;
    test3(&m);
    cout << m << endl;
    int mn = 1000;
    test4(&m, &mn);
    cout << m << "\t" << mn << endl;


    //struct
    SinhVien x;
    x.ten = "Vu Van Tu";
    x.tuoi = 22;
    x.diachi = "Go Vap";
    SinhVien *ptr = &x;
    cout << ptr->ten << "\t" << ptr->tuoi << "\t" << ptr->diachi << endl;
    cout << (*ptr).ten << "\t" << (*ptr).tuoi << "\t" << (*ptr).diachi << endl;
    cout << x.ten << "\t" << x.tuoi << "\t" << x.diachi << endl;
    

    //mang array
    mang();


    //cap phat dong/ cap phat tinh
    cap_phat();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

//struct gop cac du lieu thanh 1 kieu du lieu moi nhu luu thong tin cac thu
//trong struct co the chua 1 ham
//struct co the long nhau

//tem, gpa, dia chi, mssv
//gom cac thanh phan tren vao 1 struct
// struct ten_struct   {};

struct SinhVien
{
    string ten;
    string mssv;
    double gpa;
    string dc;

    //Constructor gia tri mac dinh khi goi 
    //over loading cho phep nhieu chuong trinh ten giong nhau khi goi ham no phu thuoc vao tham so de lua chon function
    SinhVien(){
        mssv = "N18DCDT";
        ten = "vu van tu";
        gpa = 2.213154;
        dc = "HCM";
    }
    SinhVien(string ma, string name, double diem, string diachi){
        mssv = ma;
        ten = name;
        gpa = diem;
        dc = diachi;
    }

    void in(){
        cout << ten << " " << mssv << " " << fixed << setprecision(2) << gpa << " " << dc << endl;
    }

    void nhap(){
        getline(cin, ten);
        cin >> mssv; 
        cin.ignore();
        cin >> gpa;
        cin.ignore();
        getline(cin, dc);
    }
};

struct sophuc
{
    int a, b;
    //nap trong toan tu 
    //kieu tra ve operator(+,-,....) (danh sach tham so)
    //C1
        // sophuc operator + (const sophuc other){
        //     sophuc tong;
        //     tong.a = a + other.a;
        //     tong.b = b + other.b;
        //     return tong;
        // }

    //C2 
    friend sophuc operator + (const sophuc x, const sophuc y){
        sophuc tong;
        tong.a = x.a + y.a;
        tong.b = x.b + y.b;
        return tong;
    }

    //insertion (>>)
    friend istream& operator >> (istream& in, sophuc &x){
        in >> x.a  >> x.b;
        return in;
    }

    //extraction (<<)
    friend ostream& operator << (ostream& out, sophuc x){
        out << x.a << " " << x.b;
        return out;
    }

    //nap trong / dinh nghia so sanh == 
    // bool operator == (const sophuc other){
    //     return a == other.a && b == other.b;
    // }
    friend bool operator == (const sophuc x, const sophuc y){
        return x.a == y.a && x.b == y.b;
    }

    //nap trong / dinh nghia so sanh <
    friend bool operator < (const sophuc x, const sophuc y){
        return x.a < y.a && x.b < y.b; 
        //co the dinh nghia theo y cua minh nhu duoi day la binh phuong len r so sanh
        return (x.a*x.a + x.b*x.b < y.a*y.a + y.b*y.b); //tinh gia tri binh phuong so thuc so ao cua 2 so phuc r so sanh
    }
};

struct sv
{
    string ten;
    string mssv;
    double gpa;


    //sap xep sv theo thu tu gpa tang dan
    bool operator < (const sv other){
        return gpa < other.gpa;
    }
};

// long nhau
struct time
{
    int gio, phut, giay;
};

struct vephim
{
    string ten;
    time tg;
};

void truy_cap_struct_long(){
    vephim v;
    getline(cin, v.ten);
    cin >> v.tg.gio >> v.tg.phut >> v.tg.giay >> endl;
}

//khao bao 1 doi tuong SinhVien

void basic(){
    SinhVien x;
    //SinhVien x{"vu van tu", "N18DCDT049", 2.61231, "HCM"}; //nhap truc tiep
    //nhap thong tin tung phan
    getline(cin, x.ten);
    cin >> x.mssv; 
    cin.ignore();
    cin >> x.gpa;
    cin.ignore();
    getline(cin, x.dc);
    //in ra thong tin tung phan
    cout << x.ten << " " << x.mssv << " " << fixed << setprecision(2) << x.gpa << " " << x.dc << endl;
    //<< fixed << setprecision(2) << x.gpa lay 2 so sau thap phan
    
}



int main(){
    //SinhVien x;
    //basic();

    // x.nhap();
    // x.in();

    // SinhVien y = x;
    // y.in();

    // SinhVien z("N18DCDT","VU VAN TU", 2.1234, "HCM");
    // z.in();

    // sophuc a{1,2}, b{3,4};
    // sophuc c = a+b; ////nap trong toan tu 
    // //kieu tra ve operator(+,-,....) (danh sach tham so) thi moi cong duoc
    // cout << c.a <<  " " << c.b << endl;

    //khi co insertion(istream >>) va extraction(ostream <<) thi chung ta co the nhap truc tiep tu terminal
    //  sophuc a, b;
    //  cin >> a >> b;
    //  sophuc c = a+b;
    //  cout << c << endl;
    //  //so sanh operatore ==
    //  if(a == b) cout << "YES";
    //  else cout << "NO";
    //  cout << endl;
    //  if(a < b) cout << "YES";
    //  else cout << "NO";

    int n; cin >> n;
    sv ds[n];
    for(int i = 0; i < n; i++){
        cin.ignore();
        getline(cin,ds[i].ten);
        cin.ignore();
        cin >> ds[i].mssv;
        cin.ignore();        
        cin >> ds[i].gpa;
    }
    sort(ds, ds+n);
    for(sv x:ds){
        cout << x.ten << " " << x.mssv << " " << fixed << setprecision(2) << x.gpa << endl;
    }
    return 0;
}
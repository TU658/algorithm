#include <bits/stdc++.h>

using namespace std;


// //khai bao class
// class OOP
// {
// private:
//     /* data */
// public:
//     OOP(/* args */);
//     ~OOP();
// };
// //cac function trong public duoc truy cap class
// OOP::OOP(/* args */)
// {
// }

// OOP::~OOP()
// {
// }

//xay dung cac class
//thuoc tinh: attribute
//phuong thuc: method, behavior
//object: doi tuong
//constructor: ham khoi tao
//destructor: ham huy
//-encapsulation : dong goi
//access modifier
//private: thuoc tinh
//public: phuong thuc
//chi thao tac duoc ben trong class
//protected
//this pointer
//setter getter: cach lay ra thuoc tinh nhung k vi pham ting dong goi cua class(get), thay doi thuoc tinh nhung k vi pham tinh dong goi cua class(set)
//static bien: chia se cac gia tri trong class cho tung class con ( sai chung gia tri )
//friend function, friend class
//forward declaration
//toan tu chong operator overloading // insertion >>(istream) (cin) , extraction <<(ostream)(cout),


class SinhVien
{   
    friend class GiaoVien; // cho phep class GiaoVien truy cap vao class SinhVien
    //thuoc tinh va phuong thuc
    private:
        string id, ten, ns;
        double gpa;
        static int dem;
        //... ra ngoai class k dung duoc 
    public:
        void xinchao(); // co the viet ben trong or ben ngoai class
        void dihoc();
        void nhap();
        void in();
        double getGpa(); // ham tra ve gpa de so sanh ben ngoai class return ve Gpa
        void tangDem();
        int getDem();
        // string getId();
        // string getTen();
        // string getNs();
        void setGpa(double);
        //....truy cap ra ngoai class duoc
        SinhVien(); //ham khoi tao constructor luon duoc goi ra khi goi class
        SinhVien(string, string, string, double); //cung la constructor nhung co the add gia tri vao private
        ~SinhVien(); //ham huy ~SinhVien duoc goi khi ham SinhVien ket thuc
        friend void chuanhoa_ten(SinhVien&);
        
};


int SinhVien::dem = 0;
//implementation
SinhVien::SinhVien(){
    cout << "class SinhVien da duoc khoi tao-------------------\n";
    // id = ten = ns = "";
    // gpa = 0;
    this ->id = this ->ten = this ->ns = "";
    this ->gpa = 0;
}

// SinhVien::SinhVien(string ma, string name, string birth, double diem){
//     cout << "ham khoi tao co tham so duoc goi !\n";
//     id = ma;
//     ten = name;
//     ns = birth;
//     gpa = diem;
// }
//con tro this dc dung khi gan trung ten de phan biet nao la trong class nao la tham so
SinhVien::SinhVien(string id, string ten, string ns, double gpa){
    cout << "class SinhVien khoi tao co tham so duoc goi !\n";
    this -> id = id;
    this -> ten = ten;
    this -> ns = ns;
    this -> gpa = gpa;
}
void SinhVien::xinchao(){
    cout << "hello everyone ! \n";
}
void SinhVien::dihoc(){
    cout << "Di hoc nao ae \n";
}

SinhVien::~SinhVien(){
    cout << "class SinhVien da duoc ket thuc--------------------\n";
}


    // SinhVien x;
    // x.nhap();
    // x.in();
// ham khoi tao duoc goi !
// nhap id: n18
// nhap ten : vu van tu
// nhap ngay sinh : 08/07/2000
// nhap diem : 2.623
// n18 vu van tu 08/07/2000 2.623
// doi tuong duoc huy tai day
void SinhVien::nhap(){
    // cout << "nhap id: "; cin >> id;
    // cin.ignore();
    // cout << "nhap ten : "; 
    // getline(cin,ten);
    // cout << "nhap ngay sinh : ";
    // getline(cin,ns);
    // cout << "nhap diem : "; cin >> gpa; 

    // cout << "nhap id: "; cin >> this->id;
    // cin.ignore();
    // cout << "nhap ten : "; 
    // getline(cin,this->ten);
    // cout << "nhap ngay sinh : ";
    // getline(cin,this->ns);
    // cout << "nhap diem : "; cin >> this->gpa; 

    //tu dong tang id
    dem++;
    this->id = "SV" + string(3-to_string(dem).length(), '0') + to_string(dem);
    //SV001/002/003/010/011 
    cout << "nhap ten : "; 
    getline(cin,this->ten);
    cout << "nhap ngay sinh : ";
    getline(cin,this->ns);
    cout << "nhap diem : "; cin >> this->gpa; 
    cin.ignore();
}

void SinhVien::in(){
    //cout << id << " " << ten << " "  << ns << " " << gpa << endl;
    cout << this->id << " " << this->ten << " "  << this->ns << " " << this->gpa << endl;
}

void abc(){
    SinhVien x;
}
//function get gpa trung gian de so sanh ben ngoai class
double SinhVien::getGpa(){
    return this->gpa;
}
void SinhVien::setGpa(double gpa){
    this->gpa = gpa;
}
//so sanh
bool cmp(SinhVien a, SinhVien b){
    return a.getGpa() > b.getGpa();
}

//bien static
void SinhVien::tangDem(){
    dem++;
}

int SinhVien::getDem(){
    return dem;
}

//operator overloading

//friend function
void chuanhoa_ten(SinhVien &a){
    string res = "";
    stringstream ss(a.ten);
    string word;
    while(ss >> word){
        res += toupper(word[0]);
        for(int i = 1; i < word.length(); i++){
            res += tolower(word[i]);
        }
        res += " ";
    }
    res.erase(res.length() - 1);
    a.ten = res;
}


//friend class
class GiaoVien
{
private:
    string khoa;
    string trinhdo;
    string ngonngu;
    double total;
public:
    //int update(SinhVien&);
    friend istream& operator >> (istream &in, GiaoVien& b){
        cout << "nhap khoa : ";
        getline(in, b.khoa);
        cout << "nhap trinh do : ";
        getline(in, b.trinhdo);
        cout << "nhap ngon ngu : ";
        getline(in, b.ngonngu);
        cout << "nhap tong diem : ";
        in >> b.total;
        in.ignore();
        return in;
    }
    friend ostream& operator << (ostream &out, GiaoVien b){
        cout << b.khoa << " " << b.trinhdo << " " << b.ngonngu << " " << b.total << endl;
        return out;
    }
    //bool operator < (GiaoVien a);
    friend bool operator < (GiaoVien a, GiaoVien b);
};

// GiaoVien::GiaoVien()
// {
//     cout << "class GiaoVien da duoc khoi tao --------\n";
// }

// GiaoVien::~GiaoVien()
// {
//     cout <<"class GiaoVien da duoc ket thuc -----------\n";
// }

// int GiaoVien::update(SinhVien &a){
//     a.gpa = 3.12;
// }

// bool GiaoVien::operator < (GiaoVien a){
//     return this->total < a.total;
// }

bool operator < (GiaoVien a, GiaoVien b){
    return a.total < b.total;
}

class sophuc
{
private:
    int thuc, ao;
public:
    sophuc();
    //insertion 
    friend istream& operator >> (istream& in, sophuc& a){
        in >> a.thuc >> a.ao;
        return in;
    }
    friend ostream& operator << (ostream& out, sophuc a){
        out << a.thuc << " " << a.ao;
        return out;
    }
    bool operator == (sophuc another);
    sophuc operator - (sophuc another);
    sophuc operator + (sophuc another){
        sophuc tong;
        tong.thuc = this->thuc + another.thuc;
        tong.ao = this->ao + another.ao;
        return tong;
    }
    ~sophuc();
};

sophuc::sophuc()
{
}

sophuc::~sophuc()
{
}

bool sophuc::operator == (sophuc another){
    return this->thuc == another.thuc;
}

sophuc sophuc::operator - (sophuc another){
    sophuc hieu;
    hieu.thuc = this->thuc - another.thuc;
    hieu.ao = this->ao - another.ao;
    return hieu;
}

int main(){
    
    // abc();
    // SinhVien x; //SinhVien();
    // //SinhVien x("N18", "Vu Van Tu", "08/07/2000", 2.612);//SinhVien(string, string, string, double)
    // x.dihoc();
    // x.xinchao();
    // cout << "xin chao\n";
    // if(1){
    //     SinhVien x;
    // }
    // cout << "hello \n";

    // SinhVien x;
    // x.nhap();
    // x.in();
    
    //mang sinh vien
    // int n; 
    // cout << "nhap so luong sinh vien : ";
    // cin >> n;
    // SinhVien a[n];
    // for(int i = 0; i < n; i++){
    //     a[i].nhap();
    // }
    // sort(a, a+n, cmp);
    // for(int i = 0; i < n; i++){
    //     a[i].in();
    // }

    //setter getter
    //x.setGpa(3.123); //thay doi truc tiep dung set
    //co the class con va gan nhu struct vay

    // //static bien
    // SinhVien x;
    // x.nhap();
    // chuanhoa_ten(x);
    // x.in();
    // SinhVien y;
    // y.nhap();
    // chuanhoa_ten(y);
    // y.in();


    ////friend function
    // SinhVien x;
    // x.nhap();
    // chuanhoa_ten(x);
    // x.in();


    // //friend class
    // SinhVien x;
    // x.nhap();
    // GiaoVien y;
    // y.update(x);
    // x.in();

    // GiaoVien x,y;
    // cin >> x >> y;
    // if(x < y) cout << "yes";
    // else cout << "no";

    //operator so phuc
    sophuc a, b;
    cout << "so phuc a la : "; cin >> a;
    cout << "so phuc b la : "; cin >> b;
    if(a == b) cout << "2 so phuc bang nhau\n";
    else    cout << "2 so phuc khong bang nhau\n";
    sophuc tong = a + b;
    cout << "tong 2 so phuc la : " << tong << endl;
    sophuc hieu = a - b;
    cout << "hieu 2 so phuc la : " << hieu << endl;   
    return 0;
}
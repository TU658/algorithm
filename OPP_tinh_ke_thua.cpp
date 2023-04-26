#include <bits/stdc++.h>

using namespace std;

//giup minh su dung lai code, tranh du thua, tan dung code 
//base class: class cha -> dinh nghia, khai bao cai thuoc tinh chung
//derived class: class con
//khi chay class con thi class cha se chay truoc (person())
//khi huy thi se huy class con truoc roi den class cha (~person())
//co the ke thua nhieu class voi nhau: vd: class bat : public mammal, public wingedanimal{}(da ke thua); or class wingedanimal : public mammal{}; class bat : public wingedanimal{};(ke thua theo chuoi)
//function overriding (ham ghi de): khi goi toi thi no se tim tu class vua goi neu khong co thi tim den class cha gan nhat neu khong co nua tim tiep den class cha tiep theo(KHONG AP DUNG CHO DA KE THUA VI KHONG BIET CUA AI NEU CA 2 CLASS CHA DEU CO), ap dung cho ke thua theo chuoi (multi level)


//ke thua co(access mode) : 
// public(ke thua cac tinh chat cua thang class cha(access modifier) co the truy cap class cha tu class con thoai mai), 
// private(cac members cua class cha se thanh private trong class con nen khong truy cap duoc class cha tu class con nua),(nhung van co the truy cap duoc class con bth)
// protected(khong the truy cap ngoai class)

//mac du class con ke thua class cha , class con se co cac phuong thuc va thuoc tinh cua class cha nhung k phai luc nao cung truy cap vao duoc tuy thuoc vao access mode
//khong the truy cap truc tiep vao class thi dung get va set de truy cap vao class khong cho phep
class Person
{
private:
   string name;
   string address;
public:
    void nhap(){
        getline(cin, name);
        getline(cin, address);
    }
    string getName(){
        return name;
    }
    string getAddress(){
        return address;
    }

    void setName(string name){
        this->name = name;
    }
    void setAddress(string address){
        this->address = address;
    }
    void in(){
        cout << name << "\t" << address << "\t";
    }
    Person(string name, string address){
        this->name = name;
        this->address = address;
    }
};



//class Student ke thua Person : class Student : public Person 
class Student : public Person
{
private:
    float gpa;
public:
    float getGpa(){
        return gpa;
    }
    float setGpa(float gpa){
        this->gpa = gpa;
    }
    void in(){
        //ghi de trong class con : function overriding
        //cout << name << " " << address << " " << gpa << endl; // sai nhe , khong truy cap private person duoc
        //cout << getName() << " " << getAddress() << " " << gpa << endl; 
        //goi luon ham in trong Person
        Person::in();
        cout << gpa << endl;
    }
    void nhap(){
    //function overriding : ghi de
        Person::nhap();
        cin >> gpa;
    }

    //ham tao cua class con goi ham tao cua class cha
    Student(string name, string address, float gpa) : Person(name, address){
        this->gpa = gpa;
    }
    
};


class  Lecturer : public Person
{
private:
    
public:

};


class Employee : public Person
{
private:
    
public:

};





int main(){
    Student s("nguyen van tu", "chieu van pham", 3.5);
    s.in();
    
    //nhap/in trong class con
    //neu trong ham con khong co ham thi no goi len thang cha
    s.nhap();
    s.in();
    
    //nhap/in trong class cha
    // s.Person::nhap();
    // s.Person::in();
    
    s.setName("Vu Van Tu\t");
    s.setAddress("Pham Van Chieu Go Vap\t");
    s.setGpa(3.42);
    cout << s.getName() << " " << s.getAddress() << " " << s.getGpa() << endl;

}














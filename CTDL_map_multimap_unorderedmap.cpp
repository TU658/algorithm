// map luu cac phan tu theo cap key, value ( key khac nhau , value co the giong nhau)
// phu hop bai toan tan suat xuat hien trong mang 
// map co the them cap key,value
//            truy xuat value tu key
//            remove key,value ra khoi map

#include <bits/stdc++.h>

using namespace std;

// cau truc map<datatype1, datatype2> mp;
// insert 
// count 
// find
// erase
// dem so lan xuat hien phan tu trong mang, sau do in ra kem theo tan suat cua no

void map_basic(){
    map<int, int>  mp;
    mp[100] = 200; // (100, 200)
    mp.insert({300, 400});
    mp[200] = 300; // (200, 300)
    // co the them key, value
    
    mp.insert({400, 500});

    // in ra size
    cout << mp.size() << endl;

    // them moi key trung nhau thi so luong k doi value thay doi 
    mp[100] = 300;
    cout << mp[100] << endl;

    // liet ke cac phan tu co trong map dung for each
    for(pair<int, int>x : mp){
        // ban chat cac cap key, value trong map la cac cap pair 
        cout << x.first << " " << x.second << endl;
    }
    // liet ke cac phan tu co trong map dung auto
    for(auto it : mp){
        cout << it.first << " " << it.second << endl;
    }
    // liet ke cac phan tu co trong map dung iterator
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
        cout << (*it).first << " " << (*it).second << endl;
    }

    // truy xuat value tu key
    // count tra ve gia tri bao nhieu lan tim thay
    // find tra ve iterator
    if(mp.count(100) != 0 ){ // mp.find(100) != mp.end()
        cout << "FOUND !" ;
        cout << endl;
    } else {
        cout << "NOT FOUND !" << endl;
    }

    // xoa remove key, value (pair)
    mp.erase(300);
    for(auto it : mp){
        cout << it.first << " " << it.second << endl;
    }
    //system("pause");
}

    // dem so lan xuat hien phan tu trong mang, sau do in ra kem theo tan suat cua no map co the dem duoc phan tu am 
    // input 
    // 8
    // 1 1 2 1 3 5 1 -4
    // output
    // 1 4
    // 2 1
    // 3 1
    // -4 1
    // 5 1 
void map_tan_xuat(){   
    map<int, int> mp;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int  x; cin >> x;
        mp[x]++;
    }
    //nhap 8 lan key x khi x trung thi value cua x tang len 1 (mp[x]++)
    for(pair<int, int>x:mp) cout << x.first << " " << x.second << endl; //in ra cap gia tri key value << endl; // theo thu tu(ordered) key tu thap len cao
    // for(auto x:mp) cout << x.first << " " << x.second << endl;
}

    // nhap mang char
void map_char(){
    map<char, int> mp;
    int n; cin >> n;
    char a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    for(auto x:mp) cout << "key : " << x.first << "\ttan so xuat hien : "<< x.second << endl;
    // for(int i = 0; i < n; i++){
    //     cout << a[i] << " " << mp[a[i]] << endl; 
    // }
    // for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++ ){
    //      //liet ke dung iterator   
    //     cout << (*it).first << " " << (*it).second << endl;
    // }
}

    // nhap mang string
void map_string(){
    map<string, int> mp;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string x; cin >> x;
        mp[x]++;
    }
    for(auto y:mp) cout <<"key la : " << y.first << "\t duoc xuat hien : " << y.second << endl;

    //in ra tan xuat hien nhieu nhat 
    int max = 0;
    string res;
    for(auto y:mp){
        if(y.second >= max){ // neu co cung tan xuat xuat hien thi lua chon theo bang chu cai : >= bang chu cai lon hon , > thi bang chu cai nho hon
            max = y.second;
            res = y.first;
        }
    }
    cout << "tu khoa duoc xuat hien nhieu nhat : " << res << "\t tan xuat la : " << max;
}

//multimap cho phep 1 key co nhieu value chi dung lenh gan bang insert moi duoc
//unodered_map nhu map nhung k sap xep theo thu tu tu be den lon

int main(){
    map_string();
}
// cap gia tri datatype trong cung 1 bien
#include <bits/stdc++.h>

using namespace std;

//pair<datatype1, datatype2> v;
//make_pair(a,b) khoi tao // {a,b}
//v.first
//v.second
//pair chong nhau pair<pair<a,b>,c> v; // tuple<datatype1,datatype2,datatype3> v{1,2,3};

int main(){
    pair<int,int> v = {100,200}; // make_pair(a,b)
    cout << get<0>(v) << endl;//v.first = get<0>(v)
    cout << get<1>(v) << endl;//v.second = get<1>(v)
    // tuple<int,int,int> t{1,2,3};
    // cout << get<2>(t) << endl;
    return 0;
}
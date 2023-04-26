#include <bits/stdc++.h>

using namespace std;

//sap xep 
//sort : tang dan, giam dan, char, int, string,...
//stable_sort: bubble, insertion sort, merge sort


void basic(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    //sort
    //sort(a, a+n) , sort(a + x, a + y) => a[x, y-1]
    //sort(a.begin(), a.end())
    //greater<datatype>() : sap xep theo thu tu giam dan 
    sort(a,a + n); // tang dan 
    sort(a,a + n,greater<int>()); // giam dan
    for(int x:a) cout << x << " ";
}
    // sap xep cac ki tu trong xau string
void char_of_string(){
    string s;
    getline(cin,s);
    sort(s.begin(),s.end(),greater<char>());
    cout << s << " "; 
}
    // sap xep cac pair
void sap_xep_pair(){ 
    int n; cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    for(auto it : a) cout << it.first << " " << it.second << endl;
}

//sap xep theo y cua minh bang cach xay dung comparator
bool cmp(int a, int b){
    // muon a dung truoc b co nghia la sap xep theo giam dan return a > b;
    // muon a dung truoc b co nghia la sap xep theo tang dan return a < b; 
    // muon a dung truoc b co nghia la sap xep theo tang dan 
    return abs(a) < abs(b); 
}
void sort_i_want(){
    int n; cin >> n;
    int a[n];
    for(int &x:a) cin >> x;
    sort(a, a+n, cmp);
    for(auto it:a) cout << it << " ";
}

// sap xep cac phan tu trong mang theo thu tu tang dan ve gia tri tuyet doi dung stable_sort van sap xep nhung giu lai ban chat thu tu ban dau 
//input
// 8
// 1 -1 2 1 5 -2 -5
// output
// 1 -1 1 2 -2 5 -5

void xep_xep_stable_sort(){
    int n; cin >> n;
    int a[n];
    for(int &x:a) cin >> x;
    stable_sort(a, a+n, cmp);
    for(auto it:a) cout << it << " ";
}

//tieu chi 1 : sap xep cac tu theo thu tu chieu dai giam dan, //tieu chi 2: n tu co cung chieu dai thi tu nao co thu tu tu dien nho hon se in truoc
// 5
// python java php c sql
// output : java php sql c
// 5
// c++ 
// python
// java
// php
// sql
// python java c++ php sql

//xay dung cach sap xep i want (comparator)
bool cmp_string(string a, string b){
    // tieu chi 1
    //return a.length() > b.length(); // giam dan
    // giam dan "<""
    
    // tieu chi 2 + tieu chi 2
    if(a.length() != b.length()){
        return a.length() > b.length(); // tieu chi 1: chieu dai giam dan
    }
    return a < b; //tieu chi 2:  thu tu tu dien nho hon
}
void sort_string_long(){
    int n; cin >> n;
    string a[n];
    for(string &x:a) cin >> x;
    sort(a, a+n, cmp_string);
    for(auto it:a) cout << it << " ";
    //for(string x:a) cout << x << " ";
}


//sap xep chon: co gang dua gia tri nho nhat chua duoc sap xep len dau mang
// nhap so phan tu cua mang a[] : 5
// nhap tung phan tu cua mang a[] : 3 1 5 2 4
// cac phan tu cua mang a[] la : 3 1 5 2 4
// phan tu trong mang a[] duoc sap xep lai : 1 2 3 4 5
void selection_sort(){
    cout << "nhap so phan tu cua mang a[] : ";
    int n; cin >> n;
    int a[n];
    cout << "nhap tung phan tu cua mang a[] : ";
    for(int &x:a) cin >> x;
    cout << "cac phan tu cua mang a[] la : ";
    for(int x:a) cout << x << " ";
    for(int i = 0; i < n - 1; i++){
        // gan tam gia tri tai vi tri i la min de duyet
        int min = i;
        for(int j = i + 1; j < n; j++ ){
            if(a[j] < a[min]){
                // co phan tu nho hon min
                min = j;
            }
        }
        swap(a[i],a[min]); // doi gia tri voi min len dau 
    }
    cout << endl << "phan tu trong mang a[] duoc sap xep lai : ";
    for(int y:a) cout << y << " ";
}

//sap xep noi bot: so sanh 2 phan tu lien ke
// nhap so phan tu cua mang a[] : 10
// nhap tung phan tu cua mang a[] : 3 4 2 1 5 8 7 9 6 0
// cac phan tu cua mang a[] la : 3 4 2 1 5 8 7 9 6 0 
// phan tu trong mang a[] duoc sap xep lai : 0 1 2 3 4 5 6 7 8 9
void bubble_sort(){
    cout << "nhap so phan tu cua mang a[] : ";
    int n; cin >> n;
    int a[n];
    cout << "nhap tung phan tu cua mang a[] : ";
    for(int &x:a) cin >> x;
    cout << "cac phan tu cua mang a[] la : ";
    for(int x:a) cout << x << " ";
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    cout << endl << "phan tu trong mang a[] duoc sap xep lai : ";
    for(int x:a) cout << x << " ";
}

//sap xep chen: moi buoc se co dua vi tri hien tai ve dung vi tri trong do cac phan tu truoc do da duoc sap xep
void insert_sort(){
    cout << "nhap so phan tu cua mang a[] : ";
    int n; cin >> n;
    int a[n];
    cout << "nhap tung phan tu cua mang a[] : ";
    for(int &x:a) cin >> x;
    cout << "cac phan tu cua mang a[] la : ";
    for(int x:a) cout << x << " ";
    for(int i = 1; i < n ; i++){
        int x = a[i]; //bien so sanh
        int pos = i - 1; // bien dich 
        while(pos >= 0 && x < a[pos]){
            a[pos + 1] = a[pos]; // dich cac phan tu lon hon ra sau +1
            pos--;
        }
        a[pos + 1] = x;
    }
    cout << endl << "phan tu trong mang a[] duoc sap xep lai : ";
    for(int x:a) cout << x << " ";
}

//sap xep dem phan phoi : dem tan so xuat hien -> duyet tu nho den lon
//dk : phan tu k am , phan tu <= 10^7
// nhap so phan tu cua mang a[] : 7 
// nhap tung phan tu cua mang a[] : 2 1 3 2 1 3 8
// cac phan tu cua mang a[] la : 2 1 3 2 1 3 8 
// phan tu trong mang a[] duoc sap xep lai : 1 1 2 2 3 3 8
int cnt[10000001];
void count_sort(){
    cout << "nhap so phan tu cua mang a[] : ";
    int n; cin >> n;
    int a[n];
    int m = INT_MIN;
    cout << "nhap tung phan tu cua mang a[] : ";
    for(int &x:a) {cin >> x; cnt[x]++; m = max(m,x);}
    cout << "cac phan tu cua mang a[] la : ";
    for(int x:a) cout << x << " ";
    cout << endl << "phan tu trong mang a[] duoc sap xep lai : ";
    for(int i = 0; i <= m; i++){
        if(cnt[i] != 0){
            for(int j = 0; j < cnt[i]; j++){
                cout << i << " ";
            }
        }
    }
}

// ghep 2 mang chua duoc sap xep thanh 1 mang roi sap xep tang dan
// tu nghi ra tu lam khong co copy
void mix(){
    int n, m;
    cin >> n >> m;
    int a[n] , b[m], c[n+m];
    int i = 0;
    int j = n;
    // for(int &x:a) {
    //     cin >> x;
    //     if(i <= n - 1){
    //     c[i] = x;
    //     i++;
    //     }
    // } 
    // for(int &y:b) {
    //     cin >> y;
    //     if(j <= (m + n) - 1){
    //     c[j] = y;
    //     j++;
    //     }
    // }
    // for(int i = 0; i < n + m; i++){
    //     cout << c[i] << " "; 
    // }
    // sort(c,c + m +n, greater<int>());
    // for(int x:c) cout << x << " ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
        c[i] = a[i];
    }
    for(int i = n; i < (m+n); i++){
        cin >> b[i];
        c[i] = b[i];
    }
    sort(c, c + m + n);
    for(int x:c) cout << x << " ";
}

//ghep 2 mang da sap xep thanh 1 mang 
// 3 5
// 1 3 5 
// 2 4 6 8 10
// 1 2 3 4 5 6 8 10 
void mix1(){
    int n,m;
    cin >> n >> m;
    int a[n], b[m], c[m+n];
    for(int &x:a) cin >> x;
    for(int &x:b) cin >> x;
    int i = 0, j = 0, cnt = 0;
    while(i<n && j<m){ //khi 1 trong 2 mang a hoac b het thi ket thuc
        if(a[i] <= b[j]){//so sanh tung mang a[i] vs b[j] den khi 1 trong 2 mang het thi ket thuc while
            c[cnt++] = a[i];
            ++i;
        }
        else{
            c[cnt++] = b[j];
            ++j;
        }
    }
    while(i<n){ //khi b[m] het ma a[n] con thi add cac phan tu con lai cua a vao duoi c[cnt++]
        c[cnt++] = a[i++];
    } 
    while(j<m){//khi a[n] het ma b[m] con thi add cac phan tu con lai cua b vao duoi c[cnt++]
        c[cnt++] = b[j++];
    } 
    for(int x:c) cout << x << " ";
}

///////////////////////////////////////////////////////////////thuat toan sap xep tron merge sort phan nho cac phan tu trong mang roi gop lai // thuat toan de quy
//dung de tron 2 day con day1[l, m] day2[m+1, r] da duoc sap xep
int merge(int a[], int l, int m, int r){ // function sap xep lai cac thanh phan con khi da duoc tach ra de sap xep tang dan
    vector<int> x(a+l, a+m+1);
    vector<int> y(a+m+1, a+r+1);
    int i = 0, j = 0;
    //dem cap nghich the (dung 2 for cung dc do phuc tap 0n^2) dung trong merge_sort giup lam giam do phuc tap bai toan
    int cnt = 0;
    while(i<x.size() && j<y.size()){
        if(x[i] <= y[j]){
            a[l] = x[i];
            ++l;
            ++i;
        }
        else{
            //co nghia x[i] > y[j] co 1 cap nghich the 
            cnt += x.size()-i;
            a[l] = y[j];
            ++l;
            ++j;
        }
    }
    while(j<y.size()){
        a[l++] = y[j++];
    }
    while(i<x.size()){
        a[l++] = x[i++];
    }
    return cnt;
}

int mergeSort(int a[], int l, int r){   // function chia nho tung phan trong mang
    // if(l >= r) return;
    // int m =(l+r)/2;
    // mergeSort(a, l, m);
    // mergeSort(a, m+1, r);
    // merge(a, l, m, r);   
    int dem = 0;
    if(l < r){
        int m =(l+r)/2;
        dem += mergeSort(a, l, m);
        dem += mergeSort(a, m+1, r);
        dem += merge(a, l, m, r);
    }    
    return dem;
}

int random(int minN, int maxN){ // cho random tu minN den maxN function random so 
    return minN + rand() % (maxN + 1 - minN);
}

void load_merge_sort(){
        // sap xep theo merge sort va dem cap nghich the 
// 6
// 8 7 1 9 2 3
// theo 2 for thi : 9       theo merge_sort thi : 9
    int n; cin >> n;
    int a[n];
    for(int &x:a) cin >> x;
    // srand((int) time(0)); // sinh so ngau nhien cho rand()
    // for(int i = 0; i < n; i++){
    //     a[i] = random(1,1000);
    // } 
    // dung 2 for de dem cap nghich the
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1 ; j < n; j++){
            if(a[i] > a[j]){
                cnt++;
            }
        }
    }
    // dung mergeSort dem cap nghich the
    int y = mergeSort(a, 0, n-1);
    cout << "theo 2 for thi : " << cnt << "\t theo merge_sort thi : " << y << endl;
}

////////////////////////////////////////////////////////////////////thuat toan sap xep vun dong , thuat toan heap sort: heap la 1 cay nhi phan hoan chinh
// maxHeap : thang cap cao lon hon 2 thang con cua no( trai , phai ) trong cay nhi phan hoan chinh, sort tang dan
// minHeap : thang cap cao nho hon 2 thang con cua no( trai , phai ) trong cay nhi phan hoan chinh, sort giam dan
// thao tac heapify
// tao ra maxheap thao tac note k phai la leaf 

// 5
// 2 1 5 3 4
// 1 2 3 4 5 

void max_Heap(int a[], int n, int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    //khoi tao bien largest
    int largest = i;
    if(l < n && a[l] > a[largest]){
        largest = l;
    }
    if(r < n && a[r] > a[largest]){
        largest = r;
    }
    // ktra xem largest moi nhat co bang gia tri goc ban dau hay k , neu k thi swap
    if(largest != i){
        swap(a[i], a[largest]);
        max_Heap(a, n, largest);
    }  
}

//xay dung sort heap
void heap_sort(int a[], int n){
    //duyet cac note k phai la leaf xay dung maxheap cac note k phai la leaf duoc tinh bang ct : i = n/2 - 1
    for(int i = n/2 - 1; i >= 0; i--){
        max_Heap(a,n,i); // gor nay dung de thay doi gia tri i k phai la note lien tuc tu i = n/2 - 1; i >= 0 de tim largest
    }
    // xay dung duoc maxheap r thi root(goc) co gia tri lon nhat t swap ve cuoi mang de sap xep tang dan
    for(int i = n - 1; i >= 0; i--){
        swap(a[i],a[0]);
        // duyet lai maxheap tru phan tu cuoi mang da duoc xac dinh la lon nhat, giam so luong phan tu cua mang di 1 moi lan
        max_Heap(a,i,0); // for nay dung de thay doi so luong mang di 1 moi khi co largest swap ve cuoi mang
    }
}

void load_sort_heap(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    heap_sort(a,n);
    // in ra khi da sap xep
    for(int x:a) cout << x << " ";
}


///////////////////////////////////////////////thuat toan sap xep nhanh quick sort: gan giong nhu cua merge sort cung la chia nho cac thanh phan trong mang 
//quicksort(a,p,r)
//if p < r
//thao tac partition(A,p,r) phan hoach de chia ra 2 phan rieng <= > pivot

//phan hoach
//////////////////////////////lomuto
//chia mang thanh 2 nua voi gia tri pivot :thanh phan ben trai <= pivot <= thanh phan ben phai (pivot auto duoc chon gia tri o vi tri cuoi mang)

int partition(int a[], int l, int r){
    int pivot = a[r];
    int i = l - 1;
    for(int j = l; j < r; j++){ // xet cac phan tu chay tu l den r <= chot(pivot) thi swap
        if(a[j] <= pivot){
            i++;
            swap(a[i],a[j]);
        }
    } 
    //dua chot(pivot) vao giua
    i++;
    swap(a[i],a[r]);
    return i; // vi tri pivot dc chuyen ve giua
}

void quick_sort(int a[], int l,  int r){
    if(l >= r) // khi co phan hoach co l >= r thi ket thuc
        return;
    int p = partition(a, l, r);
    quick_sort(a, l, p - 1); // xu li partition ben trai den khi con 1 phan tu 
    quick_sort(a, p + 1, r); // xu li partition ben phai den khi con 1 phan tu 
}

void load_quick_sort(){
    int n; cin >> n;
    int a[n];
    for(int &x:a) cin >> x;
    for(int x:a) cout << x <<" ";
    quick_sort(a, 0, n-1);
    cout << endl << "mang da duoc sap xep lai : ";
    for(int x:a) cout << x << " ";
}

////////////////////////////////hoare
// tim cap nghich the roi swap ()
int partition_hoare(int a[], int l, int r){
    int pivot = a[l];
    int i = l - 1;
    int j = r + 1;
    while(1){
        do{
            i++;
        }while(a[i] < pivot);
        do{
            j--;
        }while(a[j] > pivot);
        if(i < j){
            swap(a[i],a[j]);
        }
        else
            return j;  
    }
}

void quick_sort_hoare(int a[], int l, int r){
    if(l >= r) 
        return;
    int p = partition_hoare(a, l, r);
    quick_sort_hoare(a, l, p);
    quick_sort_hoare(a, p + 1, r);
}

void load_quick_sort_hoare(){
    int n; cin >> n;
    int a[n];
    for(int &x:a) cin >> x;
    quick_sort_hoare(a, 0, n-1);
    cout << endl << "mang duoc sap xep lai la : ";
    for(int x:a) cout << x <<" ";
}


bool cmp3(int a, int b){
        return abs(a) < abs(b);
}
// ham thuong duoc su dung trong thu vien algorithm
void ham_thong_dung_algorithm(){
    int a[5] = {1,2,1,5,8};
    int a1[5] = {1,2,3,4,5};
    vector<int> b = {1,2,1,4,8};
    vector<int> b1 = {1,2,3,4,5};
    string d[] = {"python", "c++", "java", "lap trinh", "php"};
    
// min 
    cout << min(10,20) << endl;
    cout << min({1,2,3,4}) << endl; // nhieu so {}
// max
    cout << max(10,20) << endl;
    cout << max({1,2,3,4}) << endl; // nhieu so {}
// min_element (mang , vecto)
    //array
    cout << min_element(a, a+5) << endl; // mang tro toi dia chi
    cout << *min_element(a, a+5) << endl; // * truy cap gia tri
    //vector
    cout << *min_element(b.begin(), b.end());
// max_element (mang , vecto)
    //array
    cout << max_element(a, a+5) << endl; // mang tro toi dia chi
    cout << *max_element(a, a+5) << endl; // * truy cap gia tri
    // vector
    cout << *max_element(b.begin(), b.end()) << endl;
// accumulate // tong ca phan tu 
    //array
    int sum = accumulate(a,a+5,0); // 0 la gia tri ban dau    
    cout << sum << endl;
    //vector
    cout << accumulate(b.begin(), b.end(),0) << endl;
// swap //hoan doi gia tri cua 2 bien
    swap(a[2], b[3]);
    for(int x:a) cout << x << " ";
    cout << endl;
    for(int x:b) cout << x << " ";
// sort 
    //sap xep trong mang va vector , theo tieu chi cua minh 
    //array
    sort(a, a+5); // giam dan thi dung greater<int>()
    cout << endl;
    for(int x:a) cout << x << " ";
    //vector
    sort(b.begin(), b.end(),greater<int>());
    cout << endl;
    for(int x:b) cout << x << " ";
    //string
    sort(d, d + 5);
    cout << endl;
    for(string x:d) cout << x << " ";
// stable_sort 
    //co them tinh chat stable : on dinh (co cung gia tri trong mang duoc bao toan vi tri la giu theo thu duoc sap xep ban dau) // merge_sort , bubble_sort , insert_sort  
    int e[6] = {1,3,-2,-1,-3,2};
    stable_sort(e, e+6, cmp);
    cout << endl;
    for(int x:e) cout << x << " ";
// find 
    //tim kiem va tra ve gia tri con tro ma no tim thay hoac cuoi cung khi k tim thay
    //array
    auto it = find(a,a+5,3); // gia tri can tim 
    if(it == a + 5){
        cout << endl << "tim thay ";
    }
    else 
        cout << endl << "k tim thay";
    //vector
    auto it1 = find(b.begin(), b.end(), 5);
    if(it1 == b.end()){
        cout << endl << "k tim thay";
    }
    else    cout << endl << "tim thay";
// binary_search 
    // dung cho mang da duoc sap xep
    //array
    if(binary_search(a1, a1 + 5, 2)) cout << endl << "found";
    else cout << endl << "not found";
    //vector
    if(binary_search(b1.begin(), b1.end(), 6)) cout << endl << "found";
    else cout << endl << "not found"; 
// lower_bound >= key
    //ap dung cho mang vector duoc sap xep , set, map
    //tra ve con tro hoac iterator dau tien xuat hien trong mang >= key thi tra ve con tro , iterator k co thi tra ve end-> vector a+n -> array
    //tim kiem trong [first, last)
    //array
    auto it2 = lower_bound(a1,a1+5,3);
    cout << endl << *it2 << endl; // gia tri
    cout << it2 - a1 << endl; //vi tri a1+2-a1 = 2
    //vector
    auto it3 = lower_bound(b1.begin(), b1.end(), 4);
    cout << *it3 << endl; // gia tri
    cout << it3 - b1.begin() << endl; // dia chi

// upper_bound > key
    // tuong tu lower_bound nhung la > key

//memset
    //gan toan bo gia tri co trong mang thanh -1 / 0 ngoai 2 gia tri nay thi k gan dc
    //array
        // memset(a, -1, sizeof(a));
        // for(int x:a) cout << x << " ";

// fill 
    //gan gia tri cho thanh phan trong mang , vector
    //array
        // fill(a, a+5, 32);
        // for(int x:a) cout << x << " ";
        // //vector
        // fill(b.begin(), b.end(), 23);
        // cout << endl;
        // for(int x:b) cout << x << " ";
// merge
    //tron 2 day con co the trong mang vs vecto ra mang or vector
    int res[10];
    merge(a,a+5,b1.begin(),b1.end(), res);
    for(int x:res) cout << x << " ";
    
// reverse
    //lat nguoc lai 
    //ap dung duoc cho array vector ca string
    reverse(res, res + 10);
    cout << endl;
    for(int x:res) cout << x << " ";
    //string
    string f = "vuvantu";
    reverse(f.begin(), f.end());
    cout << endl;
    cout << f << endl;

// set_union 
    //union tap hop da duoc sap xep // gan giong nhu merge nhung set k luu gia tri trung nhau //in ra gia toan bo gia tri nhung k in ra trung nhau
    vector <int> res1(10);
    auto it4 = set_union(a, a+5, b1.begin(), b1.end(), res1.begin());
    res1.resize(it4 - res1.begin()); // fix lai do lon cua mang cho phu hop 1 2 3 4 4 5 8 0 0 0 - > 1 2 3 4 4 5 8
    for(int x:res1) cout << x << " ";

// set_intersection 
    //in ra cac gia tri vua nam trong day a vua nam trong day b
    vector <int> res2(10);
    auto it5 = set_intersection(a, a+5, b1.begin(), b1.end(), res2.begin());
    res2.resize(it5 - res2.begin());
    cout << endl;
    for(int x:res2) cout << x << " ";
// set_difference 
    //lay ra phan tu thuoc day a va khong thuoc day b
    vector <int> res3(10);
    auto it6 = set_difference(a, a+5, b1.begin(), b1.end(), res3.begin());
    res3.resize(it6 - res3.begin());
    cout << endl;
    for(int x:res3) cout << x << " ";
// set_symmetric_difference
    //lay ra cac phan tu trong khong nam trung trong day a va day b
    vector <int> res4(10);
    auto it7 = set_symmetric_difference(a, a+5, b1.begin(), b1.end(), res4.begin());
    res4.resize(it7 - res4.begin());
    cout << endl;
    for(int x:res4) cout << x << " ";
}

int main(){
    //selection_sort();
    //bubble_sort();
    //insert_sort();
    //count_sort();
    //mix1();
    //load_merge_sort();
    //load_sort_heap();
    //load_quick_sort();
    //load_quick_sort_hoare();
    ham_thong_dung_algorithm();
}




#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    int a = 10;
    int &p = a;
    cout << &p << endl << &a << endl << p << a;
    return 0;
}
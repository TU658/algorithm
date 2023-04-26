#include <stdio.h>
 
struct marks {
    int num;
 
    // Member function inside Structure to
    // take input and store it in "num"
    void Set(int temp) { num = temp; }
 
    // function used to display the values
    void display() { printf("%d", num); }
};
 
// Driver Program
int main()
{
    struct marks m1;
    // calling function inside Struct to
    // initialize value to num
    m1.Set(9);
 
    // calling function inside struct to
    // display value of Num
    m1.display();
}
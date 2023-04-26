#include <bits/stdc++.h>

using namespace std;

//infor Student 
struct Student
{
    string name;
    string mssv;
    double gpa;
};

//each Node in linked list
struct Node
{
    Student s;
    Node *Next;
};

//change datatype 
typedef struct Node* node;

//create new node in linked list with data is struct Student
node makeNode(){
    Student s;
    cout << "nhap vao ten cua sinh vien : \t" ;
    cin.ignore();
    getline(cin, s.name);
    cout << "nhap vao ma so sinh vien cua sinh vien do: \t";
    cin.ignore();
    getline(cin, s.mssv);
    cout << "nhap diem gpa: \t";
    cin >> s.gpa;
    cin.ignore();

    node tmp = new Node(); 
    tmp->s = s;
    tmp->Next = NULL;
    return tmp;
}

//check empty linked list
bool empty(node a){
    return a == NULL;
}

// return size of linked list
int Size(node a){
    int cnt = 0;
    while(a != NULL){
        cnt++;
        a = a->Next;
    }
    return cnt;
}

// add member at the first in linked list
void insertFirst(node &a){
    node tmp = makeNode();
    if(a == NULL){
        a = tmp;
    }
    else{
        tmp->Next = a;
        a = tmp;
    }
}

//add member at the last in linked list
void insertLast(node &a){
    node tmp = makeNode();
    if(a == NULL){
        a = tmp;
    }
    else{
        node p = a; // assign p is first Node in linked list to run 
        while(p->Next != NULL){
            p = p->Next;
        }
        p->Next = tmp;
        tmp->Next = NULL;
    }
}

//add member at anywhere in linked list 
void insertMiddle(node &a, int pos){
    node tmp = makeNode();
    if(a == NULL){
        a = tmp;
    }   
    if(pos == 1){
        insertFirst(a);
    }
    else if(pos <= Size(a) && pos > Size(a) + 1){
        cout << "Error position";
        return;
    }
    else if(pos == Size(a) + 1){
        insertLast(a);
    }
    else{
        node p = a;
        for(int i = 1; i < pos-1; i++){
            p = p->Next;
        }
        tmp->Next = p->Next;
        p->Next = tmp;
    }
}

//delete member at the first in linked list
void deleteFirst(node &a){
    if(a == NULL) return;
    else    a = a->Next;
}

//delete member at the last in linked list
void deleteLast(node &a){
    if(a == NULL)   return;
    else{
        node p = a;
        for(int i = 1; i < Size(a); i++){
            p = p->Next;
        }
        p->Next = NULL;
    }
}

//delete member at anywhere in linked list
void deleteMiddle(node &a, int pos){
    if(a == NULL)   return;
    if(pos == 1){
        deleteFirst(a);
    }
    else if(pos == Size(a)+1){
        deleteLast(a);
    }
    else if (pos <= 0 && pos > Size(a)+1){
        cout << "error position\n";
        return;
    }
    else{
        node at_p = a;
        node p = a;
        for(int i = 1; i < pos-1; i++){
            p = p->Next;
        }
        for(int j = 1; j <= pos-1; j++){
            at_p = at_p->Next;
        }
        p->Next = at_p->Next;
        at_p->Next = NULL;
    }
}

//print each Student
void print_Student(Student s){
    cout << "--------------------------\n";
    cout << "name :\t" << s.name << endl;
    cout << "mssv :\t" << s.mssv << endl;
    cout << "GPA :\t" << s.gpa << endl;
    cout << "--------------------------\n";
}

//print all member have in linked list 
void print_list(node a){
    while(a != NULL){
        print_Student(a->s);
        a = a->Next;
    }
}

//sort member with gpa a->z
void sort_list_gpa(node &a){
    for(node p = a; p->Next != NULL; p = p->Next){
        node min = p;
        for(node q = p->Next; q->Next != NULL; q = q->Next){
            if(q->s.gpa < min->s.gpa){
                min = q;
            }
        }
        Student tmp = min->s;
        min->s = p->s;
        p->s = tmp;
    }
}

int main(){
    node head = NULL;
    while(1){
        cout << "-----------------MENU-----------------------\n";
        cout << "1.  add member at the first in linked list.\n";
        cout << "2.  add member at the last in linked list.\n";
        cout << "3.  add member at anywhere in linked list.\n";
        cout << "4.  delete member at the first in linked list.\n";
        cout << "5.  delete member at the last in linked list.\n";
        cout << "6.  delete member at anywhere in linked list.\n";
        cout << "7.  sort member with gpa min->max.\n";
        cout << "8.  print list \n";
        cout << "0.  exit program !\n";
        cout << "============================================\n";
        cout << "sl you want :\t";
        int sl; cin >> sl;
        if(sl == 1){
            insertFirst(head);
        }
        else if(sl == 2){
            insertLast(head);
        }
        else if(sl == 3){
            cout << "cmt position you want insert in list : \t";
            int pos; cin >> pos;
            insertMiddle(head,pos);
        }
        else if(sl == 4){
            deleteFirst(head);
        }
        else if(sl == 5){
            deleteLast(head);
        }
        else if(sl == 6){
            cout << "cmt position you want delete in list : \t";
            int pos; cin >> pos;
            deleteMiddle(head,pos);
        }
        else if(sl == 7){
            sort_list_gpa(head);
        }
        else if(sl == 8){
            print_list(head);
        }
        else{
            break;
        }
    }
    return 0;
}
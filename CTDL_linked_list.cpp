#include <bits/stdc++.h>

using namespace std;

//trong ham co tham tri(a khong muon lam thay doi gia tri cu ban dau), tham so(&a muon thay doi gia tri ban dau), con tro ham(*a muon thay doi gia tri ban dau)


//ưu điểm so với mangr là có thể mở rộng và thu nhỏ nhờ cơ ché cấp phát động. để quản lí một danh sách liên kết chỉ cần lưu thông tin của node đầu tiên trong danh sách
//nhược điểm so với mảng là thời gian truy cập lâu hơn vì phải truy cập tuyến tính(duyệt từ đâu đến nơi mình muốn)

//đầu danh sách gọi là head , node cuối cùng luôn chỉ về NULL


struct Node
{
    int data;
    Node *Next;
};

typedef struct Node* node;

//xay dung ham de add linked list
//cap phat dong de cap phat 1 Node
//con tro ma muon chi vao phan tu thi dung dau ->
node makeNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->Next = NULL;
    return tmp;
}

//kiem tra rong 
bool empty(node a){
    //node a la node dau tien trong danh sach
    return a == NULL;
}

//ham de dem so phan tu trong danh sach lien ket

int Size(node a){
    int cnt = 0;
    while(a != NULL){
        cnt++;
        a = a->Next; // gan dia chi Node tiep theo cho Node hien tai den khi nao = NULL den phan tu cuoi cung
        //cho Node hien tai nhay sang Node tiep theo den khi = NULL
    }
    return cnt;
}


//them 1 phan tu vao dau danh sach lien ket dung tham so
void insertFirst(node &a, int x){
    //&a thay doi khi co su thay doi ( tham chieu )
    //a k thay doi khi co su thay doi 
    node tmp = makeNode(x);
    if(a == NULL){
        //khi chua co phan tu nao 
        a = tmp;
    }
    else{
        //tro dia chi tiep theo cua tmp la Node moi la a truoc do
        //sau do cho tmp la Node moi = a
        //vay moi du duoc phan tu cu truoc do neu khong thi danh sach lien ket chi co 1 phan tu la tmp la Next tro toi NULL
        tmp->Next = a;
        a = tmp;
    }
}

//them 1 phan tu vao dau danh sach lien ket su dung con tro ham
void insertFirst_pointer(node *a, int x){ // *a trong day la con tro dang node
    node tmp = makeNode(x);
    if(*a == NULL){// *a trong day la gia tri cua con tro node a
        *a = tmp;
    }
    else{
        tmp->Next = *a;
        *a = tmp;
    }
}

//them phan tu vao cuoi danh sach lien ket dung con tro
void insertLast_pointer(node *a, int x){
    node tmp = makeNode(x);
    if(*a == NULL){
        *a = tmp;
    }
    else{
        //duyet de den Node cuoi cung trong danh sach lien ket
        node p = *a;
        while(p->Next != NULL){
            p = p->Next;
        }
        p->Next = tmp;
    }
}

//them phan tu vao cuoi danh sach dung tham so
void insertLast(node &a, int x){
    node tmp = makeNode(x);
    if(a == NULL){
        a = tmp;
    }
    else{
        node p = a;
        while(p->Next != NULL){
            p = p->Next;
        }
        p->Next = tmp;
    }
}

//them phan tu vao giua danh sach lien ket dung tham so
void insertMiddle(node &a, int x, int pos){//pos la vi tri can chen vao //x la Node can chen vao
    int n = Size(a);
    if(pos <= 0 || pos > n + 1){
        cout << "vi tri chen trong danh sach lien ket khong hop le\n";
        return;
    }
    if(pos == 1){
        insertFirst(a,x);
        return;
    }
    else if (pos == n+1){
        insertLast(a,x);
        return;
    }
    else{
        node p = a;
        for(int i = 1; i < pos-1; i++){
            //chay toi vi tri can chen vao
            p = p->Next;
        }
        node tmp = makeNode(x);
        //theo thu tu moi dung nha, trong Node can chen vao thi gan Next truoc
        tmp->Next = p->Next;
        p->Next = tmp;
    }
    
}

//xoa phan tu o dau trong danh sach lien ket 
void deleteFirst(node &a){
    if(a == NULL)   return;
    else{
        a = a->Next; // bo qua phan tu dau tien de den phan tu tiep theo -> xoa dau
    }
}

//xoa phan tu o cuoi trong danh sach lien ket
void deleteLast(node &a){
    if(a == NULL) return;
    else{
        int n = Size(a);
        node p = a;
        for(int i = 1; i < n - 1; i++){
            p = p->Next;
        }
        p->Next = NULL;
    }
}

//xoa phan tu o vi tri bat ki trong danh sach lien ket
void deleteMiddle(node &a, int pos){
    if(pos <= 0 || pos > Size(a))   return;
    node front_pos = NULL; // con tro duyet den vi tri pos - 1
    node at_pos = a; // tai vi tri pos
    for(int i = 1; i < pos; i++){
        //duyet toi vi tri pos - 1 ta co front pos va at_pos la vi tri truoc xoa la vi tri xoa
        front_pos = at_pos;
        at_pos = at_pos->Next;
    }
    if(front_pos == NULL){
        //chi co 1 phan tu trong danh sach lien ket thi nhu xoa phan tu dau tien
        a = a->Next;
    }
    else{
        front_pos->Next = at_pos->Next;       
    }
}

//in cac phan tu trong danh sach lien ket
void print_linked_list(node a){
    cout << "----------------------------------------------\n";
    while(a != NULL){
        cout << a->data << " ";
        a = a->Next;
    }
    
    cout << endl << "------------------------------------------------\n";
}


//sap xep cac phan tu trong danh sach lien ket
void sort_linked_list(node &a){
    for(node p = a; p->Next != NULL; p = p->Next){
        node min = p;  
        for(node q =  p->Next; q != NULL; q = q->Next){
            if(q->data < min->data){
                min = q;
            }
        }
        int tmp = min->data ;
        min->data = p->data;
        p->data = tmp;
    }
}

//tim kiem trong danh sach lien ket
//tim phan tu lon nhat trong danh sach lien ket
int find_linked_list(node a){
    int max = 0;
    for(node p = a; p->Next != NULL; p = p->Next){
        if(p->data > max){
            max = p->data;
        }        
    }
    int n = Size(a);
    node q = a;
    for(int i = 1; i < n; i++){
        q = q->Next;
    }
    if(max < q->data){
        max = q->data;
    }
    return max;
}

int main(){
    //khoi tao 1 Node dau tien trong danh sach lien ket
    node head = NULL;
    //--------------------
    while(1){
        cout << "----------------MENU------------------------\n";
        cout << "1. chen phan tu vao dau danh sach lien ket\n";
        cout << "2. chen phan tu vao cuoi danh sach lien ket\n";
        cout << "3. chen phan tu vao bat ki vi tri danh sach lien ket\n";
        cout << "4. xoa phan tu dau trong danh sach lien ket\n";
        cout << "5. xoa phan tu cuoi trong danh sach lien ket\n";
        cout << "6. xoa phan tu bat ki trong danh sach lien ket\n";
        cout << "7. duyet danh sach lien ket\n";
        cout << "8. tim phan tu lon nhat trong danh sach lien ket\n";
        cout << "9. sap xep cac phan tru trong danh sach lien ket\n";
        cout << "0. thoat !\n";
        cout << "--------------------------------------------------------\n";
        cout << "nhap lua chon cua ban : "; 
        int lc; cin >> lc; 
        if(lc == 1){
            int x; cout << "nhap gia tri can chen vao dau danh sach: "; cin >> x;
            insertFirst(head, x);
        }
        else if (lc == 2){
            int x; cout << "nhap gia tri can chen vao cuoi danh sach: "; cin >> x;
            insertLast(head,x);
        }
        else if(lc == 3){
            int x, pos;
            cout << "nhap gia tri can chen vao trong danh sach: "; cin >> x;
            cout << "nhap vi tri can chen gia tri vua nhap: "; cin >> pos;
            insertMiddle(head, x, pos);
        }
        else if(lc == 4){
            deleteFirst(head);
        }
        else if(lc == 5){
            deleteLast(head);
         }
        else if(lc == 6){
            int pos; cout << "nhap vi tri can xoa trong danh sach: "; cin >> pos;
            deleteMiddle(head, pos);
        }
        else if(lc == 7){
            print_linked_list(head);
        }
        else if(lc == 8){
            int i = find_linked_list(head);
            cout << "phan tu lon nhat trong danh sach lien ket la:\t"<< i << endl;
        }
        else if(lc == 9){
            sort_linked_list(head);
        }       
        else{
            break;
        }
    }
    return 0;
}



// trong stack thi top la head trong danh sach lien ket 
// trong queue thi head trong danh sach lien ket la o vi tri back va phan tu cuoi cua danh sach lien ket se o vi tri front trong queue
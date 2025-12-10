#include <iostream>
using namespace std;
typedef char Elemtype;
class LinkList{
private:
    struct Lnode{
        int data;
        Lnode *next;
        Lnode(int x):data{x},next{nullptr}{}
    };
    int length;
    Lnode *head;
public:
    LinkList(): head(nullptr),length(0){}

    void ListInsert(int num , Elemtype c){
        head = Lnode
    }

};

int main(){
    LinkList L;
    Elemtype e;
    cout<< "单链表基本运算" << "\n";
    cout << "(1)初始化单链表h" << "\n";
    cout << "(2)依次使用尾插法插入a、b、c,d,e元素" << "\n";
    L.ListInsert(1,'a');
    L.ListInsert(2,'b');
    L.ListInsert(3,'c');
    L.ListInsert(4,'d');
    L.ListInsert(5,'e');
    cout << "(3)输出单链表h:" << "\n";
    L.DispList();
    cout << "(4)单链表长度："<<L.ListLength() << "\n";
    //删除
    //查找a
    LocateElem(L,a)
}
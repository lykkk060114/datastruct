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


};

int main(){
    LinkList L;
    Elemtype e;
    cout<< "单链表基本运算" << "\n";
    cout << 
}
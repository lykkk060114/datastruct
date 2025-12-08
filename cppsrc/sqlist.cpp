#include <iostream>
using namespace std;

#define MaxSize 50

class SqList {
private:
    char *data; // 动态数组
    int length;

public:
    // 构造函数
    SqList() {
        data = new char[MaxSize]; // 动态分配内存
        length = 0;
    }

    // 创建列表
    void CreateList(const char a[], int n) {
        for (int i = 0; i < n; i++) {
            data[i] = a[i];
        }
        length = n;
    }

    // 初始化列表
    void InitList() {
        length = 0;
    }

    // 销毁列表
    void DestroyList() {
        delete[] data;  // 释放动态分配的内存
    }

    // 判断列表是否为空
    bool ListEmpty() const {
        return length == 0;
    }

    // 获取列表长度
    int ListLength() const {
        return length;
    }

    // 显示列表
    void DispList() const {
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // 获取第 i 个元素
    bool GetElem(int i, char &e) const {
        if (i < 1 || i > length) return false;
        e = data[i - 1];
        return true;
    }

    // 查找元素的位置
    int LocateElem(char e) const {
        for (int i = 0; i < length; i++) {
            if (data[i] == e) {
                return i + 1; // 返回位置从1开始
            }
        }
        return 0; // 未找到
    }

    // 插入元素
    bool ListInsert(int i, char e) {
        if (i < 1 || i > length + 1 || length >= MaxSize) return false;
        for (int j = length; j > i - 1; j--) {
            data[j] = data[j - 1];
        }
        data[i - 1] = e;
        length++;
        return true;
    }

    // 删除元素
    bool ListDelete(int i, char &e) {
        if (i < 1 || i > length) return false;
        e = data[i - 1];
        for (int j = i - 1; j < length - 1; j++) {
            data[j] = data[j + 1];
        }
        length--;
        return true;
    }

    // 析构函数
    ~SqList() {
        delete[] data; // 释放内存
    }
};

int main() {
    SqList L;
    char e;

    cout << "Basic operations of sequence list are as follows:" << endl;
    cout << "    (1) Initiate sequence list L" << endl;
    L.InitList();

    cout << "    (2) Insert a, b, c, d, e" << endl;
    L.ListInsert(1, 'a');
    L.ListInsert(2, 'b');
    L.ListInsert(3, 'c');
    L.ListInsert(4, 'd');
    L.ListInsert(5, 'e');

    cout << "    (3) Display sequence list" << endl;
    L.DispList();

    cout << "    (4) Length of the sequence list: " << L.ListLength() << endl;

    cout << "    (5) Sequence list is " << (L.ListEmpty() ? "Empty" : "Non-Empty") << endl;

    cout << "    (6) The 3rd element of sequence list: ";
    if (L.GetElem(3, e)) {
        cout << e << endl;
    } else {
        cout << "Error getting element" << endl;
    }

    cout << "    (7) The position of 'a': " << L.LocateElem('a') << endl;

    L.DestroyList();

    return 0;
}

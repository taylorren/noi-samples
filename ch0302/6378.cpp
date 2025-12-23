#include <iostream>
#include <sstream>

using namespace std;

// 定义链表节点
struct Node
{
    int data;   // 节点数据
    Node *next; // 指向下一个节点
};

// 创建链表
Node *createLinkedList(int arr[], int n)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    for (int i = 0; i < n; ++i)
    {
        Node *newNode = new Node{arr[i], nullptr}; // 创建新节点
        if (!head)
        {
            head = newNode; // 如果是第一个节点
            tail = head;
        }
        else
        {
            tail->next = newNode; // 将新节点添加到链表末尾
            tail = newNode;
        }
    }
    return head;
}

// 删除指定值的节点
Node *deleteValue(Node *head, int value)
{
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            if (prev == nullptr)
            {
                // 删除头节点
                Node *temp = current;
                current = current->next;
                delete temp;    // 释放内存
                head = current; // 更新头节点
            }
            else
            {
                // 删除中间或尾节点
                prev->next = current->next;
                delete current;       // 释放内存
                current = prev->next; // 更新当前节点
            }
        }
        else
        {
            prev = current;          // 更新前一个节点
            current = current->next; // 移动到下一个节点
        }
    }
    return head; // 返回更新后的头节点
}

// 输出链表
void printLinkedList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl; // 输出换行
}

// 释放链表内存
void freeLinkedList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *temp = current;
        current = current->next;
        delete temp; // 释放节点内存
    }
}

int main()
{
    int n;
    cin >> n;              // 读取元素个数
    int *arr = new int[n]; // 动态分配数组

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i]; // 读取元素
    }

    int k;
    cin >> k; // 读取待删除的元素

    // 创建链表
    Node *head = createLinkedList(arr, n);
    // 删除指定值的节点
    head = deleteValue(head, k);
    // 输出链表
    printLinkedList(head);
    // 释放链表内存
    freeLinkedList(head);

    delete[] arr; // 释放动态数组内存
    return 0;
}
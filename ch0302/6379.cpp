#include <iostream>
#include <cstring>

using namespace std;

// 定义学生信息结构体
struct Student {
    char id[21];        // 学号，长度不超过20
    char name[41];      // 姓名，长度不超过40
    char gender;        // 性别，长度为1
    int age;            // 年龄
    double score;       // 得分
    char address[41];   // 地址，长度不超过40
    Student* next;      // 指向下一个学生的指针
};

int main() {
    Student* head = nullptr;  // 链表头指针
    char id[21];
    
    // 读取学生信息
    while (true) {
        cin >> id;
        
        // 检查是否到达输入结束标记
        if (strcmp(id, "end") == 0) {
            break;
        }
        
        // 创建新的学生节点
        Student* newStudent = new Student;
        strcpy(newStudent->id, id);
        
        // 读取其他信息
        cin >> newStudent->name >> &newStudent->gender >> newStudent->age 
            >> newStudent->score >> newStudent->address;
        
        // 将新节点插入到链表头部（实现倒序输出）
        newStudent->next = head;
        head = newStudent;
    }
    
    // 输出学生信息（已经是倒序）
    Student* current = head;
    while (current != nullptr) {
        cout << current->id << " " << current->name << " " << current->gender 
             << " " << current->age << " " << current->score << " " 
             << current->address << endl;
        
        // 移动到下一个节点
        Student* temp = current;
        current = current->next;
        
        // 释放当前节点内存
        delete temp;
    }
    
    return 0;
}
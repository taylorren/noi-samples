#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 表示一个目录或文件的节点
struct Node {
    string name;
    bool isDir;
    vector<Node*> children;  // 子目录
    vector<string> files;    // 当前目录下的文件
    
    Node(string n, bool dir) : name(n), isDir(dir) {}
};

// 递归打印目录结构
void printTree(Node* root, string indent = "") {
    cout << indent << root->name << endl;
    
    // 先处理子目录（新的层级）
    string newIndent = indent + "|     ";
    for(Node* child : root->children) {
        printTree(child, newIndent);
    }
    
    // 再处理当前目录下的文件（和目录同级）
    sort(root->files.begin(), root->files.end());
    for(const string& file : root->files) {
        cout << indent << file << endl;
    }
}

// 递归删除树
void deleteTree(Node* root) {
    for(Node* child : root->children) {
        deleteTree(child);
    }
    delete root;
}

// 读取一个目录的内容
Node* readDirectory(string name) {
    Node* dir = new Node(name, true);
    string line;
    
    while(getline(cin, line)) {
        if(line == "]") break;
        if(line == "*" || line == "#") {
            cin.putback('\n');
            cin.putback(line[0]);
            break;
        }
        
        if(line[0] == 'd') {  // 是目录
            dir->children.push_back(readDirectory(line));
        } else {  // 是文件
            dir->files.push_back(line);
        }
    }
    
    return dir;
}

int main() {
    string line;
    bool first = true;
    int dataSet = 1;
    
    while(getline(cin, line)) {
        if(line == "#") break;
        
        if(!first) cout << endl;
        cout << "DATA SET " << dataSet << ":" << endl;
        first = false;
        
        // 创建根目录
        Node* root = new Node("ROOT", true);
        
        // 处理输入
        do {
            if(line == "*") {
                dataSet++;
                break;
            }
            
            if(line[0] == 'd') {
                root->children.push_back(readDirectory(line));
            } else {
                root->files.push_back(line);
            }
        } while(getline(cin, line));
        
        // 打印树
        printTree(root);
        
        // 清理内存
        deleteTree(root);
        
        if(line != "*") break;
    }
    
    return 0;
}
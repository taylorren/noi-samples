#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    
    // 找到x到根节点的路径
    vector<int> pathX;
    int temp = x;
    while (temp >= 1) {
        pathX.push_back(temp);
        temp /= 2;
    }
    
    // 找到y到根节点的路径
    vector<int> pathY;
    temp = y;
    while (temp >= 1) {
        pathY.push_back(temp);
        temp /= 2;
    }
    
    // 反转路径，使其从根节点开始
    reverse(pathX.begin(), pathX.end());
    reverse(pathY.begin(), pathY.end());
    
    // 找到最近公共祖先
    int lca = 1;
    int minLen = min(pathX.size(), pathY.size());
    
    for (int i = 0; i < minLen; i++) {
        if (pathX[i] == pathY[i]) {
            lca = pathX[i];
        } else {
            break;
        }
    }
    
    cout << lca << endl;
    
    return 0;
}
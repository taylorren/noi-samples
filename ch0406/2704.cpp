/*
算法：排序 + 支配关系判定
难度：★★★☆☆ (3星)
描述：在二维平面上找出非支配点
算法分析：
1. 使用结构体存储点的坐标
2. 按x坐标排序后检查支配关系
3. 优化：移除了支配关系判断中的冗余条件
4. 时间复杂度：O(N²)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& other) const {
        return x < other.x;
    }
};

// 判断p1是否支配p2
bool dominates(const Point& p1, const Point& p2) {
    return p1.x >= p2.x && p1.y >= p2.y;
}

vector<Point> findMaximalPoints(vector<Point>& points) {
    vector<Point> maximal;
    int n = points.size();
    
    // 按x坐标排序
    sort(points.begin(), points.end());
    
    // 对每个点，检查是否被其他点支配
    for (int i = 0; i < n; i++) {
        bool isMaximal = true;
        for (int j = 0; j < n; j++) {
            if (i != j && dominates(points[j], points[i])) {
                isMaximal = false;
                break;
            }
        }
        if (isMaximal) {
            maximal.push_back(points[i]);
        }
    }
    
    return maximal;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    vector<Point> maximalPoints = findMaximalPoints(points);
    
    // 输出结果
    for (int i = 0; i < maximalPoints.size(); i++) {
        cout << "(" << maximalPoints[i].x << "," << maximalPoints[i].y << ")";
        if (i < maximalPoints.size() - 1) {
            cout << ",";
        }
    }
    cout << endl;
    
    return 0;
}
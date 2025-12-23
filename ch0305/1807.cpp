#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// 定义点结构
struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    
    bool operator==(const Point& p) const {
        return x == p.x && y == p.y;
    }
};

// 自定义哈希函数，用于将点作为哈希表的键
struct PointHash {
    size_t operator()(const Point& p) const {
        return hash<int>()(p.x) ^ hash<int>()(p.y);
    }
};

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<Point> points(n);
        
        // 读取所有点的坐标
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }
        
        // 使用哈希集合存储所有点，便于快速查找
        unordered_set<Point, PointHash> pointSet;
        for (const auto& p : points) {
            pointSet.insert(p);
        }
        
        int count = 0;
        
        // 枚举所有可能的点对作为正方形的两个相邻顶点
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // 计算从i到j的向量
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                
                // 计算另外两个点的坐标（旋转90度）
                Point p3(points[i].x - dy, points[i].y + dx);
                Point p4(points[j].x - dy, points[j].y + dx);
                
                // 检查这两个点是否在给定的点集中
                if (pointSet.count(p3) && pointSet.count(p4)) {
                    count++;
                }
                
                // 检查另一个方向旋转得到的点
                Point p5(points[i].x + dy, points[i].y - dx);
                Point p6(points[j].x + dy, points[j].y - dx);
                
                if (pointSet.count(p5) && pointSet.count(p6)) {
                    count++;
                }
            }
        }
        
        // 每个正方形被计算了4次，需要除以4
        cout << count / 4 << endl;
    }
    
    return 0;
}
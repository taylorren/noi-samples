#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

struct Point
{
    int x, y, garbage;
};

// 检查点p是否在以(cx,cy)为中心，边长为2d+1的正方形范围内
bool inRange(const Point& p, int cx, int cy, int d)
{
    return abs(p.x - cx) <= d && abs(p.y - cy) <= d;
}

int main()
{
    int d, n;
    cin >> d >> n;

    // 读入所有垃圾点
    vector<Point> points(n);
    for(int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y >> points[i].garbage;
    }

    int maxGarbage = 0;          // 最大垃圾量
    set<pair<int, int>> visited; // 记录已经计算过的点
    map<pair<int, int>, int> garbageAtPoint; // 记录每个点的垃圾量

    // 遍历所有可能的投放点
    for(int i = 0; i < n; i++)
    {
        // 以当前垃圾点为中心，遍历周围可能的投放点
        for(int dx = -d; dx <= d; dx++)
        {
            for(int dy = -d; dy <= d; dy++)
            {
                int cx = points[i].x + dx;
                int cy = points[i].y + dy;

                // 检查坐标是否在有效范围内且未被访问过
                if(cx < 0 || cx > 1024 || cy < 0 || cy > 1024 ||
                   visited.count({cx, cy}))
                {
                    continue;
                }

                visited.insert({cx, cy});

                // 计算当前位置能覆盖的垃圾总量
                int totalGarbage = 0;
                for(const Point& p : points)
                {
                    if(inRange(p, cx, cy, d))
                    {
                        totalGarbage += p.garbage;
                    }
                }

                // 记录这个点的垃圾量
                garbageAtPoint[{cx, cy}] = totalGarbage;
                // 更新最大值
                maxGarbage = max(maxGarbage, totalGarbage);
            }
        }
    }

    // 计算达到最大垃圾量的投放点数量
    int maxCount = 0;
    for(const auto& point : garbageAtPoint)
    {
        if(point.second == maxGarbage)
        {
            maxCount++;
        }
    }

    cout << maxCount << " " << maxGarbage << endl;
    return 0;
}
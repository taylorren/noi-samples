#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define inf 0x3f3f3f3f
typedef long long ll;

const int N = 110;
const int nmax = 1010;
const double esp = 1e-8;
const double PI = 3.1415926;

struct node
{
    double x, y;
};

int col[N];

double dis(node p, node q)
{
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

double mymin(double x, double y)
{
    if(x - y < esp)
        return x;
    return y;
}

double pre[nmax][2], now[nmax][2];

int main()
{
    int t, cn, tn;
    int co;
    scanf("%d", &t);
    while(t--)
    {
        // vector容器保存染色道端点，vec[i][0]表示染颜色i的左端点，vec[i][1]表示染颜色i的右端点
        vector<node> vec[nmax][2];
        node l, r;
        double sx, sy, tx, ty;
        scanf("%lf%lf%lf%lf", &sx, &sy, &tx, &ty);
        // 把开始点作为必须经过的一个染色道，染色为0
        l.x = r.x = sx;
        l.y = r.y = sy;
        col[0] = 0;
        vec[0][0].push_back(l);
        vec[0][1].push_back(r);
        scanf("%d", &cn);
        for(int i = 1; i <= cn; i++)
            scanf("%d", &col[i]);

        scanf("%d", &tn);
        for(int i = 1; i <= tn; i++)
        {
            scanf("%lf%lf%lf%lf%d", &l.x, &l.y, &r.x, &r.y, &co);
            vec[co][0].push_back(l);
            vec[co][1].push_back(r);
        }
        // 把终点点作为必须经过的一个染色道，染色为0
        col[cn + 1] = 101;
        l.x = r.x = tx;
        l.y = r.y = ty;
        vec[101][0].push_back(l);
        vec[101][1].push_back(r);
        pre[0][0] = pre[0][1] = 0.0;
        for(int i = 1; i <= cn + 1; i++)
        {
            int id = col[i];
            for(int j = 0; j < vec[id][0].size(); j++)
            {
                // 初始化通过第j个可以染色为col[i]的管道，且从管道左边进去的值为无穷大
                now[j][0] = 11111111.1;
                // 初始化通过第j个可以染色为col[i]的管道，且从管道右边进去的值为无穷大
                now[j][1] = 11111111.1;
                int val = col[i - 1];
                double len = dis(vec[id][0][j], vec[id][1][j]);
                for(int k = 0; k < vec[val][0].size(); k++)
                { // 遍历从上一次染色经过的每一条符合染色经过的最小距离的染色道到当前符合染色的第j个染色道的最小距离
                    now[j][0] = mymin(
                        now[j][0],
                        mymin(pre[k][0] + dis(vec[val][1][k], vec[id][0][j]) +
                                  len,
                              pre[k][1] + dis(vec[val][0][k], vec[id][0][j]) +
                                  len));
                    now[j][1] = mymin(
                        now[j][1],
                        mymin(pre[k][0] + dis(vec[val][1][k], vec[id][1][j]) +
                                  len,
                              pre[k][1] + dis(vec[val][0][k], vec[id][1][j]) +
                                  len));
                }
            }
            for(int j = 0; j < vec[id][0].size(); j++)
            {
                // 保存到符合染色为col[i]的染色道最小距离
                pre[j][0] = now[j][0];
                pre[j][1] = now[j][1];
            }
        }
        double minl =
            mymin(now[0][0],
                  now[0][1]); // 取最后一次（即终点）从左侧和从右侧进去的最小值
        printf("%.3lf\n", minl);
    }
    return 0;
}
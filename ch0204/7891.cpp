#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// 计算f(x)的值
double f(double x, double a, double b, double c, double d)
{
    return a * x * x * x + b * x * x + c * x + d;
}

// 二分查找在区间[left, right]内的根
double find_root(double left, double right, double a, double b, double c,
                 double d)
{
    const double eps = 1e-6; // 精度控制
    double fl = f(left, a, b, c, d);
    double fr = f(right, a, b, c, d);

    // 确保区间内有根
    if(fl * fr >= 0)
        return left; // 这种情况在本题中不会发生

    while(right - left > eps)
    {
        double mid = (left + right) / 2;
        double fm = f(mid, a, b, c, d);

        if(abs(fm) < eps)
            return mid;

        if(fm * fl < 0)
        {
            right = mid;
            fr = fm;
        }
        else
        {
            left = mid;
            fl = fm;
        }
    }

    return (left + right) / 2;
}

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<double> roots;
    // 在[-100, 100]范围内每隔0.9搜索函数值的符号变化
    for(double x = -100; x <= 99; x += 0.9)
    {
        double f1 = f(x, a, b, c, d);
        double f2 = f(x + 0.9, a, b, c, d);
        // 如果发现符号改变，说明这个区间内有根
        if(f1 * f2 <= 0)
        {
            double root = find_root(x, x + 0.9, a, b, c, d);
            // 检查是否是新的根（与已有的根相差至少1）
            bool is_new_root = true;
            for(double existing_root : roots)
            {
                if(abs(root - existing_root) < 0.9)
                {
                    is_new_root = false;
                    break;
                }
            }
            if(is_new_root)
            {
                roots.push_back(root);
            }
        }
    }

    // 对根进行排序
    sort(roots.begin(), roots.end());

    // 输出结果，保留两位小数
    cout << fixed << setprecision(2);
    for(int i = 0; i < 3; i++)
    {
        if(i > 0)
            cout << " ";
        cout << roots[i];
    }
    cout << endl;

    return 0;
}
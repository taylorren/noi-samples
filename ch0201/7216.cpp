#include <cmath>
#include <iostream>
using namespace std;

// 计算长方体表面积（需要的贴纸数量）
int calculateSurfaceArea(int length, int width, int height)
{
    return 2 * (length * width + length * height + width * height);
}

int main()
{
    int N;
    cin >> N;

    int min_stickers = 1e9;

    // 计算立方根的近似值作为搜索的中心点
    int cube_root = round(pow(N, 1.0 / 3));

    // 扩大搜索范围，从1到N的立方根的两倍
    for(int length = 1; length <= min(N, cube_root * 2); length++)
    {
        if(N % length != 0)
            continue;

        int remaining = N / length;
        // 对剩余的面积，也从最接近正方形的地方开始搜索
        int sqrt_remaining = round(sqrt(remaining));

        // 扩大搜索范围，确保不会错过最优解
        for(int width = 1; width <= remaining; width++)
        {
            if(remaining % width != 0)
                continue;

            int height = remaining / width;
            if(length * width * height != N)
                continue;

            int stickers = calculateSurfaceArea(length, width, height);
            min_stickers = min(min_stickers, stickers);
        }
    }

    cout << min_stickers << endl;
    return 0;
}
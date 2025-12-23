#include <iostream>
#include <string>

using namespace std;

void permute(string& str, bool used[], string& curr, int depth = 0)
{
    // string indent(depth * 2, ' ');
    // cout << indent << "进入递归 depth=" << depth << ", curr=\"" << curr << "\"" << endl;
    // cout << indent << "used数组: ";
    // for(int i = 0; i < str.length(); i++)
    // {
    //     cout << str[i] << ":" << used[i] << " ";
    // }
    // cout << endl;

    if(curr.length() == str.length())
    {
        cout << curr << endl;
        // cout << indent << "找到一个排列: " << curr << endl;
        // cout << indent << "退出递归 depth=" << depth << endl;
        return;
    }
    
    for(int i = 0; i < str.length(); i++)
    {
        // cout << indent << "  检查字符'" << str[i] << "': ";
        if(used[i])
        {
            // cout << "已被使用，跳过" << endl;
            continue;
        }
        // cout << "可以使用" << endl;
        
        // cout << indent << "  在位置" << curr.length() 
        //      << "放置字符'" << str[i] << "'" << endl;
        
        used[i] = true;
        curr.push_back(str[i]);
        
        // cout << indent << "  递归前 curr=\"" << curr << "\"" << endl;
        permute(str, used, curr, depth + 1);
        // cout << indent << "  递归后准备回溯，当前curr=\"" << curr << "\"" << endl;
        
        curr.pop_back();
        used[i] = false;
        
        // cout << indent << "  回溯完成，curr=\"" << curr << "\"" << endl;
    }
    // cout << indent << "退出递归 depth=" << depth << endl;
}

int main()
{
    string s;
    cin >> s;
    bool used[7] = {false};  // 题目说明长度最大为6
    string curr = "";
    permute(s, used, curr);
    return 0;
}
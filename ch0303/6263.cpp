#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 表达式求值类
class BooleanExpressionEvaluator {
private:
    string expr;
    int pos;

    // 跳过空格
    void skipSpaces() {
        while (pos < expr.length() && expr[pos] == ' ') {
            pos++;
        }
    }

    // 解析基本表达式（V、F或带括号的表达式）
    bool parsePrimary() {
        skipSpaces();
        
        if (pos >= expr.length()) {
            return false;
        }
        
        char c = expr[pos];
        pos++;
        
        if (c == 'V') {
            return true;
        } else if (c == 'F') {
            return false;
        } else if (c == '(') {
            bool result = parseExpression();
            skipSpaces();
            if (pos < expr.length() && expr[pos] == ')') {
                pos++;
                return result;
            }
        } else if (c == '!') {
            return !parsePrimary();
        }
        
        return false;
    }

    // 解析与表达式
    bool parseAnd() {
        bool left = parsePrimary();
        
        while (true) {
            skipSpaces();
            if (pos >= expr.length() || expr[pos] != '&') {
                break;
            }
            
            pos++; // 跳过 &
            bool right = parsePrimary();
            left = left && right;
        }
        
        return left;
    }

    // 解析或表达式
    bool parseExpression() {
        bool left = parseAnd();
        
        while (true) {
            skipSpaces();
            if (pos >= expr.length() || expr[pos] != '|') {
                break;
            }
            
            pos++; // 跳过 |
            bool right = parseAnd();
            left = left || right;
        }
        
        return left;
    }

public:
    bool evaluate(const string& expression) {
        expr = expression;
        pos = 0;
        return parseExpression();
    }
};

int main() {
    string line;
    BooleanExpressionEvaluator evaluator;
    
    while (getline(cin, line)) {
        bool result = evaluator.evaluate(line);
        cout << (result ? "V" : "F") << endl;
    }
    
    return 0;
}
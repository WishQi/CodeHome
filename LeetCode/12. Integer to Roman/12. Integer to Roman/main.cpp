//
//  main.cpp
//  12. Integer to Roman
//
//  Created by limaoqi on 29/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 别人的思路：建立各位数上的数字与Roman数字的符号表
class Solution {
public:
    string intToRoman(int num) {
        vector<string> I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> M = {"", "M", "MM", "MMM"};
        return M[num / 1000] + C[num % 1000 / 100] + X[num % 100 / 10] + I[num % 10];
    }
};

int main(int argc, const char * argv[]) {
    
    int num;
    while (cin >> num) {
        cout << Solution().intToRoman(num) << endl;
    }

    return 0;
}

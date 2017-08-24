//
//  main.cpp
//  ZigZagConversion
//
//  Created by limaoqi on 24/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> result(numRows, "");
        int step = numRows - 1, n = (int)s.length();
        if (step == 0) return s;
        for (int i = 0; i <= n / step; ++i) {
            for (int j = 0; j < step; ++j) {
                int index = i * step + j;
                if (index < n) {
                    if (i % 2 == 0) {
                        result[j] += s[index];
                    } else {
                        result[step - j] += s[index];
                    }
                }
            }
        }
        string rs = "";
        for (int i = 0; i < numRows; ++i) {
            rs += result[i];
        }
        return rs;
    }
};

int main(int argc, const char * argv[]) {
    
    cout << (Solution().convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI") << endl;
    
    return 0;
}

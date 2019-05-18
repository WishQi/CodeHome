//
//  main.cpp
//  38. Count and Say
//
//  Created by limaoqi on 21/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // AC, 3ms
    string countAndSay(int n) {
        string res = "1";
        if (n == 1) return res;
        for (int i = 2; i <= n; ++i) {
            int count = 1;
            string lastStr = res;
            res = "";
            if (lastStr.length() == 1) {
                res = "1";
                res.push_back(lastStr[0]);
            } else {
                for (int j = 0; j < lastStr.length(); ++j) {
                    if (j > 0 && lastStr[j] == lastStr[j - 1]) {
                        count++;
                    } else if ((j > 0 && lastStr[j] != lastStr[j - 1])) {
                        string str;
                        str.push_back((char)(count + 48));
                        str.push_back(lastStr[j - 1]);
                        res += str;
                        count = 1;
                    }
                    if (j == (int)lastStr.length() - 1) {
                        string str;
                        str.push_back((char)(count + 48));
                        str.push_back(lastStr[j]);
                        res += str;
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        cout << Solution().countAndSay(n) << endl;
    }
    return 0;
}

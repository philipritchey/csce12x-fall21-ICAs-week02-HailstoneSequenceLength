#include <iostream>
#include <utility>
#include <tuple>
#include <list>
#include "code.h"

/*
This file unit tests the function(s) in code.cpp
Dr. Ritchey had to write this because Replit doesn't support unit testing for C++ (smh)
By the end of 121, you could be able to write this (and better), too.
*/

std::pair<int,int> test(std::list<std::pair<int,int>> tests) {
    int pass_cnt = 0, fail_cnt = 0;

    for (auto testcase : tests) {
        int number = testcase.first;
        int expected = testcase.second;
        int actual = hailstone_sequence_length(number);
        if (actual != expected) {
            std::cout << "[FAIL] expected hailstone_sequence_length("<<number<<") to be " << expected << ", got " << actual << std::endl;
            fail_cnt++;
        } else {
            pass_cnt++;
        }
    }

    return std::make_pair(pass_cnt, fail_cnt);
}

int main() {
    std::list<std::pair<int,int>> tests = {
        {2, 2},
        {27, 112},
        {3, 8},
        {1, 1},
        {26623, 308}
        };

    int pass_cnt, fail_cnt;

    std::tie(pass_cnt,fail_cnt) = test(tests);

    std::cout << "passing " << pass_cnt << std::endl;
    std::cout << "failing " << fail_cnt << std::endl;
}
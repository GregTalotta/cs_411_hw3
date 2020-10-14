// contigsum.hpp
// Greg Talotta
// 13 Oct 2020
//
// For CS 411 Fall 2020
// Used in Assignment 3, Exercise A

#ifndef FILE_CONTIGSUM_HPP_INCLUDED
#define FILE_CONTIGSUM_HPP_INCLUDED

#include <vector>
#include <iostream>
using std::vector;

int max(int first, int second)
{
    if (first >= second)
    {
        return first;
    }
    else
    {
        return second;
    }
}

int max(int first, int second, int third)
{
    if ((first >= second) && (first >= third))
    {
        return first;
    }
    else if (second >= third)
    {
        return second;
    }
    else
    {
        return third;
    }
}

int above_0(int test)
{
    if (test > 0)
    {
        return test;
    }
    return 0;
}

template <typename RAIter>
vector<int> example_algorithm(RAIter first, RAIter last)
{
    if (first == last)
    {
        return {0, 0, 0, 0};
    }
    if (last - first == 1)
    {
        return {above_0(*first), above_0(*first), above_0(*first), *first};
    }
    vector<int> left = example_algorithm(first, (first + ((last - first) / 2)));
    vector<int> right = example_algorithm((first + ((last - first) / 2)), last);
    return {(max(left[0], right[0], (left[2] + right[1]))), (max(left[1], (left[3] + right[1]))), (max(right[2], (right[3] + left[2]))), (left[3] + right[3])};
}

template <typename RAIter>
int contigSum(RAIter first, RAIter last)
{
    return example_algorithm(first, last)[0];
}

#endif //#ifndef FILE_CONTIGSUM_HPP_INCLUDED
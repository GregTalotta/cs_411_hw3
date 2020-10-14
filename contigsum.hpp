// contigsum.hpp
// Greg Talotta
// 13 Oct 2020
//
// For CS 411 Fall 2020
// Used in Assignment 3, Exercise A

#ifndef FILE_CONTIGSUM_HPP_INCLUDED
#define FILE_CONTIGSUM_HPP_INCLUDED

#include <vector>
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

int gcs_two(int first, int second)
{
    int gcs = max(first + second, first, second);
    if (gcs > 0)
    {
        return gcs;
    }
    else
    {
        return 0;
    }
    return 0;
}

template <typename RAIter>
vector<int> example_algorithm(RAIter first, RAIter last)
{
    if (first == last)
    {
        vector<int> results = {0, 0, 0, 0};
        return results;
    }
    else if (last - first == 2)
    {
        vector<int> results = {gcs_two(*first, *(first +1)), *first, *(first + 1), (*first + *(first + 1))};
        return results;
    }
    vector<int> results;
    vector<int> left = example_algorithm(first, first + ((last - first) / 2));
    vector<int> right = example_algorithm(first + ((last - first) / 2) + 1, last);
    results.push_back(max(left[0], right[0], (left[2] + right[1])));
    results.push_back(max(left[1], (left[3] + right[1])));
    results.push_back(max(right[2], (right[3] + left[2])));
    results.push_back(left[3] + right[3]);
    return results;
}

template <typename RAIter>
int contigSum(RAIter first, RAIter last)
{
    vector<int> results = example_algorithm(first, last);
    return results[0];
}

#endif //#ifndef FILE_CONTIGSUM_HPP_INCLUDED
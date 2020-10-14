// contigsum.hpp
// Greg Talotta
// 13 Oct 2020
//
// For CS 411 Fall 2020
// Used in Assignment 3, Exercise A

#ifndef FILE_CONTIGSUM_HPP_INCLUDED
#define FILE_CONTIGSUM_HPP_INCLUDED

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

template <typename RAIter>
int contigSum(RAIter first, RAIter last)
{
    if (first == last) // check if empty set
    {
        return 0;
    }
    if (last - first == 1) // check if only 1 element
    {
        if (*first > 0)
        {
            return *first;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int left = contigSum(first, (first + (last - first) / 2));
        int right = contigSum((first + (last - first) / 2) + 1, last);
        int total = 0;
        int left_mid = 0;
        for (auto it = (first + (last - first) / 2); it != first + 1; it--)
        {
            total += *it;
            if (total > left_mid)
            {
                left_mid = total;
            }
        }
        if (left_mid < 0)
        {
            left_mid = 0;
        }
        total = 0;
        int right_mid = 0;
        for (auto it = (first + (last - first) / 2) + 1; it != last; it++)
        {
            total += *it;
            if (total > right_mid)
            {
                right_mid = total;
            }
        }
        if (right_mid < 0)
        {
            right_mid = 0;
        }
        int crossing = left_mid + right_mid; //biggest to the right and left

        return max(right, left, crossing);
    }
}

#endif //#ifndef FILE_CONTIGSUM_HPP_INCLUDED
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
    else if (second > third)
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
    if (last - first == 1) // check if empty set
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
        int right = contigSum(first, (first + (last - first) / 2));
        int left = contigSum((first + (last - first) / 2) + 1, last);
        int crossing = 0; //biggest to the right and left
        return max(right, left, crossing);
    }
}

#endif //#ifndef FILE_CONTIGSUM_HPP_INCLUDED
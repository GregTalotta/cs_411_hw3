// contigsum.hpp
// Greg Talotta
// 13 Oct 2020
//
// For CS 411 Fall 2020
// Used in Assignment 3, Exercise A

#ifndef FILE_CONTIGSUM_HPP_INCLUDED
#define FILE_CONTIGSUM_HPP_INCLUDED

template <typename RAIter>
int contigSum(RAIter first, RAIter last)
{
    if (first == last) // check if empty set
    {
        return 0;
    }
    if ((last-first==1) && (*first > 0)) // check if empty set
    {
        return *first;
    }
    else
    {
        return 0;
    }
    int right = contigSum(first, (first + (last - first) / 2));
    int left = contigSum((first + (last - first) / 2) + 1, last);
    int crossing = 0; //?
}

#endif //#ifndef FILE_CONTIGSUM_HPP_INCLUDED
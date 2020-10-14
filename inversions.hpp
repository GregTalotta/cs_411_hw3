// inversions.hpp
// Greg Talotta
// 14 Oct 2020
//
// For CS 411 Fall 2020
// Used in Assignment 3, Exercise B

// modified from:
//      merge_sort.cpp
//      Glenn G. Chappell
//      9 Oct 2015
//
//      For CS 411/611 Fall 2015
//      Merge Sort using Iterators
#ifndef FILE_INVERSIONS_HPP_INCLUDED
#define FILE_INVERSIONS_HPP_INCLUDED

#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;
#include <algorithm>
using std::copy;
#include <iterator>
using std::advance;
using std::distance;
#include <type_traits>
using std::remove_reference;

template <typename RAIter>
size_t stableMerge(RAIter first, RAIter middle, RAIter last)
{
    using Value = typename remove_reference<decltype(*first)>::type;
    vector<Value> buffer(distance(first, last));
    RAIter in1 = first;
    RAIter in2 = middle;
    auto out = buffer.begin();
    size_t total = 0;
    while (in1 != middle && in2 != last)
    {
        if (*in2 < *in1)
        {
            total += distance(in1, middle);
            *out++ = *in2++;
        }
        else
        {
            *out++ = *in1++;
        }
    }
    copy(in1, middle, out);
    copy(in2, last, out);
    copy(buffer.begin(), buffer.end(), first);
    return total;
}

template <typename RAIter>
size_t inversions(RAIter first, RAIter last)
{
    size_t size = distance(first, last);
    if (size <= 1)
        return 0;
    RAIter middle = first;
    advance(middle, size / 2);
    return (inversions(first, middle) + inversions(middle, last) + stableMerge(first, middle, last));
}

#endif //#ifndef FILE_INVERSIONS_HPP_INCLUDED
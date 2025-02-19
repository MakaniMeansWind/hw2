#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{

    typename std::set<T>::iterator setIterator;

    typename std::set<T> intersectionSet;

    for(setIterator = s1.begin(); setIterator != s1.end(); ++setIterator)
    {

        typename std::set<T>::iterator it = s2.find(*setIterator);

        if(it != s2.end())
        {

            intersectionSet.insert(*setIterator);

        }

    }

    return intersectionSet;

}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{

    typename std::set<T>::iterator setIterator;

    typename std::set<T> unionSet;

    for(setIterator = s1.begin(); setIterator != s1.end(); ++setIterator)
    {

        unionSet.insert(*setIterator);

    }

    for(setIterator = s2.begin(); setIterator != s2.end(); ++setIterator)
    {

        unionSet.insert(*setIterator);

    }

    return unionSet;

}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif

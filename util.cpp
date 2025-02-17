#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
    
std::set<std::string> parseStringToWords(string rawWords)
{

    std::set<std::string> stringSetResult;

    std::string result = "";

    int startingSize = rawWords.size();

    int iterations = 0;

    while(iterations < startingSize)
    {

        result = "";

        while(!ispunct(rawWords[iterations]) && !isspace(rawWords[iterations]) && iterations < startingSize)
        {

            result += rawWords[iterations];

            iterations++;

        }

        iterations++;

        // std::string rawWordsSub = rawWords.substr(iterations);

        // rawWords = rawWordsSub;

        if(result.size() >= 2)
        {
            
            std::string returnString = convToLower(result);

            stringSetResult.insert(returnString);

            // cout << "Return String is: " << returnString << endl;
    
        }
        
    }
    
    return stringSetResult;
    
    
}

// void printExamples(std::set<std::string> stringSet)
// {
    
//     std::set<std::string>::iterator it;
    
//     for(it = stringSet.begin(); it != stringSet.end(); ++it)
//     {
        
//         cout << "String is: " << *it << endl;
        
//     }
    
// }

// int main()
// {
    
//     std:: string exampleOne = "Hello world!";
    
//     std::set<std::string> setOne = parseStringToWords(exampleOne);
    
//     printExamples(setOne);
    
//     std:: string exampleTwo = "I'll go out hello world. J. Men's";
    
//     std::set<std:: string> setTwo = parseStringToWords(exampleTwo);
    
//     printExamples(setTwo);
    
// }
    

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

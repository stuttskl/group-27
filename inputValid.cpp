/******************************************************************************
** Program name: inputvalid.cpp
** Author: April Castaneda, Victoria Fisher, Katie Stutts
** Date: 06.20.2019
** Description: This file contains four functions that test various
 * levels of input validation.
*********************************************************************/
#include "inputValid.hpp"

#include <string>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::atoi;

/******************************************************
returnInt() takes in a string as input, and utilizies a
 do/while loop to get input from user using getline(),
 and first removes any blank spaces or periods from the
 input. Then, the input is passed into isInt(), to verify
 each index in the input string is a digit. If so, that means
 the input is a valid integer, and is then converted from
 a string to integer, using atoi().
 ******************************************************/
int getIntInput()
{
    string input;
    int num = 0;


    do
    {
        getline(cin, input);

        input.erase(remove(input.begin(), input.end(), ' '), input.end());

        if (!isInt(input))
        {
            cout << "ERR. Please enter a valid integer." << endl;
        }

    } while (!(isInt(input)));



    num = atoi(input.c_str());

    return num;
}

/******************************************************
 returnString() takes in a string as input, and utilizies a
 do/while loop to get input from user using getline(),
 and first removes any blank spaces or periods from the
 input. Checks to ensure user cannot enter a blank string.
 ******************************************************/
std::string returnString()
{
    string input;

    do
    {
        getline(cin, input);

        input.erase(remove(input.begin(), input.end(), ' '), input.end());
        /*
         if (!isInt(input))
         {
         cout << "ERR. Please enter a valid integer." << endl;
         }
         */
        if (input.empty())
        {
            cout << "ERR. You entered an empty string." << endl;
        }

    } while (input.empty());

    return input;
}


/******************************************************
isInt() takes in a string as an input, and iterates
 through the length of the input, and does an if check at
 each index using the isdigit() function to verify each
 index in the string is a digit. If so, the funtion returns
 true.
******************************************************/
bool isInt(string input)
{
    if (input.empty())
    {
        return false;
    }

    for (unsigned int i = 0; i < input.size(); i++)
    {
        if (!(isdigit(input[i])))
        {
            return false;
        }
    }

    return true;
}

/******************************************************
isInRange() takes in a number, minimum number and maximum
 number. Compares the number to ensure it is smaller than the
 maximum and larger than the minimum. If either of these
 comparisions fail, the function returns false, indicating
 that number is not within a given range.
******************************************************/
bool isInRange(int num, int min, int max)
{
    if (num < min)
    {
        cout << "Please enter an integer greater than " << min << endl;
        return false;
    } else if (num > max)
    {
        cout << "Please enter an integer less than " << max << endl;
        return false;
    }
    return true;
}

/*
    Program that allows a user to enter a string consisting solely of letters.
    Author: Yan
*/

#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

bool ValidInput(const string& str, size_t index)
{
    if (index == str.length())
    {
        return true;
    }
    if (!((str[index]>='a' && str[index]<='z')|| (str[index]>='A' && str[index]<='Z')))
    {
        return false;
    }
    return ValidInput(str, index + 1);
}
char Lowercase(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch - 'A' + 'a';
    }
    return ch;
}

bool isPalindrome(const string& str, int first, int last)
{
    if(first>=last)
    {
        return true;
    }
    if (Lowercase(str[first]) != Lowercase(str[last]))
    {
        return false;
    }
    return isPalindrome(str, first +1, last -1);
}
int main()
{
    try{
        cout << "Enter a word (letters only, no spaces, numbers, or special characters): ";
        string input;
        getline(cin, input);

        if(!ValidInput(input, 0))
        {
            throw invalid_argument("Invalid input. Please enter a word with letters only.");
        }

        bool palindrome = isPalindrome(input, 0, input.length()-1);

        if(palindrome)
        {
            cout << "The entered word is a palindrome." << endl;
        }
        else
        {
            cout << "The entered word is not a palindrome." << endl;
        }
    }
    catch(const exception& e)
    {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}
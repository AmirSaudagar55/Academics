/*
A palindrome is a string of character that‘s the same forward and backward. Typically,
punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a droop”
is a palindrome, as can be seen by examining the characters “poor danisina droop” and
observing that they are the same forward and backward. One way to check for a
palindrome is to reverse the characters in the string and then compare with them the
original-in a palindrome, the sequence will be identical. Write C++ program with
functions
    a) To print original string followed by reversed string using stack
    b) To check whether given string is palindrome or not
*/
#include <iostream>
using namespace std;
#define siz 50

class Stack{
    public:
    int top;
    char arr[siz];

    Stack()
    {
        top = -1;
    }

    void push(char c) {
        if(top >= siz)
        {
            cout<<"Stack is overflow"<<endl;
        }
        else
        {
            arr[++top] = c;
        }
    }  

    char pop()
    {
        if(top == -1)
        {
            cout<<"Stack is underflow"<<endl;
        }
        else{
            return arr[top--];
        }
    }

    void display()
    {
        for(int i =top; i>=0; i--)
        {
            cout<<arr[i]<<endl;
        }
    }

};


int main()
{
    Stack s;
    string original;
    string str;
    cout<<"Enter a string : ";
    getline(cin,str);

    for(int i=0; i<=str.size(); i++)
    {
        char ch = str[i];

        if(ch >= 'a' and ch<='z')
        {
            ch = (char)(ch - 'a' + 'A');
        }
        if(ch >='A' and ch <= 'Z')
        {
            s.push(ch);
            original.push_back(ch);
        }
    }
    
    cout<<"Original string : "<<original<<endl;

    string rev;
    while(s.top != -1)
    {
        rev.push_back(s.pop());
    }
    cout<<"Reversed string : "<<rev<<endl;

    bool ispalindrome = true;
    for(int i =0; i< original.size(); i++)
    {
        if(original[i]!=rev[i])
        {
            ispalindrome = false;
            break;
        }
    }

    cout<<"' "<<str<<" ' "<<"is"<<(ispalindrome? " ":" not ")<<"a"<<" Palindrome"<<endl; 

}
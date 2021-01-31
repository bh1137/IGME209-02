// HelloWorld_Hawke.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


int main()
{
    //Prints out "hello world"
    std::cout << "Hello World!\n";

    //Integers for the second part of the Practice Exercise...
    //Letter 'A'
    const int DecemberDays = 31;
    const int secondsInMinute = 60;
    const int minutesInHour = 60;
    const int hoursInDay = 24;
    int decemberSeconds = ((secondsInMinute * minutesInHour) * hoursInDay) * DecemberDays;
    //print out the answer
    std::cout << "The number of seconds in December is..." << decemberSeconds << std::endl;

    //Letter 'B'
    double radius = 6.2;
    double pi = 3.14;
    double area = pi * (radius * radius);
    double finalAnswer = round(area*10)/10;
    //print out the answer
    std::cout << finalAnswer << std::endl;

    //Letter 'C'
    int a = 5;
    int b = 6;
    double divisionAnswer = (a / b);
    //print out the answer
    std::cout << divisionAnswer << std::endl;
    //Explaining 'C'
    //If you try to divide two integers, it does not produce a double, but it truncates. The answer would have been .833; it it was rounded,
    //if would have been 1, but the final answer ended up being 0. 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

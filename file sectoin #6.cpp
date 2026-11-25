// file sectoin #6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    ofstream out("grades.txt");

    int x;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter grade: ";
        cin >> x;
        out << x << endl;
    }

    out.close();

    ifstream in("grades.txt");

    cout << "\nGrades before deletion:\n";

    while (in >> x)
    {
        cout << x << endl;
    }

    in.close();

    int del;

    cout << "\nEnter grade to delete: ";
    cin >> del;

    in.open("grades.txt");
    ofstream temp("temp.txt");
    while (in >> x)
    {
        if (x != del)
        {
            temp << x << endl;
        }
    }

    in.close();
    temp.close();

    if (remove("grades.txt") == 0 && rename("temp.txt", "grades.txt") == 0)
    {
        cout << "\nGrade deleted successfully!\n";
    }
    else
    {
        cout << "\nError replacing file!\n";
    }

    in.open("grades.txt");

    cout << "\nGrades after deletion:\n";

    while (in >> x)
    {
        cout << x << endl;
    }

    in.close();

    return 0;
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

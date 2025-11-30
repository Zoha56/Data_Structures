// Lab02-03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include< stdio.h >
#include< windows.h>
#include<fstream>
using namespace std;
struct Student
{
    int roll;
    char name[30];
    Student() :roll(0)
    {
        strcpy_s(name, "none");
    }
};
void addToStudentUnBuffered(int N)
{
    ofstream  ofs("studentdatabase.txt", ios::binary | ios::out);
    Student s;
    for (int i = 1; i < N; i++)
    {
        s.roll = i;
        ofs.write((char*)(&s), sizeof(Student));
    }
    ofs.close();
}
const int bs = 30000;
void addToStudentBuffered()
{
    for (int i = 0; i < 10000000; i += 20000)
    {
        Student s1[20000];
        for (int j = 0; j < 20000; j++)
        {
            s1[j].roll = j + 1;
        }
        ofstream  ofs("studentdatabase.txt", ios::binary | ios::out | ios::app);
            ofs.write((char*)(&s1), sizeof(Student) * 20000);
        ofs.close();
    }
}
void ReadStudentUnBuffered(int N)
{
    ifstream  ifs("studentdatabase.txt", ios::binary | ios::in);
    Student s;
    for (int i = 1; i < N; i++)
    {
        ifs.read((char*)(&s), sizeof(Student));
    }
    ifs.close();
}
void ReadStudentBuffered(int N)
{
    ifstream  ifs("studentdatabase.txt", ios::binary | ios::in);
    for (int i = 0; i < N; i += 20000)
    {
        Student s[20000];
        ifs.read((char*)(&s), sizeof(Student) * 20000);
    }
    ifs.close();
}
int main()
{

    SYSTEMTIME systime;
    cout << "\nWriting Records to File one by one";
    GetLocalTime(&systime);
    cout << endl << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;
    addToStudentUnBuffered(10000000);
 
    GetLocalTime(&systime);
    cout << endl << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;
    cout << "\nWriting Records to File buffered";
    GetLocalTime(&systime);
    cout << endl << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;
    addToStudentBuffered();
    cout << endl << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;
    cout << "\n reading Records to File buffered";
    GetLocalTime(&systime);
    cout << endl << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;
    ReadStudentBuffered(10000000);
    cout << endl << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;
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

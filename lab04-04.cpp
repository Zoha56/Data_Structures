// lab04-04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Queue.cpp"
using namespace std;
class Process {
private:
    int processId;
    string processName;
    int executionTime;
public:
    Process() {
        processId = 0;
        processName = "";
        executionTime = 0;
    }
    Process(int id, string name, int time)
    {
        processId = id;
        processName = name;
        executionTime = time;

    }
    int getId()
    {
        return processId;
    }
    string getName()
    {
        return processName;
    }
    int getExecutionTime()
    {
        return executionTime;
    }
    void setExecutionTime(int t)
    {
        executionTime = t;
    }
};
class Scheduler {
private:
    Queue<Process> q;
    int timeQuantum;
public:
    Scheduler(Process arr[], int len, int tq)
    {
        for (int i = 0; i < len; i++)
        {
            q.enqueue(arr[i]);
        }
        timeQuantum = tq;
    }
    void assignProcessor()
    {   
       
        while (!q.isEmpty())
        {
            Process p1 = q.dequeue();
            if (p1.getExecutionTime() > timeQuantum)
            {
                p1.setExecutionTime(p1.getExecutionTime() - timeQuantum);
                q.enqueue(p1);
            }
            if (p1.getExecutionTime() > timeQuantum)
            {
                cout << "Execution process for " << p1.getName() << "is 5" << endl;
            }
            else
                cout << "Execution process for " << p1.getName() << "is "<<p1.getExecutionTime() <<endl;

        }
    }
};

 int main()
    {
        Process arr[] = {
        Process(1, "notepad.exe", 20),
        Process(13, "mp3player.exe", 5),
        Process(4, "bcc.exe", 30),
        Process(11, "explorer.exe", 2)
        };

        Scheduler s(arr, 4, 5); // time quantum = 5
        s.assignProcessor();
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

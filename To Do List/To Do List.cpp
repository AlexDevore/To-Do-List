#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    char input;
    string Stask;
    vector<string> Vtask;

    ifstream List1("To-Do List.txt");
    while (getline(List1, Stask))
    {
        Vtask.push_back(Stask);
    }
    List1.close();

    while (true) {
        cout << "To-Do List" << endl;
        cout << "Enter 'A' to add a task" << endl;
        cout << "Enter 'D' to display tasks" << endl;
        cout << "Enter 'R' to remove task" << endl;
        cout << "Enter 'C' to clear all tasks" << endl;
        cout << "Enter 'E' to exit program" << endl;
        cout << "Enter input: ";
        cin >> input;
        cin.ignore();

        switch (input)
        {
        case 'A':
            cout << "Enter task: ";
            getline(cin, Stask);

            Vtask.push_back(Stask);
            break;

        case 'D':

            cout << "Displaying tasks:" << endl;
            for (int i = 0; i < Vtask.size(); ++i)
            {
                cout << i + 1 << ". " << Vtask[i] << endl;
            }
            break;

        case 'R':
        {
            cout << "Enter task to remove: ";
            getline(cin, Stask);

            auto it = find(Vtask.begin(), Vtask.end(), Stask);
            if (it != Vtask.end()) {
                Vtask.erase(it);
                cout << "Task removed." << endl;
            }
            else {
                cout << "Task not found." << endl;
            }
            break;
        }
        case 'C':
        {
            cout << "Removing all tasks: " << endl;
            Vtask.clear();
            
            
            break;
        }
        case 'E':
        {
            ofstream List2("To-Do List.txt");
            for (int i = 0; i < Vtask.size(); ++i)
            {
                List2 << Vtask[i] << endl;
            }
            List2.close();
            return 0;
        }
        default:
            cout << "Invalid input. Please enter 'A', 'D', or 'E'." << endl;
        }
    }
}
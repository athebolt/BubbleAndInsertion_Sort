//====================================
//Name: Alexander Thebolt
//Date: 03-28-2023
//Desc: Program 1 - Sorting Algorithms
//====================================

#include <iostream>
#include "Person.h"
#include "fstream"
#include "string"
#include "iomanip"
#include "time.h"
#include "chrono"

using namespace std;
using namespace std::chrono;

void readTextFile(Person[], int);

void bubbleSort(Person[], int);

void insertionSort(Person[], int);

void displayFirst(Person[]);

void displayLast(Person[], int);

int main()
{
    int selection;
    const int size = 576;
    Person person[size];

    readTextFile(person, size);

    cout << "This program is going to read a very large text file and sort it." << endl;
    cout << "Which sort would you like to perform?" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "Make your selection: ";
    cin >> selection;

    high_resolution_clock::time_point start = high_resolution_clock::now();

    if (selection == 1)
    {
        bubbleSort(person, size);
    }
    else if (selection == 2)
    {
        insertionSort(person, size);
    }

    high_resolution_clock::time_point end = high_resolution_clock::now();

    duration<double, milli> time = end - start;

    displayFirst(person);
    displayLast(person, size);

    cout << "It took: " << time.count()/1000 << " seconds" << endl;
    cout << "It took: " << time.count()/1000 / 60 << " minutes" << endl;
}

void readTextFile(Person person[], int size)
{
    ifstream inputFile;
    string fileName = "CensusSmall.txt";
    string lineOfText;

    inputFile.open(fileName);

    if (inputFile)
    {
        for (int i = 0; i < size; i++)
        {
            getline(inputFile, lineOfText);

            person[i].setName(lineOfText.substr(0, 15));
            lineOfText = lineOfText.substr(21);

            person[i].setWage(lineOfText.substr(0, 6));
            lineOfText = lineOfText.substr(8);

            person[i].setId(stoi(lineOfText.substr(0, 5)));
            lineOfText = lineOfText.substr(7);

            person[i].setDeptId(lineOfText);
        }
    }
    else
    {
        cout << "File not opened." << endl;
    }

    inputFile.close();
}

void bubbleSort(Person person[], int size)
{
    Person current;
    bool swap;

    //Passes loop

    for (int x = 0; x < size; x++)
    {
        swap = false;

        //Iteration loop

        for (int i = 0; i < size - 1; i++)
        {
            current = person[i];

            //swap
            if(current.getId() > person[i + 1].getId())
            {
                person[i] = person[i + 1];
                person[i + 1] = current;

                swap = true;
            }
        }

        //if no swaps occur, the list is sorted
        if (!swap)
        {
            return;
        }
    }
}

void insertionSort(Person person[], int size)
{
    Person current;
    Person currentSorted;

    //goes down list
    for (int x = 0; x < size; x++)
    {
        current = person[x];

        //goes down the sorted list
        for (int i = 0; i < x; i++)
        {
            currentSorted = person[i];

            //if the new person's id is less than the current person in the sorted array's id
            //then they switch. The swap will repeat until every person out of order
            //swaps in the sorted list.
            if (currentSorted.getId() > current.getId())
            {
                person[i] = person[x];
                person[x] = currentSorted;
            }
        }
    }
}

void displayFirst(Person person[])
{
    cout << "FIRST 10" << endl;
    cout << "ID                  Name                     Hourly" << endl;
    cout << "===================================================" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << left << setw(20) << person[i].getId() << left << setw(25) << person[i].getName() << person[i].getWage() << endl;
    }
}

void displayLast(Person person[], int size)
{
    cout << "LAST 10" << endl;
    cout << "ID                  Name                     Hourly" << endl;
    cout << "===================================================" << endl;
    
    for (int i = size - 10; i < size; i++)
    {
        cout << left << setw(20) << person[i].getId() << left << setw(25) << person[i].getName() << person[i].getWage() << endl;
    }
}
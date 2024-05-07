// Split Evens and Odds Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "intLinkedList.h"
int main()
{
    intLinkedList originalList;
    intLinkedList evensList;
    intLinkedList oddsList;

    int num;

    cout << "Enter integers ending with -999: ";
    cin >> num;

    while (num != -999) {
        originalList.insertLast(num);
        cin >> num;
    }

    // Split the original list into evens and odds
    originalList.splitEvensOddsList(evensList, oddsList);

    // Print the original list using iterators
    cout << "list: ";
    for (linkedListIterator<int> iter = originalList.begin(); iter != originalList.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    // Print the evens list using iterators
    cout << "evensList: ";
    for (linkedListIterator<int> iter = evensList.begin(); iter != evensList.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    // Print the odds list using iterators
    cout << "oddsList: ";
    for (linkedListIterator<int> iter = oddsList.begin(); iter != oddsList.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}


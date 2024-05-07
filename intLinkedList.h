#pragma once
#include <iostream>
#include "unorderedLinkedList.h" // Include the header file for unorderedLinkedList

using namespace std;

class intLinkedList : public unorderedLinkedList<int> {
public:
    void splitEvensOddsList(intLinkedList& evensList, intLinkedList& oddsList);
};

void intLinkedList::splitEvensOddsList(intLinkedList& evensList, intLinkedList& oddsList) {
    nodeType<int>* current = this->first; // Start from the first node of the original list

    while (current != nullptr) {
        nodeType<int>* nextNode = current->link; // Save the next node before modifying current

        // Detach the current node from the original list
        current->link = nullptr;

        if (current->info % 2 == 0) {
            // If the current node contains an even number, append it to evensList
            if (evensList.isEmptyList()) {
                evensList.first = current;
                evensList.last = current;
            }
            else {
                evensList.last->link = current;
                evensList.last = current;
            }
        }
        else {
            // If the current node contains an odd number, append it to oddsList
            if (oddsList.isEmptyList()) {
                oddsList.first = current;
                oddsList.last = current;
            }
            else {
                oddsList.last->link = current;
                oddsList.last = current;
            }
        }

        // Move to the next node in the original list
        current = nextNode;
    }

    // Reset the original list to an empty state
    this->first = nullptr;
    this->last = nullptr;
    this->count = 0;
}
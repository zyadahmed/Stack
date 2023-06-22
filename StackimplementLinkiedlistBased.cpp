#pragma once
#include <iostream>
#include "linkiedlistStack.h"
#include "linkiedlistStack.cpp"
using namespace std;

enum class Choice {
    PUSH = 1,
    POP,
    TOP,
    QUIT
};

void printChoices() {
    std::cout << "Choose Command:" << std::endl
        << "1. PUSH" << std::endl
        << "2. POP" << std::endl
        << "3. TOP" << std::endl
        << "4. QUIT" << std::endl;
}

int main() {
    linkiedlistStack<int> s1;
    char c;
   
    do {
        printChoices();
        cin >> c;
        Choice choice = static_cast<Choice>(c - '0');
        switch (choice) {
        case Choice::PUSH: {
            int value;
            cout << "Enter a value : ";
            cin >> value;
            s1.push(value);
            break;
        }
        case Choice::POP: {
            try {
                s1.pop();
            }
            catch (const std::out_of_range& e) {
                cerr << e.what() << endl;
            }
            break;
        }
        case Choice::TOP: {
            try {
                int value = s1.top();
                cout << "Top value: " << value << endl;
            }
            catch (const std::out_of_range& e) {
                cerr << e.what() << endl;
            }
            break;
        }
        case Choice::QUIT:
            cout << "Goodbye!" << endl;
            break;
        default:
            cerr << "Invalid choice!" << endl;
            break;
        }
    } while (c != 4);

    return 0;
}
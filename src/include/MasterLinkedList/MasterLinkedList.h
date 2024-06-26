#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "../Node/Node.h"
#include "../LineLinkedList/LineLinkedList.h"
using namespace std;

class MasterLinkedList
{
    Node *HEAD;
    Node *TAIL;

    bool isNotLastNode(Node *node)
    {
        return (node != nullptr);
    }

    bool isNotLastNodeByNext(Node *node)
    {
        return (node->NEXT != nullptr);
    }

public:
    MasterLinkedList()
    {
        HEAD = TAIL = nullptr;
    }

    bool isEmpty()
    {
        return (HEAD == nullptr);
    }

    void insertLine(string *words, int count)
    {
        Node *newNode = new Node;
        newNode->NEXT = nullptr;

        for (int i = 0; i < count; i++)
        {
            newNode->DATA += words[i];

            if (i != count - 1)
            {
                newNode->DATA += " ";
            }
        }

        if (isEmpty())
        {
            HEAD = TAIL = newNode;
        }
        else
        {
            TAIL->NEXT = newNode;
            TAIL = newNode;
        }
    }

    int getLinesCount()
    {
        if (isEmpty())
        {
            return 0;
        }

        int count = 0;

        Node *TEMP_HEAD = HEAD;
        while (isNotLastNode(TEMP_HEAD))
        {
            count++;
            TEMP_HEAD = TEMP_HEAD->NEXT;
        }

        return count;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "\nNo lines added yet to the linked list" << endl;
            return;
        }

        cout << "The inserted lines are:\n";

        Node *TEMP_HEAD = HEAD;
        while (isNotLastNode(TEMP_HEAD))
        {
            cout << TEMP_HEAD->DATA << endl;
            TEMP_HEAD = TEMP_HEAD->NEXT;
        }
        cout << endl;
    }

    void displayByLineIndex(int index)
    {
        int loopIndex = 0;
        bool isFound = false;

        if (isEmpty())
        {
            cout << "\nNo lines added yet to the linked list" << endl;
            return;
        }

        Node *TEMP_HEAD = HEAD;
        while (isNotLastNode(TEMP_HEAD))
        {
            loopIndex++;

            if (loopIndex == index)
            {
                cout << TEMP_HEAD->DATA;
                isFound = true;
            }

            TEMP_HEAD = TEMP_HEAD->NEXT;
        }

        if (!isFound)
        {
            cout << "\nThere is no line with index: " << index << endl;
        }

        cout << endl;
    }

    void searchByWord(string key)
    {
        bool isFound = false;

        Node *TEMP_HEAD = HEAD;
        while (isNotLastNode(TEMP_HEAD))
        {
            istringstream iss(TEMP_HEAD->DATA);
            string word;

            while (iss >> word)
            {
                if (word == key)
                {
                    isFound = true;
                    break;
                }
            }
            TEMP_HEAD = TEMP_HEAD->NEXT;
        }

        if (isFound)
        {
            cout << "\nThe word: '" << key << "' is found" << endl;
        }
        else
        {
            cout << "\nThe word: '" << key << "' is not found." << endl;
        }
    }

    void searchByWordAndLine(int lineIndex, int wordIndex)
    {
        if (getLinesCount() < lineIndex || lineIndex < 1)
        {
            cout << "The line " << lineIndex << " is not exists \n";
            return;
        }
        if (getWordsCount(lineIndex) < wordIndex || wordIndex < 1)
        {
            cout << "Wrong word number as the line " << lineIndex << " has only " << getWordsCount(lineIndex) << " words\n";
            return;
        }

        Node *TEMP_HEAD = HEAD;
        for (int i = 1; i < lineIndex; i++)
        {
            TEMP_HEAD = TEMP_HEAD->NEXT;
        }

        istringstream iss(TEMP_HEAD->DATA);
        string word;
        int count = 0;
        while (iss >> word)
        {
            count++;
            if (count == wordIndex)
            {
                cout << "The word " << wordIndex << " in line " << lineIndex << " is: " << word << endl;
                return;
            }
        }

        cout << "The word " << wordIndex << " in line " << lineIndex << " is : " << word << endl;
    }

    int getLettersCountByWordIndex(int index)
    {
        int loopIndex = 0;

        Node *TEMP_HEAD = HEAD;
        while (isNotLastNode(TEMP_HEAD))
        {
            loopIndex++;

            if (loopIndex == index)
            {
                return TEMP_HEAD->DATA.length();
            }

            TEMP_HEAD = TEMP_HEAD->NEXT;
        }

        return -1;
    }

    int getLettersCount()
    {
        int count = 0;

        Node *TEMP_HEAD = HEAD;
        while (isNotLastNode(TEMP_HEAD))
        {
            count += TEMP_HEAD->DATA.length();
            TEMP_HEAD = TEMP_HEAD->NEXT;
        }

        return count;
    }

    int getWordsCount(int lineIndex)
    {
        int count = 0;
        bool isLast = false;
        string word;
        Node *TEMP_HEAD = HEAD;

        for (int i = 0; i <= lineIndex; i++)
        {
            if (!isNotLastNode(TEMP_HEAD) + 1)
            {
                break;
                isLast = true;
            }
            TEMP_HEAD = TEMP_HEAD->NEXT;

            if (isLast)
            {
                return -1;
            }
        }

        istringstream iss(TEMP_HEAD->DATA);
        while (iss >> word)
        {
            count++;
        }
        return count;
    }
};
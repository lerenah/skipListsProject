#include "SkipList.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

SkipList::SkipList():
    head(new Node(std::make_pair("", -1), MAX_LEVEL)),
    gen(rd())
    {}

SkipList::~SkipList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->getNext(0);
        delete current;
        current = next;
    }
}

void SkipList::insert(std::pair<std::string, int> data) {
    Node* update[MAX_LEVEL];
    Node* current = head;

    for (int i = MAX_LEVEL - 1; i >= 0; i--) {
        while (current->getNext(i) != nullptr && current->getNext(i)->data.second < data.second) {
            current = current->getNext(i);
        }
        update[i] = current;
    }

    int level = 0;
    while (gen() % 2 == 0 && level < MAX_LEVEL - 1) {
        level++;
    }

    Node* newNode = new Node(data, level + 1);
    for (int i = 0; i <= level; i++) {
        newNode->setNext(update[i]->getNext(i), i);
        update[i]->setNext(newNode, i);
    }

    for (int i = 0; i <= level; i++) {
        current = newNode;
        int currentMax = data.second;

        while (current != head) {
            if (current->maxData >= currentMax) {
                break;
            }
            current->maxData = currentMax;
            current = update[i];
        }

        if (head->maxData < currentMax) {
            head->maxData = currentMax;
        }
    }
}


int SkipList::getHighestPrice() {
    Node* current = head;

    while (current->getNext(MAX_LEVEL - 1) != nullptr) {
        current = current->getNext(MAX_LEVEL - 1);
    }

    return current->maxData;
}


bool SkipList::deleteNode(std::string ticker) {
    Node* update[MAX_LEVEL];
    Node* current = head;

    for (int i = MAX_LEVEL - 1; i >= 0; i--) {
        while (current->getNext(i) != nullptr && current->getNext(i)->data.first < ticker) {
            current = current->getNext(i);
        }
        update[i] = current;
    }

    current = current->getNext(0);
    if (current != nullptr && current->data.first == ticker) {
        for (int i = 0; i < MAX_LEVEL; i++) {
            if (update[i]->getNext(i) != current) continue;
            update[i]->setNext(current->getNext(i), i);

            Node* temp = head;
            int newMaxData = temp->data.second;
            while (temp != update[i]) {
                temp->maxData = std::max(temp->data.second, temp->getNext(i) ? temp->getNext(i)->maxData : temp->data.second);
                temp = temp->getNext(i);
            }
        }
        delete current;
        return true;
    }
    return false;
}

bool SkipList::search(std::string ticker) {
    Node* current = head;
    for (int i = MAX_LEVEL - 1; i >= 0; i--) {
        while (current->getNext(i) != nullptr && current->getNext(i)->data.first < ticker) {
            current = current->getNext(i);
        }
    }
    current = current->getNext(0);
    if (current != nullptr && current->data.first == ticker) {
        return true;
    }
    return false;
}

void SkipList::print() {
    for (int i = MAX_LEVEL - 1; i >= 0; i--) {
        Node* node = head->getNext(i);
        std::cout << "Level " << i << ": ";
        while (node != nullptr) {
            std::cout << "(" << node->data.first << ", " << node->data.second << ") ";
            node = node->getNext(i);
        }
        std::cout << std::endl;
    }
}

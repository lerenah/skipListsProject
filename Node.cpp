#include "Node.h"
#include <iostream>

Node::Node(std::pair<std::string, int> data, int levels):
    data(data),
    maxData(data.second),
    next(levels, nullptr)
    {}

void Node::setNext(Node* nextNode, int level) {
    if (level >= 0 && level < next.size()) {
        this->next[level] = nextNode;
    }
}

Node* Node::getNext(int level) {
    if (level >= 0 && level < next.size()) {
        return this->next[level];
    }
    return nullptr;
}

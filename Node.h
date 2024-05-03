#ifndef NODE_H
#define NODE_H

#include <vector>
#include <map>
#include <string>

class Node {
public:
    std::pair<std::string, int> data;
    int maxData;
    std::vector<Node*> next;

    Node(std::pair<std::string, int> data, int levels);
    void setNext(Node* nextNode, int level);
    Node* getNext(int level);
};

#endif

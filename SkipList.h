#include "Node.h"
#include <random>

class SkipList {
private:
    Node* head;
    static const int MAX_LEVEL = 6;
    std::random_device rd;
    std::mt19937 gen;

public:
    SkipList();
    ~SkipList();
    void insert(std::pair<std::string, int> data);
    bool deleteNode(std::string ticker);
    bool search(std::string ticker);
    int getHighestPrice();
    void print();
};

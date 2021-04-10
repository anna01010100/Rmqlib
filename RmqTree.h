#ifndef _RMQ_TREE_H_
#define _RMQ_TREE_H_

#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

class RmqTree
{
private:
    struct RmqNode
    {
        RmqNode(int leftInterval, int rightInterval)
        {
            this->leftInterval = leftInterval;
            this->rightInterval = rightInterval;
        }

        RmqNode* left = nullptr;
        RmqNode* right = nullptr;

        int max = 0, add = 0;
        int leftInterval = 0, rightInterval = 0;
    };


public:
    RmqTree(int *arr, int size);
    ~RmqTree();

    void modify(int leftInterval, int rightInterval, int value);
    int findmax(int leftInterval, int rightInterval);
    int getElement(int index);
    void show();

private:
    void createTree(RmqNode* currentNode);
    void modifyNode(RmqNode* node, int leftInterval, int rightInterval, int value);
    int findSumNode(RmqNode* node, int leftInterval, int rightInterval, int sumadd);
    void showNode(RmqNode* node, string tab = "");
    int getElementRecursive(RmqNode* node, int sumAdd, int index);
    
private:
    int *arr = nullptr;
    int size = 0;

    RmqNode root = RmqNode(-1, -1);
};

#endif
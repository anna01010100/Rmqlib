#include "RmqTree.h"

RmqTree::RmqTree(int *arr, int size)
{
    if (arr == nullptr || size == 0)
        return;

    this->size = size;
    this->arr = new int[size];
    for (int i = 0; i < size; i++)
        this->arr[i] = arr[i];

    //Tree creation
    int leftInterval = 0, rightInterval = size - 1;
    root = RmqNode(leftInterval, rightInterval);
    createTree(&root);
}

RmqTree::~RmqTree()
{
    delete[] arr;
}

void RmqTree::createTree(RmqNode *current)
{
    if (root.leftInterval == -1 || root.rightInterval == -1)
    {
        cout << "Root is not initialized!\n";
        return;
    }

    if (current->leftInterval != current->rightInterval)
    {
        current->left = new RmqNode(current->leftInterval, (current->leftInterval + current->rightInterval) / 2);
        current->right = new RmqNode(current->left->rightInterval + 1, current->rightInterval);
        createTree(current->left);
        createTree(current->right);

        current->max = max(current->left->max, current->right->max);
    }
    else
    {
        current->max = arr[current->leftInterval];
    }
}

void RmqTree::modify(int leftInterval, int rightInterval, int value)
{
    modifyNode(&root, leftInterval, rightInterval, value);
}

int RmqTree::findmax(int leftInterval, int rightInterval)
{
    return findSumNode(&root, leftInterval, rightInterval, 0);
}

int RmqTree::getElement(int index)
{
    return getElementRecursive(&root, 0, index);
}

void RmqTree::modifyNode(RmqNode *node, int leftInterval, int rightInterval, int value)
{
    //Если это конец и мы не попадаем в диапазон
    if (node->leftInterval == node->rightInterval)
    {
        if (node->leftInterval >= leftInterval && node->rightInterval <= rightInterval)
            node->add += value;
        return;
    }

    if (leftInterval <= node->leftInterval && rightInterval >= node->rightInterval)
    {
        //Накрывает полностью
        node->add += value;
        //modifyNode(node->left, leftInterval, rightInterval, value);
    }
    //Если накрывает частично
    else if (leftInterval <= node->leftInterval || rightInterval >= node->rightInterval)
    {
        //Если накрывает левую хотя бы частично
        if (leftInterval <= node->left->leftInterval || rightInterval >= node->left->rightInterval)
            modifyNode(node->left, leftInterval, rightInterval, value);

        //Если накрывает правую хотя бы частично
        if (leftInterval <= node->right->leftInterval || rightInterval >= node->right->rightInterval)
            modifyNode(node->right, leftInterval, rightInterval, value);

        //Пересчёт поля max
        node->max = max(node->left->max + node->left->add, node->right->max + node->right->add);
    }
    else
    {
        modifyNode(node->left, leftInterval, rightInterval, value);
        modifyNode(node->right, leftInterval, rightInterval, value);
    }
}

void RmqTree::show()
{
    showNode(&root);
}

void RmqTree::showNode(RmqNode *node, string tab)
{
    cout << tab << "[" << node->leftInterval << ":" << node->rightInterval << "] -> max(" << node->max << ") add(" << node->add << ")\n";
    if (node->left != node->right)
    {
        showNode(node->left, tab + "---");
        showNode(node->right, tab + "---");
    }
}

int RmqTree::findSumNode(RmqNode *node, int leftInterval, int rightInterval, int sumadd)
{
    if (node->leftInterval == leftInterval && node->rightInterval == rightInterval)
    {
        return sumadd + node->max;
    }
    else
    {
        int res = 0;
        if (leftInterval <= node->left->rightInterval)
        {
            res = max(findSumNode(node->left, leftInterval, min(rightInterval, node->left->rightInterval),
                                  sumadd + node->left->add), res);
        }
        if (rightInterval >= node->right->leftInterval)
        {
            res = max(findSumNode(node->right, max(leftInterval, node->right->leftInterval), rightInterval,
                                  sumadd + node->right->add), res);
        }
        return res;
    }
}

int RmqTree::getElementRecursive(RmqNode* node, int sumAdd, int index)
{
    if (node->leftInterval == node->rightInterval)
        return node->max + node->add + sumAdd;

    sumAdd += node->add;
    if (node->left->leftInterval <= index && node->left->rightInterval >= index)
        return getElementRecursive(node->left, sumAdd, index);
    if (node->right->leftInterval <= index && node->right->rightInterval >= index)
        return getElementRecursive(node->right, sumAdd, index);

    return -10000000;
}
﻿#include <iostream>
#include "Rmqlib.h"
using namespace std; 


int max(int a, int b)
{
    return a > b ? a : b;
}
 
int min(int a, int b)
{
    return a < b ? a : b;
}

rmq* creatermq(int l, int r, int a[])
{
    rmq* root = new rmq;
    if (l == r) { 
        root->l = l;
        root->r = r;
        root->max = a[l]; 
        cout << root->max << " ";
        root->add = 0;
    }
    if (l < r)
    {
        root->left = creatermq(l, (l + r) / 2, a);
        root->right = creatermq((l + r) / 2 + 1, r, a);
        root->max = max(root->left->max, root->right->max);
        cout << root->max << " ";
    }
    return root;
}

void modify(rmq* root, int l, int r, int val)
{
    if (root->l == l && root->r == r) root->add += val;
    
    else
    {
        if (l <= root->left->r) modify(root->left, l, min(r, root->left->r), val);
        if (r >= root->right->l) modify(root->right, max(l, root->right->l), r, val);
        root->max = max(root->left->max + root->left->add, root -> right->max + root->right->add);
    }
}

int findmax(rmq* root, int l, int r, int sumadd)
{
    if (root->l == l && root->r == r) return sumadd + root->max;
    else
    {
        int res = 0;
     if (l <= root->left->r) res = max(findmax(root->left, l, min(r, root->left->r), sumadd + root->left->add), res);
     if (r >= root->right->l) res = max(findmax(root->right,max(l, root->right->l), r, sumadd + root->right->add), res);

        return res;
    }
}

void toMassive(rmq* root, int l, int r, int b[])
{
    if (root->l == root->r)
        b[l] = root-> max + root-> add;
    else {
        toMassive(root->left, l, r / 2, b);
        toMassive(root->right, r / 2 + 1, r, b);
    }
}


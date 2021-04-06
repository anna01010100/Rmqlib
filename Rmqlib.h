#pragma once
#ifndef RMQ_H
#define RMQ_H


int max(int a, int b);
int min(int a, int b); 
typedef struct _rmq
{
	int max, add, l, r;
	struct _rmq* left, * right;
} rmq;


rmq* creatermq(int l, int r, int a[]);

void modify(rmq* root, int l, int r, int val);

int findmax(rmq* root, int l, int r, int sumadd); 

void toMassive(rmq* root, int l, int r, int b[]); 

#endif
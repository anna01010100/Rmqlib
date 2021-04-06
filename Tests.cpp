#include "Rmqlib.h"
#include <iostream>
#include <fstream>
using namespace std; 

int main()
{
	int n, i;
	rmq* Tree;
	ifstream input("input.txt"); //creating tree 
	input >> n;

	int* a = new int[n];
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		input >> a[i];
		cout << a[i] << endl;
	}
	Tree = creatermq(0, n - 1, a);
	input.close();

	ofstream test1("test1.txt", ios_base::trunc);  //test1. Modify the part of interval and check with the .txt
	if (!test1.is_open()) cout << "cannot open the file";
	else {
		int R, L, X;
		R = 1; L = 3; X = 100;
		modify(Tree, 1, 3, 100);
		toMassive (Tree, 0, n-1, a); 
		for (int i = 0; n - 1; i++) test1 << a[i] << " ";

	}test1.close();

	ofstream test2("test2.txt", ios_base::trunc);  //test2. Modify the WHOLE interval and check with the .txt
	if (!test2.is_open()) cout << "cannot open the file";
	else {
		int Ri, Le, X;
		Ri = 0; Le = 5; X = 30;
	    modify (Tree, 0, 5, 30);
		for (int i = 0; i < n; i++)
		{
			
		}

	}test2.close();

	ofstream test3("test3.txt", ios_base::trunc); // test3. Find Max in the same interval and check with the .txt
	if (!test3.is_open()) cout << "cannot open the file";
	else {
		int Rr, Ll, value;
		Rr = 1; Ll = 3; value = 0;
		int sum;

		sum = findmax(Tree, 1, 3, 0);
		test3 << sum;
	}test3.close();


	ofstream test4("test4.txt", ios_base::trunc); // test4. Find Max in the other interval and check with the .txt 
	if (!test4.is_open()) cout << "cannot open the file";
	else {
		int Right, Left, value;
		int sum1;
		Right = 2; Left = 5; value = 0;
		sum1 = findmax(Tree, 2, 5, 0);
		test4 << sum1;
	}test4.close();

	ofstream test5("test4.txt", ios_base::trunc); // test5. Find Max and modify in the same time and check with the .txt 
	if (!test5.is_open()) cout << "cannot open the file";
	else {
		int Rig, Lef, value;
		int sum1;
		Rig = 2; Lef = 5; value = 50;
		sum1 = findmax(Tree, 2, 5, 50);
		test5 << sum1;
	}test5.close();

	ofstream test6("test6.txt", ios_base::trunc); // test6.  Find Max in the whole interval and check with the .txt 
	if (!test6.is_open()) cout << "cannot open the file";
	else {
		int Righ, left, value;
		int sum1;
		Righ = 0; left = 5; value = 50;
		sum1 = findmax(Tree, 0, 5, 50);
		test6 << sum1;
	}test6.close();

	delete[]a;
	delete[]Tree; 

}
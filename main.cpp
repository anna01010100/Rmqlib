#include "RmqTree.h"
#include <fstream>

int main()
{
    int i; 
    ifstream fin;
    fin.open("input.txt");
    int n1, l1, r1, val1;   //test1.txt- modify the part of the interval
    fin >> n1; 
    int* arr1 = new int[n1];
    fin >> l1 >> r1 >> val1; 
    for (i = 0; i < n1; i++)
    {
        fin >> arr1[i]; 
    }
    RmqTree tree(arr1, n1);
    tree.modify(l1, r1, val1);
    tree.show();
    cout << endl; 
     ofstream fout1; 
    fout1.open("test1.txt"); 
    for (i = 0; i < n1; i++)
    {
        arr1[i] = tree.getElement(i); 
        fout1 << arr1[i]<< " "; 
    } 
    delete[]arr1; 
    fout1.close(); 


    int n2, l2, r2, val2; //test2.txt- modify the whole interval
    fin >> n2;
    int* arr2 = new int[n2];
    fin >> l2 >> r2 >> val2;
    for (i = 0; i < n2; i++)
    {
        fin >> arr2[i];
    }
    RmqTree tree2(arr2, n2);
    tree2.modify(l2, r2, val2);
    tree2.show();
    cout << endl; 
    ofstream fout2;
    fout2.open("test2.txt");
    for (i = 0; i < n2; i++)
    {
        arr2[i] = tree2.getElement(i);
        fout2 << arr2[i] << " ";
    }
    delete[]arr2;
    fout2.close();
   

    int n3, l3, r3;  //test3. Find max in the part of interval
    fin >> n3;
    int* arr3 = new int[n3];
    fin >> l3 >> r3; 
    for (i = 0; i < n3; i++)
    {
        fin >> arr3[i];
    }
    RmqTree tree3(arr3, n3);
    int rez; 
    rez=tree3.findmax( l3, r3);
    tree3.show();
    cout << endl; 
    ofstream fout3;
    fout3.open("test3.txt");
    fout3 << rez; 
    delete[]arr3; 
    fout3.close();

    int n4, l4, r4;  //test4. Find max in the whole interval
    fin >> n4;
    int* arr4 = new int[n4];
    fin >> l4 >> r4;
    for (i = 0; i < n4; i++)
    {
        fin >> arr4[i];
    }
    RmqTree tree4(arr4, n4);
    int rez1;
    rez1 = tree4.findmax(l4, r4);
    tree4.show();
    cout << endl; 
    ofstream fout4;
    fout4.open("test4.txt");
    fout4 << rez1;
    delete[]arr4;
    fout4.close();
    
    int n5, l5, r5, val5;  //test5. Modify and Find max in the whole interval
    fin >> n5;
    int* arr5 = new int[n5];
    fin >> l5 >> r5>> val5;
    for (i = 0; i < n5; i++)
    {
        fin >> arr5[i];
    }
    RmqTree tree5(arr5, n5);
    tree5.modify(l5, r5, val5); 
    int rez2; 
    rez2 = tree5.findmax(l5, r5);
    tree5.show();
    cout << endl; 
    ofstream fout5;
    fout5.open("test5.txt");
    fout5 << rez2;
    delete[]arr5;
    fout5.close();

    fin.close(); 
    return 0;
}

# Binary-Search-Tree

Note: Please download the zip file for the complete code.

Given the following structure that represents the building block of a binary tree.

const int MAX_CHILD=2;

struct Node{

int index;

int data;

int child_count;

int children[MAX_CHILD];

int color; // -1(uncolored) , 1(White), 0(Black)

int bf; // balance factor

};

Write complete C program to do the following:
1. Implement a function to create two binary search trees (BST) from a file already
arranged to include BST.
Use the following file (as an example) to construct each tree.

6 (count of nodes in tree)
Index/ data/count_child/ child0…/ initial-color

![image](https://user-images.githubusercontent.com/42114538/211150477-77bb6f05-4b52-4f85-9b21-131993dc502c.png)

2. Implement an iterative function that returns the closest value in the constructed BST to an
external double value. For example the closest value to the double value= 13.67 is 14.

3. Implement a function that computes the height of any given tree.

4. Implement a function that stores the balance factor (bf) for each node in any given tree.

5. Implement a function that takes two binary search trees as parameters. Your function should
merge them using the following property: if two nodes are overlapped, then you should sum
them in a new node, otherwise you should use the none NULL node as is.

![image](https://user-images.githubusercontent.com/42114538/211150510-d852b959-1165-4433-abb9-2400cc95c51a.png)


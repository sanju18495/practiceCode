#include <bits/stdc++.h>
using namespace std;
#define long long int ll

typedef struct node
{
	char data;
	node *left,*right;
}node;

node *newNode(int data)
{
	node *temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

bool findPath(node *root,vector<int>& path,int key)
{
	if(root==NULL)
	return false;
	path.push_back(root->data);
	if(root->data==key)
	return true;
	if((root->left&&findPath(root->left,path,key))||(root->right&&findPath(root->right,path,key)))
	return true;
	path.pop_back();
	return false;
}

int findLCA(node *root,int n1,int n2)
{
	vector<int> path1,path2;
	if(!findPath(root,path1,n1)||!findPath(root,path2,n2))
	return -1;
	int i;
	for(i=0;i<path1.size()&&i<path2.size();i++)
	if(path1[i]!=path2[i])
	break;
	return path1[i-1];
}

int main()
{
	node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "\nLCA(4, 5) = " << findLCA(root, 4, 5);
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
    return 0;
return 0;
}


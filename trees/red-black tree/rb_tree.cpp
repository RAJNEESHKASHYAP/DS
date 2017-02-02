#include<iostream>
using namespace std;

struct rb_node
{
	int val;
	char c;					//c = color of node. n = no color, r = red, b = black//
	struct rb_node *left,*right,*parent;
};

class RbTree
{
	rb_node *root;
	public:
		RbTree() : root(NULL){ }
		
		rb_node * get_root()
		{
			return root;
		}
		
		void setRoot(rb_node * r)
		{
			root=r;
		}
		
		void createNode(int val)
		{
			rb_node *ptr= new rb_node;
			ptr->val=val;
			ptr->c='r';
			ptr->parent=NULL;
			ptr->left=NULL;
			ptr->right=NULL;	
			bstInsert(ptr);
		}
		
		void bstInsert(rb_node *ptr)
		{
			rb_node *r = root;
			if(r==NULL)
			{
				r = ptr;
				ptr->c='b';
				return;
			}
			while(true)
			{
				if(r->left==NULL&&r->val>ptr->val)	
				{
					r->left=ptr;
					ptr->parent=r;
					break;
				}
				else if(r->left!=NULL&&r->val>ptr->val)	r=r->left;
				else if(r->right==NULL&&r->val<ptr->val) 
				{
					r->right=ptr;
					ptr->parent=r;
					break;
				}
				else	r=r->right;
			}
			if(ptr->c==ptr->parent->c&&ptr->c=='r')
				solveRedRed(ptr);
			else
				return;	
		}
		
		void solveRedRed(rb_node *ptr)
		{								
			if(ptr->parent==ptr->parent->parent->left)							//condition to find if ptr's parent is left child of it's gand parent
			{
				if(ptr->parent->parent->right==NULL)															//ptr's uncle doe not exist.
				{
					/*check for 2 conditions. i.e. ll,rl (only 2 possible 
					cases as we have found from above that parent is left 
					child of ptr's grand parent)*/
					if(ptr==ptr->parent->left)																	//ll case
						rightRotate(ptr);
					else if(ptr==ptr->parent->right)															//rl case
						leftRightRotate(ptr);					
				}
				else if(ptr->parent->parent->right->c=='r')														//ptr's uncle is red
				{														
					ptr->parent->c='b';
					ptr->parent->parent->right->c='b';
					ptr->parent->parent->c='r';
					//make a recursive call to check ptr->parent->parent
				}
				else if(ptr->parent->parent->right->c='b')														//ptr's uncle is black
				{
					//similar to above, check for ll or rl case and rotate
					/*check for 2 conditions. i.e. ll,rl (only 2 possible 
					cases as we have found from above that parent is left 
					child of ptr's grand parent)*/
					if(ptr==ptr->parent->left)																	//ll case
						rightRotate(ptr);
					else if(ptr==ptr->parent->right)															//rl case
						leftRightRotate(ptr);					
				}
			}
			else if(ptr->parent==ptr->parent->parent->right)					//condition to find if ptr's parent is right child of it's grand parent
			{
				//~ to above, check all the conditions here also
				if(ptr->parent->parent->left==NULL)															//ptr's uncle doe not exist.
				{
					/*check for 2 conditions. i.e. rr,lr (only 2 possible 
					cases as we have found from above that parent is left 
					child of ptr's grand parent)*/
					if(ptr==ptr->parent->left)																	//lr case
						rightLeftRotate(ptr);
					else if(ptr==ptr->parent->right)															//rr case
						leftRotate(ptr);					
				}
				else if(ptr->parent->parent->left->c=='r')														//ptr's uncle is red
				{														
					ptr->parent->c='b';
					ptr->parent->parent->left->c='b';
					ptr->parent->parent->c='r';
					//make a recursive call to check ptr->parent->parent
				}
				else if(ptr->parent->parent->left->c='b')														//ptr's uncle is black
				{
					//similar to above, check for ll or rl case and rotate
					/*check for 2 conditions. i.e. ll,rl (only 2 possible 
					cases as we have found from above that parent is left 
					child of ptr's grand parent)*/
					if(ptr==ptr->parent->left)																	//lr case
						rightLeftRotate(ptr);
					else if(ptr==ptr->parent->right)															//rr case
						leftRotate(ptr);
				}
			}
		}
};

int main()
{
	
}


//Binary Search Tree
//Anter Aaron M. Custodio
//2011-42733
//B.S. Comsci

#include<iostream>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    node* parent;
    node* root;
};

void preOrder(node* &p) //preorder display
{

 if (!p ) return;
  cout<<p->data<<",";
  preOrder(p->left);
  preOrder(p->right);



}
void postOrder(node* &p) //postorder display
{

 if (!p ) return;
  postOrder(p->left);
  postOrder(p->right);
  cout<<p->data<<",";



}

void inOrder(node* &p) //inorder display
{

 if (!p ) return;
  inOrder(p->left);
  cout<<p->data<<",";
  inOrder(p->right);

}



void insert(node*&root, int key) //function that insets data to the tree.
{

node* curr = new node;
if(root==NULL) // if the tree is empty, assign root.
{

    node* newNode = new node;
    newNode->data=key;
    root=newNode;
    root->parent =NULL;
    root->left = NULL;
    root->right = NULL;

    return;
}
else
{

    if(key<root->data) // less than the root
    {
        if(root->left==NULL)
        {

            curr->data = key;
            curr->parent = root;
            root->left = curr;
            curr->left = NULL;
            curr->right=NULL;

            return;
        }
        else
        {
            curr = root->left;
            while(curr)
            {
                if(key<curr->data)
                {
                    if(curr->left==NULL)
                    {
                        node* y = new node;
                        y->data = key;
                        y->left = NULL;
                        y->right = NULL;
                        curr->left = y;
                        y->parent = curr;
                        curr = y;
                        return;
                    }
                    curr=curr->left;
                }
                else
                {
                    if(curr->right==NULL)
                    {
                        node* y = new node;
                        y->data = key;
                        y->left = NULL;
                        y->right = NULL;
                        curr->right = y;
                        y->parent = curr;
                        curr = y;
                        return;
                    }
                    curr = curr->right;
                }

            }



        }

    }
    else // larger than the root
    {
        if(root->right==NULL)
        {
            curr->data = key;
            curr->parent = root;
            root->right = curr;
            curr->left = NULL;
            curr->right=NULL;
            return;
        }
        else
        {
            curr = root->right;
            while(curr)
            {
                if(key<curr->data)
                {
                    if(curr->left==NULL)
                    {
                        node* y = new node;
                        y->data = key;
                        y->left = NULL;
                        y->right = NULL;
                        curr->left = y;
                        y->parent = curr;
                        curr = y;
                        return;
                    }
                    curr=curr->left;
                }
                else
                {
                    if(curr->right==NULL)
                    {
                        node* y = new node;
                        y->data = key;
                        y->left = NULL;
                        y->right = NULL;
                        curr->right = y;
                        y->parent = curr;
                        curr = y;
                        return;
                    }
                    curr = curr->right;

                }

            }



        }

    }




}
}

node* minimum(node* x)
{
while(x->left)
{
    x=x->left;
}
return x;
}

node* successor(node* x)
{

 node* y = new node;
 if(x->right!=NULL)
 {
    return minimum(x->right);
 }
    y=x->parent;

while(y!=NULL&&x==y->right)
{
    x=y;
    y=y->parent;
}
return y;

}


void del (node*&t)
{
if(!t) //deleting the root
{
    cout<<"\nTree is empty!";
    return;
}
int n;
node* z = t;
node* x = new node;
node* y = new node;


cout<<"\nPlease enter the number you want to delete: ";
cin>>n;

while(z)
{
if(z->data ==n)
{
    break;
}
if(n<z->data)
{
    z=z->left;
}
else
{
    z=z->right;
}

}



if(z->left==NULL&&z->right==NULL)//if the root is the only one that has value
{
    y=z;

}
else
{
    y = successor(z);
}

if(y->left!=NULL)
{
    x = y->left;
}
else
{
    x= y->right;

}

if(x!=NULL)
{
    x->parent=y->parent;
}

if(y->parent==NULL)
{

    t->root = x;

}
else
{

    if(y==y->parent->left)
    {
        y->parent->left = x;

    }
    else
    {
        y->parent->right= x;

    }
}
if(y!=z)
{
    z->data=y->data;
}
return;
}


int main()
{
int choice = 0;
node* A = new node;
A=NULL;



while(choice!=6)
{
cout<<"\n\n_____________________________";
cout<<"\n            M E N U          |\n";
cout<<"_____________________________|\n\n";
cout<<"(#) Choose what to perform:\n\n"
    <<"[1]. Insert\n"
    <<"[2]. Delete\n"
    <<"[3]. In Order Tree Walk\n"
    <<"[4]. Pre-Order Tree Walk\n"
    <<"[5]. Post-Order Tree Walk\n"
    <<"[6]. Exit\n\n";
cout<<"Your choice: ";
cin>>choice;

int x;
switch(choice)
{
    case 1:
        cout<<"\nInput the integer to be inserted\n";
        cin>>x;
        insert(A,x);
        break;
    case 2:
        del(A);
        break;
    case 3:
        cout<<"\nInOrder Traversal:  ";
        inOrder(A);
        break;
    case 4:
        cout<<"pre-Order Traversal:  ";
        preOrder(A);
        break;
    case 5:
        cout<<"\npost-Order Traversal:  ";
        postOrder(A);
        break;
    case 6:
        cout<<"\nThank You for using the program . . . Have a nice day! :)\n";
        break;
    default:
        cout<<"\nThere's no such choice in the MENU\n";
}


};


}

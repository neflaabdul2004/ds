#include<stdio.h>
#include<stdlib.h>
struct node
{	
	int data;
	struct node *lchild,*rchild;
};

void main()
{

	struct node * insert(struct node *,int);
	struct node * search(struct node *,int);

	void inorder(struct node*);
	struct node * delete(struct node*,int);
	struct node* root=0;//represent null bst

	int item,opt;
	while(1)
		{
			printf("\n 1.insert \n 2.delete \n 3.search\n 4.display \n 5.exit \n");
			printf("your option:");
			scanf("%d",&opt);
			switch(opt)
			{
				case 1 :printf("item insert:");
					scanf("%d",&item);
					root=insert(root,item);
				        break;
			        case 2 : printf("item to delete:");
			        	 scanf("%d",&item);
			        	 root=delete(root,item);
					break;
				case 3 : printf("item to search:");
					 scanf("%d",&item);
					 if(search(root,item)==(struct node *)0)
					 printf("not found..");
					 else
					 printf("found..");
					 break;
				case 4 : inorder(root);
					break;
					
				case 5 :exit(0);   
			}
		}
	}//end of main


//function to search
struct node* search(struct node *root,int data)
{
	while(root!=0 && root->data != data)
	if(data <root->data)
	root=root->lchild;
	else
	root=root->rchild;
	return root;
}

//function to insert an item
struct node *insert(struct node *root,int data)
{
	struct node * t,*par=0,*t1;
	t=(struct node * ) malloc(sizeof(struct node ));
	t->data=data;
	t->lchild= t->rchild=0;//leaf
	if(root==0)
	root=t;
	else if(search(root,data)!=0)
	printf("%d is duplicats",data);
	else
	{
		t1=root;
		while(t1 !=0)
		{
		par=t1;
		if(data<=t1->data)
		t1=t1->lchild;
		else
		t1=t1->rchild;
		}

		if(data<par->data)//inserting
		par->lchild=t;
		else
		par->rchild=t;
		}
		return root;
		}
		
//function to traverse in  inorrder

void inorder(struct node * root)
{
	if (root!=0)
	{
	inorder( root->lchild);
	printf("%d \n",root->data);
	inorder(root->rchild);
	}
}

// function to  delete a node
struct node * delete(struct node* root,int data)
{
	struct node * t=root,*par=0,*suc,*sucpar;
	while(t!=0 && t->data !=data)
	{
	par=t;
	if(data<t->data)
	t=t->lchild;
	else
	t=t->rchild;
	}
	if(t==0)
	printf("%d not found...",data);
	else
	{
	if(t->lchild==0 && t->rchild==0)//case of leaf node
	{
	if(par==0)
	root==0;
	 else if (data<par->data)
	par->lchild=0;
	else
	par->rchild=0;
	}
	else if (t->lchild==0 || t->rchild==0)//case one child
	{
	if(par==0)// root is to be deleted
	root=root->lchild==0?root->rchild:root->lchild;
	else if (data<par->data)
	par->lchild=t->lchild==0?t->rchild:t->lchild;
	else
	par->rchild=t->lchild==0?t->rchild:t->lchild;
	}

	else//case of 2children
	{
	sucpar=t;
	suc=t->rchild;
	while(suc->lchild !=0)//finding inorder successor
	{
	sucpar=suc;
	suc=suc->lchild;
	}
	t->data=suc->data;
//delete inordersearch
	if (suc->data<sucpar->data)
	sucpar->lchild=suc->rchild;
	else
	sucpar->rchild=suc->rchild;
	t=suc;
	}
	free(t);
	}
	return root;
	}



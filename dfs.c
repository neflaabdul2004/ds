#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
struct node
{// to represent vertex and edge
int data;
int status;
struct node * next, *point;
};
struct topsort//to represent vertices to topological sort
{
int n;
struct topsort * next;
};

int time;
struct node *q[10];//to maintain queue
int front=0,rear=0;//queue handling pointers
struct node*g=0;//to store graph
struct topsort * tsort=0;// to store topoligical sort order

//function to add a vertex

void addvertex(int n)
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	t->data=n;
	t->point=0;
	t->next=g;
	g=t;
}

//function to find vertex node address of a vertex

struct node* find(int n)
{
	struct node *t=g;
	while(t!=0 && t->data!=n)
	t=t->next;
	return t;
}
//function to add an edge

void addedge(int u, int v)
{ 
	struct node *v1,*v2,*t;
	v1=find(u);//vertex address
	v2=find(v);//vertex address
	t=(struct node*)malloc(sizeof(struct node));
	t->next=v1->point;
	v1->point=t;
	t->point=v2;
	return;
}

//function to print a graph

void printgraph()
{
	struct node*t1,*t2,*t3;
	printf("\n Vertex \t Edge List \n");
	t1=g;
	while(t1!=0)
	{
	printf("\n %d...\t\t",t1->data);
	t2=t1->point;
	while(t2!=0)
	{
		t3=t2->point;
		printf("%d,",t3->data);
		t2=t2->next;
		}
	t1=t1->next;
	}
}

// inserting nodes in topoligical order list at beganing

void topsorting(int n)
{
	struct topsort *z=(struct topsort *)malloc(sizeof(struct topsort));
	z->n=n;
	z->next=tsort;
	tsort=z;
}

//printing topological order list

void topsortout()
{
	while(tsort!=0)
	{
		printf("%d,",tsort->n);
		tsort=tsort->next;
	}
}

// dfs - visit

void dfs_visit(struct node *u)
{
	struct node *t,*t1;
	u->status=1;//vist vertex
	printf("%d,",u->data);
	t=u->point;
	while(t!=0)
	{
		t1=t->point;
		if(t1->status==0)//if not visted
		dfs_visit(t1);
		t=t->next;
	}
	
	topsorting(u->data);//store the node topplogicalal sort list
	return ;
}

//dfs search

void dfs (struct node *g1)
{
	
	struct node *t=g;
	while(t!=0)
	{
	t->status=0;//set as not visted
	t=t->next;
	}
	dfs_visit(g1);
	}
//enqueue opration
void enque(struct node*s)
{
	int r1=rear;
	    r1=(r1+1)%SIZE;
	    if(front==r1)
	    {
	    printf("queue is full");
	    exit(1);
	    }
	    rear=r1;
	    q[rear]=s;
 }
 
 //empty-to test queue is empty or not
 
 int emptyq()
 {
 if (front==rear)
 return 1;
 else 
 return 0;	    
}
// dequeue opration

struct node* deque()
{
	if(emptyq())
	{
	printf("empty queue");
	exit(2);
	}
front=(front+1)%SIZE;
return q[front];
}
//bfs
void bfs(struct node *s)
{
struct node *t=g,*t1,*u;
while(t!=0)
{
t->status=0;
//set all verticsas not visited

t=t->next;
}
s->status=1;//visit start vertex
printf("%d,",s->data);
enque(s);
while(!emptyq())
{
u=deque();
t=u->point;
while(t!=0)
{
t1=t->point;
if(t1->status==0)
{
printf("%d,",t1->data);
t1->status=1;
enque(t1);
}
t=t->next;
}
}
}

//main function to demonstrate grraph search and topoligical sort

 void main()
{
	addvertex(1);
	addvertex(2);
	addvertex(3);
	addvertex(4);
	addvertex(5);
	addedge(1,2);
	addedge(1,4);
	addedge(2,3);
	addedge(2,4);
	addedge(4,3);
	addedge(4,5);
	
printf("the graph is:\n");
printgraph();
printf("\n\nDFS travers:");
dfs(find(1));
printf("\n BFS traverse:");
bfs(find(1));
printf("\n topoligcal sort orders is:");
topsortout();
}
	
		




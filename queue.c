#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int que[SIZE],front=0,rear=0; // empty queue
void main()
{
	void enque(int);
	int opt,item,ans;
	int deque();
	void display();
	int search();
	while(1)
	
	{
		printf("\n 1.insert \n 2.Delete \n 3.Display \n 4.Search \n 5.exit \n");
		printf("your option:");
		scanf("%d",&opt);
		switch(opt)
		
		{
			case 1 : printf("Item to insert:");
			        scanf("%d",&item);
			        enque(item);
			        break;
			        
		       case 2 :  item =deque();
		                printf("Deleted item =%d",item);
		                break;
		         
		       case 3 :  display();
		       		break;
		       		
		       case 4 :  printf("Item to search :");
		       		scanf("%d",&item);
		       		ans= search(item);
		       		if(ans==1)
		       		printf("found...");
		       		
		       		else
		       		printf("Not found.");
		       		break;
		       		
		      case 5 :  	exit(0);
		      
                   }
          } // end of while
          
}	
	
// function to insert an item in circular queue

void enque(int data)

{
	int r1;
	r1=(rear+1)%SIZE;
	if(r1==front)
	printf("queue is full");
	else
	{
		rear=r1;
		que[rear]=data;
	}
	
	return;
}

//function to delete an item from queue

int deque()
{
	if(front==rear)
	{
		printf("empty queue");
		exit(1)	;
	}
	
	else
	{
		front=(front+1)%SIZE;
		return que[front];
	}
}

//function to display queue contents

void display()
{
	int f=front,r=rear;
	while(f!=r)
	{	
		f=(f+1)%SIZE;
		printf("%d\n",que[f]);
	}
	return;
}
//function to search

int search(int item)
{
	int f=front,r=rear;
	while(f!=r)
	{
		f=(f+1)%SIZE;
		if(que[f]==item)
		return 1;
	}
	return 0;
}	 

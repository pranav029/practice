#include<iostream>
using namespace std;				

class node{
public:
	int data;
	node *left;
	node *right;

	node (int data)
	{
		this->data=data;
		left=right=NULL;
	}
};
node *root=NULL;
#include<iostream>
using namespace std;
class stack{
	public:
	node *in;
	stack *nxt;
};
stack *top=NULL;

void push(node *temp)
{
	stack *local=(stack*)malloc(sizeof(stack));
	local->in=temp;
	local->nxt=NULL;
	if(top==NULL)
	  top=local;
	  else
	  {
		  local->nxt=top;
		  top=local; 
	  }  
}

void pop()
{
	stack *temp;
	temp=top;
	top=top->nxt;
	free(temp);
}

node* stackpeek()
{
   return top->in;
}

void stackdisplay(node* temp)
{
	push(temp);
	while(top!=NULL)
	{
		 node *loc=stackpeek();
		

		 if(loc->right!=NULL)
		    push(loc->right);

	    if(loc->left!=NULL)
		    push(loc->left);
			
			 pop();
			 node *lo=stackpeek();
		 cout<<" "<<lo->data;		
	}
}



class que{
	public:
	node *info;
	que *nxt;
};	
que *head=NULL;
que *tail=NULL;
int size=0;

void enqueue(node *info)
{
	que *temp=(que*)malloc(sizeof(que));
	temp->info=info;
	temp->nxt=NULL;
	if(head==NULL)
	{
		head=temp;
		tail=temp;
		size++;
		return;
	}
	tail->nxt=temp;
	tail=temp; 
	size++;
}

void dequeue()
{
	que *re=head;
	head=head->nxt;
	size--;
	free(re);
}

node* peek()
{
	return head->info;
}

void levelorder(node *rot)
{ 
    if(rot==NULL)
	  return;
	   enqueue(rot); 
	  while(size)
	  {
		  node *rec=peek();
		  cout<<" "<<rec->data;
          dequeue();
           if(rec->left!=NULL)
				enqueue(rec->left);		    
		   if(rec->right!=NULL)
			    enqueue(rec->right); 	     
	  }
}


node* create()
{
	  node *temp=NULL;
	   int n; 
	   cout<<"Enter the data"<<endl;
	   cin>>n;
	
	 if(n==-1)
	 	return NULL;
         //temp=(node*)malloc(sizeof(node));
         temp=new node(n);
         
	   cout<<"Enter the left data for "<<temp->data<<endl;
	   temp->left=create();
	   cout<<"Enter the right data for "<<temp->data<<endl;
	   temp->right=create();

	 return temp;
}
int max4(int temp1,int temp2)
{
	if(temp1>temp2)
		return temp1;
	else
		return temp2;
}

int height(node *temp)
{
	if(temp==NULL)
		return 0;

	return 1+max4(height(temp->left),height(temp->right));
}


void display(node *loc)
{
	if(loc==NULL)
	      return;

        display(loc->left);
		cout<<" "<<loc->data;
		display(loc->right);
		
}

void search(node *loc,int X)
{
	if(loc==NULL)
	      return;
		 if(loc->data==X)
		 {
			 cout<<"Element found"<<endl;
			 return;
		 }
        search(loc->left,X);
		search(loc->right,X);
		
}


bool isBalanced(node *temp)
{
	if(temp==NULL)
	return false;

	int l=height(temp->left);
	int r=height(temp->right);

	if(abs(l-r)<=1 && isBalanced(temp->left)  && isBalanced(temp->right))
	   return true;

	   return false;
}
void linkToArray(node *temp,int arr[],int parent)
{
	if(temp==NULL)
	return;
	if(arr[0]=='\0')
	     arr[0]=temp->data;

	linkToArray(temp->left,arr,parent+1);
	arr[(parent*2)+1]=temp->data;
	linkToArray(temp->right,arr,parent+1);
	arr[(parent*2)+2]=temp->data;
}
void iterativeInorder(node *temp)
{
	push(temp);
	while(top!=NULL)
	{
		 node *loc=stackpeek();
		 pop();

		 if(loc->right!=NULL)
		    push(loc->right);

	    if(loc->left!=NULL)          
		    push(loc->left);
			
			
		 cout<<" "<<loc->data;		
	}
}
int main()
{
	node *temp=create();
	// int arr[pow(2,height(temp))];
	display(temp);
	// int X=33;
	// int i=max(temp,X);
	cout<<endl<<"  "<<height(temp);
	cout<<endl<<isBalanced(temp);
	cout<<endl;
	// int i=0;
	// while(arr[i])
	// {
	// 	cout<<" "<<arr[i];
	// }
	// cout<<endl;
	// int array[10],k=0;
	// linkToArray(temp,array,0);
	// while(array[k]!='\0')
	// {
	// 	cout<<" "<<array[k++];
	// }
	// int h=height(temp);
	// cout<<endl<<" height of tree :- "<<h<<endl;
	// cout<<endl<<"Leve order by Recursion:"<<endl;
	// levelorder(temp);
	// cout<<endl;
	// bottomview(temp);
	return 0;
}


cp
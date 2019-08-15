#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct node
{
	int data;
	struct node *link;
};

struct node *ptr2,*header, *start,*ptr, *ptr1, *temp;	char z[200]; int ch=0,see=6/*giving a random value except 0 or 1*/;

void put();
void push();
int ins();
void rev();
void print();
int del();
void option();
void sort();
int check(char z[]);
int num(char z[]);
int flag=0;

int main()
{
	int choice; 
	int cont = 1 ;


	header = (struct node *) malloc(sizeof(struct node));

	header->data = 0;
	header->link = NULL;
	
	
	 printf("\n*****************************\nPlease choose an Option first\n*****************************\n\n#1. put  = Put on top or Insert at the end.\n#2. push = insert at buttom.\n#3. help = show all commands or options.\n");
	
	
do
{//start do loop main
if(flag==0){printf("input:");};
if(flag==1){printf("input/[Put]:");};
if(flag==2){printf("input/[Push]:");};

scanf("%s",z);

if(((z[0])<=57)&&((z[0])>=48)){see=check(z);/*printf("\n\nsee=%d\n",see);*/};

if(see==1) {
	if(flag==0){ch=1;printf("\n*****************************\nPlease choose an Option first\n*****************************\n\n#1. put  = Put on top or Insert at the end.\n#2. push = insert at buttom.\n#3. help = show all commands or options.\n");};
	if(flag==1){ch=1;put();};
	if(flag==2){ch=1;push();};
}
if((z[0]=='p')&&(z[1]=='u')&&(z[2]=='t')&&(z[3]=='\0')){ch=1;printf("\n Enter data to put on top: \n");flag=1;};// put //
if((z[1]=='u')&&(z[2]=='s')&&(z[3]=='h')&&(z[4]=='\0')){ch=1;printf("\n Enter value to push at buttom: \n");flag=2;};//push
if((z[0]=='r')&&(z[1]=='e')&&(z[2]=='v')&&(z[3]=='\0')){ch=1;rev();};//rev
if((z[0]=='s')&&(z[1]=='o')&&(z[3]=='t')&&(z[4]=='\0')){ch=1;sort();};//sort
if((z[4]=='t')&&(z[1]=='r')&&(z[2]=='i')&&(z[5]=='\0')){ch=1;if((header->link)==NULL) printf("No Data!!\nList is empty\n"); else print();};// print
if((z[0]=='d')&&(z[1]=='e')&&(z[2]=='l')&&(z[3]=='\0')){ch=1;if((header->link)==NULL) printf("No Data!!\nList is empty\n"); else del();};// del
if((z[0]=='i')&&(z[1]=='n')&&(z[2]=='s')&&(z[3]=='\0')){ch=1;ins();};// insert
if((z[0]=='h')&&(z[1]=='e')&&(z[3]=='p')&&(z[4]=='\0')){ch=1;option();};// help
if((z[0]=='e')&&(z[1]=='x')&&(z[3]=='t')&&(z[4]=='\0')){ch=1;return(0);};
if((flag==0)||(((flag==1)||(flag==2))&&(ch==0)))

{
	if((flag==0)&&(ch!=1)){printf("\nplease give a valid command or input\n\n");};
	if(flag==1){printf("\nInvalid input!\nplease give a valid command or Enter a number to Put on Top\n\n");};
	if(flag==2){printf("\nInvalid input!\nplease give a valid command or Enter a number to Push at Buttom\n\n");};
	
};
ch=0;see=6;
	
	
	
}while(strcmp(z,"exit")!=0);//end do loop main

}

void option(void)
{
printf("\n ****OPTIONS****\n");
printf("\n#1. put  = Put on top or Insert at the end.");
printf("\n#2. push = insert at buttom.");
printf("\n#3. ins  = inser at a position of your choise.");
printf("\n#4. del  = delet a data of any position of your choise.");
printf("\n#5. sort = rearrange the list into ascending order.");
printf("\n#6. rev  = reverse the list.");
printf("\n#7. print= print or display the current linked list.");
printf("\n#8. help = show all commands or options.");
printf("\n#9. exit = exit .\n\n");
};

void put(void )
{
	int data_value; 
	data_value=num(z);
	printf("Added on top\n ");
	
	temp = (struct node *) malloc(sizeof(struct node));

	ptr = header;
	while(ptr->link != NULL)
	{
		ptr = ptr->link;
	}

	temp->data = data_value;
	ptr->link=temp;
	temp->link=NULL;
}

void print(void )
{	
	printf("\nContents of the linked list are: \n");
	
	ptr = header->link;
	while(ptr!= NULL)
	{
		printf("***");
		ptr=ptr->link;
	};printf("\n");
	
	ptr = header->link;
	while(ptr!= NULL)
	{
		printf("%d ", ptr->data);
		ptr=ptr->link;
	};printf("\n");
	
	ptr = header->link;
	while(ptr!= NULL)
	{
		printf("***");
		ptr=ptr->link;
	};printf("\n");
	
	
}

void push()
{
	int value;
	printf("Added at buttom\n ");
	value=num(z);
	flag=2;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	if(header->link==NULL)
	{
		header->link=temp;
		temp->link=NULL;
	}
	else
	{
		temp->link=header->link;
		header->link=temp;
	}
	
}

int ins()
{
	char a[20];
	int n,q,c=0,pos;
	printf("To cancel insert or < ins > operation you may use < cancel > command.");
	do
	{
		printf("\nEnter the data:");
		scanf("%s",a);
		if((a[0]=='c')&&(a[1]=='a')&&(a[2]=='n')&&(a[6]=='\0'))
			{
				printf("\ninsert cancelled\n");
				return(0);
			}
			
		q=check(a);
		if(q!=1)
		{
			printf("'%s' is not a number\n",a);
		}
			
		else
		{
			n=num(a);
		}
	}while(q!=1);
	
	do
	{
		printf("enter the position:");
		scanf("%s",a);
		if((a[0]=='c')&&(a[1]=='a')&&(a[2]=='n')&&(a[6]=='\0'))
			{
				printf("\ninsert cancelled\n");
				return(0);
			}
			
		q=check(a);
		pos=num(a);
		if(q==0)
		{
			printf("'%s' is not a number\n",a);
		}
			
		if(q==1)
		{
			int count=0;
			ptr=header;
			while(ptr->link!=NULL)
			{
				count=count+1;
				ptr=ptr->link;
			}
			
			if(pos<=(count+1))
			{
				pos=num(a);
				q=1;
			}
			
			if(pos>(count+1))
			{
				q=0;
				printf("Only %d Numbers are present, enter a position between 1 and %d\n",count,(count+1));
				
			}
			
			
			
			
			
		}
		
		
		
		
	}while(q!=1);
	
	
	if(pos<=0)
	{
		printf("unable to insert\n");
	}
	
	else
	{
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	if(pos==1)
	{
		header->link=temp;
		temp->link=NULL;
	}
	else
	{
	ptr=header;
	while(ptr->link!=NULL)
	{
		c=c+1;
		ptr=ptr->link;
		if(c==pos-1)
		{
			temp->link=ptr->link;
			ptr->link=temp;
		}
	}
}
}
printf("%d added at position %d successfully.\n",n,pos);
}
	
void rev()
{
	
	if((header->link)==NULL)
		printf("No data!\ntwo or more data must be present\n\n");
	else if((((header->link)->link))==NULL)
		printf("two or more data must be present\n\n");
	else
		{
        ptr2=header;
        ptr1=header->link;
        header=header->link;
		ptr2=NULL;
 		while(header!=NULL)
        {
            header=header->link;
            ptr1->link=ptr2;
            ptr2=ptr1;
            ptr1=header;
        }
		start=(struct node*)malloc(sizeof(struct node));
		start->link=ptr2;
        header=start;
		
    	printf("The list has been reversed successfully\n");
    }
}

int del()
{
	char y[20];
	int key,p=0;
	printf("To cancel Delete or < del > operation you may use < cancel > command.");
	
	do
	{
		
			printf("\nEnter the data of the node to be deleted: ");
			scanf("%s", &y);
			if((y[0]=='c')&&(y[1]=='a')&&(y[2]=='n')&&(y[6]=='\0'))
			{
				printf("\nDelete cancelled\n");
				return(0);
			}
			else{
			p=check(y);
			if(p==1)
			{
				key=num(y);
				ptr = header;
				while((ptr->link!=NULL) && (ptr->data!=key))
				{
					ptr1=ptr;
					ptr=ptr->link;
				}
				
				if(ptr->data==key)
				{
					ptr1->link=ptr->link;
					free(ptr);
					printf("\nNode with data %d deleted.\n", key);
				}
				
				else
				{
					p=0;
					printf("\nValue %d not found. Deletion not possible.\n", key);
				}
			}		
	
			else
			{
				printf("\n '%s' is not a number. ",y);
			}
			
			}
			
			
		

	}while(p!=1);
	
	
}


void sort(void)
{
	if((header->link)==NULL)
		printf("No data!\ntwo or more data must be present\n\n");
	else if((((header->link)->link))==NULL)
		printf("two or more data must be present\n\n");
	else	
	{
	int hold;
	ptr1=header->link;
	printf("Sorting");
	while(ptr1!=NULL)
	{
		ptr2=ptr1->link;
		
		while(ptr2!=NULL)
		{
			if((ptr1->data)>(ptr2->data))
			{
				hold=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=hold;				
			}
			
			ptr2=ptr2->link;
		}
		
		ptr1=ptr1->link;
		printf(".");
		
	}
	
	printf("\nThe list has been sorted (ascending order)\n");
	
	}
	
	
}



int num(char z[])
{
	int d=0,i=0,m=1;
	while(z[i]!='\0')
	{
		i++;
	}
	
	while(i!=0)
	{
		d=d+(((z[--i])-48)*m);
		m=m*10;
	}
	return(d);
}


int check(char z[])//checks if there in any letter in the given input and returns 0 or 1
{
	int i=0,p=5,q=5;
	
	while(z[i]!='\0')
	{
		if(((z[i])>=58)||((z[i])<=47)){q=0;/*printf("l=2:i=%d,p=%d,q=%d\n",i,p,q);*/};
		i++;
	
	};
	if(q==0){p=0;};/*printf("if=1:i=%d,p=%d,q=%d\n",i,p,q);*/
	if(q==5){p=1;};/*printf("if=2:i=%d,p=%d,q=%d\n",i,p,q);*/
	//printf("output: %d",p);
	return(p);
}
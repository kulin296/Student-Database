#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct st
{
	int rn;
	char name[20];
	float per;
	struct st *next;	
}SLL;
int count_record(SLL *);
void add_record(SLL **);
void show_list(SLL *);
void del_record(SLL **);
void mod_record(SLL **);
void del_all_record(SLL **);
void reverse_list(SLL **);
void save_record(SLL *);
void sort_record(SLL *);
void exit_file(SLL *);
void main()
{
	SLL *head=0;
	char op;
	while(1)
	{
		printf("******STUDENT RECORD MENU******\n");
		printf("A:Add new record\nD:Delete a record\nS:Show the list\nM:Modify a record\nV:Save\nE:Exit\nT:Sort the list\nL:Delete all the records\nR:Reverse The list\n");
		printf("Enter your Choice: ");
		scanf(" %c",&op);
		switch(op)
		{
			case 'A': add_record(&head); break;
			case 'S': show_list(head); break;
			case 'D': del_record(&head); break;
			case 'M': mod_record(&head); break;
			case 'L': del_all_record(&head); break;
			case 'R': reverse_list(&head); break;
			case 'V': save_record(head); break;
			case 'T': sort_record(head); break;
			case 'E': exit_file(head); break; 
			default: printf("Enter valid option!\n");
		}
	}
}
void exit_file(SLL *ptr)
{
	char op;
	printf("A:Save and Exit\nB:Exit without saving\nEnter choice: ");
	scanf(" %c",&op);
	switch(op)
	{
		case 'A':
			save_record(ptr);
			exit(0);
		case 'B':
			exit(0);
	}
}
void sort_record(SLL *ptr)
{
	if(ptr==0)	
	{
		printf("No records found!\n");
		return;
	}
	int i,j,c=count_record(ptr);
	char op;
	SLL *p1,*p2,temp;
	p1=ptr;
	printf("Enter sorting option:\nA:By Roll No\nB:By Percentage\nEnter choice: ");
	scanf(" %c",&op);
	switch(op)
	{
		case 'A':
			for(i=0;i<c-1;i++)
			{
				p2=p1->next;
				for(j=0;j<c-1-i;j++)
				{
					if(p1->rn > p2->rn)
					{
						temp.rn=p1->rn;
						strcpy(temp.name,p1->name);
						temp.per=p1->per;
				
						p1->rn=p2->rn;
						strcpy(p1->name,p2->name);
						p1->per=p2->per;
				
						p2->rn=temp.rn;
						strcpy(p2->name,temp.name);
						p2->per=temp.per;
					}
					p2=p2->next;
				}
				p1=p1->next;
			}
			printf("List has been sorted!\n");
			break;
		case 'B':
			for(i=0;i<c-1;i++)
			{
				p2=p1->next;
				for(j=0;j<c-1-i;j++)
				{
					if(p1->per > p2->per)
					{
						temp.rn=p1->rn;
						strcpy(temp.name,p1->name);
						temp.per=p1->per;
				
						p1->rn=p2->rn;
						strcpy(p1->name,p2->name);
						p1->per=p2->per;
				
						p2->rn=temp.rn;
						strcpy(p2->name,temp.name);
						p2->per=temp.per;
					}
					p2=p2->next;
				}
				p1=p1->next;
			}
			printf("List has been sorted!\n");
		
	}	
}

void save_record(SLL *ptr)
{
	if(ptr==0)	
	{
		printf("No records found!\n");
		return;
	}
	SLL *p=ptr;
	FILE *fp;
	fp=fopen("student.dat","w");
	while(p)
	{
		fprintf(fp,"%d %s %f\n",p->rn,p->name,p->per);
		p=p->next;
	}
	fclose(fp);
	printf("Records has been strored in \"student.dat\" file\n");
}

void reverse_list(SLL **ptr)
{
	if(*ptr==0)
	{
		printf("No records found!\n");
		return;
	}
	int c=count_record(*ptr);
	if(c>1)
	{
		SLL **arr=malloc(sizeof(SLL *)*c);
		SLL *temp=*ptr;
	int i=0;
	while(temp)
	{
		arr[i++]=temp;
		temp=temp->next;
	}
	for(i=1;i<c;i++)
		arr[i]->next=arr[i-1];
	arr[0]->next=0;
	*ptr=arr[c-1];
	}
	printf("Reverse list is completed!\n");
}

int count_record(SLL *ptr)
{
	int c=0;
	SLL *p=ptr;
	while(p)
	{
		c++;
		p=p->next;
	}
	return c;
}
void add_record(SLL **ptr)
{
	int i;
	SLL *new,*p,*last;
	new=malloc(sizeof(SLL));
	p=*ptr;
	while (p) 
	{
        	if (p->rn == i) 
		{
            		i++;
            		p = *ptr;
        	}
		else 
            		p = p->next;
    	}
    	new->rn = i;
	printf("name and percentage: ");
	scanf("%s%f",new->name,&new->per);
	new->next=0;
	if(*ptr==0) 
		*ptr=new;
	else
	{
		last=*ptr;
		while(last->next)
			last=last->next;
		last->next=new;
	}
}

void show_list(SLL *ptr)
{
	if(ptr==0)
	{
		printf("No records found!\n");
		return;
	}
	SLL *p;
	p=ptr;
	while(p)
	{
		printf("%d %s %f\n",p->rn,p->name,p->per);
		p=p->next;
	}
}

void del_record(SLL **ptr)
{
	if(*ptr==0)
	{
		printf("No record Found!\n");
		return;
	}
	int rn,c=0;
	char op,name[20];
	SLL *p=*ptr,*prev;
	printf("How you want to delete record: \n");
	printf("A:Based on Roll no\nB:Based on name\n");
	scanf(" %c",&op);
	switch(op)
	{
		case 'A':
			printf("Enter roll no: ");
			scanf("%d",&rn);
			while(p)
			{
				if(p->rn == rn)
				{
					if(p==*ptr)
					{
						*ptr=p->next;
						free(p);
						printf("Record has been deleted!\n");
						return;
					}
					else
					{
						prev->next=p->next;
						free(p);
						printf("Record has been deleted!\n");
						return;
					}
				}
				prev=p;
				p=p->next;
			}
			printf("Roll number not found!\n ");
			break;
		case 'B':
			printf("Enter Name: ");
			scanf(" %s",name);
			while(p)
			{
				if(strcmp(p->name,name)==0)
					c++;
				p=p->next;
			}
			p=*ptr;
			if(c>1)
			{
				printf("Identical names are availabe so Please enter rollno:\n");
				while(p)
				{	
					if(strcmp(p->name,name)==0)
						printf("%d %s %f\n",p->rn,p->name,p->per);
					p=p->next;
				}
				printf("Enter Roll no: ");
				scanf("%d",&rn);
				p=*ptr;
				while(p)
				{
				if(p->rn == rn)
				{
					if(p==*ptr)
					{
						*ptr=p->next;
						free(p);
						printf("Record has been deleted!\n");
						return;
					}
					else
					{
						prev->next=p->next;
						free(p);
						printf("Record has been deleted!\n");
						return;
					}
				}
				prev=p;
				p=p->next;
			}
			printf("Roll number not found!\n ");
			}
			else
			{
			while(p)
			{
				if(strcmp(p->name,name)==0)
				{
					if(p==*ptr)
					{
						*ptr=p->next;
						free(p);
						printf("Record has been deleted!\n");
						return;
					}
					else
					{
						prev->next=p->next;
						free(p);
						printf("Record has been deleted!\n");
						return;
					}
				}
				prev=p;
				p=p->next;
			}
			printf("Name not found!\n ");
		}
			break;
	}
}

void mod_record(SLL **ptr)
{
	char op,name[20],name1[20];
	int rn,nrn,c=0;
	float f;
	SLL *p=*ptr,*q=*ptr;
	printf("Search record:\n");
	printf("A:By roll no\nB:By name\nC:By persentage\nEnter your Choice: ");
	scanf(" %c",&op);
	switch(op)
	{
		case 'A':
			printf("Enter roll no: ");
			scanf("%d",&rn);
			while(p)
			{
				if(p->rn == rn)
				{
					printf("Enter new roll no: ");
					scanf("%d",&nrn);
					while(q)
					{
						if(q->rn==nrn)
						{
							printf("This roll no is already present!\n");
							return;
						}
						q=q->next;
					}
					p->rn=nrn;
					printf("Roll no is modified!\n");
					return;
				}
				p=p->next;
			}
			printf("Roll no not found!\n");
			break;
		case 'B':
			printf("Enter Name: ");
			scanf(" %s",name);
			while(p)
			{
				if(strcmp(p->name,name)==0)
					c++;
				p=p->next;
			}
			if(c==0)
			{
				printf("Name is not found!\n");
				return;
			}
			p=*ptr;
			if(c>1)
			{
				printf("Identical names are availabe so Please enter rollno:\n");
				while(p)
				{	
					if(strcmp(p->name,name)==0)
						printf("%d %s %f\n",p->rn,p->name,p->per);
					p=p->next;
				}
				printf("Enter Roll no: ");
				scanf("%d",&rn);
				p=*ptr;
				while(p)
				{
					if(p->rn == rn)
					{
						printf("Enter new name: ");
						scanf(" %s",name1);
						strcpy(p->name,name1);
						printf("Name is modified!\n");
						return;
					}
					p=p->next;
				}
			}
			else
			{
				while(p)
				{
					if(strcmp(p->name,name)==0)
					{
						printf("Enter new name: ");
						scanf(" %s",name1);
						strcpy(p->name,name1);
						printf("Name is modified!\n");
						return;				
					}
					p=p->next;
				}
			}
		break;
		case 'C': break;
		
	}
}

void del_all_record(SLL **ptr)
{
	if(*ptr==0)
	{
		printf("No records foud\n");
		return;
	}
	SLL *del=*ptr;
	while(del)
	{
		*ptr=del->next;
		free(del);
		del=*ptr;
	}
	printf("All records deleted\n");
}

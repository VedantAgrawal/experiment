#include <stdio.h>

void push(int *a,int *top,int max_size,int item)
{
	if(*top<max_size-1)
	{
		a[++(*top)]=item;
	}
}

int pop(int* a,int* top)
{
	if(*top!=-1)
	{
		(*top)--;
		return (a[*top+1]);
	}
	else
	{
		return -99999999;
	}
}

void display(int* a,int* top)
{
	int i;
	printf("\n");
	for(i=0;i<=*top;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

int stn(char* st)
{
	int ans=0;
	int i=0;
	while(st[i]!='\0')
	{
		ans=ans*10+(st[i]-'0');
		i++;
	}
	return ans;
}

int main()
{
	setbuf(stdout, NULL);
	char st[1000];
	scanf("%[^\n]%*c",st);
	int a[1000];
	int top=-1;
	int i=0;
	int len=0;
	while(st[len]!='\0')
	{
		len++;
	}
	st[len]=' ';
	st[len+1]='\0';
	len++;
	int start=0;
	for(i=0;i<len;i++)
	{
		if(st[i]==' ')
		{
			if(i-start==1)
			{
				if(st[start]=='+')
				{
					int op1=pop(a,&top);
					int op2=pop(a,&top);
					push(a,&top,1000,op2+op1);
				}
				else if(st[start]=='-')
				{
					int op1=pop(a,&top);
					int op2=pop(a,&top);
					push(a,&top,1000,op2-op1);
				}
				else if(st[start]=='*')
				{
					int op1=pop(a,&top);
					int op2=pop(a,&top);
					push(a,&top,1000,op2*op1);
				}
				else if(st[start]=='/')
				{
					int op1=pop(a,&top);
					int op2=pop(a,&top);
					push(a,&top,1000,op2/op1);
				}
				else
				{
					char temp[2];
					temp[0]=st[start];
					temp[1]='\0';
					push(a,&top,1000,stn(temp));
				}
			}
			else
			{
				char temp[1000];
				int j;
				for(j=start;j<i;j++)
				{
					temp[j-start]=st[j];
				}
				temp[i-start]='\0';
				push(a,&top,1000,stn(temp));
			}
			start=i+1;
		}
	}
	printf("%d",a[0]);
	return 0;
}

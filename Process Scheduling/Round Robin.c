#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct proc
	{
		char pro[3];
		int burst;
	};

typedef struct process
	{
		int pid,st,ft,prior;
		int wt,tat,at,bt;
		int flag;
	}pr;
int n=3;
pr p[10];
void round_robin(int);

int main()
	{
		struct proc pc[5];
		int ch,tq,i;
		FILE *fp;
		clrscr();
		fp=fopen("rr2.txt","r");
		printf("\n\nPROCESS       BURST TIME \n");
		for(i=0;i<n;i++)
			{
				fscanf(fp,"%s",&pc[i].pro);
				fscanf(fp,"%d",&pc[i].burst);
				printf("%s",pc[i].pro);
				printf("      %d",pc[i].burst);
				printf("\n");
			}
		printf("\nwelcome to the program\n");
		printf("\n\tEnter the Time Quantum: ");
		scanf("%d",&tq);
		for(i=0;i<n;i++)
			{
				p[i].at=0;
				p[i].bt=pc[i].burst;
				p[i].pid=i;
			}
		round_robin(tq);
		getch();
	}

void round_robin(int tq)
	{
		int allterminate=0,cnt=0,i;
		int gt[30],ps[30],temp=0,pcnt=0,b[30];
		float avgtat=0.0,wt=0.0;
		for(i=0;i<n;i++)
		b[i]=p[i].bt;
		printf("\n\tGANTT CHART\n\n");
		while(allterminate<n)
			{
				for(i=0;i<n;i++)
				    {
					if(p[i].flag==0) //process incomplete
						{
							p[i].st=temp;
							cnt++;
							if(p[i].bt>=tq)//burst time > time slice
							       {
								    p[i].bt=p[i].bt-tq;
								    temp=temp+tq;
								    gt[cnt]=temp;
								    ps[pcnt]=p[i].pid;
								    pcnt++;
								}
							else
								{ //burst time < time slice
								    temp=temp+p[i].bt;
								    gt[cnt]=temp;
								    p[i].bt=0;
								    ps[pcnt]=p[i].pid;
								    pcnt++;
								}
							if(p[i].bt==0)
								{
								    allterminate++;
								    p[i].flag=1;
								    p[i].ft=temp;
								}
							if(p[i].flag==1)
								{
								     p[i].tat=p[i].ft;
								     avgtat=avgtat+p[i].tat;
								}
						}//if
				    }//for

			}//while
		printf("\n-------------------------------\n");
		for(i=0;i<pcnt;i++)
			{
				printf("\t   P%d |",ps[i]+1);
			}
		printf("\n\t0 ");
		for(i=1;i<=cnt;i++)
			{
				printf("\t %d ",gt[i]);
			}
		avgtat=avgtat/n;
		printf("\n\t** Average Turn Around Time: %f **",avgtat);
		for(i=0;i<n;i++)
			{
				b[i]=p[i].tat-b[i];
				wt=wt+b[i];
			}
		printf("\n\n***Average waiting time is %f ",wt/n);
	}

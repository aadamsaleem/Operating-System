#include<stdio.h>
#include<conio.h>

struct process
	{
		char pro[3];
		int burst;
	};

int main()
	{
		struct process p[5];
		int a[10],b[10],n,i,t[10];
		float avg=0.0,tt=0.0;
		FILE *fp;
		clrscr();
		fp=fopen("fcfs.txt","r");
		n=4;
		for(i=0;i<n;i++)
			{
				fscanf(fp,"%s",&p[i].pro);
				fscanf(fp,"%d",&p[i].burst);
				printf("%s",p[i].pro);
				printf("       %d",p[i].burst);
				printf("\n");
			}
		for(i=0;i<n;i++)
			{
				b[i]=p[i].burst;
				if(b[i]<0)
					{
						printf("\n invalid input");
						exit(0);
					}
				tt=tt+b[i]; /* calculating turn around time */
				t[i]=tt;
			}
		a[0]=0;
		for(i=1;i<n;i++)
			{
				a[i]=a[i-1]+b[i-1];
				avg=avg+a[i];
			}
		tt=tt+avg;
		tt=tt/n;
		avg=avg/n;
		printf("Turn around time: %f",tt);
		printf("\nAvg.waiting time: %f",avg);
		printf("\n-----------------------------------------\n");
		for(i=0;i<n;i++)
		printf(" | %s ",p[i].pro);
		printf("\n------------------------------------\n");
		printf("0");
		for(i=0;i<n;i++)
		printf("     %d   ",t[i]);
		getch();
	}

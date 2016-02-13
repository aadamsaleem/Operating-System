#include<stdio.h>
#include<conio.h>
#include<string.h>

struct process
	{
		char pro[3];
		int burst;
		int priority;
	};

void main()
	{
		struct process p[6];
		FILE *fp;
		char t2[3];
		int bt[10],w[10],pr[10],i,j,n,s,t,t1,t3,temp[10];
		float avg=0.0,tt=0.0;
		clrscr();
		fp=fopen("priority.txt","r");
		printf("\nPROCESS       BURST TIME   PRIORITY\n");
		for(i=0;i<5;i++)
			{
				fscanf(fp,"%s",&p[i].pro);
				fscanf(fp,"%d",&p[i].burst);
				fscanf(fp,"%d",&p[i].priority);
				printf("%s",p[i].pro);
				printf("        %d",p[i].burst);
				printf("                    %d",p[i].priority);
				printf("\n");
			}
		n=5;
		for(i=0;i<n;i++)
			{
				bt[i]=p[i].burst;
				if(bt[i]<0)
					{
						printf("\n INVALID DATA");
						exit(0);
					}
				tt=tt+bt[i];

			}
		t3=tt;
		for(i=0;i<n;i++)
		pr[i]=p[i].priority;
		for(i=0;i<n;i++)
			{
				for(j=i;j<n;j++)
				     {
					if(pr[i]>pr[j])
					     {
						   t=bt[i]; /* swaping */
						   bt[i]=bt[j];
						   bt[j]=t;
						   t1=pr[i];
						   pr[i]=pr[j];
						   pr[j]=t1;
						   strcpy(t2,p[i].pro);
						   strcpy(p[i].pro,p[j].pro);
						   strcpy(p[j].pro,t2);
					     }
				     }
			}
		w[0]=0;
		s=0;
		for(i=1;i<n;i++)
			{
				s=s+bt[i-1];
				temp[i]=s;
				w[i]=s;
				avg=avg+w[i];
			}
		tt=tt+avg; /* calculating turn around time and acerage time */
		tt=tt/n;
		avg=avg/n;
		printf("\n turn around time is : %f",tt);
		printf("\n average waiting time is : %f",avg);
		printf("\n---------------------------\n");
		for(i=0;i<5;i++)
		printf("   %s",p[i].pro);
		printf("\n-----------------------\n");
		printf("0");
		for(i=1;i<n;i++)
		printf("    %d",temp[i]);
		printf("    %d",t3);
		getch();
	}

#include<stdio.h>
#include<conio.h>
#include<string.h>

struct process
	{
		char pro[3];
		int burst;
		int arrival;
	};


void main()
	{
		struct process p[5];
		FILE *fp;
		char t3[3];
		int a[10],at[10],n,i,j,ta[4],b[10],w[10],t,t1,t2,s=0,k;
		float tt=0.0,avg=0.0;
		clrscr();
		fp=fopen("sjfarr.txt","r");
		printf("\nPROCESS           BURST TIME       ARRIVAL TIME\n");
		for(i=0;i<4;i++)
			{
				fscanf(fp,"%s",&p[i].pro);
				fscanf(fp,"%d",&p[i].burst);
				fscanf(fp,"%d",&p[i].arrival);
				printf(" %s",p[i].pro);
				printf("                  %d",p[i].burst);
				printf("                %d",p[i].arrival);
				printf("\n");
			}

		  n=4;
		  for(i=0;i<n;i++)
			{
				a[i]=p[i].burst;
				at[i]=p[i].arrival;
			}
		  for(i=0;i<n;i++)
			{
				if(a[i]<0)
					{
						printf("\ninvalid input");
						exit(0);
					}
				b[i]=0;
				tt=tt+a[i];
			}
		  k=0;
		  j=1;
		  for(i=0;i<n-1;i++)
			{
				if(a[i]!=0)
					{
						while(at[i+1]!=s)
							{
								k=i;
								for(j=0;j<i;j++)
								      {
									   if(a[i]>a[j])
									   k=j;
								      }
								a[k]=a[k]-1;
								b[k]++;
								s=s+1;
							}
					}
			}
		for(i=0;i<n;i++)
			{
				for(j=i;j<n;j++)
					{
						if(a[i]>a[j]) /* swaping */
							{
								t=a[i];
								a[i]=a[j];
								a[j]=t;
								t1=at[i];
								at[i]=at[j];
								at[j]=t1;
								t2=b[i];
								b[i]=b[j];
								b[j]=t2;
								strcpy(t3,p[i].pro);
								strcpy(p[i].pro,p[j].pro);
								strcpy(p[j].pro,t3);
							}
					}
			}
		for(i=0;i<n;i++)
			{
				w[i]=s-b[i];
				s=s+a[i];
			}
		for(i=0;i<n;i++)
			{
				w[i]=w[i]-at[i];
				avg=avg+w[i];
			}
		tt=tt+avg; /* calculating average time and turn around time */
		tt=tt/n;
		avg=avg/n;
		printf("\nturn around time is %f",tt);
		printf("\navg waiting time is %f\n",avg);
		for(i=0;i<n;i++)
		printf(" %s |",p[i].pro);
		getch();
	}

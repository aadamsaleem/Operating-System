#include<stdio.h>
#include<conio.h>
#include<string.h>

struct process
	{
		char pro[3];
		int burst;
	};

void main()
	{
		struct process p[5];
		FILE *fp;
		char t1[3];
		int w[10],b[10],n,i,j,k=0,t,temp1[10],t2;
		float avg=0.0,tt=0.0;
		clrscr();
		fp=fopen("sjf.txt","r");
		printf("\nPROCESS    BURST TIME\n");
		n=4;
		for(i=0;i<n;i++)
			{
				fscanf(fp,"%s",&p[i].pro);
				fscanf(fp,"%d",&p[i].burst);
				printf("%s",p[i].pro);
				printf("     %d",p[i].burst);
				printf("\n");
			}
		for(i=0;i<n;i++)
			{
				b[i]=p[i].burst;
				if(b[i]<0)
					{
						printf("\n Invalid input");
						exit(0);
					}
				tt=tt+b[i];
			}
		t2=tt;
		for(i=0;i<n;i++)
			{
				for(j=i;j<n;j++)
					{
					       if(b[i]>b[j])
							{
							    t=b[i]; /* swaping */
							    b[i]=b[j];
							    b[j]=t;
							    strcpy(t1,p[i].pro);
							    strcpy(p[i].pro,p[j].pro);
							    strcpy(p[j].pro,t1);
							}
					}
			}
		w[0]=0;
		k=0;
		for(i=1;i<n;i++)
			{
				w[i]=w[i-1]+b[i-1]; /* calculating average time */
				temp1[k]=w[i];
				k++;
				avg=avg+w[i];
			}
		tt=tt+avg;/* calculating turn around time */
		tt=tt/n;
		avg=avg/n;
		printf("\n Turn Aound Tme: %f",tt);
		printf("\n Average Waiting Time: %f",avg);
		printf("\n------------------------------\n");
		for(i=0;i<n;i++)
		printf("  %s|",p[i].pro);
		printf("\n--------------------------------\n");
		printf("0");
		for(i=0;i<n-1;i++)
		printf("    %d",temp1[i]);
		printf("     %d",t2);
		getch();
	}

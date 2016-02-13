#include<stdio.h>
#include<conio.h>

int n,page[20],f,fr[20],i;

struct pages
	{
		int pagenos;
	};


void display()
	{
		printf("\n");
		for(i=0;i<f;i++)
			{
				if(fr[i]!=-1)
				printf("%d|",fr[i]);
				else
				printf(" |");
			}
	}


void request()
	{
		struct pages p[30];
		FILE *fp;
		fp=fopen("optimal.txt","r");
		printf("\n          *****WELCOME TO THE OPTIMAL PAGE REPLACEMENT PROGRAM****\n");
		printf("\nENTER NUMBER OF PAGES : ");
		scanf("%d",&n);
		printf("\nENTER NUMBER OF FRAMES : ");
		scanf("%d",&f);
		// printf("enter no.of page no.s");
		for(i=0;i<n;i++)
			{
				// scanf("%d",&page[i]);
				fscanf(fp,"%d",&p[i].pagenos);
				page[i]=p[i].pagenos;
			}
		for(i=0;i<n;i++)
			{
				fr[i]=-1;
			}
	}


void replace()
	{
		int j,flag=0,pf=0;
		int max,lp[10],index,m;
		for(j=0;j<f;j++)
			{
				fr[j]=page[j];
				flag=1;
				pf++;
				display();
			}
		for(j=f;j<n;j++)
			{
				flag=0;
				for(i=0;i<f;i++)
					{
						if(fr[i]==page[j])
							{
								flag=1;
								break;
							}
					}
				if(flag==0)
					{
						for(i=0;i<f;i++)
						lp[i]=0;
						for(i=0;i<f;i++)
						    {
							for(m=j+1;m<n;m++)
							     {
								if(fr[i]==page[m])
								    {
									lp[i]=m-j;
									break;
								    }
							     }
						    }
						max=lp[0];
						index=0;
						for(i=0;i<f;i++)
						    {
						       if(lp[i]==0)
								{
								     index=i;
								     break;
								}
							else
								{
								      if(max<lp[i])
									 {
									     max=lp[i];
									     index=i;
									 }
								}
						    }
						fr[index]=page[j];
						pf++;
						display();
					}
			}
		printf("\nPAGE FAULTS IS %d ",pf);
	}

void main()
	{
		clrscr();
		request();
		replace();
		getch();
	}

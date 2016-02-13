#include<stdio.h>
#include<conio.h>

struct pages
{
int pagenos;
};

void main()
	{
		struct pages pg[30];
		FILE *fp;
		int q[20],p[50],c=0,c1,d,f,i,j,k=0,n,r,t,b[20],c2[20];
		clrscr();
		fp=fopen("lru1.txt","r");
		printf("\n        ****WELCOME TO THE LRU PAGE REPLACEMENT PROGRAM****\n");
		printf("\nENTER NUMBER OF PAGES : ");
		scanf("%d",&n);
		//printf("Enter the reference string:");
		for(i=0;i<n;i++)
			{
				// scanf("%d",&p[i]);
				fscanf(fp,"%d",&pg[i].pagenos);
				p[i]=pg[i].pagenos;
			}
		printf("\nENTER NUMBER OF FRAMES : ");
		scanf("%d",&f);
		q[k]=p[k];
		printf("\n\t%d\n",q[k]);
		c++;
		k++;
		for(i=1;i<n;i++)
			{
				c1=0;
				for(j=0;j<f;j++)
					{
						if(p[i]!=q[j])
						c1++;
					}
				if(c1==f)
					{
						c++;
						if(k<f)
							{
								q[k]=p[i];
								k++;
								for(j=0;j<k;j++)
								printf("\t%d",q[j]);
								printf("\n");
							}
						else
							{
								for(r=0;r<f;r++)
								   {
								       c2[r]=0;
								       for(j=i-1;j<n;j--)
									    {
										 if(q[r]!=p[j])
										 c2[r]++;
										 else
										 break;
									    }
								   }
								for(r=0;r<f;r++)
								b[r]=c2[r];
								for(r=0;r<f;r++)
								   {
									for(j=r;j<f;j++)
										{
										    if(b[r]<b[j])
										       {
											    t=b[r];
											    b[r]=b[j];
											    b[j]=t;
											}
										}
								   }
								for(r=0;r<f;r++)
								   {
									if(c2[r]==b[0])
									q[r]=p[i];
									printf("\t%d",q[r]);
								   }
								printf("\n");
							}
					}
			}
		printf("\nTHE NUMBER OF PAGE FAULTS IS %d ",c);
		getch();
	}

#include<stdio.h>
#include<conio.h>

struct pages
{
int pagenos;
};

int main()
	{
		struct pages p[30];
		FILE *fp;
		int i,j,n,a[50],frame[10],no,k,avail,count=0;
		clrscr();
		fp=fopen("fifo1.txt","r");
		printf("\n      ****WELCOME TO THE FIFO PAGE REPLACEMENT PROGRAM****\n");
		printf("\n ENTER THE NUMBER OF PAGES : ");
		scanf("%d",&n);
		//  printf("\n ENTER THE PAGE NUMBER :\n");
		for(i=1;i<=n;i++)
			{
				// scanf("%d",&a[i]);
				fscanf(fp,"%d",&p[i].pagenos);
				a[i]=p[i].pagenos;
			}
		printf("\n ENTER THE NUMBER OF FRAMES : ");
		scanf("%d",&no);
		for(i=0;i<no;i++)
		frame[i]= -1;
		j=0;
		printf("\nREFERENCE STRING\t\t\t PAGE FRAMES\n");
		for(i=1;i<=n;i++)
			{
				printf("%d\t\t\t\t\t",a[i]);
				avail=0;
				for(k=0;k<no;k++)
				if(frame[k]==a[i])
				avail=1;
				if (avail==0)
				    {
					frame[j]=a[i];
					j=(j+1)%no;
					count++;
					for(k=0;k<no;k++)
						{
							if(frame[k]!=-1)
							printf("%d\t",frame[k]);
							else
							printf("  \t");
						}
				    }
				printf("\n");
			}
		printf("PAGE FAULT IS %d",count);
		getch();
		return 0;
	}

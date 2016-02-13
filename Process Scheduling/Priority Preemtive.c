 #include<stdio.h>
 #include<conio.h>
 #include<dos.h>
 #include<alloc.h>
 
 struct Process
  {
	int p_id,arrive,burst_time,priority,wait,status,copy_burst;
  }p[10];
 
  int count(int n)
   {
	 int i,cnt=0;
	 for (i=0;i<n;i++)
	  {
		cnt=cnt+p[i].burst_time;
	  }
	 return cnt;
   }
 
  void accept(int n)
   {
	 int i;
 
	 for (i=0;i<n;i++)
	  {
		p[i].p_id=i;
		clrscr();
		printf("\n\n\t ********** Priority Scheduling With Preemption **********");
		printf("\n\n Enter information for process %d",p[i].p_id);
		if (p[i].p_id==0)
		{
			p[i].arrive=0;
		}
		else
	 	{
	   		printf("\n\n Enter arrival time : ");
	   		scanf("%d",&p[i].arrive);
	 	}
	 	printf("\n\n Enter burst time : ");
	 	scanf("%d",&p[i].burst_time);
	 	printf("\n Enter priority : ");
	 	scanf("%d",&p[i].priority);
	 	p[i].copy_burst=p[i].burst_time;
	 	p[i].status=0;
	 	p[i].wait=0;
	  }
   }
 
  void display(int n)
   {
	 int i;
	 clrscr();
	 printf("\n\n\t ********** Priority Scheduling With Preemption **********");
	 printf("\n\n \t\t ********** Process Waiting Time **********");
	 printf("\n\n Process Id  Arrival Time    Burst Time  Priority   Waiting Time     Status \n");
	 for (i=0;i<n;i++)
	  {
		printf("\n\t %d \t   %d    \t %d \t %d \t\t %d\t\t%d",p[i].p_id,p[i].arrive,p[i].burst_time,p[i].priority,p[i].wait,p[i].status);
	  }
   }
 
   void gantt_chart(int cnt,int *gantt)
   {
	 int i;
	 clrscr();
	 printf("\n\n\t ********** Priority Scheduling With Preemption **********");
	 printf("\n\n \t\t ********** Gantt Chart **********\n");
	 //for process numbers
	 for (i=0;i<cnt;i++)
	  {
		if (i==0)
		 printf("\n\n    P%d",gantt[i]);
		else
		 {
		   if (gantt[i]!=gantt[i-1])
			{
			  	printf("  P%d",gantt[i]);
			}
			else
			{
			  	printf("  ");
			}
		  }
	   }
 
	 // for upper lines
	 printf("\n    ");
	 for (i=0;i<cnt;i++)
	  {
		if (i==0)
		 printf("__");
		else
		 {
		   if (gantt[i]!=gantt[i-1])
			{
			  	printf("  __");
			}
		   else
			{
			  	printf("__");
			}
		 }
	  }
 
	 //for lines
	 printf("\n  ||");
	 for (i=0;i<cnt;i++)
	  {
		if (i==0)
		 printf("__");
		else
		 {
		   if (gantt[i]!=gantt[i-1])
			{
			  	printf("||__");
			}
		   else
			{
			  	printf("__");
			}
		 }
	  }
	  printf("||");
 
	  //for time
	 printf("\n");
	 for (i=0;i<cnt;i++)
	  {
		if (i==0)
		 printf("  00  ");
		else
		 {
		   if (gantt[i]!=gantt[i-1])
			{
			  	printf("%0.2d  ",i);
			}
		   else
			{
			  	printf("  ");
			}
		 }
	  }
	  printf("%2d",cnt);
   }
 
  int minjob(int n,int ex_time)
   {
	 int i,min,pr;
	 min=10;
	 for (i=0;i<n;i++)
	  {
		if( (p[i].status!=1) && (p[i].priority<min) && (p[i].arrive<=ex_time))
	 	{
			min=p[i].copy_burst;
			pr=i;
	 	}
	  }
	  return pr;
   }
 
  void wait_time(int n,int min,int exe)
   {
	 int i;
	 for (i=0;i<n;i++)
	  {
		 if( (min!=i) && (p[i].arrive<=exe) && (p[i].status!=1) )
		   {
			 p[i].wait=p[i].wait+1;
		   }
	  }
   }
 
  void schedule(int n,int cnt)
	{
	  int i,min,*gantt;
	  gantt=(int*)calloc(cnt,sizeof(int));
	  printf("\n total time : %d",cnt);
	  for (i=0;i<cnt;i++)
	   {
		 min=minjob(n,i);
		 clrscr();
		 display(n);
		 printf("\n\n \t Time : %d",i);
		 printf("\n\n \t process %d is executing...",min);
		 sleep(1);
		 p[min].copy_burst=p[min].copy_burst - 1;
		 gantt[i]=min;
		 wait_time(n,min,i);
		 if(p[min].copy_burst==0)
		  {
			p[min].status=1;
		  }
	   }
	   display(n);
	   do
		{
		  	printf("\n\n \t Execution completed ..!! Press * to continue.. ");
		}while(getch()!='*');
	   gantt_chart(cnt,gantt);
	 }
 
  void display_ave(int n)
   {
	 int i,sum=0;
	 float ave;
 
	 for (i=0;i<n;i++)
	  {
		sum=sum+p[i].wait;
	  }
	 ave = sum/n;
	 printf("\n\n\n \t Average Waiting Time : %0.2f",ave);
   }
 
  void main()
   {
	 int n,cnt;
	 clrscr();
	 printf("\n\n\t ********** Priority Scheduling With Preemption **********");
	 printf("\n\n Enter no. of processes to be executed : ");
	 scanf("%d",&n);
 
	 accept(n);
	 cnt=count(n);
	 schedule(n,cnt);
	 display_ave(n);
	 getch();
   }

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int n;
void *getdata()
{

	printf("\nEnter a number upto which you want to find prime numbers : \n");
	scanf("%d",&n);
	pthread_exit(NULL);
}

void *display(void *a)
{  sleep(5);
	int i,j,fact;
	int *b=(int *)a;
	int n=*b;
	if(n<2)
	{
		printf("\ninvalid number");
		
	}
	else
	{
	
	printf("Prime Numbers are: \n");
    for(i=1; i<=n; i++)
    {
        fact=0;
        for(j=1; j<=n; j++)
        {
            if(i%j==0)
                fact++;
        }
        if(fact==2)
            printf("%d " ,i);
    }
    pthread_exit(NULL);
}
}

int main()
{    
	pthread_t th1,th2;
	pthread_create(&th1,NULL,getdata,NULL);
    pthread_create(&th2,NULL,display,&n);	
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    
}

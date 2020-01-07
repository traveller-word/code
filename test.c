java html python 
typedef struct _value {
		int *tmp;
		int tmpi;
}value;
	
void *tfn(void *arg)
{

	//printf("num = %d\n", num);
	//打印是第几个线程
	
	value p = *((value *)arg);
	//printf("I am %dth pthread", i+1);
	//打印进程ID，线程ID
	for (int i = 0;i < 4;i++) {
			printf("%d\t", *(p.tmp + i));
	}
	printf("%dth process\n", p.tmpi);
	printf("pid = %d, tid = %ld\n", getpid(), pthread_self());
	pthread_exit(NULL);
}


int main()
{
	value st_value;
	st_value.tmp =(int *)malloc(sizeof(int) * 4);
	for (int i = 0;i < 4;i++) {
		*(st_value.tmp + i) = i + 1;
	}
	printf("\n");
	int num = 10;
	int ret = 0;
	pthread_t tid = 0;
	for (int i = 0;i < 4;i++) {
			printf("%d\t", *(st_value.tmp + i));
	}
	printf("\n");
	printf("sizeof is %d\n", sizeof(value));
	printf("sizeof is %d\n", sizeof(void *));
	for (st_value.tmpi = 0;st_value.tmpi < 50;st_value.tmpi++) {
		//函数传参采用值传递
		sleep(1);
		ret = pthread_create(&tid, NULL , tfn, (void *)&st_value);
		if (ret != 0) {
			perror("pthread_create failed");
		}
	}
	sleep(1);
	printf("main: I am main\n");
	pthread_exit(NULL);
}
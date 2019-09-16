#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

typedef struct
{
	int c_custkey;
	char c_mkgsegment[20];
}customer;

typedef struct
{
	int o_orderkey;
	int o_custkey;
	char o_orderdate[10];
}orders;

typedef struct
{
	int l_orderkey;
	double  l_extendedprice;
	char l_shipdate[10];
}lineitem;

typedef struct
{
	int l_orderkey;
	char o_orderdate[10];
	double l_extendedprice;
}result;

customer * read_data_customer()
{
	FILE *fp;
	char word;
	customer *p = NULL;
	int i;
	i = 0;
	p = (customer *)malloc(100 * sizeof(customer));
	if ((fp = fopen("/home/work/customer.txt", "r")) == NULL)
	{
		printf("1");
		return NULL;
	}
	while (!feof(fp))
	{

		fscanf(fp, "%d%c%s", &p[i].c_custkey, &word, &p[i].c_mkgsegment);
		printf("%d%c%s\n", p[i].c_custkey, word, p[i].c_mkgsegment);
		i = i + 1;
	}
	fclose(fp);
	return p;
}

orders *read_data_order()
{
	FILE *fp;
	char word1;
	char word2;
	int a;
	orders *p;
	int i;
	i = 0;
	p = (orders *)malloc(4000 * sizeof(orders));
	if ((fp = fopen("/home/work/orders.txt", "r")) == NULL)
	{
		return NULL;
	}
	while (!feof(fp))
	{
		fscanf(fp, "%d%c%d%c%s", &p[i].o_orderkey, &word1, &a, &word2, &p[i].o_orderdate);
		printf("%d%c%d%c%s\n", p[i].o_orderkey, word1, a, word2, p[i].o_orderdate);
		i = i + 1;
	}
	fclose(fp);
	return p;
}

lineitem *read_data_lineitem()
{
	FILE *fp;
	char word1;
	char word2;
	lineitem *p;
	int i;
	i = 0;
	p = (lineitem *)malloc(4000 * sizeof(lineitem));
	if ((fp = fopen("/home/work/lineitem.txt", "r")) == NULL)
	{
		return NULL;
	}
	while (!feof(fp))
	{
		fscanf(fp, "%d%c%lf%c%s", &p[i].l_orderkey, &word1, &p[i].l_extendedprice, &word2, &p[i].l_shipdate);
		printf("%d%c%lf%c%s\n", p[i].l_orderkey, word1, p[i].l_extendedprice, word2, p[i].l_shipdate);
		i = i + 1;
	}
	fclose(fp);
	return p;
}

result *select(customer *cus, orders *ord, lineitem *lin,char *order_date,char *ship_date)
{
	result *flag1=NULL;
	result *flag2=NULL;
	int control = 0;
	int control_1 = 0;
	int control_2 = 0;
	int a, b, c;
	flag1 = (result *)malloc(10000 * sizeof(result));
	flag2 = (result *)malloc(10000 * sizeof(result));
	for (a = 0; a < 100; a++)
	{
		for (b = 0; b < 4000; b++)
		{
			for (c = 0; c < 1000; c++)
			{
				if ((cus[a].c_custkey == ord[b].o_custkey) && (ord[b].o_orderkey == lin[c].l_orderkey) 
					      && (strcmp(ord[b].o_orderdate, order_date) < 0)&&(strcmp(lin[c].l_shipdate,ship_date)>0))
				{
					printf("%d,%s,%lf\n", lin[c].l_orderkey, ord[b].o_orderdate, lin[c].l_extendedprice);
					flag1[control].l_orderkey = lin[c].l_orderkey;
					strcpy(flag1[control].o_orderdate, ord[b].o_orderdate);
					flag1[control].l_extendedprice = lin[c].l_extendedprice;
					control = control + 1;
				}
			}
		} 
	}
	for (control_1 = 0; control_1 < control; control_1++)
	{
		if (control_1 == 0)
		{
			flag2[control_2].l_extendedprice = flag1[control_1].l_extendedprice;
			flag2[control_2].l_orderkey = flag1[control_1].l_orderkey;
			strcpy(flag2[control_2].o_orderdate, flag1[control_1].o_orderdate);
		}
		if (control_1 != 0 && flag1[control_1].l_orderkey == flag1[control_1-1].l_orderkey)
		{
			flag2[control_2].l_extendedprice = flag2[control_2].l_extendedprice + flag1[control_1].l_extendedprice;
		}
		if (control_1 != 0 && flag1[control_1].l_orderkey != flag1[control_1 - 1].l_orderkey)
		{
			control_2 = control_2 + 1;
			flag2[control_2].l_extendedprice = flag1[control_1].l_extendedprice;
			flag2[control_2].l_orderkey = flag1[control_1].l_orderkey;
			strcpy(flag2[control_2].o_orderdate, flag1[control_1].o_orderdate);
		}
	}
	return flag2;
}

int run_shell(char *a,char *b,char*c,int d)
{
	int i;
	customer *cus;
	orders *ord;
	a = read_data_customer();
	b = read_data_order();
	c = read_data_lineitem();
	int limit=d;
	result *run=NULL;
	run=select(cus,ord,lin,b,c);
	printf("l_orderkey|o_orderdate|revenue\n");
	for(i=0;i<limit;i++)
	{
		printf("%d|%s|%lf\n", flag2[control_1].l_orderkey, flag2[control_1].o_orderdate, flag2[control_2].l_extendedprice);
	}
	return 0;
}
int main(int argc,char **argv)
{
	
	//char order_date[] = "1995-03-27";
	//char ship_date[] = "1995-03-27";
	int i;
	int a;
	unsigned int n=atoi(argv[4]);
	for(i=1;i<limit;i++)
	{
		unsighed int t=atoi(argv[4*i+4];
		a=run(argv[4*i+1],argv[4*i+2],argv[4*i+3],t);
	}
	return 0;
}

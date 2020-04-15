#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using  namespace  std;
#define MAXBIT      100
#define MAXVALUE  10000
#define MAXLEAF     30
#define MAXNODE    MAXLEAF*2 -1
typedef struct            //哈夫曼编码结构体
{
    int bit[MAXBIT];
    int start;
} HCodeType;    
typedef struct            //哈夫曼树结构体
{        
    double   weight;
    int parent;
    int lchild;
    int rchild;
    char  value;
} HNodeType;      

typedef struct node    //哈夫曼编码结构体，用于当中间变量，避免混淆
{
      int bit[MAXBIT];
	  int start;
}coding;

char     str[200]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 //字符集来源
char     dtr[200];//输入的初始化字符
char     ptr[200];//中间变量
char     jd;//用于交互的判断
double   vc[30]={186,64,13,22,32,103,21,15,47,571,5,32,20,57,63,15,1,48,51,80,23,7,18,2,16,11}; //字符集中各字符的权值（频度）
void   HuffmanTree (HNodeType HuffNode[MAXNODE],  int n)
{
//用于构建哈夫曼树
    int i, j;double   m1, m2;int   x1, x2;
    for (i=0; i<2*n-1; i++)
    {
        HuffNode[i].weight = 0;//初始化 各节点权值位0
        HuffNode[i].parent =-1;//-1代表空，双亲节点为空
        HuffNode[i].lchild =-1;//-1代表空，左孩子节点为空
        HuffNode[i].rchild =-1;//-1代表空，右孩子节点为空
        HuffNode[i].value=i; //i对应字符串str[i]的字符，赋予字符
} 

    for (i=0; i<n; i++)//赋予各节点权值（完成初始化）
    {
        scanf ("%lf", &HuffNode[i].weight);//对各字符赋予权值
    }  
    for (i=0;i<n-1; i++)//构建哈夫曼树    {
        m1=m2=MAXVALUE;  
//x1和m1用于查找记录权值最小，x2和m2用于查找记录权值其次小
        x1=x2=0;
        for (j=0; j<n+i; j++)
        {
            if (HuffNode[j].weight < m1 && HuffNode[j].parent==-1)//找到权值最小的节点并标记             {
                m2=m1;
                x2=x1;
                m1=HuffNode[j].weight;
                x1=j;
            }
            else if (HuffNode[j].weight < m2 && HuffNode[j].parent==-1)//找到权值其次小的节点并标记 
            {
                m2=HuffNode[j].weight;
                x2=j;
            }
        } 
        HuffNode[x1].parent  = n+i;//赋予两个最小值同一个parent节点
        HuffNode[x2].parent  = n+i;
        HuffNode[n+i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
//求出parent节点权值，并放回查找中
        HuffNode[n+i].lchild = x1;//赋予parent节点左子节点
        HuffNode[n+i].rchild = x2;//赋予parent节点右子节点
    } 

} 
int main()
{
	coding code[MAXBIT];
    HNodeType HuffNode[MAXNODE];    
    HCodeType HuffCode[MAXLEAF],  cd;    
    int i, j, c, p, n=26,x=0，tn,er=0,pt,h,b;//x,tn，er=0用于交互判断,pt用于计算输入密码长度
	char inputing[MAXBIT];//输入要加密的数据

    printf("************************************************************************************************************************");
	printf("\n\n                                            请输入初始化字符大小：");//交互
	while(er==0)
	{
	scanf("%d",&tn);
	if(tn<=0||tn>26)
	{
	printf("\n\n                                       错误,请输入初始化字符大小：");
	 er=0;
	
	}
	else
		er=1;
	}
	printf("************************************************************************************************************************");
	printf("\n\n                                            请输入要初始化的字符：");
	cin>>dtr;
	
	if(tn!=strlen(dtr))
	{
		printf("\n\n                         	        错误,请输入初始化的字符：");
		er=0;
		cin>>dtr;
	}
	//输入 包含两个自检
	printf("************************************************************************************************************************");
	printf("                                  输入完成，是否显示哈夫曼编码(Y/N)");

	    HuffmanTree (HuffNode, n);
    for (i=0; i < n; i++)
    {
        cd.start = n-1; 哈夫曼编码起点从后开始倒叙输入，记录哈夫曼码的头
        c = i;     c对应字符串中字符的位置
        p = HuffNode[c].parent;//从根节点开始向下遍历
        while (p != -1) 
        {
            if (HuffNode[p].lchild == c)//若为左节点添0，右节点添1
                cd.bit[cd.start] = 0;
            else
                cd.bit[cd.start] = 1;
            cd.start--;     
            c=p;
            p=HuffNode[c].parent;  
        } 
        for (j=cd.start+1; j<n; j++)
        {
            HuffCode[i].bit[j] = cd.bit[j];将编码从中间变量转移并存储
			
        }
		
        HuffCode[i].start = cd.start;将起始头节点也记录过来
		
    }

	cin>>jd;//输入交互的字符
	if(jd=='Y')
	{

		for(b=0;b<strlen(dtr);b++)
		{
			
printf ("                                            您的字符%c哈夫曼编码为: ", dtr[b]);
		for (i=0; i<n; i++) //输出初始化字符的哈夫曼编码
    {
       
		if(dtr[b]==str[i])
		{
        for (j=HuffCode[i].start+1; j < n; j++)
        {
            printf ("%d", HuffCode[i].bit[j]);
        }

        printf ("\n");
		}
    }
		}

	}
	printf("************************************************************************************************************************");
	printf("\n\n\n\n\n\n\n\n\n\n                                            请输入加密文件：");
    HuffmanTree (HuffNode, n);
    for (i=0; i < n; i++)//构建哈夫曼编码，与之前的一样
    {
        cd.start = n-1;
        c = i;
        p = HuffNode[c].parent;
        while (p != -1) 
        {
            if (HuffNode[p].lchild == c)
                cd.bit[cd.start] = 0;
            else
                cd.bit[cd.start] = 1;
            cd.start--;     
            c=p;
            p=HuffNode[c].parent;  
        } 
        for (j=cd.start+1; j<n; j++)
        {
            HuffCode[i].bit[j] = cd.bit[j];
			
        }
		
        HuffCode[i].start = cd.start;
		
    }

	
	for(i=0;;i++)//输入加密数据并加密
	{
	    scanf("%c",&inputing[i]);//输入加密数据
		if(inputing[i]=='\n')
			break;
		for(j=0;j<n;j++)
		{
			if(inputing[i]==str[j]){//对照内置的字符集，找到对应的哈夫曼编码进行加密
			    for (c=HuffCode[j].start+1; c < n; c++)
        {
			if(c==HuffCode[j].start+1)
			{
				code[i].start=c;
			}
               code[i].bit[c] =HuffCode[j].bit[c];
			      
        }
			     break;
			}
			
		}
	}
	printf("                                            加密成功！请记住密码\n");
	printf("                                   ");
	for(c=0;c<i;c++){
		
		for(j=code[c].start;j<n;j++)
			printf("%d",code[c].bit[j]);//输出密码
		    printf("*");
	
	}
	printf("\n                                            是否破译哈夫曼编码(Y/N)");
	cin>>jd;
	if(jd=='Y')//交互判断
	{
		printf("\n\n                                            请输入您要破解的密码：");
		cin>>ptr;//输入要翻译的密码
		pt=strlen(ptr);//记录密码长度
	
		h=0;
		for(c=0;c<tn;c++)//根据密码转化成相应的哈夫曼编码
		{
		while(ptr[h]!='*')
		{
		for(j=code[c].start;j<n;j++)
		{
			code[c].bit[j]=ptr[h]-48;//为解决字符和数字转换间产生的误差
		    h=h+1;
		}
		    
		}
		    
	
	    }



	printf("\n\n                                            密码破译为：");
	for(c=0;c<i;c++)//根据哈夫曼编码搜索对应的字符
	{
		for(j=0;j<n;j++)
		{
			if(code[c].start==HuffCode[j].start+1){
			for(p=code[c].start; p < n; p++)
        {
			if(HuffCode[j].bit[p]!=code[c].bit[p]){//根据哈夫曼吗与密码相比对
			     x=1;//存在不同则进行标记，1为不同，不输出
				 break;
			}
        }
			if(x==0){
			   printf("%c",str[j]);//输出解密对应的字符
			     break;
			}
			x=0;
		}
		}
	}
	}
	printf("\n\n                                            运行完毕");

    return 0;
}
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using  namespace  std;
#define MAXBIT      100
#define MAXVALUE  10000
#define MAXLEAF     30
#define MAXNODE    MAXLEAF*2 -1
int jk=0;
typedef struct
{
    int bit[MAXBIT];
    int start;
} HCodeType;    
typedef struct
{
    double   weight;
    int parent;
    int lchild;
    int rchild;
    char  value;
} HNodeType;      

char     str[100];
void   HuffmanTree (HNodeType HuffNode[MAXNODE],  int n)
{
	char arr[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	double   vc[26]={186,64,13,22,32,103,21,15,47,571,5,32,20,57,63,15,1,48,51,80,23,7,18,2,16,11};
    int i, j;double   m1, m2;int   x1, x2;
	int temp[26],t1=0,t2=0;
	for(t1=0;t1<n;t1++){
		for(t2=0;t2<26;t2++){//对字符集初始化
			if(arr[t2]==str[t1]){
			      temp[t1]=t2;
				  break;
			}
		
		}
	
	}
    for (i=0; i<2*n-1; i++)//对节点初始化
    {
        HuffNode[i].weight = 0;
        HuffNode[i].parent =-1;
        HuffNode[i].lchild =-1;
        HuffNode[i].rchild =-1;
        HuffNode[i].value=i; 
    } 
    for (i=0; i<n; i++)
    {
        HuffNode[i].weight=vc[temp[i]];
    } 
    for (i=0; i<n-1; i++)
    {
        m1=m2=MAXVALUE;  
        x1=x2=0;
        for (j=0; j<n+i; j++)
        {
            if (HuffNode[j].weight < m1 && HuffNode[j].parent==-1)
            {
                m2=m1;
                x2=x1;
                m1=HuffNode[j].weight;
                x1=j;
            }//找到权值最小的节点，重复的忽略

            else if (HuffNode[j].weight < m2 && HuffNode[j].parent==-1)
            {
                m2=HuffNode[j].weight;
                x2=j;//找到权值其次小的节点，重复的忽略
            }
        } 
        HuffNode[x1].parent  = n+i;
        HuffNode[x2].parent  = n+i;
        HuffNode[n+i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
        HuffNode[n+i].lchild = x1;
        HuffNode[n+i].rchild = x2;
    } //构建哈夫曼树

} 

void Coding(HNodeType HuffNode[MAXNODE],HCodeType HuffCode[MAXLEAF],HCodeType &cd,int &n){
	int i=0,j=0,c=0,p=0;
	char jd;
    for (i=0; i < n; i++)
    {
        cd.start = n-1;
        c = i;
        p = HuffNode[c].parent;//节点随着循环被双亲节点取代，向上查找
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
        for (j=cd.start+1; j<n; j++)//记录哈夫曼编码和对照的字符
        {
            HuffCode[i].bit[j] = cd.bit[j];
		//哈夫曼编码倒叙输入正序输出，故存储的头节点也记录	
        }
		
        HuffCode[i].start = cd.start;
		
    }
	printf("\n                                              ");
    printf ("是否显示哈夫曼编码(Y/N)：");
	cin>>jd;
	if(jd=='Y'||jd=='y')
	{
    for (i=0; i<n; i++)
    {
		printf("\n                                              ");
        printf ("你要加密的字符 %c  哈夫曼编码为", str[i]);
        for (j=HuffCode[i].start+1; j < n; j++)
        {
            printf ("%d", HuffCode[i].bit[j]);
        }

        printf ("\n");
    }
	}

}

void Printcode(char inputing[], HCodeType HuffCode[],int n){
	int i=0,j=0,c=0;
	for(i=0;;i++)
	{
	    scanf("%c",&inputing[i]);
		if(inputing[i]=='\n')
			break;
		if(inputing[i]>='a'&&inputing[i]<='z')
			inputing[i]=inputing[i]-32;//对错输入的小写字符纠错
		for(j=0;j<n;j++){
			if(inputing[i]==str[j]){
			    for (c=HuffCode[j].start+1; c < n; c++)//输出密码
        {
			printf("%d",HuffCode[j].bit[c]);
			
        }
				printf("*");
				jk=jk+1;//记录密码个数
			     break;
			}
			
		}
	}
	
			printf("密码个数为%d",jk);


}

void Print( HCodeType HuffCode[],int n){
	int cod[MAXLEAF][MAXBIT];
	int i=0,j=0,k=0,m=0;
	int temp=0,x=0;
	char ch=0;
	printf("************************************************************************************************************************");
	printf("\n                                              ");
	printf("请输入需要破解密码个数:");
	scanf("%d",&k);
	printf("\n                                              ");
	printf("请输入需要破解的密码:\n");
	getchar();
	for(i=0;i<k;i++){
		for(j=0;;j++){
			printf("\n                                              ");
			scanf("%c",&ch);
		
		    if(ch=='\n')
				break;
			else{
				temp=ch-48;//字符与数组间转化发生的差值
			    cod[i][j]=temp;
			}
			}
		}
	for(i=0;i<k;i++){
		for(m=0;m<n;m++)
		{
		for(j=HuffCode[m].start+1;j<n;j++){
			if(HuffCode[m].bit[j]!=cod[i][j-(HuffCode[m].start+1)]){
			    x=1;//对比哈夫曼编码，错的标记
				break;
			}
		
		}
		
	     if(x==0){
			 printf("%c",str[m]);//未标记的为正确，输出相应字符
			 break;
		 }
	     x=0;
		}
	}
	
}
void wordjob(int n){
	int i=0;
	for(i=0;i<n;i++){
	    if(str[i]>='a'&&str[i]<='z')//对小写纠错
			str[i]=str[i]-32;
	}


}
int main()
{
    HNodeType HuffNode[MAXNODE];    
    HCodeType HuffCode[MAXLEAF],  cd;    
    int n=0;
	char js;
	char inputing[MAXBIT];
	printf("************************************************************************************************************************");
	printf("\n                                              ");
	printf("请输入初始化字符大小：");
	cin>>n;
	printf("************************************************************************************************************************");
	printf("\n                                              ");
	printf("请输入初始化字符：");
    cin>>str;
	wordjob(n);
    HuffmanTree (HuffNode, n);
    Coding(HuffNode,HuffCode,cd,n);
	printf("\n                                              ");
	printf("请输入加密文件：");printf("\n                                              ");
	getchar();
	Printcode(inputing,HuffCode,n);
	printf("\n                                              ");
	printf("请记住密码后按回车确认");
	getchar();
	printf("\n                                              ");
	printf("是否破译密码（Y/N）");
	cin>>js;
	if(js=='Y'||js=='y')
	{
	getchar();
	Print(HuffCode,n);
	}
    return 0;
}
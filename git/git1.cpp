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
		for(t2=0;t2<26;t2++){//���ַ�����ʼ��
			if(arr[t2]==str[t1]){
			      temp[t1]=t2;
				  break;
			}
		
		}
	
	}
    for (i=0; i<2*n-1; i++)//�Խڵ��ʼ��
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
            }//�ҵ�Ȩֵ��С�Ľڵ㣬�ظ��ĺ���

            else if (HuffNode[j].weight < m2 && HuffNode[j].parent==-1)
            {
                m2=HuffNode[j].weight;
                x2=j;//�ҵ�Ȩֵ���С�Ľڵ㣬�ظ��ĺ���
            }
        } 
        HuffNode[x1].parent  = n+i;
        HuffNode[x2].parent  = n+i;
        HuffNode[n+i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
        HuffNode[n+i].lchild = x1;
        HuffNode[n+i].rchild = x2;
    } //������������

} 

void Coding(HNodeType HuffNode[MAXNODE],HCodeType HuffCode[MAXLEAF],HCodeType &cd,int &n){
	int i=0,j=0,c=0,p=0;
	char jd;
    for (i=0; i < n; i++)
    {
        cd.start = n-1;
        c = i;
        p = HuffNode[c].parent;//�ڵ�����ѭ����˫�׽ڵ�ȡ�������ϲ���
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
        for (j=cd.start+1; j<n; j++)//��¼����������Ͷ��յ��ַ�
        {
            HuffCode[i].bit[j] = cd.bit[j];
		//���������뵹����������������ʴ洢��ͷ�ڵ�Ҳ��¼	
        }
		
        HuffCode[i].start = cd.start;
		
    }
	printf("\n                                              ");
    printf ("�Ƿ���ʾ����������(Y/N)��");
	cin>>jd;
	if(jd=='Y'||jd=='y')
	{
    for (i=0; i<n; i++)
    {
		printf("\n                                              ");
        printf ("��Ҫ���ܵ��ַ� %c  ����������Ϊ", str[i]);
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
			inputing[i]=inputing[i]-32;//�Դ������Сд�ַ�����
		for(j=0;j<n;j++){
			if(inputing[i]==str[j]){
			    for (c=HuffCode[j].start+1; c < n; c++)//�������
        {
			printf("%d",HuffCode[j].bit[c]);
			
        }
				printf("*");
				jk=jk+1;//��¼�������
			     break;
			}
			
		}
	}
	
			printf("�������Ϊ%d",jk);


}

void Print( HCodeType HuffCode[],int n){
	int cod[MAXLEAF][MAXBIT];
	int i=0,j=0,k=0,m=0;
	int temp=0,x=0;
	char ch=0;
	printf("************************************************************************************************************************");
	printf("\n                                              ");
	printf("��������Ҫ�ƽ��������:");
	scanf("%d",&k);
	printf("\n                                              ");
	printf("��������Ҫ�ƽ������:\n");
	getchar();
	for(i=0;i<k;i++){
		for(j=0;;j++){
			printf("\n                                              ");
			scanf("%c",&ch);
		
		    if(ch=='\n')
				break;
			else{
				temp=ch-48;//�ַ��������ת�������Ĳ�ֵ
			    cod[i][j]=temp;
			}
			}
		}
	for(i=0;i<k;i++){
		for(m=0;m<n;m++)
		{
		for(j=HuffCode[m].start+1;j<n;j++){
			if(HuffCode[m].bit[j]!=cod[i][j-(HuffCode[m].start+1)]){
			    x=1;//�Աȹ��������룬��ı��
				break;
			}
		
		}
		
	     if(x==0){
			 printf("%c",str[m]);//δ��ǵ�Ϊ��ȷ�������Ӧ�ַ�
			 break;
		 }
	     x=0;
		}
	}
	
}
void wordjob(int n){
	int i=0;
	for(i=0;i<n;i++){
	    if(str[i]>='a'&&str[i]<='z')//��Сд����
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
	printf("�������ʼ���ַ���С��");
	cin>>n;
	printf("************************************************************************************************************************");
	printf("\n                                              ");
	printf("�������ʼ���ַ���");
    cin>>str;
	wordjob(n);
    HuffmanTree (HuffNode, n);
    Coding(HuffNode,HuffCode,cd,n);
	printf("\n                                              ");
	printf("����������ļ���");printf("\n                                              ");
	getchar();
	Printcode(inputing,HuffCode,n);
	printf("\n                                              ");
	printf("���ס����󰴻س�ȷ��");
	getchar();
	printf("\n                                              ");
	printf("�Ƿ��������루Y/N��");
	cin>>js;
	if(js=='Y'||js=='y')
	{
	getchar();
	Print(HuffCode,n);
	}
    return 0;
}
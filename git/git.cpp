#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using  namespace  std;
#define MAXBIT      100
#define MAXVALUE  10000
#define MAXLEAF     30
#define MAXNODE    MAXLEAF*2 -1
typedef struct            //����������ṹ��
{
    int bit[MAXBIT];
    int start;
} HCodeType;    
typedef struct            //���������ṹ��
{        
    double   weight;
    int parent;
    int lchild;
    int rchild;
    char  value;
} HNodeType;      

typedef struct node    //����������ṹ�壬���ڵ��м�������������
{
      int bit[MAXBIT];
	  int start;
}coding;

char     str[200]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 //�ַ�����Դ
char     dtr[200];//����ĳ�ʼ���ַ�
char     ptr[200];//�м����
char     jd;//���ڽ������ж�
double   vc[30]={186,64,13,22,32,103,21,15,47,571,5,32,20,57,63,15,1,48,51,80,23,7,18,2,16,11}; //�ַ����и��ַ���Ȩֵ��Ƶ�ȣ�
void   HuffmanTree (HNodeType HuffNode[MAXNODE],  int n)
{
//���ڹ�����������
    int i, j;double   m1, m2;int   x1, x2;
    for (i=0; i<2*n-1; i++)
    {
        HuffNode[i].weight = 0;//��ʼ�� ���ڵ�Ȩֵλ0
        HuffNode[i].parent =-1;//-1����գ�˫�׽ڵ�Ϊ��
        HuffNode[i].lchild =-1;//-1����գ����ӽڵ�Ϊ��
        HuffNode[i].rchild =-1;//-1����գ��Һ��ӽڵ�Ϊ��
        HuffNode[i].value=i; //i��Ӧ�ַ���str[i]���ַ��������ַ�
} 

    for (i=0; i<n; i++)//������ڵ�Ȩֵ����ɳ�ʼ����
    {
        scanf ("%lf", &HuffNode[i].weight);//�Ը��ַ�����Ȩֵ
    }  
    for (i=0;i<n-1; i++)//������������    {
        m1=m2=MAXVALUE;  
//x1��m1���ڲ��Ҽ�¼Ȩֵ��С��x2��m2���ڲ��Ҽ�¼Ȩֵ���С
        x1=x2=0;
        for (j=0; j<n+i; j++)
        {
            if (HuffNode[j].weight < m1 && HuffNode[j].parent==-1)//�ҵ�Ȩֵ��С�Ľڵ㲢���             {
                m2=m1;
                x2=x1;
                m1=HuffNode[j].weight;
                x1=j;
            }
            else if (HuffNode[j].weight < m2 && HuffNode[j].parent==-1)//�ҵ�Ȩֵ���С�Ľڵ㲢��� 
            {
                m2=HuffNode[j].weight;
                x2=j;
            }
        } 
        HuffNode[x1].parent  = n+i;//����������Сֵͬһ��parent�ڵ�
        HuffNode[x2].parent  = n+i;
        HuffNode[n+i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
//���parent�ڵ�Ȩֵ�����Żز�����
        HuffNode[n+i].lchild = x1;//����parent�ڵ����ӽڵ�
        HuffNode[n+i].rchild = x2;//����parent�ڵ����ӽڵ�
    } 

} 
int main()
{
	coding code[MAXBIT];
    HNodeType HuffNode[MAXNODE];    
    HCodeType HuffCode[MAXLEAF],  cd;    
    int i, j, c, p, n=26,x=0��tn,er=0,pt,h,b;//x,tn��er=0���ڽ����ж�,pt���ڼ����������볤��
	char inputing[MAXBIT];//����Ҫ���ܵ�����

    printf("************************************************************************************************************************");
	printf("\n\n                                            �������ʼ���ַ���С��");//����
	while(er==0)
	{
	scanf("%d",&tn);
	if(tn<=0||tn>26)
	{
	printf("\n\n                                       ����,�������ʼ���ַ���С��");
	 er=0;
	
	}
	else
		er=1;
	}
	printf("************************************************************************************************************************");
	printf("\n\n                                            ������Ҫ��ʼ�����ַ���");
	cin>>dtr;
	
	if(tn!=strlen(dtr))
	{
		printf("\n\n                         	        ����,�������ʼ�����ַ���");
		er=0;
		cin>>dtr;
	}
	//���� ���������Լ�
	printf("************************************************************************************************************************");
	printf("                                  ������ɣ��Ƿ���ʾ����������(Y/N)");

	    HuffmanTree (HuffNode, n);
    for (i=0; i < n; i++)
    {
        cd.start = n-1; �������������Ӻ�ʼ�������룬��¼���������ͷ
        c = i;     c��Ӧ�ַ������ַ���λ��
        p = HuffNode[c].parent;//�Ӹ��ڵ㿪ʼ���±���
        while (p != -1) 
        {
            if (HuffNode[p].lchild == c)//��Ϊ��ڵ���0���ҽڵ���1
                cd.bit[cd.start] = 0;
            else
                cd.bit[cd.start] = 1;
            cd.start--;     
            c=p;
            p=HuffNode[c].parent;  
        } 
        for (j=cd.start+1; j<n; j++)
        {
            HuffCode[i].bit[j] = cd.bit[j];��������м����ת�Ʋ��洢
			
        }
		
        HuffCode[i].start = cd.start;����ʼͷ�ڵ�Ҳ��¼����
		
    }

	cin>>jd;//���뽻�����ַ�
	if(jd=='Y')
	{

		for(b=0;b<strlen(dtr);b++)
		{
			
printf ("                                            �����ַ�%c����������Ϊ: ", dtr[b]);
		for (i=0; i<n; i++) //�����ʼ���ַ��Ĺ���������
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
	printf("\n\n\n\n\n\n\n\n\n\n                                            ����������ļ���");
    HuffmanTree (HuffNode, n);
    for (i=0; i < n; i++)//�������������룬��֮ǰ��һ��
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

	
	for(i=0;;i++)//����������ݲ�����
	{
	    scanf("%c",&inputing[i]);//�����������
		if(inputing[i]=='\n')
			break;
		for(j=0;j<n;j++)
		{
			if(inputing[i]==str[j]){//�������õ��ַ������ҵ���Ӧ�Ĺ�����������м���
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
	printf("                                            ���ܳɹ������ס����\n");
	printf("                                   ");
	for(c=0;c<i;c++){
		
		for(j=code[c].start;j<n;j++)
			printf("%d",code[c].bit[j]);//�������
		    printf("*");
	
	}
	printf("\n                                            �Ƿ��������������(Y/N)");
	cin>>jd;
	if(jd=='Y')//�����ж�
	{
		printf("\n\n                                            ��������Ҫ�ƽ�����룺");
		cin>>ptr;//����Ҫ���������
		pt=strlen(ptr);//��¼���볤��
	
		h=0;
		for(c=0;c<tn;c++)//��������ת������Ӧ�Ĺ���������
		{
		while(ptr[h]!='*')
		{
		for(j=code[c].start;j<n;j++)
		{
			code[c].bit[j]=ptr[h]-48;//Ϊ����ַ�������ת������������
		    h=h+1;
		}
		    
		}
		    
	
	    }



	printf("\n\n                                            ��������Ϊ��");
	for(c=0;c<i;c++)//���ݹ���������������Ӧ���ַ�
	{
		for(j=0;j<n;j++)
		{
			if(code[c].start==HuffCode[j].start+1){
			for(p=code[c].start; p < n; p++)
        {
			if(HuffCode[j].bit[p]!=code[c].bit[p]){//���ݹ���������������ȶ�
			     x=1;//���ڲ�ͬ����б�ǣ�1Ϊ��ͬ�������
				 break;
			}
        }
			if(x==0){
			   printf("%c",str[j]);//������ܶ�Ӧ���ַ�
			     break;
			}
			x=0;
		}
		}
	}
	}
	printf("\n\n                                            �������");

    return 0;
}
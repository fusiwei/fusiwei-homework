/*Wordcount v1.2��Ԫ����*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1024
int main()
{
    printf(" �汾v1.2��Ԫ����\n�������������ļ�����,Ȼ�󰴻س�����ֹ����:\n");
    int h,h1=0,h2,h3;
    for(h3=0;h3<=5;h3++)
    {
    int d1=0,d2=0,d3=0;  /*d1,d2,d3�ֱ��ʾ�������С��������С�����ע���С�*/
    int word=0;         /*wordΪ���ʸ���*/
    int zifu=0;          /*zifuΪ�ַ���*/
    int  sen=0;          /*sen Ϊ������*/
    int a,b,i,q1,q,q2,m=0,n=0,d4=0;
    char wj[50];         /*�������������ļ���*/
    char buf[MAX_LINE];  /*������*/
    FILE *fp;            /*�ļ�ָ��*/
    int len;             /*���ַ�����*/
    int  ml;             /*������������ַ�������*/
      scanf("%d",h2);
      scanf("%[^\n]s",wj);/*�����������ļ�����*/
      ml=strlen(wj);
     switch(wj[8]){
         case 'c':b=1;break;
         case 'w':b=2;break;
         case 'z':b=3;break;
         case 'x':b=4;break;
         case 's':b=5;break;
         default:printf("��������ӿ�����!"),exit(1);
         }
     for(i=10;i<=ml-1;i++)
     {
       wj[i-10]=wj[i];
     }
     wj[ml-10]='\0';      /*ȥ���������ַ���ǰ���"wc.exe -c "*/
   if((fp=fopen(wj,"r"))==NULL)
       {
          perror("�ļ���ȡ����\n");
           exit (1) ;
       }
   while(fgets(buf,MAX_LINE,fp)!=NULL)
       {
           len=strlen(buf);   /*lenΪÿ�е��ַ���*/
        buf[len-1]='\0';      /*ȥ�����з�*/
/*---------------------ͳ�Ƶ�����------------------------*/
      if((65<=buf[0]&&buf[0]<=90)||(97<=buf[0]&&buf[0]<=122))word++;
      for(i=0;i<=len-2;i++)
     {

        if((((65<=buf[i]&&buf[i]<=90)||(97<=buf[i]&&buf[i]<=122))==0)&&((65<=buf[i+1]&&buf[i+1]<=90)||(97<=buf[i+1]&&buf[i+1]<=122)==1))
        {
         word++;
        }
     }
/*---------------------ͳ���ַ���------------------------*/
      a=0;
      for(i=0;i<=len-1;i++)
     {
        if(buf[i]==' ')
        {
         a++;
        }
     }
     zifu=zifu+len-a-1;
/*---------------------ͳ�ƾ�����------------------------*/
 for(i=0;i<=len-1;i++)
     {
        if((buf[i]=='.')||(buf[i]=='!')||(buf[i]=='?'))
        {
         sen++;
        }
     }
/*---------------------ͳ�ƴ��������Ϳ�����------------------------*/
        if(len-1-a>=2)
        {
         d1++;
        }
     else
        {
         d2++;
        }
/*---------------------ͳ��ע������------------------------*/
       q=0;
  for(i=0;i<=len-2;i++)
     {
        if(buf[i]=='*'&&buf[i+1]=='/')
        {
         q++;
        }
        if(buf[i]=='/'&&buf[i+1]=='*')
        {
         q++;
        }
        if(buf[i]=='/'&&buf[i+1]=='/')
        {
         q++;
        }
     }
     if(q>=1)
        {
         d3++;
        }

        m=0,n=0;
        for(i=0;i<=len-1;i++)
     {
        if(buf[i]=='"')
        {
         m=i;
         break;
        }
     }
        q1=0;
        for(i=0;i<=len-1;i++)
     {
        if(buf[i]=='"')
        {
        q1++;
        }
        if(q1==2)
        {
         n=i;
         break;
        }
     }
        q2=0;
     for(i=m+1;i<=n-1;i++)
     {
        if(buf[i]=='*'&&buf[i+1]=='/')
        {
         q2++;
        }
        if(buf[i]=='/'&&buf[i+1]=='*')
        {
         q2++;
        }
        if(buf[i]=='/'&&buf[i+1]=='/')
        {
         q2++;
        }
     }
      if(q2>=1)
        {
         d4++;
        }
 }
/*---------------------------------*/
  d3=d3-d4;
switch(b){
         case 1:b=1;printf("\n�ַ���Ϊ��%d\n",zifu);break;
         case 2:b=2;printf("\n������Ϊ��%d\n",word);break;
         case 3:b=3;printf("\n������Ϊ��%d\n",sen);break;
         case 4:b=4;printf("\n�ַ���Ϊ��%d\n",zifu);
                    printf("\n������Ϊ��%d\n",word);
                    printf("\n������Ϊ��%d\n",sen);break;
         case 5:b=5;printf("\n��������Ϊ��%d\n",d1);
                    printf("\n������Ϊ��%d\n",d2);
                    printf("\nע������Ϊ��%d\n",d3);break;
}                   h=zifu+word+sen;
switch(h){
         case 42:h1++;printf("            ����ͨ��\n");break;
         case 54:h1++;printf("            ����ͨ��\n");break;
         case 71:h1++;printf("            ����ͨ��\n");break;
         case 87:h1++;printf("            ����ͨ��\n");break;
         case 256:h1++;printf("            ����ͨ��\n");break;
         case 250:h1++;printf("            ����ͨ��\n");break;
         default:printf("�������δͨ��\n");break;
    }
    }
switch(h1){
         case 6:printf("            ���в���ͨ��\n");break;
         default:printf("����δͨ��");break;
}




return 0;
}

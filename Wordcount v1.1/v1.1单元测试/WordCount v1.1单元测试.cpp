/*wordcount v1.1*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1024
int main()
{
    printf(" �汾v1.1��Ԫ����\n�������������ļ�����,Ȼ�󰴻س�����ֹ����:\n");
    int h,h1=0,h2,h3;
    for(h3=0;h3<=3;h3++)
    {
    int a,b,i,word=0;         /*wordΪ���ʸ���*/
    int zifu=0;          /*zifuΪ�ַ���*/
    int  sen=0;          /*sen Ϊ������*/
  /*-----------������------------*/

  /*-----------������------------*/
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
/*-----------������------------*/

/*-----------������------------*/
         default:printf("��������ӿ�����!\n"),exit(1);
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
     zifu=zifu+len-1-a;
/*---------------------ͳ�ƾ�����------------------------*/
 for(i=0;i<=len-1;i++)
     {
        if((buf[i]=='.')||(buf[i]=='!')||(buf[i]=='?'))
        {
         sen++;
        }
     }
/*-----------������------------*/

/*-----------������------------*/
     }
switch(b){
         case 1:b=1;printf("\n�ַ���Ϊ��%d\n",zifu);break;
         case 2:b=2;printf("\n������Ϊ��%d\n",word);break;
         case 3:b=3;printf("\n������Ϊ��%d\n",sen);break;
         case 4:b=4;printf("\n�ַ���Ϊ��%d\n",zifu);
                    printf("\n������Ϊ��%d\n",word);
                    printf("\n������Ϊ��%d\n",sen);break;
}
       h=zifu+word+sen;
switch(h){
         case 42:h1++;printf("            ����ͨ��\n");break;
         case 54:h1++;printf("            ����ͨ��\n");break;
         case 71:h1++;printf("            ����ͨ��\n");break;
         case 87:h1++;printf("            ����ͨ��\n");break;
         default:printf("�������δͨ��\n");break;
    }
    }
switch(h1){
         case 4:printf("            ���в���ͨ��\n");break;
         default:printf("����δͨ��");break;
}
return 0;
}

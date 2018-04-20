/*Wordcount v1.2单元测试*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1024
int main()
{
    printf(" 版本v1.2单元测试\n请输入相关命令及文件名称,然后按回车键终止输入:\n");
    int h,h1=0,h2,h3;
    for(h3=0;h3<=5;h3++)
    {
    int d1=0,d2=0,d3=0;  /*d1,d2,d3分别表示“代码行”，“空行”，“注释行”*/
    int word=0;         /*word为单词个数*/
    int zifu=0;          /*zifu为字符数*/
    int  sen=0;          /*sen 为句子数*/
    int a,b,i,q1,q,q2,m=0,n=0,d4=0;
    char wj[50];         /*保存输入的命令及文件名*/
    char buf[MAX_LINE];  /*缓冲区*/
    FILE *fp;            /*文件指针*/
    int len;             /*行字符个数*/
    int  ml;             /*输入的命令行字符串长度*/
      scanf("%d",h2);
      scanf("%[^\n]s",wj);/*输入相关命令及文件名称*/
      ml=strlen(wj);
     switch(wj[8]){
         case 'c':b=1;break;
         case 'w':b=2;break;
         case 'z':b=3;break;
         case 'x':b=4;break;
         case 's':b=5;break;
         default:printf("输入命令接口有误!"),exit(1);
         }
     for(i=10;i<=ml-1;i++)
     {
       wj[i-10]=wj[i];
     }
     wj[ml-10]='\0';      /*去掉命令行字符串前面的"wc.exe -c "*/
   if((fp=fopen(wj,"r"))==NULL)
       {
          perror("文件读取错误\n");
           exit (1) ;
       }
   while(fgets(buf,MAX_LINE,fp)!=NULL)
       {
           len=strlen(buf);   /*len为每行的字符数*/
        buf[len-1]='\0';      /*去掉换行符*/
/*---------------------统计单词数------------------------*/
      if((65<=buf[0]&&buf[0]<=90)||(97<=buf[0]&&buf[0]<=122))word++;
      for(i=0;i<=len-2;i++)
     {

        if((((65<=buf[i]&&buf[i]<=90)||(97<=buf[i]&&buf[i]<=122))==0)&&((65<=buf[i+1]&&buf[i+1]<=90)||(97<=buf[i+1]&&buf[i+1]<=122)==1))
        {
         word++;
        }
     }
/*---------------------统计字符数------------------------*/
      a=0;
      for(i=0;i<=len-1;i++)
     {
        if(buf[i]==' ')
        {
         a++;
        }
     }
     zifu=zifu+len-a-1;
/*---------------------统计句子数------------------------*/
 for(i=0;i<=len-1;i++)
     {
        if((buf[i]=='.')||(buf[i]=='!')||(buf[i]=='?'))
        {
         sen++;
        }
     }
/*---------------------统计代码行数和空行数------------------------*/
        if(len-1-a>=2)
        {
         d1++;
        }
     else
        {
         d2++;
        }
/*---------------------统计注释行数------------------------*/
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
         case 1:b=1;printf("\n字符数为：%d\n",zifu);break;
         case 2:b=2;printf("\n单词数为：%d\n",word);break;
         case 3:b=3;printf("\n句子数为：%d\n",sen);break;
         case 4:b=4;printf("\n字符数为：%d\n",zifu);
                    printf("\n单词数为：%d\n",word);
                    printf("\n句子数为：%d\n",sen);break;
         case 5:b=5;printf("\n代码行数为：%d\n",d1);
                    printf("\n空行数为：%d\n",d2);
                    printf("\n注释行数为：%d\n",d3);break;
}                   h=zifu+word+sen;
switch(h){
         case 42:h1++;printf("            测试通过\n");break;
         case 54:h1++;printf("            测试通过\n");break;
         case 71:h1++;printf("            测试通过\n");break;
         case 87:h1++;printf("            测试通过\n");break;
         case 256:h1++;printf("            测试通过\n");break;
         case 250:h1++;printf("            测试通过\n");break;
         default:printf("该项测试未通过\n");break;
    }
    }
switch(h1){
         case 6:printf("            所有测试通过\n");break;
         default:printf("测试未通过");break;
}




return 0;
}

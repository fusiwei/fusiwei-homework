/*wordcount v1.1*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1024
int main()
{
    int a,b,i,word=0;         /*word为单词个数*/
    int zifu=0;          /*zifu为字符数*/
    int  sen=0;          /*sen 为句子数*/
  /*-----------待扩充------------*/

  /*-----------待扩充------------*/
    char wj[50];         /*保存输入的命令及文件名*/
    char buf[MAX_LINE];  /*缓冲区*/
    FILE *fp;            /*文件指针*/
    int len;             /*行字符个数*/
    int  ml;             /*输入的命令行字符串长度*/
      printf(" 版本v1.1\n请输入相关命令及文件名称,然后按回车键终止输入:\n");
      scanf("%[^\n]s",wj);/*输入相关命令及文件名称*/
      ml=strlen(wj);
     switch(wj[8]){
         case 'c':b=1;break;
         case 'w':b=2;break;
         case 'z':b=3;break;
         case 'x':b=4;break;
/*-----------待扩充------------*/

/*-----------待扩充------------*/
         default:printf("输入命令接口有误!\n"),exit(1);
         }
     for(i=10;i<=ml-1;i++)
     {
       wj[i-10]=wj[i];
     }
     wj[ml-10]='\0';      /*去掉命令行字符串前面的命令如wc.exe -c*/
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
      if((65<=buf[0]&&buf[0]<=90)||(97<=buf[0]&&buf[0]<=122))
         {word++;}
      for(i=0;i<=len-2;i++)
     {
        if((((65<=buf[i]&&buf[i]<=90)||(97<=buf[i]&&buf[i]<=122))==0)&&((65<=buf[i+1]&&buf[i+1]<=90)||(97<=buf[i+1]&&buf[i+1]<=122)))
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
     zifu=zifu+len-1-a;
/*---------------------统计句子数------------------------*/
 for(i=0;i<=len-1;i++)
     {
        if((buf[i]=='.')||(buf[i]=='!')||(buf[i]=='?'))
        {
         sen++;
        }
     }
/*-----------待扩充------------*/

/*-----------待扩充------------*/
     }
switch(b){
         case 1:b=1;printf("\n字符数为：%d\n",zifu);break;
         case 2:b=2;printf("\n单词数为：%d\n",word);break;
         case 3:b=3;printf("\n句子数为：%d\n",sen);break;
         case 4:b=4;printf("\n字符数为：%d\n",zifu);
                    printf("\n单词数为：%d\n",word);
                    printf("\n句子数为：%d\n",sen);break;
}
return 0;
}



//
//  tempreture.c
//  t_unit1_1
//
//  Created by 熊蕲涛 on 2018/11/21.
//  Copyright © 2018 熊蕲涛. All rights reserved.
//

#include "tempreture.h"
#define IN 0
#define OUT 1
#define MAXLINE 1000
//温度程序
int tempreture(){
    int fahr,celsius;
    int lower,upper,step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    while(fahr <= upper){
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n",fahr,celsius);
        fahr = fahr + step;
    }
    return 0;
}



//测试字符宽度问题


void testWidth(){
    float a = 2345.684934;
    printf("%6.1f\n",a);        //测试结果为。6.1中的6位宽度包含.的宽度,即2345.7。后面进行舍位了
    printf("%6f\n",a);          //测试结果为,最少6位宽度,全打印出来了
}



//1.51文件复制

void testCopyFile(){
    int c;
    c = getchar();
    while(c != EOF){
        putchar(c);
        c = getchar();
    }
}
void testCopyFile2(){
    int c;
    while((c = getchar()) != EOF){
        putchar(c);
    }
}

//1.5.2 字符记数
void testCountChar(){
    long nc = 0;
    while(getchar() != EOF){
        ++nc;
        getchar();
    }
    printf("%ld\n",nc);
    printf("end");
}

//1.5.2双精度字符记数
void testCountChar2(){
    double nc;
    for (nc = 0; getchar() != EOF; nc ++) {
        ;
    }
    printf("%.0f\n",nc);
    
}

//1.5.3行记数

void testCountLine(){
    int c,n1;
    n1 = 0;
    while((c = getchar()) != EOF){
        if (c != '\n') {
            ++n1;
        }
    }
    printf("line is : %d\n",n1);
}

// 1.5.4 单词记数
void testCountWords(){
    int c,nl,nw,nc,state;//c:字符,nl:行数,nc:字符数,nw:单词数 state:单词内外标志,
    state = IN;
    nl = nw = nc = 0;
    while((c=getchar())!=EOF){
        ++nc;
        if (c =='\n')
            ++nl;
        if(c =='\n' || c == ' ' || c == '\t')
            state = OUT;
        else if (state == OUT){
            state = IN;
            ++nw;
        }
        
    }
    printf("%d %d %d",nl,nw,nc);
}

//1.6 统计字符次数
void testCharTimes(){
    int ndigit[10];
    int c,nwhite,nother,i;
    nwhite = nother = 0;
    for(i = 0;i < 10;i++){
        ndigit[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        if(c >='0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == '\n' || c == ' ' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }
    printf("digits = ");
    for (i =0; i<10; i++) {
        printf(" %d",ndigit[i]);
    }
    printf(" ,white space = %d, other = %d",nwhite,nother);
}


//1.9字符数组
void testLongestLine(){
    
    int len,max;
    max = 0;
    char line[MAXLINE],longest[MAXLINE];
    while((len = getLine(line,MAXLINE)) > 0) {
        if(len > max){
            max = len;
            copyChar(longest,line);
        }
    }
    if (max > 0) {
        printf("%s",longest);
    }
}

int getLine(char s[],int lim){
    int c,i;
    c = getchar();
    for(i = 0;i<lim-1 && (c = getchar()) != EOF && c != '\n';i++)
        s[i] = c;
    if (c =='\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    
    return i;
}
// copy 函数:将from 复制到to,这里假定to足够大
void copyChar(char to[],char from[]){
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}

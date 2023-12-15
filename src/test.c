#include<stdio.h>
#include<string.h>

void clean_stdin()
{
    int ch;
    do
    {
        ch=getchar();
    }while(ch!='\n' && ch!=EOF);
}

int take_input(char ip[50])
{
    int count=0;
    char ch;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='\n') break;
        ip[count++]=ch;
    }
    ip[count]='\0';
    return count;
}

int main()
{
    char id[5],name[50],author[50],year[5];

    printf("Id: ");
    scanf("%s",id);
    clean_stdin();
    printf("Name: ");
    take_input(name);
    printf("Author: ");
    take_input(author);
    printf("Year: ");
    scanf("%s",year);
    fflush(stdin);
    printf("%s,%s,%s,%s",id,name,author,year);

    return 0;
}

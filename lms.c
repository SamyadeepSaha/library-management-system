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

int add_book()
{
    FILE *fp;
    char id[5],name[50],author[50],year[5];
    printf("Enter book details:");
    printf("\nId: ");
    scanf("%s",id);
    clean_stdin();
    printf("Name: ");
    take_input(name);
    printf("Author: ");
    take_input(author);
    printf("Year: ");
    scanf("%s",year);
    clean_stdin();
    fp=fopen("books.cvs","w");
    if(fp)
    {
        fprintf(fp,"%s,%s,%s,%s",id,name,author,year);
        fclose(fp);
    }
    return 0;
}
int search_book()
{
    return 0;
}
int del_book(char *key)
{
    return 0;
}
int show_book()
{
    FILE *fp;
    char value;
    fp=fopen("books.csv","rb");
    if(fp)
    {
        while(1)
        {
            value=fgetc(fp);
            if(value==EOF) break;
            else printf("%c",value);
        }
    }
    fclose(fp);
    return 0;
}
int main()
{
    int choice;
    printf("Welcome to library!");
    do
    {
        printf("\nSelect a option");
        printf("\n1. Add book");
        printf("\n2. Show book");
        printf("\n3. Search book");
        printf("\n4. Exit");
        printf("\nChoice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                add_book();
                break;
            case 2:
                show_book();
                break;
            case 3:
                search_book();
                break;
            case 4:
                printf("Exit.\n");
                break;
            default:
                printf("Choose a valid option.");
                break;
        }
    }while(choice!=4);

    return 0;
}

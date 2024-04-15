#include<stdio.h>
#include"database.h"

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

int add_member()
{
    static MEMBER m;
    printf("Enter member details:");
    printf("\nId: ");
    scanf("%s",m.id);
    clean_stdin();
    printf("Name: ");
    take_input(m.name);
    printf("Deposit: ");
    scanf("%d",&m.deposit);
    printf("flag");
    clean_stdin();
    insert_member(m);
    return 0;
}

int add_book()
{
    BOOK bk;
    printf("Enter book details:");
    printf("\nId: ");
    scanf("%s",bk.id);
    clean_stdin();
    printf("Name: ");
    take_input(bk.name);
    printf("Author: ");
    take_input(bk.author);
    printf("Publication: ");
    take_input(bk.pub);
    printf("Price: ");
    scanf("%d",&bk.price);
    clean_stdin();
    insert_book(bk);
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
        printf("\n2. Delete book");
        printf("\n3. Add member");
        printf("\n4. Delete member");
        printf("\n5. Issue book");
        printf("\n6. Return book");
        printf("\n7. Exit");
        printf("\nChoice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            char id[6];
            case 1:
                add_book();
                break;
            case 2:
                printf("Enter book id");
                scanf("%s", &id);
                del_book(id);
                break;
            case 3:
                add_member();
                break;
            case 4:
                printf("Enter member id");
                scanf("%s", &id);
                del_member(id);
                break;
            case 5:
                insert_issue();
                break;
            case 6:
                printf("Enter issue id");
                scanf("%s", &id);
                del_issue(id);
                break;
            case 7:
                printf("Exit.\n");
                break;
            default:
                printf("Choose a valid option.");
                break;
        }
    }while(choice!=4);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* Maximum length of data*/
#define strMax 20
typedef struct node                     //definitions from the question
{ 
    char data [strMax];
    struct node * next;
}queueNode;

typedef struct 
{
    queueNode *head;
    queueNode *tail;
} stringQueue;
stringQueue queue;

void initializeQueue (stringQueue *queue)           //initializing the queue
{
    queue->head=NULL;
    queue->tail=NULL;
}

int empty(stringQueue queue)                    //function to check empty queue
{
    if(queue.head==NULL)
    return 1;
    else return 0;
}

int enqueue (stringQueue *queue, char *item)            //inserting the node
{
    queueNode *temp;
    temp = (queueNode *)malloc(sizeof(queueNode));
    strcpy(temp->data,item);
    temp->next=NULL;
    if(empty(*queue))                   //adding first node
    {
        queue->head=temp;
        queue->tail=temp;
    }
    else
    {
    queue->tail->next=temp;                 //adding the node to queue
    queue->tail=temp;
    }
    return strlen(item);
}

char *dequeue(stringQueue *queue)
{
    static char s1='$';
    if(empty(*queue))                       //finally emptying queue and assigning NULL
    {
        queue->head=NULL;
        queue->tail=NULL;
        printf("\nqueue is empty");
        return s1;
    }
    else
    {
        
        queueNode *temp;
        static char ch[strMax];
        temp=queue->head;
        queue->head=queue->head->next;          //moving head to next node
        if(queue->head==NULL)
        {
            queue->tail==NULL;
        }
        strcpy(ch,temp->data);
        free(temp);         //freeing the space
        return ch;
    }
}

void print(stringQueue *queue)
{
    queueNode *temp;
    temp=queue->head;
    if(temp==NULL)
    {
        printf("\n queue is empty");
    }
    else
    {
        printf("\n The queue is as : \n");
        while(temp!=NULL)
        {
            printf("%s\n",temp->data);
            temp=temp->next;                //moving to next node
        }
    }
}


void main()
{
    int ch,t;
    char *t1;
    char s[strMax];
    initializeQueue(&queue);
    do
    {
        printf("\n\t\tMain Menu");
        printf("\n\t1) Enqueue");
        printf("\n\t2) Dequeue");
        printf("\n\t3) Print");
        printf("\n\t4) Exit");
        printf("\n\n\t Enter your choice from the menu : ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("\nEnter the string you want to enter : ");
            scanf(" %[^\n]%*c", &s);
        }
        switch(ch)
        {
            case 1:
            t=enqueue(&queue,s);
            break;
            case 2:
            t1 = dequeue(&queue);
            if(t1!='$')
            printf("\nHead Node containing '%s' is deleted from the queue\n",t1);
            break;
            case 3:
            print(&queue);
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\nYou have entered wrong choice");
        }
    }while(ch!=4);
}

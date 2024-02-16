#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char letter;
    struct node* next;
} node;


int length(node* head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}


char* toCString(node* head)
{
    int len = length(head);
    char* str = (char*)malloc(len + 1);
    char* p = str;
    while (head != NULL) {
        *p++ = head->letter;
        head = head->next;
    }
    *p = '\0';
    return str;
}


void insertChar(node** pHead, char c)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->letter = c;
    new_node->next = NULL;


    if (*pHead == NULL)
    {
        *pHead = new_node;
    } else {

        node* current = *pHead;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

void deleteList(node** pHead)
{
    node* current = *pHead;
    node* next_node;

    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *pHead = NULL;
}

int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt", "r");


    if (inFile == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    fscanf(inFile, " %d\n", &numInputs);
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++) {
            fscanf(inFile, " %c", &c);
            insertChar(&head, c);
        }
        str = toCString(head);
        printf("String is : %s\n", str);
        free(str);
        deleteList(&head);

        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
    return 0;
}
//
//  main.cpp
//  DoublyLinkedList
//
//  Created by Devang Papinwar on 19/02/21.
//

#include <iostream>
using namespace std;

struct Person
{
    int data;
    Person* next;
    Person* prev;
};

void display(Person* head)
{
    cout << "\nDisplaying Information : " << endl ;
    int counter = 0;
    while(head != NULL)
    {
        counter++;
        cout << "Data " << counter << " : " << head->data << " - > ";
        head = head->next;
    }
    cout << endl;
}

void insertAtBeg(Person** head)
{
    struct Person* new_node = (struct Person*) malloc(sizeof(struct Person));
    cout << "Enter Data : ";
    cin >> new_node->data;
    (*head)->prev = new_node;
    new_node->next = *head;
    new_node->prev = NULL;
    *head = new_node;
}

void insertInMiddle(Person* head,int loc)
{
    struct Person* new_node = (struct Person*) malloc(sizeof(struct Person));
    cout << "Enter Data : ";
    cin >> new_node->data;
    Person* temp = new Person();
    Person* tem = head;
    for(int i=0; i<=loc-1 ; i++)
    {
        tem = head;
        temp = tem->next;
        head = head->next;
    }
    new_node->next = temp;
    new_node->prev = tem;
    temp->prev = new_node;
    tem->next = new_node;
}

void insertAtEnd(Person* head)
{
    struct Person* new_node = (struct Person*) malloc(sizeof(struct Person));
    Person* temp = head;
    cout << "Enter Data : ";
    cin >> new_node->data;
    new_node->next = NULL;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next=new_node;
    new_node->prev = temp;
}

void deleteInBeg(Person** head)
{
    struct Person* temp = (struct Person*) malloc(sizeof(struct Person));
    temp = *head;
    *head = temp->next;
    (*head)->prev = NULL;
    temp->next = NULL;
}

void deleteFromMiddle(Person* head,int loc)
{
    struct Person* new_node = (struct Person*) malloc(sizeof(struct Person));
    Person* temp = new Person();
    Person* tem = new Person();
    for(int i=0; i<=loc-1 ; i++)
    {
        tem = head;
        temp = tem->next;
        head = head->next;
    }
    new_node = temp->next;
    tem->next = new_node;
    new_node->prev = tem;
    temp->next = NULL;
    temp->prev = NULL;
}

void deleteFromBack(Person* head)
{
    while(head->next->next != NULL)
    {
        head = head->next;
    }
    head->next = NULL;
}

int main(int argc, const char * argv[])
{
    Person* p1 = new Person();
    Person* p2 = new Person();
    Person* p3 = new Person();
    Person* head = new Person();
    
    p1->data = 10;
    p2->data = 20;
    p3->data = 30;
    
    head = p1;
    p1->next = p2;
    p1->prev = NULL;
    p2->next = p3;
    p2->prev = p1;
    p3->next = NULL;
    p3->prev = p2;
    insertAtBeg(&head);
    insertInMiddle(head,2);
    //insertAtEnd(head);
    //deleteInBeg(&head);
    //deleteFromMiddle(head, 2);
    deleteFromBack(head);
    display(head);
}

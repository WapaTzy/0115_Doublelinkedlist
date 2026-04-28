#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
    int noMhs;
    Node *next;
    Node *prev;

};

class DoubleLinkedList
{
    private:
    Node *START;

    public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        // Step1: Allocate memory for new node
        Node *newNode = new Node();

        //Setep 2: Assig value to the data fields
        newNode->noMhs = nim;

        //Setape 3: Insert at beginning if list is empaty or nim is dmallest
         if(START == NULL || nim <= START ->noMhs)
         {
            if (START !=NULL && nim == START ->noMhs )
         {
            cout << "\nDuplicate number not allowed"<< endl;
            return;
         }
         //Stepe 4: newNode.next = START
         newNode->next = START;

         //Setape 5: Setart.prev = newNode (if START exists)
         if (START != NULL)
         START->prev = newNode;

         //step 6: newNode.prev = NULL
         newNode->prev = NULL;

         // STEP 7: START =newNode
         START = newNode;
         return;

         }
         // insert in between node
         // stape 8: locte position for insertion
         Node *current = START;
         while (current->next != NULL && current->next->noMhs<nim)
         {
            current = current->next;

         }

         if (current->next != NULL && nim == current->next->noMhs)
         {
            cout << "\nDuplicate roll numbers not allowed"<< endl;
            return;
         }
         // step 9: Insert between current and current->next
         newNode->next = current->next;// stap 9a: newNode.next = current.next
         newNode->prev = current;// stape 9b: newNode.preve = curent

         // insert last node
         if(current->next != NULL)
         current->next->prev = newNode; // step 9c: current.next.prev = newNode
         current->next = newNode; //step 9d: current.next = newNode

    }
    void hapus()
    {
        if(START == NULL)
        {
            cout << "\nList is empty"<< endl;
            return;
        }
        cout << "\nEnter the roll number of the student whose record is to delete: ";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        // Step 1: Traverse the list to find the node
        while(current != NULL && current->noMhs != rollNo)
            current = current->next;
        
        if (current == NULL)
        {
            cout << "Record not found"<< endl;
            return;
        }
        // Step 2: If node is at the beginning
        if(current == START)
        {
            START = current->next;// step 2a: START = START.next
            if (START != NULL)
             START->prev = NULL;// atep 2b: START.PREV = NULL
            
        }
        else 
        {
            // stape 3. Link previos node to next of current
            current->prev->next = current->next;

            // stepe 4. If current is not the last node
            if(current->next != NULL)
            current->next->prev = current->prev;
        }
        // stape 5: Detle the node 
        delete current;
        cout << " Record with roll number"<< rollNo<<"deleted"<<endl;
    }
    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty"<< endl;
            return;
        }
        
        // Step 1a: Mark first node as currentNode
        Node *currentNode = START;
        // Step 2b: Repeat nutil currentNode == NULL
        cout << "\nRecords in ascending order of roll number are:\n";
        int i = 0;
        while (currentNode != NULL)
        {
            cout << i + 1 << ". "<< currentNode->noMhs<<" "<<endl;

          
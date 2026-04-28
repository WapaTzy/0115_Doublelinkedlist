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

class DobleLinkedList
{
    private:
    Node *START;

    public:
    DobleLinkedList()
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
        cout << "\nMasukan nim yg akan didelete";
        int rollNo;
        cin >> rollNo;

        Node *curretn = START;

        // Stape 1: Tranvers the list to find the node
        while(curretn != NULL && curretn->noMhs != rollNo)
        {
            curretn = curretn->next;
        }
        if (curretn == NULL)
        {
            cout << "Record not found"<< endl;
            return;
        }
        // Step 2: If node is at the beginning
        if(curretn == START)
        {
            START = curretn->next;// step 2a: START = START.next
            if (START != NULL)
            
             START->prev = NULL;// atep 2b: START.PREV = NULL
            
        }
        else 
        {
            // stape 3. Link previos node to next of current
            curretn->prev->next = curretn->next;

            // stepe 4. If current is not the last node
            if(curretn->next != NULL)
            curretn->next->prev = curretn->prev;
        }
        // stape 5: Detle the node 
        delete curretn;
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

            // Setap 3c: Move to next node
            currentNode = currentNode->next;
            i++;
        }

    }
    void revtraverse()
    {
        if (START==NULL)
        {
            cout << "\nList is empty"<<endl;
            return;
        }
        // Step 1a: Move to last node
        Node *currenrNode = START;
        int i = 0;
        while (currenrNode->next != NULL)
        {
            currenrNode = currenrNode->next;
            i++;
        }
        // Step 2b: Traverst backward
        cout << "\nRecords in descending order of roll number are:\n";
        while (currenrNode !=NULL)
        {
            cout << i + 1<< ". "<< currenrNode->noMhs<<" "<<endl;
            // Step 3c: Move to previous node
            currenrNode = currenrNode->prev;
            i--;
        }
        
    }

    void searchData()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }
        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        Node *current = START;

        // Step 1a: Traverse to fide matching roll number
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

            // Step 2b: Output result
            if (current == NULL)
            {
                cout << "Record not found\n";

            }
            else
            {
                cout << " Record found\n";
                cout << "Roll Number :" << current->noMhs<< endl;
            }
            

        
        
    }

};
int main()
{
   DobleLinkedList list;
   char choice;
   do
   {
    cout << "\nMenu:\n";
    cout << "1. Add Record\n";
    cout << "2. Delete Record\n";
    cout << "3. View Ascending\n";
    cout << "4. View Descending\n";
    cout << "5. Search Record\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";

    cin >> choice;
    switch (choice)
    {
    case '1':
        list.addNode();
        break;
    case '2':
        list.hapus();
        break;
    case '3':
        list.traverse();
        break;
    case '4':
        list.revtraverse();
        break;
    case '5':
        list.searchData();
    case '6':
        return 0;

    
    default:
        cout << "Invalid option\n";

    }
    cout <<"\nPress Enter to continue...";
    cin.ignore();
    cin.get();
    cout << endl;
    system("clear");
   } while (choice != '6');
}
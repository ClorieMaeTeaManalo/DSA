#include <iostream>

using namespace std;

    typedef struct Node{
        string songName;
        Node *link;
}Node;
Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;
    
    return newNode;

}

void traverse(Node *head){
    Node *temp = new Node;
    temp = head;

    cout << " My Plsylist" <<endl;
    while(temp != NULL){
        cout << temp->songName<< "->" <<endl;
        if(temp ->link == NULL){
            cout << "NULL" <<endl;

        }

        temp = temp->link;
    }
}

Node *insertAtEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;

    while(temp->link != NULL){
        temp = temp->link;
    }

    Node *newNode = createNode(data);
    temp->link;

    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}
Node *insertAtBeginning(string data, Node *head){
   Node *newNode = createNode(data);
   newNode->link = head;

   head =  newNode;

   cout << "A new node has been inserted at the beginning \n" <<endl;

   return head;
}

string insertAfter(string after, string data, Node *head){
    Node *temp = new Node;
    temp = head;

    while(temp->songName.compare(after) != 0){
        if(temp == NULL){
            return "No such song exist, please try again later.";
        }
        temp = temp->link;
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;

    return "An new node has been added after " + after + "\n";
}

string deleteAtEnd(Node *head){
    if(head == NULL){
        return "The link list is empty \n";
    }
    
    if(head->link == NULL){
        delete head;
        return "The head has been deleted \n";
    }

    Node *temp = new Node;
    temp = head;

    while(temp->link->link != NULL){
        temp = head;
    }

    temp->link = NULL;

    return "A node has been deleted at the end \n";
}

Node *deleteFromBEginning(Node *head){
    if(head == NULL){
        cout << "The linked list is empty \n" <<endl;
        return NULL;
    }

    if(head->link == NULL){
        delete head;

    }

    head = head->link;

    cout << "A node has been delete from the beginning \n" <<endl;

    return head;
}

Node *deleteFromGivenNode(string givenNode, Node *head){
    if(head == NULL){
        cout << "The linked list is empty. \n" <<endl;
        return NULL;
    }

    if(head->songName.compare(givenNode) != 0){
        head = deleteFromBEginning(head);
        cout << "The Node " + givenNode + " has been delete. \n" << endl;
        return head;
    }

    Node *temp = new Node;
    Node *next = new Node;
    temp = head;
    next = temp->link;

    while(next->songName.compare(givenNode) != 0){
        if(temp == NULL){
            cout << "No node such exist. \n" <<endl;
            return head;
        }
        next = next->link;
        temp = temp->link;
    } 

    temp->link = next;
    cout << "The Node " + givenNode + " has been deleted. \n" << endl;
    return head;
}

int main(){
    Node *head = createNode("Sanctuary by Joji");       
    head = insertAtEnd("Palagi by TJ Monterde", head);
    head = insertAtEnd("Sa Bawat Sandali by Amiel Sol", head);
    head = insertAtEnd("Ikaw lang by NOBITA", head);
    head = insertAtEnd("Sining by Dionela, Jay R", head);
    head = insertAtBeginning("Bad Guy by Billie Eillish", head);
    head = insertAtBeginning("Die With A Smile by Bruno Mars, Lady Gaga", head);
    head = insertAtBeginning("The Man Who Can't Be Moved by The Script", head);
    head = insertAtBeginning("Snooze by SZA", head);

   traverse(head);

    string result = insertAfter("Palagi by TJ Monterde", "Bad Guy by Billie Eillish ", head);
    cout << result;

    string result1 = insertAfter("Die With A Smile by Bruno Mars, Laddy Gaga", "bomtarattarat", head);
    cout << result1;

    string result2 = insertAfter("The Man Can't Be Move by The Script", "pusong bato", head);
    cout << result2;

    string END = deleteAtEnd(head);
    cout << END << endl;
    head = deleteFromBEginning(head);
    head = deleteFromGivenNode("Sining by Dionela, Jay R", head);

    traverse(head);
    
    return 0;
    }
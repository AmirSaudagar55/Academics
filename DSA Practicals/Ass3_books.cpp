#include <iostream>
using namespace std;

class Node
{
    public:
        string label;
        int cnt;    //Counts number of chapters, sections, sub-sections
        Node *child[10];
};

class Book{
    public:
        Node *root;
        
        Book()
        {
            root = NULL;
        }
        
        void createData()
        {
            root = new Node;
            cout << "Enter the name of the book : ";
            cin.ignore();
            getline(cin, root->label);
            cout << "How many Chapters are there in book ' " << root->label << " ' : ";
            cin >> root->cnt;
            
            for(int i = 0; i < root->cnt; i++)
            {
                root->child[i] = new Node;
                cout << "Enter name of chapter " << i+1 << ") : ";
                cin.ignore();
                getline(cin, root->child[i]->label);
                
                cout << "Enter number of sections does it has : ";
                cin >> root->child[i]->cnt;
                
                for(int j = 0; j < root->child[i]->cnt; j++)
                {
                    root->child[i]->child[j] = new Node;
                    cout << "Enter the name of section : ";
                    cin.ignore();
                    getline(cin, root->child[i]->child[j]->label);
                }
                cout << endl;
            }
			
			cout<<"---------------------------------------------"<<endl;
            
        }
        
        void displayData()
        {
            cout << "Title of the book : " << root->label << endl;
            
            for(int i = 0; i < root->cnt; i++)
            {
                cout << root->child[i]->label << endl;
                
                for(int j = 0; j < root->child[i]->cnt; j++)
                {
                    cout << root->child[i]->child[j]->label << endl;
                }
                cout<< endl;
            }
			cout<<"--------------------------------------"<<endl;
            
        }
        
};

int main()
{
    Book b1;
    int choice;
    do {
        cout << "Enter your choice:" << endl;
        cout << "1. Create data" << endl;
        cout << "2. Display data" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                b1.createData();
                break;
            case 2:
                b1.displayData();
                break;
            case 3:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}

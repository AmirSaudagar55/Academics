#include <iostream>
using namespace std;

class Node {
public:
    string label;
    int cnt; // Counts number of chapters, sections, subsections
    Node* child[10];
    Node* subsection[10];
};

class Book {
public:
    Node* root;

    Book() {
        root = NULL;
    }

    void createData() {
        root = new Node;
        cout << "Enter the name of the book: ";
        cin.ignore();
        getline(cin, root->label);
        cout << "How many chapters are there in the book '" << root->label << "': ";
        cin >> root->cnt;

        for (int i = 0; i < root->cnt; i++) {
            root->child[i] = new Node;
            cout << "Enter the name of chapter " << i + 1 << ": ";
            cin.ignore();
            getline(cin, root->child[i]->label);

            cout << "Enter the number of sections it has: ";
            cin >> root->child[i]->cnt;

            for (int j = 0; j < root->child[i]->cnt; j++) {
                root->child[i]->child[j] = new Node;
                cout << "Enter the name of section " << j + 1 << ": ";
                cin.ignore();
                getline(cin, root->child[i]->child[j]->label);

                cout << "Enter the number of subsections it has: ";
                cin >> root->child[i]->child[j]->cnt;

                for (int k = 0; k < root->child[i]->child[j]->cnt; k++) {
                    root->child[i]->child[j]->subsection[k] = new Node;
                    cout << "Enter the name of subsection " << k + 1 << ": ";
                    cin.ignore();
                    getline(cin, root->child[i]->child[j]->subsection[k]->label);
                }
                cout << endl;
            }
            cout << endl;
        }

        cout << "---------------------------------------------" << endl;
    }

    void displayData() {
        cout << "Title of the book: " << root->label << endl;

        for (int i = 0; i < root->cnt; i++) {
            cout << "Chapter " << i + 1 << ": " << root->child[i]->label << endl;

            for (int j = 0; j < root->child[i]->cnt; j++) {
                cout << "   Section " << j + 1 << ": " << root->child[i]->child[j]->label << endl;

                for (int k = 0; k < root->child[i]->child[j]->cnt; k++) {
                    cout << "      Subsection " << k + 1 << ": " << root->child[i]->child[j]->subsection[k]->label << endl;
                }
                cout << endl;
            }
            cout << endl;
        }

        cout << "--------------------------------------" << endl;
    }
};

int main() {
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

#include <iostream>
#include <fstream>
#include <memory>
#include <cmath>
#include <string>
using namespace std;
struct node{
    string content;
    node *next = nullptr;
};
void addToList(node*&,fstream&);
bool isEmpty(fstream&);
int main(){;
    while(true){
        cout << "What would you like to do?" << endl << endl;
        cout << "Enter a number" << endl;
        cout << "1. Add To the List" << endl;
        cout << "2. remove From the List" << endl;
        cout << "3. exit" << endl;
        char input;
        cin >> input;
        node *head = nullptr;
        fstream file("todoList.txt", ios:: in | ios:: out);
        if (!isEmpty(file)){
            node *trav = head;
            string line;
            while (getline(file,line)){
                node *ptr = new node;
                ptr->content = line;
                if (head == nullptr){
                    head = ptr;
                }else {
                    node *trav = head;
                    while (trav->next != nullptr){
                        trav = trav->next;

                    }
                    trav->next = ptr;
                }

            }
        }
        file.close();
        if (input == '1'){
            fstream file("todoList.txt", ios:: in | ios:: out |ios ::app);
            addToList(head,file);

        }else if (input == '2'){

        }else if(input == '3'){
            return 0;
        }else {
            cout << endl << endl;
            cout << "wrong number was entered please enter a new number" << endl << endl;
        }
    }
        
   
   return 0;
}
bool isEmpty(fstream& file){
    streampos currentPos = file.tellg();
    file.seekg(0, ios:: end);
    streampos endPos = file.tellg();

    if (currentPos == endPos){
        return true;
    }
    file.good();
    return false;
}
void addToList(node *&head, fstream& file){
    cout << "What would you like to add" << endl << endl;
    string line;
    do{
        getline(cin,line);
    }while(line.empty());
    file << line << endl;

    
}
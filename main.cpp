#include <iostream>
#include <fstream>
#include <memory>
#include <cmath>
#include <string>
#include <conio.h>
using namespace std;
enum importance{green,yello,red};
struct node{
    string content;
    node *next = nullptr;
    importance level;
    
};
void addToList(node*&,fstream&);
bool isEmpty(fstream&);
bool isType(string);
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
    node *ptr = new node;
    cout << "What would you like to add" << endl << endl;
    string line;
    do{
        getline(cin,line);
    }while(line.empty());

    ptr->content = line;
    file << line << endl;
    cout << "Add a level of importance" << endl;
    cout << "Red is the most important. Green is the least." << endl;
    string level;
    cin >> level;
    do{
    if(level == "red" || level == "Red"){
        importance lvl = red;
        ptr->level = lvl;
    }else if(level == "green" || level == "Green"){
        importance lvl = green;
        ptr->level = lvl;
    }else if(level == "Yellow" || level == "yellow"){
        importance lvl = yello;
        ptr->level = lvl;
    }else {
        cout << "you entered a wrong type of importance level." << endl;
        cout << "Please enter a new level." << endl;
        cin >> level;
    }
    }while(!isType(level));
    node *trav = head;
    if(head == nullptr){
        head = ptr;
    }else{
        while (trav->next != nullptr){
            trav = trav->next;
        }
        trav = ptr;
    }


    
}
bool isType(string level){
    if(level == "red" || level == "Red"){
        return true;
    }else if(level == "green" || level == "Green"){
        return true;
    }else if(level == "Yellow" || level == "yellow"){
        return true;
    }else {
        return false;
    }
}
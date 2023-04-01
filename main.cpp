#include <iostream>
#include <fstream>
#include <memory>
#include <cmath>

using namespace std;

int main(){
   fstream file("todoList.txt",ios :: in | ios :: out );
   if (file){
   
   }else {
        cout << "File failed to open" << endl;
        return 1;
   }
}

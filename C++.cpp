#include <iostream>
#include <string>
#include <regex>
using namespace std;

class student {

private:
    string StudentFirstName;
    string StudentLastName;
    string StudentGNoss;

public:
    student() { 
        this -> StudentFirstName = "no"; 
        this -> StudentLastName = "no";
        this -> StudentGNoss = "no";
    }

    ~student() { }

    void setStudentLastName(string StudentLastName) {
        this -> StudentLastName = StudentLastName;
    }
 
    string getStudentLastName() {
        return this -> StudentLastName;
    }
    
    void setStudentFirstName(string StudentFirstName) {
        this -> StudentFirstName = StudentFirstName;
    }

    string getStudentFirstName() {
        return this -> StudentFirstName;
    }

    void setStudentGNoss(string StudentGNoss) {
        this -> StudentGNoss = StudentGNoss;
    }
    string getStudentGNoss() {
        return this -> StudentGNoss;
    }

};

student p[100];
int total = 0;

void addStudent() {
    string firstName;
    string lastName;
    string GNoss;

    cout << "Please enter a student's first name :" << endl;
    cin >> firstName;
    cout << "Please enter a student's last name :" << endl;
    cin >> lastName;
    cout << "please enter a student's GWorld Number :" << endl;
    cin >> GNoss;

    p[total].setStudentFirstName(firstName);
    p[total].setStudentLastName(lastName);
    p[total].setStudentGNoss(GNoss);
    total++;
    cout << "Success!" <<endl;
           
}

void showAllStudent() {
    for (int i = 0; i < total; i++) {
        cout << "FirstName :" << p[i].getStudentFirstName() << "\t\t\tLastName :" << p[i].getStudentLastName() << "\t\t\tGNumber:" << p[i].getStudentGNoss()<< endl;
    }
}


void selectStudentByGN() {
    cout << "Please enter a student's GWorld number :" << endl;
    string key; 
    cin >> key;
    for (int i = 0; i < total; i++){
        if(regex_search(p[i].getStudentGNoss(),regex(key))){
            cout << "FirstName :" << p[i].getStudentFirstName() << "\t\t\tLastName :" << p[i].getStudentLastName() << "\t\t\tGNumber:" << p[i].getStudentGNoss()<< endl;
        }
    }
}
    
void selectStudentByName() {
    cout << "Please enter a student's first name :" << endl;
    string key1; 
    cin >> key1;
    cout << "Please enter a student's last name :" << endl;
    string key2;
    cin >> key2;
    for (int i = 0; i < total; i++){
        if(regex_search(p[i].getStudentFirstName(),regex(key1)) && regex_search(p[i].getStudentLastName(),regex(key2))){
            cout << "FirstName :" << p[i].getStudentFirstName() << "\t\t\tLastName :" << p[i].getStudentLastName() << "\t\t\tGNumber:" << p[i].getStudentGNoss()<< endl;
        }
    }
}
    
void deleteStudentByGN(){
    cout << "Please enter a student's GWorld number :" << endl; 
    string key; 
    cin >> key;
    for (int i = 0; i < total; i++){
        if(regex_search(p[i].getStudentGNoss(),regex(key))){
            for (int j = i; j < total; j++){
                p[j].setStudentFirstName(p[j+1].getStudentFirstName());
                p[j].setStudentLastName(p[j+1].getStudentLastName());
                p[j].setStudentGNoss(p[j+1].getStudentGNoss());
            }
            total --;
            i = i-1;
        }
    }
}

void show() {
    cout << "\n" << endl;
    cout << "1. Add new a student" << endl;
    cout << "2. Show all students" << endl;
    cout << "3. Select students by GWorld number" << endl;
    cout << "4. Select students by name" << endl;
    cout << "5. Delete students by GWorld number" << endl;
    cout << "0. Log out the system" << endl;
}

int main() {
    bool quit = false;
    int choice = 100;

    while(!quit){
        show();
        cin >> choice;
        switch(choice){
            case 1 : addStudent(); break;
            case 2 : showAllStudent(); break;
            case 3 : selectStudentByGN(); break;
            case 4 : selectStudentByName(); break;
            case 5 : deleteStudentByGN(); break;
            case 0 : quit = true; break;
        }
    }
    return 0;
}

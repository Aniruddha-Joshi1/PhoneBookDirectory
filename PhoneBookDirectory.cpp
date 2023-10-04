#include <iostream>
#include<string>
#include <map>
using namespace std;
class PhoneDirectory{
private:
    map<string,string>m;
public: 
    PhoneDirectory();
    bool validatePhoneNum(string contactNum);
    void addContact(string name,string contact);
    // constructor overloading
    void editContact(string name,string editedName,string editedContactNum);
    void editContact(string name,string editedContactNum);

    void editName(string name,string editName);
    void deleteContact(string name);
    void searchContact(string name);
    void displayContacts();
};

PhoneDirectory::PhoneDirectory(){
    while (true){
        cout << "====  Welcome to Phone Book Directory  ====\n" << endl;
        cout << "Enter your choice" << endl;
        cout << "1. For adding contacts" << endl;
        cout << "2. For editing the contacts" << endl;
        cout << "3. For deleting the contacts" << endl;
        cout << "4. For searching ticket" << endl;
        cout << "5. For displaying all the contacts" << endl;
        cout << "6. For ending the program\n" << endl;
        int choice;
        cin >> choice;
        if(choice == 1){
            string s1,s2;
            cout << "Enter the name of the person: " << endl;
            cin.ignore();
            getline(cin,s1);
            cout << "Enter the contact number: " << endl;
            getline(cin,s2);
            addContact(s1,s2);
            cout << "\n";
        }
        else if(choice == 2){
            string s1,s2,s3;
            string response1,response2;
            int flag1=0,flag2=0;
            cout << "Enter the name of the person: ";
            cin.ignore();
            getline(cin,s1);
            cout << "\nDo you want to edit the name of a person?" << endl;
            cout << "Type 'yes' if you want to and 'no' if you don't want to: ";
            cin >> response1; 
            if(response1=="yes"){
                flag1=1;
                cout << "\nEnter the name which you want to edit it to:";
                cin.ignore();
                getline(cin,s2);
            }
            cout << "\nDo you want to edit the contact of the person?" << endl;
            cout << "Type 'yes' if you want to and 'no' if you don't want to: ";
            cin >> response2;
            if(response2=="yes"){
                flag2=1;
                cout << "\nEnter the contact number to which you want to edit it to: ";
                cin.ignore();
                getline(cin,s3);
            }
            if(flag1==1&&flag2==1)editContact(s1,s2,s3);
            else if(flag1==1&&flag2==0)editName(s1,s2);
            else if(flag1==0&&flag2==1)editContact(s1,s3);
            else{
                cout << "There is nothing to edit" << endl;
            }
            cout << "\n";
        }
        else if(choice == 3){
            string s;
            cout << "Enter the name which you want to delete: ";
            cin.ignore();
            getline(cin,s);
            deleteContact(s);
        }
        else if(choice == 4){
            string s;
            cout << "Enter the name which you want to search: ";
            cin.ignore();
            getline(cin,s);
            searchContact(s);
        }
        else if(choice == 5){
            cout << "\n----Displaying all the tickets----\n" << endl;
            displayContacts();
            cout << "\n";
        }
        else if(choice == 6){
            cout << "\n\n----------Thankyou for using the Phone Book Directory System----------\n\n" << endl;
            break;
        }
        else
            cout << "Please enter a correct number\n" << endl;
    }
}

bool PhoneDirectory:: validatePhoneNum(string contactNum){
    if(contactNum.size()!=10)return false;
    for(auto c:contactNum){
        if(!isdigit(c))return false;
    }
    return true;
}
void PhoneDirectory:: addContact(string name,string contact){
    if(validatePhoneNum(contact)){
        m[name]=contact;
    }
    else{
        cout << "Phone number is not valid" << endl;
    }
}

void PhoneDirectory:: editContact(string name,string editedName,string editedContactNum){
    if(validatePhoneNum(editedContactNum)){
        m.erase(name);
        m[editedName]=editedContactNum;
    }
    else{
        cout << "Phone number is not valid" << endl;
    }
}

void PhoneDirectory:: editContact(string name,string editedContactNum){
    if(validatePhoneNum(editedContactNum)){
        m[name]=editedContactNum;
    }
    else{
        cout << "Phone number is not valid" << endl;
    }
}

void PhoneDirectory:: editName(string name,string editedName){
    string contactNum=m[name];
    m.erase(name);
    m[editedName]=contactNum;
}

void PhoneDirectory:: deleteContact(string name){
    m.erase(name);
}

void PhoneDirectory:: searchContact(string name){
    if(m.find(name)==m.end()){
        cout << "\nThe name is not there in the directory" << endl;
    }
    else{
        cout << "\nYes it exists in the directory" << endl;
        cout << "The contact number is: " << m[name] << endl;
    }
}

void PhoneDirectory:: displayContacts(){
    int i=1;
    for(auto it:m){
        cout << i << ". " << it.first << " -> " << it.second << endl;
        i++;
    }
}
int main(){
    PhoneDirectory ph;
}
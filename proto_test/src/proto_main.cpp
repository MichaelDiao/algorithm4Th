#include <iostream>
#include <string>
#include <fstream>
#include "addressbook.pb.h"
using namespace std;

void PromptForAddress(tutorial::Person* person){
    cout << "enter person ID number: ";
    int id;
    cin >> id;
    person->set_id(id);
    cin.ignore(256, '\n');

    cout << "enter name:";
    getline(cin, *person->mutable_name());

    cout << "enter email address (blank for none)";
    string email;
    getline(cin, email);
    if (!email.empty()){
        person->set_email(email);
    }


    while (true){
        cout << "enter a phone number (or leave blank to  finish): ";
        string number;
        getline(cin, number);
        if (number.empty()){
            break;
        }


        tutorial::Person::PhoneNumber* phone_number = person->add_phones();
        phone_number->set_number(number);

        cout << "Is this a mobile, home, or work phone?";
        string type;
        getline(cin, type);

        if( type == "mobile")
                phone_number->set_type(tutorial::Person::MOBILE);
        else if (type == "home")
                phone_number->set_type(tutorial::Person::HOME);
        else if (type == "work")
                phone_number->set_type(tutorial::Person::WORK);
        else
                cout << "Unknown phone type. using default." << endl;
    }
}


int main(int argc, char *argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    if (argc != 2){
        cerr << "Usage: " << argv[0] << " ADDRESS_BOOK_FILE" << endl;
        return -1;
    }

    tutorial::AddressBook address_book;

    fstream input(argv[1], ios::in | ios::binary);
    if (!input){
        cout << argv[1] << ": file not found. Createing a new file." << endl;
    } else if (!address_book.ParseFromIstream(&input)){
        cerr << "failed to parse address book." << endl;
        return -1;
    }

    PromptForAddress(address_book.add_people());

    fstream output(argv[1], ios::out | ios::trunc | ios::binary);
    if (!address_book.SerializeToOstream(&output)){
        cerr << "Failed to write address book. " << endl;
        return -1;
    }
    
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}

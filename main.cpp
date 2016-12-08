#include "eye_sec_user.h"
#include <QApplication>

//Eye Security UI - Carlo Romo

//User Interface for the project - there are two types of users: users and admins
//Users can submit eyes only if their eye matches one found in the library.
//Admins can submit and remove eyes, regardless of comparison results.


//loads in list of names for People list
std::vector<QString> initialize_namelist() {
    std::vector<QString> result;
    std::string line;
    std::ifstream file_in;
    file_in.open("test.txt", std::ios::in);
    while (std::getline(file_in, line)) {
        result.push_back(QString::fromStdString(line));
    }
    file_in.close();
    return result;
}

//loads in library with initial images
eyeLibrary initialize_library() {
    eyeLibrary result;
    std::cout <<"Initializing library...\n";
    std::string line;
    std::ifstream file_in;
    file_in.open("/Users/delebot/Documents/eyesec-gui/namelist.txt", std::ios::in);
    while (std::getline(file_in, line)) {
        result.inputPicture(line);
        std::cout << "Added " << line << std::endl;
    }
    file_in.close();
    std::cout << "...Initialized library!\n";
    return result;
}
std::vector<Person> initialize_people() {
    std::vector<Person> result;
    result.push_back(Person("Akis"));
    result.push_back(Person("Trenton"));
    result.push_back(Person("Jad"));
    return result;
}

//Checks if two strings are equal.
bool is_equal(std::string s1, std::string s2) {
    if (0 == std::strcmp(s1.c_str(),s2.c_str())) {
        return true;
    } else return false;
}

//prints out menu
void admin_client() {
    std::cout << "Eye Security - Admin Access\nMenu: \n" <<
                 "1. Add an eye \n2. Remove an eye\n" <<
                 "3. Add a user \n4. Remove a user\n5. Quit \n" <<
                 "Choice entry: ";

}

//searches people vector for a given name.
int getPerson(std::vector<Person> people, std::string name) {
    int result;
    bool has_been_matched = false;
    if (people.size() == 0) {
        return -1;
    }
    else {

        for (unsigned int i = 0; i < people.size(); i++) {
            if (is_equal(name, people[i].getName())) {
                result = i;
                has_been_matched = true;
            }
        }
    }
    if (has_been_matched) {
        return result;
    } else {
        return -1;
    }

}
bool has_name(std::vector<Person> people, std::string name) {
    bool has_been_matched = false;
    if (people.size() == 0) {
        return false;
    }
    else {

        for (unsigned int i = 0; i < people.size(); i++) {
            if (is_equal(name, people[i].getName())) {
                has_been_matched = true;
            }
        }
    }
    return has_been_matched;
}

int main(int argc, char *argv[]) {
    std::string input;
    //user is run on a gui, admin is run on a terminal.
    std::cout << "Please specify which client to run: 'admin' or 'user'.\nEntry: ";
    std::cin >> input;
    //Initializing People vector and eye library
    std::vector<Person> people = initialize_people();
    eyeLibrary lib = initialize_library();
    if (is_equal(input, "admin")) {
        int admin_choice = 0;
        while (admin_choice != 5) {
            admin_client();
            std::cin >> admin_choice;

            //adding an eye index
            if (admin_choice == 1) {
                std::cout << "Enter Person's name. \nEntry: ";
                std::cin >> input;
                if (!has_name(people, input)) {
                    std::cout << "No matching person found. \n";
                    break;
                } else {
                    int person_index = getPerson(people, input);
                    int index_number;
                    std::cout << "Enter the exact file index of the eye to add (e.g. 2) \nEntry: ";
                    std::cin >> index_number;
                    //replace eyeLibraryObject with the object for eyeLibrary
                    vector<vector<Pixel> > picture1 = lib.getPicture(index_number);
                    Parser pars1(picture1);
                    vector<Pixel> a = pars1.getIrisArray();
                    people[person_index].addIrisInstance(a);
                }
            } //removing an eye index
            else if (admin_choice == 2) {
                std::cout << "Enter Person's name. \nEntry: ";
                std::cin >> input;

                int person_index = getPerson(people, input);
                int index_number;
                std::cout << "Enter the exact file index of the eye to add (e.g. 2) \nEntry: ";
                std::cin >> index_number;
                people[person_index].removeIrisInstance(index_number);

            } //adding a person
            else if (admin_choice == 3) {
                std::cout << "Enter the name of the person to be added (e.g. John Smith) \nEntry: ";
                std::cin >> input;
                Person p(input);
                people.push_back(p);

            } //removing a person
            else if (admin_choice == 4) {
                std::cout << "Enter the name of the person to be removed (e.g. John Smith) \nEntry: ";
                std::cin >> input;
                people.erase(people.begin() + getPerson(people, input));
            } else if (admin_choice == 5) {
                std::cout << "Exiting...\n";
            } else {
                std::cout << "Invalid choice.\n";
            }
        }

    } //launches the gui for user, code can be found in eye_sec_user.cpp
    else if (is_equal(input, "user")) {
        QApplication a(argc, argv);
        eye_sec_user w;
        w.show();

        return a.exec();
    } else {
        std::cout << "Invalid entry. Ending program.\n";
        return 0;
    }
}

#include <iostream>
#include <string>
using namespace std;

int main() {
    struct student {
        string name;
        int id;
        float mark;
    };
    student s[50];
    int choice = 0, subchoice = 0, c = 0;

    do {
        cout << "\t\t\t\tStudent System Management" << endl;
        cout << "\t\t\t\t=========================" << endl;
        cout << "\t\t1. Add Student" << endl;
        cout << "\t\t2. Search Student" << endl;
        cout << "\t\t3. Update Student" << endl;
        cout << "\t\t4. Delete Student" << endl;
        cout << "\t\t5. Display All Students" << endl;
        cout << "\t\t6. Exit" << endl;
        cout << "\t\tEnter your choice: ";
        cin >> choice;

        if (choice < 1 || choice > 6) {
            cout << "\t\tChoose Only From 1-6" << endl;
        }
        else if (choice == 1) {
            if (c == 50) {
                cout << "\t\tStudent list is full" << endl;
            } else {
                cout << "\t\tEnter student name: ";
                cin >> s[c].name;
                cout << "\t\tEnter student id: ";
                cin >> s[c].id;
                cout << "\t\tEnter student mark: ";
                cin >> s[c].mark;
                c++;
                cout << "\t\tStudent added successfully" << endl;
            }
        }
        else if (choice == 2) {
            cout << "\t\t1. Search student by name: " << endl;
            cout << "\t\t2. Search student by id: " << endl;
            cout << "\t\tEnter your choice: ";
            cin >> subchoice;
            bool check = false;
            if (subchoice == 1) {
                string searchname;
                cout << "\t\t\tEnter student name: ";
                cin >> searchname;
                for (int i = 0; i < c; i++) {
                    if (s[i].name == searchname) {
                        cout << "\t\tStudent Name : " << s[i].name << endl;
                        cout << "\t\tStudent ID   : " << s[i].id << endl;
                        cout << "\t\tStudent Mark : " << s[i].mark << endl;
                        check = true;
                        break;
                    }
                }
            } else if (subchoice == 2) {
                int searchID;
                cout << "\t\t\tEnter Student ID : ";
                cin >> searchID;
                for (int i = 0; i < c; i++) {
                    if (s[i].id == searchID) {
                        cout << "\t\tStudent Name : " << s[i].name << endl;
                        cout << "\t\tStudent ID   : " << s[i].id << endl;
                        cout << "\t\tStudent Mark : " << s[i].mark << endl;
                        check = true;
                        break;
                    }
                }
            }
            if (!check) {
                cout << "\t\tStudent Not Found" << endl;
            }
        }
        else if (choice == 3) {
            string searchname;
            cout << "\t\tEnter Student Name : ";
            cin >> searchname;
            bool check = false;
            for (int i = 0; i < c; i++) {
                if (s[i].name == searchname) {
                    cout << "\t\tEnter New Name : ";
                    cin >> s[i].name;
                    cout << "\t\tEnter New ID : ";
                    cin >> s[i].id;
                    cout << "\t\tEnter New Mark : ";
                    cin >> s[i].mark;
                    check = true;
                    cout << "\t\tStudent updated successfully" << endl;
                    break;
                }
            }
            if (!check) {
                cout << "\t\tStudent Not Found" << endl;
            }
        }
        else if (choice == 4) {
            int searchid;
            char confirm;
            cout << "\t\tEnter Student ID : ";
            cin >> searchid;
            bool check = false;
            for (int i = 0; i < c; i++) {
                if (s[i].id == searchid) {
                    check = true;
                    cout << "Are you sure you want to delete this student? (y/n): ";
                    cin >> confirm;
                    if (confirm == 'y') {
                        for (int j = i; j < c - 1; j++) {
                            s[j] = s[j + 1];
                        }
                        c--;
                        cout << "\t\tStudent deleted successfully" << endl;
                    }
                    if (confirm == 'n') {
                        cout << "\t\tStudent Not Deleted" << endl;
                    }
                    break;
                }
            }
            if (!check) {
                cout << "\t\tStudent Not Found" << endl;
            }
        }
        else if (choice == 5) {
            cout << "\tName\t\tID\t\tMark" << endl;
            cout << "\t====\t\t==\t\t====" << endl;
            for (int i = 1; i < c + 1; i++) {
                cout << "\t" << i << ". " << s[i - 1].name << "\t\t" << s[i - 1].id << "\t\t" << s[i - 1].mark << endl;
            }
            cout << "\t\tNumber of students : " << c << endl;
        }
        else if (choice == 6) {
            cout << "\t\tThank you for using the system" << endl;
        }
    } while (choice != 6);

    return 0;
}

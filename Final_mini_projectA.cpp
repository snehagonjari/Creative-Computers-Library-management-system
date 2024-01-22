#include <iostream>
#include <cstring>

using namespace std;

struct node1
{
    int admno;
    string name;
    int no_issue;

    string bname;
    // Previous pointer
    node1 *prev;
    
     // Next pointer
    node1 *next;  
};


struct node2
{
    int bno;
    string bname;
    string author;
    
    // Previous pointer
    node2 *prev;
    
     // Next pointer
    node2 *next; 
};

class DoublyList
{   
    //private class
    node1 *head1;
    node2 *head2;


public:

    DoublyList() { head1 = NULL; head2=NULL;}

    void create_Student()
    {   
        // Initialize y
        char y = 'y'; 

        node1 *nn;

        while (y == 'y')
        {
            nn = new node1;

            cout << "Enter admission no : ";
            cin >> nn->admno;
            cout << "Enter name : ";
            cin >> nn->name;
            nn->no_issue = 0;

            nn->prev = NULL;
            nn->next = NULL;

            if (head1 == NULL)
            {
                head1 = nn;
            }
            else
            {
                node1 *temp; 
                temp = head1;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = nn;
                nn->prev = temp;
            }

            cout << "Want to create new student (y/n) ??: ";
            cin >> y;
        }
    }

    void display_Student()
    {
        node1 *t;
        t = head1;

        if (t == NULL)
        {
            cout << "NO DATA AVAILABLE !\n";
            return;
        }

        cout << "-------------------------------------------------------------------------\n";
        cout << "Admission no\t| Name\t\t| No of Book Issue\t |Book Name\n";
        cout << "-------------------------------------------------------------------------\n";

        while (t != NULL)
        {
            cout << t->admno << "\t\t| " << t->name << "\t\t| " << t->no_issue << "\t\t\t | " << t->bname << "\n";
            t = t->next;
        }

        cout << "-------------------------------------------------------------------------\n";
        cout << "\n";
}


    void create_Book()
    {   
        // Initialize y
        char y = 'y'; 

        node2 *nn;

        while (y == 'y')
        {
            nn = new node2;

            cout << "Enter book no : ";
            cin >> nn->bno;
            cout << "Enter book name : ";
            cin >> nn->bname;
            cout << "Enter author name : ";
            cin >> nn->author;

            nn->prev = NULL;
            nn->next = NULL;

            if (head2 == NULL)
            {
                head2 = nn;
            }
            else
            {
                node2 *temp; 
                temp= head2;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = nn;
                nn->prev = temp;
            }

            cout << "Want to create new book (y/n) ??: ";
            cin >> y;
        }
    }


    void display_Book()
    {
        node2 *t;
        t = head2;

        if (t == NULL)
        {
            cout << "NO DATA AVAILABLE!\n";
            return;
        }

        cout << "-------------------------------------------------\n";
        cout << "Book no\t| Book Name\t| Author Name\n";
        cout << "-------------------------------------------------\n";

        while (t != NULL)
        {
            cout << t->bno << "\t| " << t->bname << "  \t  | " << t->author<<"\t" << "\n";
            t = t->next;
        }

        cout << "-------------------------------------------------\n";
        cout << "\n";
    }



    void ins_after_Student()
    {
        if (head1 == NULL)
        {
            cout << "List of students is empty, cannot insert after a specific student!";
             cout<<"\n";
            return;
        }

        int key;
        cout << "Enter Specific addmision no: ";
        cin >> key;

        node1 *nn = new node1;


        cout << "Enter admission no : ";
        cin >> nn->admno;
        cout << "Enter name : ";
        cin >> nn->name;
        nn->no_issue=0;

        node1 *temp; 
        temp = head1;

        while (temp !=NULL)
        {
            if (temp->admno == key)
            {
                nn->next = temp->next;
                nn->prev = temp;
                if (temp->next != NULL)
                {
                    temp->next->prev = nn;
                }
                temp->next = nn;
                return;
            }
            temp = temp->next;
        }

        cout << "data not found.";
         cout<<"\n";
    }

    void ins_before_Student()
    {
        if (head1 == NULL)
        {
            cout << "List of student is empty, cannot insert before a specific student!\n";
            return;
        }

        int key;
        cout << "Enter student no : ";
        cin >> key;

        node1 *nn;
        nn = new node1;


        cout << "Enter admission no : ";
        cin >> nn->admno;
        cout << "Enter name : ";
        cin >> nn->name;
        nn->no_issue=0;

        if (head1->admno == key)
        {
            nn->next = head1;
            nn->prev = NULL;
            head1->prev = nn;
            head1 = nn;
            return;
        }

        node1 *temp; 
        temp = head1->next;

        while (temp != NULL)
        {
            if (temp->admno == key)
            {
                nn->next = temp;
                nn->prev = temp->prev;
                temp->prev->next = nn;
                temp->prev = nn;
                return;
            }
            temp = temp->next;
        }

        cout << "data not found.";
        cout<<"\n";
    }


    void ins_before_Book()
    {
        if (head2 == NULL)
        {
            cout << "List of books is empty, cannot insert before a specific book!";
            cout<<"\n";
            return;
        }

        int key;
        cout << "Enter specific book no : ";
        cin >> key;

        node2 *nn;
        nn = new node2;

        cout << "Enter book no : ";
        cin >> nn->bno;
        cout << "Enter book name : ";
        cin >> nn->bname;
        cout << "Enter author name : ";
        cin >> nn->author;

        if (head2->bno == key)
        {
            nn->next = head2;
            nn->prev = NULL;
            head2->prev = nn;
            head2 = nn;
            return;
        }

        node2 *temp; 
        temp = head2->next;

        while (temp != NULL)
        {
            if (temp->bno == key)
            {
                nn->next = temp;
                nn->prev = temp->prev;
                temp->prev->next = nn;
                temp->prev = nn;
                return;
            }
            temp = temp->next;
        }

        cout << "Book not found.\n";
    }

    void ins_after_Book()
    {
        if (head2 == NULL)
        {
            cout << "List of books is empty, cannot insert after a specific book!\n";
            return;
        }

        int key;
        cout << "Enter Specific book: ";
        cin >> key;

        node2 *nn; 
        nn = new node2;

        cout << "Enter book no : ";
        cin >> nn->bno;
        cout << "Enter book name : ";
        cin >> nn->bname;
        cout << "Enter author name : ";
        cin >> nn->author;

        node2 *temp; 
        temp = head2;

        while (temp != NULL)
        {
            if (temp->bno == key)
            {
                nn->next = temp->next;
                nn->prev = temp;
                if (temp->next !=NULL)
                {
                    temp->next->prev = nn;
                }
                temp->next = nn;
                return;
            }
            temp = temp->next;
        }

        cout << "Book not found.";
         cout<<"\n";
    }

    void del_spec_Book()
    {
        if (head2 == NULL)
        {
            cout << "List of books is empty, cannot delete a specific book.";
             cout<<"\n";
            return;
        }

        int key;
        cout << "Enter Specific Book No to delete: ";
        cin >> key;

        // Search for the book
        node2 *temp; 
        temp = head2;
        while (temp != NULL)
        {
            if (temp->bno == key)
            {
                // Check if the book is issued
                node1 *student; 
                student = head1;
                while (student != NULL)
                {
                    if (student->no_issue == 1 && student->bname == temp->bname)
                    {
                        cout << "Book is currently issued to a student. Please return it before deletion.\n";
                        return;
                    }
                    student = student->next;
                }

                // If the book is not issued, proceed with deletion
                if (temp->prev !=NULL)
                {
                    temp->prev->next = temp->next;
                }
                if (temp->next != NULL)
                {
                    temp->next->prev = temp->prev;
                }
                if (temp == head2)
                {
                    head2 = temp->next;
                }
                delete temp;
                cout << "Book deleted successfully!";
                 cout<<"\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Book not found.";
         cout<<"\n";
    }


    void del_spec_Student()
    {
        if (head1 == NULL)
        {
            cout << "List of students is empty, cannot delete a specific student!";
             cout<<"\n";
            return;
        }

        int key;
        cout << "Enter Specific student admission no to delete: ";
        cin >> key;

        node1 *temp; 
        temp = head1;

        while (temp != NULL)
        {
            if (temp->admno == key)
            {
                if (temp->prev != NULL)
                {
                    temp->prev->next = temp->next;
                }
                if (temp->next != NULL)
                {
                    temp->next->prev = temp->prev;
                }
                if (temp == head1)
                {
                    head1 = temp->next;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }

        cout << "student not found.";
         cout<<"\n";
    }


    void book_Issue()
    {
        int student_admno, book_bno;

        cout << "Enter student admission no: ";
        cin >> student_admno;

        // Search for the student
        node1 *student; 
        student= head1;
        while (student != NULL)
        {
            if (student->admno == student_admno)
            {
                break;
            }
            student = student->next;
        }

        if (student == NULL)
        {
            cout << "Student not found.";
             cout<<"\n";
            return;
        }

        // Check if the student has already issued a book
        if (student->no_issue == 1)
        {
            cout << "Student has already issued a book. Please return the existing book before issuing a new one.\n";
            return;
        }

        cout << "Enter book no to issue: ";
        cin >> book_bno;

        // Search for the book
        node2 *book ;
        book = head2;
        while (book != NULL)
        {
            if (book->bno == book_bno)
            {
                break;
            }
            book = book->next;
        }

        if (book == NULL)
        {
            cout << "Book not found.";
             cout<<"\n";
            return;
        }

        // Update student data
        student->bname = book->bname;
        student->no_issue = 1;

        cout << "Book issued successfully!";
         cout<<"\n";
    }

    void deposite_Book()
    {
        int student_admno;

        cout << "Enter student admission no: ";
        cin >> student_admno;

        // Search for the student
        node1 *student ;
        student = head1;
        while (student != NULL)
        {
            if (student->admno == student_admno)
            {
                break;
            }
            student = student->next;
        }

        if (student == NULL)
        {
            cout << "Student not found.";
             cout<<"\n";
            return;
        }

        // Check if the student has any book issued
        if (student->no_issue == 0)
        {
            cout << "No book issued for this student.";
             cout<<"\n";
            return;
        }

        // Update student data
        student->bname = "";
        student->no_issue = 0;

        cout << "Book deposited successfully!";
         cout<<"\n";
    }

};////end of class



void adminmenu(DoublyList &dlist)
{
    int ch;

    do
    {
        
        cout << "\n\n\n\t MENU";
        cout << "\n\n\t1. Add Student";
        cout << "\n\n\t2. Display Student Records";
        cout << "\n\n\t3. Add Book";
        cout << "\n\n\t4. Display Book Records";
        cout << "\n\n\t5. Add before a Student";
        cout << "\n\n\t6. Add before a book";
        cout << "\n\n\t7. Add after a Student";
        cout << "\n\n\t8. Add after a Book";
        cout << "\n\n\t9. Delete Student";
        cout << "\n\n\t10. Delete Book";
        cout << "\n\n\t11. Go back to Main Menu";
        cout << "\n\n\t0. Exit";
        cout << "\n\n\t Enter your choice (0-11): ";

        cin >> ch;

        switch (ch)
        {
        case 1:
            dlist.create_Student();
            break;
        case 2:
            dlist.display_Student();
            break;
        case 3:
            dlist.create_Book();
            break;
        case 4:
            dlist.display_Book();
            break;
        case 5:
            dlist.ins_before_Student();
            break;
        case 6:
            dlist.ins_before_Book();
            break;
        case 7:
            dlist.ins_after_Student();
            break;
        case 8:
            dlist.ins_after_Book();
            break;
        case 9:
            dlist.del_spec_Student();
            break;
        case 10:
            dlist.del_spec_Book();
            break;
        case 11:
        // Go back to the main menu
            return; 
        case 0:
            exit(0);
        default:
            cout << "Invalid choice!\n";
        }

    }
    while (ch != 0);
}

int main()
{
    DoublyList dlist;

    int choice;

    cout <<"\n\t\t\t\t *****CREATIVE COMPUTERS*****\n\n";
    
    cout << "\t\t\t\t\t WELCOME TO \n \t\t\t\t\t   LIBRARY \n  \t\t\t\t\t MANAGEMENT  \n  \t\t\t\t\t   SYSTEM \n\n";
    
    cout << endl;
    do
    {
        
        cout << "\n\n\n\t MAIN MENU";
        cout << "\n\n\n\t1 BOOK ISSUE";
        cout << "\n\n\n\t2 BOOK DEPOSIT";
        cout << "\n\n\n\t3 MENU";
        cout << "\n\n\n\t4 EXIT";
        cout << "\n\n\n\t PLEASE SELECT YOUR OPTION(1-4): ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            dlist.book_Issue();
            break;
        case 2:
            dlist.deposite_Book();
            break;
        case 3:
            // Call your administrator menu function
            adminmenu(dlist);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "INVALID CHOICE";
        }
    } while (choice != 4);

    
    return 0;
}





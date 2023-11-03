#include <iostream>
#include <conio.h>
using namespace std;

class base
{
public:
  string name;
  string id;
  long int sal;
};

class teacher : public base
{
  string sub;
  string subcode;

public:
  void create()
  {
    cout << "Enter name ";
    cin >> name;
    cout << "Enter id ";
    cin >> id;
    cout << "Enter salary ";
    cin >> sal;
    cout << "Enter subject ";
    cin >> sub;
    cout << "Enter subcode ";
    cin >> subcode;
  }
  void display()
  {
    cout << "Name is \t" << name << endl;
    cout << "Id is  \t\t" << id << endl;
    cout << "Salary is \t" << sal << endl;
    cout << "Subject is \t" << sub << endl;
    cout << "Subcode is \t" << subcode << endl;
  }

  friend void del(int _count, teacher t[]);
};

void del(int _count, teacher t[])
{

  if (_count == 0)
  {
    cout << "\nEmpty Recod" << endl;
    getch();
    return;
  }

  string id;

  cout << "Enter Teacher Id: ";
  cin >> id;

  int index;
  for (int i = 0; i < _count; i++)
  {
    if (t[i].id == id)
      index = i;
  }

  cout << "Teacher's Recod with Id:" << id << " named " << t[index].name << " deleted." << endl;

  for (int i = index; i < _count - 1; i++)
  {
    t[i].id = t[i + 1].id;
    t[i].sal = t[i + 1].sal;
    t[i].name = t[i + 1].name;
    t[i].sub = t[i + 1].sub;
    t[i].subcode = t[i + 1].subcode;
  }
}

class lbass : public base
{
  int floor;
  int lbno;

public:
  void cre()
  {
    cout << "Enter name ";
    cin >> name;
    cout << "Enter id ";
    cin >> id;
    cout << "Enter salary ";
    cin >> sal;
    cout << "Enter floor ";
    cin >> floor;
    cout << "Enter lab No. ";
    cin >> lbno;
  }
  void disp()
  {
    cout << "Name is \t" << name << endl;
    cout << "Id is  \t" << id << endl;
    cout << "Salary is \t" << sal << endl;
    cout << "Floor is \t" << floor << endl;
    cout << "Lab No is  \t" << lbno << endl;
  }

  friend void delL(int _count, lbass t[]);
};

void delL(int _count, lbass t[])
{

  if (_count == 0)
  {
    cout << "\nEmpty Recod" << endl;
    getch();
    return;
  }

  string id;

  cout << "Enter Lab Assistant's Id: ";
  cin >> id;

  int index;
  for (int i = 0; i < _count; i++)
  {
    if (t[i].id == id)
      index = i;
  }

  cout << "Lab Assistant's Recod with Id:" << id << " named " << t[index].name << " deleted." << endl;

  for (int i = index; i < _count - 1; i++)
  {
    t[i].id = t[i + 1].id;
    t[i].sal = t[i + 1].sal;
    t[i].name = t[i + 1].name;
    t[i].floor = t[i + 1].floor;
    t[i].lbno = t[i + 1].lbno;
  }
}

int main()
{
  teacher t[100];
  lbass l[100];
  int choice, count = 0, cont = 0;
  char test;

start:
  cout << "\n\n===== CU MANAGEMENT SYSTEM =====\n"
       << endl;
  cout << "1)  Teachers\n";
  cout << "2)  Lab Assistant\n";
  cout << "3)  Exit program\n\n";
  cout << "Enter your choice ";
  cin >> choice;
  switch (choice)

  {
  case 1:
    while (1)

    {
    teachers:
      cout << "\n=====TEACHERS INFORMATION=====\n\n";
      cout << "\nChoose your choice\n";
      cout << "1) Create\n";
      cout << "2) Display\n";
      cout << "3) Delete\n";
      cout << "4) Jump to Main Menu\n";
      cout << "Enter your choice: ";
      cin >> choice;
      switch (choice)
      {
      case 1:
        for (int i = count; i < 100; i++)
        {
          cout << endl;
          t[i].create();
          count++;
          cout << endl;
          cout << "\n\nAre you Interested in entering data\n";
          cout << "Enter y or n:-";
          cin >> test;
          if (test == 'y' || test == 'Y')
            continue;
          else
            goto teachers;
        }
      out1:
        break;

      case 2:
        for (int i = 0; i < count; i++)
        {
          cout << endl;
          t[i].display();
          cout << endl;
        }
        getch();
        break;

      case 3:

        del(count, t);

        count--;
        getch();
        goto teachers;
      }

    case 4:
      goto start;
    default:
      cout << "\nEnter choice is invalid\ntry again\n\n";
    }

  case 2:
    while (1)
    LA:
    {
      cout << "\n=====LAB ASSISTANT INFORMATION=====\n\n";
      cout << "\nChoose your choice\n";
      cout << "1) Create\n";
      cout << "2) Display\n";
      cout << "3) Delete\n";
      cout << "4) Jump to Main Menu\n";
      cout << "Enter your choice: ";
      cin >> choice;
      switch (choice)
      {
      case 1:
        for (int i = cont; i < 10; i++)
        {
          cout << endl;
          l[i].cre();
          cont++;
          cout << endl;
          cout << "\n\nAre you Interested in entering data\n";
          cout << "Enter y or n:-";
          cin >> test;
          if (test == 'y' || test == 'Y')
            continue;
          else
            goto LA;
        }
      out2:
        break;
      case 2:
        for (int i = 0; i < cont; i++)
        {
          cout << endl;
          l[i].disp();
          cout << endl;
        }
        getch();
        break;

      case 3:
        delL(cont, l);
        cont--;
        getch();
        goto LA;

      case 4:
        goto start;
      default:
        cout << "\nEnter choice is invalid\ntry again\n\n";
      }
    }

    case 3:
      goto exit;
  }

exit:
  cout << "EXITING PROGRAM";
}
#include <cstdlib>
#include <iostream>
#include <locale.h>

using namespace std;
// Билиотечные карточки книг
class Books
  {
        string nameBook;
        string nameAutor;
  public:
        int ID;
        int flag;                                                    //Флаг наличия на руках или в библиотеке
        Books();
        ~Books();
        void newBooks(int currentNumberBook);
        void viewBook();
  };


Books::Books()
  {
  }
Books::~Books()
  {
  }

void Books::newBooks(int currentNumberBook)
    {
    fflush(stdin); 
    cout<<"\n";
    cout<<"Вводите латинницей"<<endl; 
    ID=currentNumberBook;   
    fflush(stdin); 
    cout<<"Введите название книги: "<<endl;
    getline(cin,nameBook);
    cout<<"Введите имя автора:     "<<endl;
    getline(cin,nameAutor); 
    cout<<"Укажите наличие книги в билиотеке 1- в наличие, 0 - отсуствует: "<<endl;
    cin>>flag;
    cout<<"\n";
    }
void Books::viewBook()
  {
      cout<<"\n";
      cout<<"ID:"<<ID<<endl;  
      cout<<"Название книги: "<<nameBook<<endl;
      cout<<"Имя автора:     "<<nameAutor<<endl;
      cout<<"Наличие книги в билиотеке 1- в налчие, 0 - отсуствует: "<<flag<<endl;
      cout<<"\n";
  }  



void menu(Books *pointerOnFirstBook);                                        
void showmenu();                                   
void addBook(Books *currentPointer,int currentNumberBook);
void viewBook(Books *pointerOnFirstBook,int tmpSumAllBooks);
void viewBook(Books *pointerOnFirstBook,int tmpSumAllBooks,int f);
void viewBook(Books *pointerOnFirstBook,int tmpSumAllBooks,float f);


int main()
  {
      setlocale(LC_ALL,"RUS");
      Books book[10];
      menu(book);
      system("PAUSE");
      return EXIT_SUCCESS;
  }
   
void addBook(Books *currentPointer,int currentNumberBook)             //Добавление нового объекта класса Book
  {
      currentPointer->newBooks(currentNumberBook);

  }          
void addBook(Books *currentPointer,int tmpSumAllBooks,int f)          //Изменение поля flag объекта класса Book
  {
      int tmp=0;
      cout<<"Введите ID книги статус которой хотите изменить: "<<endl;
      cin>>tmp;
      for(int j=0;j<tmpSumAllBooks;j++)
      {
       if(currentPointer->ID==tmp)
          {
          cout<<"Укажите наличие книги в билиотеке 1- в наличие, 0 - отсуствует: "<<endl;
          cin>>currentPointer->flag;
          }
        currentPointer++;  
      }
  }        

void viewBook(Books *pointerOnFirstBook,int tmpSumAllBooks)           //Вывод на экран всех объектов класса Book
  {
    for(int j=0;j<tmpSumAllBooks;j++)
      {
      pointerOnFirstBook->viewBook();
      pointerOnFirstBook++;
      }
  }        
void viewBook(Books *pointerOnFirstBook,int tmpSumAllBooks,int f)     //Вывод на экран всех объектов с flag==1 класса Book
  {
    for(int j=0;j<tmpSumAllBooks;j++)
      {
       if(pointerOnFirstBook->flag==1)
        {
        pointerOnFirstBook->viewBook();
        }
        pointerOnFirstBook++;  
      }
  }
void viewBook(Books *pointerOnFirstBook,int tmpSumAllBooks,float f)   //Вывод на экран всех объектов с flag==0 класса Book
  {

    for(int j=0;j<tmpSumAllBooks;j++)
      {
       if(pointerOnFirstBook->flag==0)
        {
        pointerOnFirstBook->viewBook();
        }
        pointerOnFirstBook++;  
      }
  }

void menu(Books *pointerOnFirstBook)
  {
    int tmpSumAllBooks=0;
    int flag1=0;                                                      // Просто флаг для перегрузки функции viewBook
    float flag0=0.;                                                   // Просто флаг для перегрузки функции viewBook
    Books *currentPointer;
    currentPointer=pointerOnFirstBook;

    char ch = 0;
    while (ch != '0')
    {
    showmenu();
      fflush(stdin);
      cin>>ch;
      switch (ch)
      {
      case '1':
        viewBook(pointerOnFirstBook,tmpSumAllBooks);
        break;
      case '2':
        tmpSumAllBooks++;
        addBook(currentPointer,tmpSumAllBooks);
        currentPointer++;
        break;
      case '3':
        viewBook(pointerOnFirstBook,tmpSumAllBooks,flag1);
        break;  
      case '4':
        viewBook(pointerOnFirstBook,tmpSumAllBooks,flag0);
        break; 
      case '5':
        addBook(pointerOnFirstBook,tmpSumAllBooks,flag1);
        break;            
      case '0':
        cout<<"\nGoodbay!\n\n";
        break;
      default:
        cout<<"\nМимо\n\n";
        break;
      }
    }
  }
void showmenu()
  {
    cout<<"Меню:\n";
    cout<<"Введите 1 чтобы вывести все карточки на экран \n";
    cout<<"Введите 2 создать новую карточку\n";
    cout<<"Введите 3 чтобы вывести на экран все книги в наличие\n";
    cout<<"Введите 4 чтобы вывести на экран книги отсутсвующие\n";
    cout<<"Введите 5 чтобы изменить статус книги\n";
    cout<<"Введите 0 чтобы выйти\n";
  }

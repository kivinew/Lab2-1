#include <cstdlib>
#include <iostream>
#include<locale.h>

using namespace std;

class Books
  {
        string nameBook;
        string nameAutor;
  public:
        int ID;
        int flag;
        Books();
        ~Books();
        void newBooks(int i);
        void viewBook();
  };

Books::Books()
	{
	}
Books::~Books()
	{
	}

void Books::newBooks(int i)
    {
    fflush(stdin); 
    cout<<"\n";
    cout<<"Вводите латинницей"<<endl; 
    ID=i;   
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



void menu(Books *p);                                        
void showmenu();                                   
void addBook(Books *p,int i);
void viewBook(Books *p,int i);
void viewBook(Books *p,int i,int f);
void viewBook(Books *p,int i,float f);


int main()
  {
      setlocale(LC_ALL,"RUS");
      Books book[10];
      menu(book);
      system("PAUSE");
      return EXIT_SUCCESS;
  }

void addBook(Books *p,int i)
  {
      p->newBooks(i);

  }
void addBook(Books *p,int i,int f)
  {
      int tmp=0;
      cout<<"Введите ID книги статус которой хотите изменить: "<<endl;
      cin>>tmp;
      for(int j=0;j<i;j++)
      {
       if(p->ID==tmp)
          {
          cout<<"Укажите наличие книги в билиотеке 1- в наличие, 0 - отсуствует: "<<endl;
          cin>>p->flag;
          }
        p++;  
      }
  }

void viewBook(Books *p,int i)
  {
  	for(int j=0;j<i;j++)
      {
      p->viewBook();
      p++;
      }
  }
void viewBook(Books *p,int i,int f)
  {
    for(int j=0;j<i;j++)
      {
       if(p->flag==1)
        {
        p->viewBook();
        }
        p++;  
      }
  }
void viewBook(Books *p,int i,float f)
  {
    for(int j=0;j<i;j++)
      {
       if(p->flag==0)
        {
        p->viewBook();
        }
        p++;  
      }
  }

void menu(Books *p)
  {
  	int i=0;
    int flag1=0;
    float flag0=0.;
  	Books *view;
  	view=p;

  	char ch = 0;
  	while (ch != '0')
  	{
  	showmenu();
  		fflush(stdin);
  		cin>>ch;
  		switch (ch)
  		{
  		case '1':
  			viewBook(view,i);
  			break;
  		case '2':
  		  i++;
        addBook(p,i);
        p++;
  			break;
      case '3':
        viewBook(view,i,flag1);
        break;  
      case '4':
        viewBook(view,i,flag0);
        break; 
      case '5':
        addBook(view,i,flag1);
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

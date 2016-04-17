#include <cstdlib>
#include <iostream>
#include<locale.h>

using namespace std;

class Books
{
      string nameBook;
      string nameAutor;
      int ID;
public:
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
    cout<<"Укажите наличие книги в билиотеке 1- в налчие, 0 - отсуствует: "<<endl;
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

void viewBook(Books *p,int i)
{
    int j;	
	for(j=0;j<i;j++)
    {
    p->viewBook();
    p++;
    }
}
void viewBook(Books *p,int i,int f)
{
  int j;

  for(j=0;j<i;j++)
    {
     if(p->flag==1)
      {
      p->viewBook();
      }
      p++;  
    }
}

void menu(Books *p)
{
	int i=0;
  int f=0;
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
  viewBook(view,i,f);
  break;  
    case '4':
viewBook(view,i);
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
	cout<<"Введите 0 чтобы выйти\n";
}

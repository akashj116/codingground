#include <iostream>
#include <string.h>
using namespace std;


class LibrarySearchEngine {     //This is an interface.. contains pure virtual functions which should be implemented by derived classes
    public:
        virtual bool search_isbn(int isbn) = 0;
        virtual bool search_title(const char *title) = 0;
};

class LseImpl1: public LibrarySearchEngine {
    public: 
        LseImpl1()
        {
            cout <<"LseImpl1 constructor\n";
        }
        bool search_isbn(int isbn)
        {
            if(isbn == 1)
            {
                cout << "search_isbn: book found\n";
                return true;
            }
            else
            {
                cout << "search_isbn: book not found\n";
                return false;
            }
        }
        bool search_title(const char *title)
        {
            if (!strcmp("jungle book LseImpl1", title))
            {
                cout<< "search_title: book found\n";
                return true;
            }
            else
            {
                cout <<"search_tile: book not found\n";
                return false;
            }
        }
    
};

class LseImpl2: public LibrarySearchEngine {
    public: 
        LseImpl2()
        {
            cout <<"LseImpl2 constructor\n";
        }
        bool search_isbn(int isbn)
        {
            if(isbn == 2)
            {
                cout << "book found\n";
                return true;
            }
            else
            {
                cout << "book not found\n";
                return false;
            }
        }
        bool search_title(const char *title)
        {
            if (!strcmp("jungle book LseImpl2", title))
            {
                cout<< "book found\n";
                return true;
            }
            else
            {
                cout <<"book not found\n";
                return false;
            }
        }
    
};

class LseFactory {      //This is factory design pattern class.. because it removes responsibility from client to create the object and itself handles object creation.
    public:
        LseFactory()
        {
            cout <<"LseFactory constructor\n";
        }
        LibrarySearchEngine* get_lse(int impl_id)   //** This input variable can be read from config file rather being passed by the client.
        {
            switch (impl_id)    //This implementation is strategy pattern.. because at run time we are deciding which impl object to create.
            {
                case 1:
                    cout <<"LseFactory: case 1" <<endl;
                    return new LseImpl1();
                case 2:
                    cout <<"LseFactory: case 2" <<endl;
                    return new LseImpl2();
            }
        }
};

int main()
{
   cout << "Client to Lse " << endl; 
   LseFactory lse_factory;
   LibrarySearchEngine* pLse_object = lse_factory.get_lse(1);
   const char *search_name = "jungle book LseImpl1";
   if (pLse_object->search_title(search_name))
   {
       cout <<"client: book found: " << search_name<< endl;
   }
   else
        cout <<"client: book not found: " << search_name << endl;
    
    search_name = "jungle book LseImpl2";
    
   if (pLse_object->search_title("search_name"))
        cout <<"client: book found: " << search_name<< endl;
    else
        cout <<"client: book not found: " << search_name << endl;
        
    int isbn =1;
   if(pLse_object->search_isbn(isbn))
        cout <<"client: book found: isbn =" << isbn<< endl;
    else
        cout <<"client: book not found: isbn=" << isbn << endl;
   
   isbn =2;
   if(pLse_object->search_isbn(isbn))
        cout <<"client: book found: isbn =" << isbn<< endl;
    else
        cout <<"client: book not found: isbn=" << isbn << endl;
   return 0;
}


#include <iostream>
#include <string>
using namespace std;

class librarayitem{
    public:
    virtual void display() = 0;
    
};
class book : public librarayitem{
    private:
    string title;
    string auther;
    int page;

    public:
    book(){
        title = "nullptr";
        auther = "nullptr";
        page = 0;
    };
    book(string t, string a, int p){
        title = t;
        auther = a;
        page = p;
    }
    int getterpage(){
        return page;
    }
    string gettertitle(){
        return title;
    }
    void display(){
        cout << "book" << title << endl;
        cout << "auther " << auther << endl;
        cout << "pages " << page << endl;
    }
};
class newspaper : public librarayitem{
    private:
    string name;
    string date;
    string edition;
    
    public:
    newspaper(string n, string d, string e){
        name = n;
        date = d;
        edition = e;
    }
    string gettername(){
        return name;
    }  
    string getteredition(){
        return edition;
    }
    void display(){
        cout << "newspaper" << name << endl;
        cout << "date " << date << endl;
        cout << "edition " << edition <<endl;
    }
};
class library{
    private:
    book books[50];
    newspaper newspapers[50];
    int bookcount;
    int newspaperscount;

    public:
    void addbook(book b){
        books[bookcount ++] = b;
    }
    void addnewspaper(newspaper n){
        newspapers[newspaperscount ++] = n;
    }
    void displaycollection(){
        cout << "books" << endl;
        for(int i = 0; i < bookcount; i++){
            books[i].display();
        }
        cout << "newspaper " << endl;
        for(int i = 0; i < newspaperscount; i++){
            newspapers[i].display();
        }
    }
    void sortbook(){
        for(int i = 0; i < bookcount - 1; i++){
            for(int j = i + 1; j < bookcount; j++){
                if(books[i].getterpage() > books[j].getterpage()){
                    book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
    }
    void sortNewspaper() {
        for (int i = 0; i < newspaperscount - 1; i++){
            for (int j = i + 1; j < newspaperscount; j++){
                if (newspapers[i].getteredition() > newspapers[j].getteredition()) {
                    newspaper temp = newspapers[i];
                    newspapers[i] = newspapers[j];
                    newspapers[j] = temp;
                }
            }
        }
    }
    book linearsearchbook(string title) {
        for (int i = 0; i < bookcount; i++){
            if (books[i].gettertitle() == title){
                return books[i];
            }
        }
    }
    newspaper linearsearchnewspaper(string name) {
        for (int i = 0; i < newspaperscount; i++){
            if (newspapers[i].gettername() == name){
                return newspapers[i];
            }
        }
    } 
    book binarysearchbook(string title) {
        int low = 0, high = bookcount - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (books[mid].gettertitle() == title){
                return books[mid];
            }
            else if (books[mid].gettertitle() < title){
                low = mid + 1;
            }
            else{ 
                high = mid - 1;
            }
        }
    }
    newspaper binarysearchnewspaper(string name) {
        int low = 0, high = newspaperscount - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (newspapers[mid].gettername() == name){
                 return newspapers[mid];
            }
            else if (newspapers[mid].gettername() < name) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
};
int main() {
   
    book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    book book2("To Kill a Mockingbird", "Harper Lee", 324);

    newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    library lib;

    lib.addbook(book1);
    lib.addbook(book2);
    lib.addnewspaper(newspaper1);
    lib.addnewspaper(newspaper2);

    cout << "Before Sorting:";
    lib.displaycollection();

    lib.sortbook();
    lib.sortNewspaper();

    cout << endl;  
    cout << "After Sorting:";
    lib.displaycollection();

    cout << "Linear Search Results:";
    book foundBook1 = lib.linearsearchbook("The Catcher in the Rye");
    foundBook1.display();

    newspaper foundNewspaper1 = lib.linearsearchnewspaper("The Times");
    foundNewspaper1.display();

    cout << "\nBinary Search Results:\n";
    book foundBook2 = lib.binarysearchbook("The Catcher in the Rye");
    foundBook2.display();

    newspaper foundNewspaper2 = lib.binarysearchnewspaper("The Times");
    foundNewspaper2.display();

    return 0;
}


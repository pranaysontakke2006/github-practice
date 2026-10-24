#include<iostream>
#include<string>
using namespace std;
class Publication
{
protected:
 string title;
 float price;
 int copies;
public:
 Publication(string t, float p, int c)
 {
 title = t;
 price = p;
 copies = c;
 }
 float saleCopy()
 {
 return price * copies;
 }
};
class Book : public Publication
{
private:
 string author;
public:
 Book(string t, float p, int c, string a) : Publication(t, p, c)
 {
 author = a;
 }
 void orderCopies(int qty)
 {
 copies = qty;
 }
 void display()
 {
 cout << "\nBook Title: " << title;
 cout << "\nAuthor: " << author;
 cout << "\nPrice: " << price;
 cout << "\nCopies Ordered: " << copies;
 cout << "\nTotal Sale: " << saleCopy();
 }
};
class Magazine : public Publication
{
public:
 Magazine(string t, float p, int c) : Publication(t, p, c)
 {
 }
 void orderQty(int qty)
 {
 copies = qty;
 }
 void currentIssue()
 {
 cout << "\nCurrent Issue: " << title;
 }
 void receiveIssue() 
 {
 cout << "\nIssue received successfully.";
 }
 void display()
 {
 cout << "\nMagazine Title: " << title;
 cout << "\nPrice: " << price;
 cout << "\nCopies Ordered: " << copies;
 cout << "\nTotal Sale: " << saleCopy();
 }
};
int main()
{
 string title, author;
 float price;
 int copies;
 cout << "Enter Book Title: ";
 cin >> title;
 cout << "Enter Author: ";
 cin >> author;
 cout << "Enter Book Price: ";
 cin >> price;
 cout << "Enter Number of Book Copies: ";
 cin >> copies;
 Book b(title, price, copies, author);
 cout << "\n--- Book Details ---";
 b.display();
 cout << "\n\nEnter Magazine Title: ";
 cin >> title;
 cout << "Enter Magazine Price: ";
 cin >> price;
 cout << "Enter Number of Magazine Copies: ";
 cin >> copies;
 Magazine m(title, price, copies);
 cout << "\n--- Magazine Details ---";
 m.display();
 m.currentIssue();
 m.receiveIssue();
 return 0;
}

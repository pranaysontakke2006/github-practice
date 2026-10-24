#include <iostream>
#include <string>
using namespace std;
class Employee
{
protected:
 string emp_name, address, mail_id, mobile_no;
 int emp_id;
 void calculateSalary(float bp)
 {
 float da, hra, pf, scf, gross, net;
 da = 0.52 * bp;
 hra = 0.27 * bp;
 pf = 0.12 * bp;
 scf = 0.001 * bp;
 gross = bp + da + hra;
 net = gross - pf - scf;
 cout << "\nBasic Pay: " << bp;
 cout << "\nDA: " << da;
 cout << "\nHRA: " << hra ;
 cout << "\nPF: " << pf;
 cout << "\nStaff Club Fund: " << scf;
 cout << "\nGross Salary: " << gross;
 cout << "\nNet Salary: " << net;
 }
 void getData()
 {
 cout << "\nEnter Employee Name: ";
 cin >> emp_name;
 cout << "Enter Employee ID: ";
 cin >> emp_id;
 cout << "Enter Address: ";
 cin >> address;
 cout << "Enter Mail ID: ";
 cin >> mail_id;
 cout << "Enter Mobile No: ";
 cin >> mobile_no;
 }
void displayData()
 {
 cout << "\nEmployee Name: " << emp_name;
 cout << "\nEmployee ID: " << emp_id;
 cout << "\nAddress: " << address;
 cout << "\nMail ID: " << mail_id;
 cout << "\nMobile No: " << mobile_no;
 }
};
class Programmer : public Employee
{
private:
 float bp;
public:
 void show()
 {
 cout << "\n\n----- PROGRAMMER PAY SLIP -----";
 getData();
 cout << "Enter Basic Pay: ";
 cin >> bp;
 displayData();
 calculateSalary(bp);
 }
};
class TeamLead : public Employee
{
private:
 float bp;
public:
 void show()
 {
 cout << "\n\n----- TEAM LEAD PAY SLIP -----";
 getData();
 cout << "Enter Basic Pay: ";
 cin >> bp;
 displayData();
 calculateSalary(bp);
 }
};
class AssistantProjectManager : public Employee
{
private:
 float bp;
public:
 void show()
 {
 cout << "\n\n----- ASSISTANT PROJECT MANAGER PAY SLIP -----";
 getData();
 cout << "Enter Basic Pay: ";
 cin >> bp;
 displayData();
 calculateSalary(bp);
 }
};
class ProjectManager : public Employee
{
private:
 float bp;
public:
 void show()
 {
 cout << "\n\n----- PROJECT MANAGER PAY SLIP -----";
 getData();
 cout << "Enter Basic Pay: ";
 cin >> bp;
 displayData();
 calculateSalary(bp);
 }
};
int main()
{
 Programmer p;
 TeamLead t;
 AssistantProjectManager a;
 ProjectManager m;
 p.show();
 t.show();
 a.show();
 m.show();
 return 0;
}
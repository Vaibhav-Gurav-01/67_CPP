/*
Write a C++ program to accpet worker information Worker_Name, No_Of_Hours_Worked,
Pay_Rate and Salary. Write necessary functions to calculate and display the salary of Worker. (Use
Default values for Pay_Rate Rs. 500 per hours)
*/

#include <iostream>
using namespace std;


class Worker
{
	private:
	    string Worker_Name;
	    int No_Of_Hours_Worked;
	    double Pay_Rate; 
	    
	public:
	
	    Worker(string name, int hours, double rate = 500.0)  
			{
				Worker_Name=name;
				 No_Of_Hours_Worked=hours; 
				 Pay_Rate=rate;
			}
	
	    double salary()  
		{
	        return No_Of_Hours_Worked * Pay_Rate;
	    }
	
	    void display() 
		{
	    cout << "\nWorker Name: " << Worker_Name << endl;
	    cout << "No of Hours Worked: " << No_Of_Hours_Worked <<endl;
	    cout << "\nPay Rate: Rs. " << Pay_Rate << " per hour" <<endl;
	    cout << "Total Salary: Rs. " << salary()<<endl;
	    }
};

main()
{
    string name;
    int hours;

     cout << "Enter Worker Name: ";
     getline( cin, name);
     
     cout << "Enter Hours Worked: ";
     cin >> hours;

    Worker worker(name, hours);

    worker.display();

}
#include <iostream>
#include <string>
using namespace std;

class Cars{
    private:
        //member variables
        string company_name; //string class instead of char companyname[50]
        string model_name;
        string fuel_type;
        float mileage;
        double price;

    public:
        //Default Constructor to initialize the member variables
        /* Cars()
        {   
            cout<<"Default Constructor Called"<<endl;
        } */

        //Constructor
        /* Cars()
        {
            company_name = "Toyota";
            model_name = "Altis";
            fuel_type = "Petrol";
            mileage = 15;
            price = 150000;
        } */

        //Default Constructor
        Cars()
        {
            cout<<"Default Constructor Called"<<endl;
            company_name = "Toyota";
        }
        //Parameterized Constructor
        Cars(string cname, string mname, string ftype, float m, double p)
        {
            cout<<"Parameterized Constructor Called"<<endl;
            company_name = cname;
            model_name = mname;
            fuel_type = ftype;
            mileage = m;
            price = p;
        }
        //Copy Constructor
        Cars(Cars &obj)
        {
            cout<<"Copy Constructor Called"<<endl;
            company_name = obj.company_name;
            model_name = obj.model_name;
            fuel_type = obj.fuel_type;
            mileage = obj.mileage;
            price = obj.price;
        }


        //member functions
        void setData(string cname,  string mname, string ftype, float m, double p)
        {
            company_name = cname;
            model_name = mname;
            fuel_type = ftype;
            mileage = m;
            price = p;
        }
        void displayData()
        {
            cout<<"Car Properties: "<<endl<<endl;
            cout<<"Car Company Name: "<<company_name<<endl;
            cout<<"Car Company Model: "<<model_name<<endl;
            cout<<"Car Fuel Type: "<<fuel_type<<endl;
            cout<<"Car Mileage: "<<mileage<<endl;
            cout<<"Car Price: "<<price<<endl<<endl;
        }

        //Destructor
        ~Cars()
        {
            cout<<"Destructor called"<<endl;
        }
};


int main()
{
    //car1 --> Default constructor called
    //car2 --> Parameterized constructor called

    Cars car1,car2("Toyota","Fortuner","Diesel",10,350000); //multiple object of Cars
    car1.setData("Toyota","Altis","petrol",15.5,150000); //if you comment this and directly display data, then default values are assigned to member variables
    car1.displayData(); 
    car2.displayData(); 

    Cars car3 = car1; //Copy constructor called
    car3.displayData(); 
    return 0;
}
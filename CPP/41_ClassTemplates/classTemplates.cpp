#include <iostream>
using namespace std;

//Class Template
template <typename T, typename U>
class Weight{
    private:
        T kg;
        U grams;
        int a;
        double b;
    public:
        void setData(T x, U y)
        {
            kg = x;
            grams = y;
        }
        T getKgData()
        {
            return kg;
        }
        U getGramData()
        {
            return grams;
        }
};

int main(){
    /* Weight <int>obj1;
    obj1.setData(5);
    cout<<"value is: "<<obj1.getData()<<endl;

    Weight <double>obj2;
    obj2.setData(5.432);
    cout<<"value is: "<<obj2.getData()<<endl; */

    Weight <int, double>obj1;
    obj1.setData(5,0.534);
    cout<<"value is: "<<obj1.getKgData()<<endl;
    cout<<"value is: "<<obj1.getGramData()<<endl;


}

/*Create a class named Fruit with a data member to calculate the number of fruits in a basket. Create two
other class named Apples and Mangoes to calculate the number of apples and mangoes in the basket.
Print the number of fruits of each type and the total number of fruits in the basket.(Inheritance)
*/



#include <iostream>
using namespace std;

class Fruit {
	protected:
	    int total;
	
	public:
	    Fruit() {
	    	 total= 0;
		}
	
	    virtual void addFruits(int count)
		{
	        total += count;
	    }
	
	    virtual int get_Total()  
		{
	        return total;
	    }

    virtual void display() const = 0; 
};
  



class Apples : public Fruit
{
	private:
  		  int appleCount;

	public:
   		 
	Apples()  
	{
		appleCount=0;
	}
			


    void addFruits(int count)
	 {
        appleCount += count;
        total += count;
    }
      

    int getAppleCount()
	 {
        return appleCount;
    }

    void display()
	 {
        cout << "Number of Apples: " << appleCount <<endl;
    }
};

	class Mangoes : public Fruit {
private:
    int mangoCount;

public:
    Mangoes() 
	 {
	 mangoCount=0;
	 
	 }

    void addFruits(int count) {
        mangoCount += count;
        total += count;
    }

    int getMangoCount()  {
        return mangoCount;
    }

    void display()  {
        cout << "Number of Mangoes: " << mangoCount <<endl;
    }
};


int main() {
    Apples appleBasket;
    Mangoes mangoBasket;

    appleBasket.addFruits(10);
    mangoBasket.addFruits(5);

    appleBasket.display();
    mangoBasket.display();

     cout << "Total Fruits in the Basket: " << appleBasket.get_Total() <<  endl;

    return 0;
}

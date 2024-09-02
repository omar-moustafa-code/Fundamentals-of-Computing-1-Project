#include <iostream>
#include <cstring>
using namespace std;

class Product
{
private:
    string name;
    int quantity;
    float price;
    string category;

public:
    Product()
    {

    }

    Product(string n, int q, float p, string c)
    {
        name = n;
        quantity = q;
        price = p;
        category = c;
    }

    string get_Name()
    {
        return name;
    }

    int get_Quantity()
    {
        return quantity;
    }

    float get_Price()
    {
        return price;
    }

    string get_Category()
    {
        return category;
    }

    void set_Name(string n)
    {
        name = n;
    }

    void set_Quantity(int q)
    {
        quantity = q;
    }

    void set_Price(float p)
    {
        price = p;
    }

    void set_Category(string c)
    {
        category = c;
    }

    void Display()
    {
        cout << "Name = " << name << endl;
        cout << "Price = " << price << endl;
        cout << "Quantity = " << quantity << endl;
        cout << "Category = " << category << endl;
    }

    void Buy()
    {
        quantity--;
    }

    void Return()
    {
        quantity++;
    }


};

class EWallet
{
private:
    int id;
    float balance;

public:
    EWallet()
    {
        balance = 0;
    }

    EWallet(int wid, float b)
    {
        id = wid;
        balance = b;
    }

    void setID(int i)
    {
        id = i;
    }

    void setBalance(float b)
    {
        balance = b;
    }

    int getID()
    {
        return id;
    }

    float getBalance()
    {
        return balance;
    }

    bool enoughBalance(float amount)
    {
        if (balance >= amount)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Pay(float amount)
    {
        balance = balance - amount;
        cout << "Payment Successful." << endl;
        cout << "Your remaining balance is " << balance << endl;

    }

    void topUp(float amount)
    {
        balance = balance + amount;
        cout << "Your balance is now " << balance << endl;
    }

    void printBalance()
    {
        cout << "Your balance = " << balance << endl;
    }

};


class Cart
{
private:
    int id;
    bool rush;
    Product products[20];
    int number_of_products;
    float totalPrice;

public:
    Cart()
    {
        rush = false;
        number_of_products = 0;
        totalPrice = 0;
    }

    Cart(int cart_id, bool r)
    {
        id = cart_id;
        rush = r;
        number_of_products = 0;
        totalPrice = 0;
    }

    int getID()
    {
        return id;
    }

    void setID(int i)
    {
        id = i;
    }

    void add(Product p)
    {
        products[number_of_products] = p;
        number_of_products++;
        totalPrice += p.get_Price();
    }

    void remove(Product p,int index)
    {
        Product p_empty;

        products[index] = products[number_of_products-1];
        products[number_of_products-1] = p_empty;

        number_of_products--;
        totalPrice=totalPrice-p.get_Price();

    }

    float getTotalPrice()
    {
        return totalPrice;
    }

    void Checkout()
    {
        Product p_empty;

        for (int i=0; i<number_of_products; i++)
        {
            products[i].Buy();
            products[i] = p_empty;
        }

    }

    void displayProducts()
    {
        for (int i=0; i<number_of_products; i++)
        {
            cout << i+1 << ". " << products[i].get_Name() << endl;
        }
    }

};

class Customer
{
private:
    string name;
    int mobile;
    int id;
    int accountNumber;
    string email;

public:
    EWallet wallet;
    Cart cart;

    Customer(string n, int m, int i, int acc, string e)
    {
        name = n;
        mobile = m;
        id = i;
        accountNumber = acc;
        email = e;
    }

    void display()
    {
        cout << "Name = " << name << endl;
        cout << "Mobile = " << mobile << endl;
        cout << "ID = " << id << endl;
        cout << "Account Number = " << accountNumber << endl;
        cout << "Email = " << email << endl;
    }

    void setName(string n)
    {
        name = n;
    }

    void setMobile(int n)
    {
        mobile = n;
    }

    void setID(int n)
    {
        id = n;
    }

    void setAccountNumber(int n)
    {
        accountNumber = n;
    }

    void setEmail(string n)
    {
        email = n;
    }

    void Checkout()
    {
        float amount = cart.getTotalPrice();

        if (wallet.enoughBalance(amount) == true)
        {
            wallet.Pay(amount);
            cart.Checkout();
        }
        else
        {
            cout << "Balance insufficient." << endl;
        }
    }

};

int main()
{

    Product Redbull("Redbull", 100, 35, "Drinks");
    Product Bag("Bag", 20, 400, "Accessories");
    Product Tshirt("Tshirt", 50, 200, "Clothes");
    Product Pants("Pants", 50, 350, "Clothes");

    Product productsArray[] = {Redbull, Bag, Tshirt, Pants};

    Customer Camelia("Camelia", 1111, 1111, 1111, "email");

    cout << "Welcome to our Shop! \n\n";
    int options;
    cout << "Choose what you wish to do." << endl;
    cout << "1. Add products to cart." << endl;
    cout<<"2. Remove products from cart"<<endl;
    cout << "3. Add balance to wallet." << endl;
    cout << "4. Check balance." << endl;
    cout << "5. Checkout cart." << endl;
    cout << "6. View cart."<< endl;
    cin >> options;
    do
    {
        if (options == 1)
        {
            cout << "\n\nOur available products are: \n" << endl;

            for (int i=0; i<4; i++)
            {
                cout << "Product " << i+1 << endl;
                productsArray[i].Display();
                cout << endl;
            }

            int add;
            int index;


            do
            {
                cout << "\nPlease enter the product number." << endl;
                cin >> index;
                cout << endl;
                productsArray[index-1].Display();
                cout << endl;

                Camelia.cart.add(productsArray[index-1]);

                cout << "Do you wish to add another product? (1 for YES, 0 for NO)" << endl;
                cin >> add;
                cout << endl;

            } while (add == 1);
        }

        else if(options==2)
        {
            int index;
            cout << "\nPlease enter the product number you want remove." << endl;
            cin >> index;
            cout << endl;
            productsArray[index-1].Display();
            cout << endl;

            Camelia.cart.remove(productsArray[index-1],index);


        }
        else if (options == 3)
        {
            float amount;
            cout << "Enter the amount you wish to add." << endl;
            cin >> amount;
            cout << endl;

            Camelia.wallet.topUp(amount);
        }
        else if (options == 4)
        {
            Camelia.wallet.printBalance();
            cout << endl;
        }
        else if (options == 5) {
            int x;
            Camelia.cart.displayProducts();
            cout << endl;
            cout << "Enter 1 for pay on delivery or enter 2 for credit card payment" << endl;
            cin>> x;
            if(x==1){
                cout << "Total price of cart is " << Camelia.cart.getTotalPrice() << endl;


            }
            if (x == 2) {
                cout << "Do you want to proceed with the checkout? (1 for YES, 0 for NO)" << endl;
                bool proceed;
                cin >> proceed;
                cout << endl;
                cout << "Total price of cart is " << Camelia.cart.getTotalPrice() << endl;
                if (proceed == 1) {
                    Camelia.Checkout();
                }
            }
        }
        else if(options==6)
        {
            Camelia.cart.displayProducts();
        }

        cout << "Choose what you wish to do." << endl;
        cout << "1. Add products to cart." << endl;
        cout << "2. Remove product from cart" << endl;
        cout << "3. Add balance to wallet." << endl;
        cout << "4. Check balance." << endl;
        cout << "5. Checkout cart." << endl;
        cout << "6. View cart." << endl;
        cout << "7. Exit." << endl << endl;
        cin >> options;
        cout << endl;
    }
    while (options != 7);

}


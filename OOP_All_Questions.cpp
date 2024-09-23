                           //        LAB-1

// 1. WAP to print hello world in c++
#include <iostream>
using namespace std;
int main() {
    cout << "Hello, World!" <<endl;
    return 0;
}

// 2. Create a class car with data members cc, speed, color and member function start, stop, accelerate

#include <iostream>
#include <string>
using namespace std;

class Car {
    private:
        string color;
        int speed;
        int cc;
    public:
        void setCar(int car_cc, int car_speed, string car_color) {
            cc = car_cc;
            speed = car_speed;
            color = car_color;
        }
        void start() {
            cout << "Car started" << endl;
        }
        void stop() {
            cout << "Car stopped" << endl;
        }
        void accelerate() {
            cout << "Car accelerated" << endl;
        }
        void displayDetails() {
            cout << "Car CC = " << cc << endl;
            cout << "Car speed = " << speed << endl;
            cout << "Car color = " << color << endl;
        }
};

int main() {
    Car c;
    c.setCar(1500, 120, "Black");
    c.displayDetails();
    c.start();
    c.accelerate();
    c.stop();
    return 0;
}

//  3. Create a class called employee  with data members emp_id, name, salary and member function display details.
// initialize data members using parameterized constructor. Data members must be private.

#include <iostream>
#include <string>
using namespace std;
class Employee {
private:
    int id;
    string name;
    float salary;
public:
    void setEmployee(int emp_id, const string &emp_name, float emp_salary) {
        id = emp_id;
        name = emp_name;
        salary = emp_salary;
    }

    void displayDetails() const {
        cout << "Name = " << name << endl;
        cout << "Id = " << id << endl;
        cout << "Salary = " << salary << endl;
    }
};
int main() {
    Employee e;
    e.setEmployee(6, "Abis Pokharel", 450000);
    e.displayDetails();
    return 0;
}

//4. Create class students with data members student name, roll and age.
// member functions getname, setname, getage, setage, getroll, setroll, display details.

#include<iostream>
#include<string>
using namespace std;

class Student{
    private:
        int roll;
        string name;
        int age;

    public:
        void setName(string student_name){
            name = student_name;
        }
        void setRoll (int student_roll){
            roll = student_roll;
        }
        void setAge(int student_age){
            age = student_age;
        }
        string getName() const { // Correct return type and const-correctness
        return name;
    }
    int getRoll() const { // Correct return type and const-correctness
        return roll;
    }
    int getAge() const { // Correct return type and const-correctness
        return age;
    }

    // Method to display details
    void displayDetails() const {
        cout << "Name = " << getName() << endl;
        cout << "Roll = " << getRoll() << endl;
        cout << "Age = " << getAge() << endl;
    }
};
int main() {
    Student s;
    s.setName("Abis Pokharel");
    s.setRoll(25);
    s.setAge(20);
    s.displayDetails();
    return 0;
}

// 5. Define a class bank to represent bank account with data members depositer name, acc_number, acc_type(as static), acc_balance.
// member function withdraw amount, deposit amount. friend function display details to display all the details.

#include <iostream>
using namespace std;

class Account {
private:
    string name;
    string number;
    static string type;
    double balance;

public:
    // Constructor to initialize account details
    Account(string acc_name, string acc_number, double acc_balance) {
        name = acc_name;
        number = acc_number;
        balance = acc_balance;
    }

    void currentBalance() {
        cout << "Current balance: " << balance << endl;
    }

    void depositBalance() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        currentBalance();
    }

    void withdrawAmount() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount <= balance && balance > 0) {
            balance -= amount;
            cout << "Amount withdrawn." << endl;
            currentBalance();
        } else {
            cout << "Insufficient balance to withdraw." << endl;
        }
    }

    // Friend function to display account details
    friend void displayDetails(const Account &acc);
};

// Initialize static member variable
string Account::type = "Savings";

// Definition of the friend function
void displayDetails(const Account &acc) {
    cout << "Depositor Name: " << acc.name << endl;
    cout << "Account Number: " << acc.number << endl;
    cout << "Account Balance: " << acc.balance << endl;
    cout << "Account Type: " << Account::type << endl;
}

int main() {
    // Creating an Account object using the constructor
    Account a("Abis", "9847417961", 45000);
    // Display initial account details
    displayDetails(a);
    a.depositBalance();
    a.withdrawAmount();
     return 0;
}

                          //                             LAB-2

// 6. Demonstrate unary operator overloading (without friend function)

#include <iostream>
using namespace std;
class Number {
private:
    int value;
public:
    // Constructor to initialize the value
    Number(int a = 0) {
        value = a;
    }
    // Function to display the value
    void display() const {
        cout << "Value: " << value << endl;
    }

    // Overloading the prefix ++ operator
    Number operator++() {
        value++;
        return *this;
    }

    // Overloading the postfix ++ operator
    Number operator++(int) {
        Number temp = *this;
        value++;
        return temp;
    }
};

int main() {
    Number n(10); // Correctly create an object with initial value 10
    cout << "Original ";
    n.display();
    ++n; // Prefix increment
    cout << "After prefix increment (++n): ";
    n.display();
    n++; // Postfix increment
    cout << "After postfix increment (n++): ";
    n.display();
    return 0;
}

// 7.Demonstrate unary operation overloading (using friend function)

#include<iostream>
using namespace std;
class Number {
private:
    int value;

public:
    Number(int a) {
        value = a;
    }
    void display() const {
        cout << "Value: " << value << endl;
    }

    // Friend function to overload the unary -- operator (prefix)
    friend Number operator--(Number &n);
};

// Definition of the friend function for unary -- operator (prefix)
Number operator--(Number &n) {
    // Decrement the value and return the updated object
    --n.value;
    return n;
}

int main() {
    Number n(10);
    cout << "Original ";
    n.display();
    Number decremented_n = --n;
    cout << "After decrement ";
    decremented_n.display();
    return 0;
}

// 8. Demonstrate binary operator overloading (without friend function)

#include <iostream>
using namespace std;
class Student {
private:
    int age;
public:
    Student(int a = 0) : age(a) {}
    Student operator+(Student s) {
        int totalAge = age + s.age;
        return Student(totalAge);
    }
    int getAge() const {
        return age;
    }
};

int main() {
    Student s1(20), s2(30);
    Student s3 = s1 + s2;
    int totalAge = s3.getAge();
    cout << "Total age = " << totalAge << endl;

    return 0;
}

//9. Demonstrate binary operator overloading (using friend function)

#include <iostream>
using namespace std;
class Student {
private:
    int age;
public:
    Student(int a = 0) : age(a) {}
    Student operator+(Student s) {
        int totalAge = age + s.age;
        return Student(totalAge);
    }

    friend Student operator+(const Student &s1, const Student &s2);

    int getAge() const {
        return age;
    }

};
Student operator+(const Student &s1, const Student &s2) {
    // Directly access the private members age of both s1 and s2
    int totalAge = s1.age + s2.age;
    // Return a new Student object with the total age
    return Student(totalAge);
};
int main() {
    Student s1(20), s2(30);
    Student s3 = s1 + s2;
    int totalAge = s3.getAge();
    cout << "Total age = " << totalAge << endl;
    return 0;
}

//10. Demonstrate insertion operation overloading
#include <iostream>
using namespace std;
class Student {
private:
    int age;
    string name;
public:
    Student(int a, string n)  {
         age = a;
         name = n;
    }
    // Friend function to overload the << operator
    friend ostream& operator<<(ostream &out, const Student &s);
};

// Definition of the friend function for the << operator
ostream& operator<<(ostream &out, const Student &s) {
    out << "Name: " << s.name << ", Age: " << s.age;
    return out;
}
int main() {
    Student s1(20, "Alice");
    Student s2(22, "Bob");
    // Use the overloaded << operator to output student details
    cout << s1 << endl;
    cout << s2 << endl;
   return 0;
}

// 11. Demonstrate extraction operator overloading
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int age;
    string name;
public:
    Student() : age(0), name("") {}
    Student(int a, string n) : age(a), name(n) {}
    friend istream& operator>>(istream &in, Student &s);
    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Definition of the friend function for the >> operator
istream& operator>>(istream &in, Student &s) {
    cout << "Enter name: ";
    in >> ws;
    getline(in, s.name);

    cout << "Enter age: ";
    in >> s.age;
    return in;
}

int main() {
    Student s1;
    cin >> s1;
    cout << "Student details:" << endl;
    s1.display();

    return 0;
}

// 12. WAP to demonstrate basic to user-defined type conversion

#include <iostream>
using namespace std;
class Distance {
private:
    int meters;
public:
    Distance(int m){
        meters = m;
    }
    void display() const {
        cout << "Distance: " << meters << " meters" << endl;
    }
};
int main() {
    int basicValue = 100;
    // Convert basic type (int) to user-defined type (Distance)
    Distance d = basicValue;
    d.display();
    return 0;
}

//13. WAP to demonstrate user-defined to basic type conversion

#include <iostream>
using namespace std;
class Distance {
private:
    int meters;
public:
    Distance(int m = 0) : meters(m) {}

    // Conversion operator to convert Distance to int
    operator int() const {
        return meters;
    }
    void display() const {
        cout << "Distance: " << meters << " meters" << endl;
    }
};
int main() {
    Distance d(150);
    int meters = d;  // Implicit conversion using the conversion operator
    cout << "Distance in meters (as int): " << meters << endl;
    return 0;
}

// 14. WAP to demonstrate user-defined to user-defined type conversion
//a)	Implicit conversion
// b)	Explicit conversion
#include<iostream>
using namespace std;

class Feet {
    private:
        int feet;
    public:
        Feet(int f = 0) {
            feet = f;
        }
        int getFeet() const { // Getter for feet
            return feet;
        }
        void display() {
            cout << "Feet: " << feet << endl;
        }
};

class Inch {
    private:
        int inch;
    public:
        Inch(int i ) {
            inch = i;
        }
        void display() {
            cout << "Inch: " << inch << endl;
        }

        // Implicit conversion from Feet to Inch
        Inch(Feet f) {
            inch = f.getFeet() * 12; // Access feet through the getter
        }

        int getInch() const { // Getter for inch
            return inch;
        }
};

class Yard {
    private:
        int yard;
    public:
        Yard(int y = 0) {
            yard = y;
        }
        void display() {
            cout << "Yard: " << yard << endl;
        }

        // Explicit conversion from Inch to Yard
        explicit Yard(Inch i) {
            yard = i.getInch() / 36; // Access inch through the getter
        }
};

int main() {
    Feet f(5);
    Inch i = f; // Implicit conversion from Feet to Inch
    i.display();

    Inch inch(60);
    Yard y = static_cast<Yard>(inch); // Explicit conversion from Inch to Yard
    y.display();
    return 0;
}

                        //      LAB-3

// 15. Write a C++ program to add two numbers using single inheritance.
// Accept these two numbers from the user in Base class and display the sum of these two numbers in derived class.

#include<iostream>
using namespace std;
class Base {
    protected:
        int x;
        int y;
    public:
        void getNumber(){
            cout << "Enter first number:";
            cin >> x;
            cout << "Enter second number:";
            cin >> y;            
        }
};
class Sum : public Base{
    public :
    void displaySum(){
        int sum = x + y ;
        cout << "The sum is:" << sum << endl;
    }
};
int main()
{
    Sum s;
    s.getNumber();
    s.displaySum();
    return 0;
}


// 16.	Write a C++ program to calculate the percentage of a student using multi-level inheritance.
// Accept the marks of three subjects in base class. A class will derived from the above mentioned 
// class which includes a function to find the total marks obtained and another class derived from this 
// class which calculates and displays the percentage of student.

#include<iostream>
using namespace std;
class Marks{
    protected:
        double computer, physics, maths;
    public:
        void getMarks(){
            cout << "Enter marks in computer:";
            cin >> computer;
            cout << "Enter marks in physics:";
            cin >> physics;
            cout << "Enter marks in maths:";
            cin >> maths;
        }
};

class Total : public Marks{
    protected:
        int total;
    public:
        void calculateTotal(){
            total = computer + physics + maths;
        }
};

class Percentage : public Total {
    protected:
        float percentage;
    public:
        void calculatePercentage(){
            percentage = float(total / 3);
            cout << "Total Marks: " << total << endl;
            cout << "Percentage: " << percentage << "%" << endl;
        }
};
int main()
{
    Percentage p;
    p.getMarks();
    p.calculateTotal();
    p.calculatePercentage();
    return 0;
}



// 17.	Write a C++ program to demonstrate how a common friend function can be used 
// to exchange the private values of two classes. (Use call by reference method).

#include<iostream>
using namespace std;

class B; // Forward declaration of Class B

class A {
private:
    int value;
public:
    A(int x) {
        value = x;
    }
    friend void exchangeValues(A &x, B &y);
    void display() {
        cout << "Value in ClassA: " << value << endl;
    }
};
class B {
private:
    int values;
public:
    B(int y) {
        values = y;
    }
    friend void exchangeValues(A &x, B &y);
    void display() {
        cout << "Value in ClassB: " << values << endl;
    }
};
void exchangeValues(A &x, B &y) {
    int temp = x.value;
    x.value = y.values;
    y.values = temp;
}

int main() {
    A c(15); 
    B d(20); 
    cout << "Before exchange:" << endl;
    c.display();
    d.display();

    exchangeValues(c, d);

    cout << "After exchange:" << endl;
    c.display();
    d.display();

    return 0;
}


// 18. Write a program to demonstrate ambiguity in multiple inheritance. Also show 
// the ways to solve it using an example.


#include <iostream>
using namespace std;
class Base1 {
public:
    void greet() {
        cout << "Hello from Base1" << endl;
    }
};
class Base2 {
public:
    void greet() {
        cout << "Hello from Base2" << endl;
    }
};
class Derived : public Base1, public Base2 {
    // No greet() method in Derived
};
int main() {
    Derived obj;
    // obj.greet(); // This would cause ambiguity
    return 0;
}


// way to solve it
//                          (scope resolution operator)

#include <iostream>
using namespace std;
class Base1 {
public:
    void greet() {
        cout << "Hello from Base1" << endl;
    }
};
class Base2 {
public:
    void greet() {
        cout << "Hello from Base2" << endl;
    }
};
class Derived : public Base1, public Base2 {
public:
    void greet() {
        Base1::greet(); // Calling greet() from Base1
        Base2::greet(); // Calling greet() from Base2
    }
};
int main() {
    Derived obj;
    obj.greet(); // Calls both Base1::greet() and Base2::greet()
    return 0;
}


//                          Creating new method in derived class
#include <iostream>
using namespace std;
class Base1 {
public:
    void greet() {
        cout << "Hello from Base1" << endl;
    }
};
class Base2 {
public:
    void greet() {
        cout << "Hello from Base2" << endl;
    }
};
class Derived : public Base1, public Base2 {
public:
    void greet() {
        // You can choose which one to call, or combine them
        Base1::greet();  // Call greet() from Base1
    }
};
int main() {
    Derived obj;
    obj.greet(); // Calls Base1::greet()
    return 0;
}



       //                                LAB - 4

// 19. WAP that demonstrates the concept of polymorphism using virtual functions. Create a 
// base class Shape with a virtual function area(). Create two derived classes, Circle and Rectangle, each with their 
// own implementation of the area() function. Calculate and display the area of different shapes using polymorphism.

#include <iostream>
#include <cmath>
using namespace std;
class Shape {
public:
    virtual ~Shape() {}
     virtual double area() const = 0;
};
class Circle : public Shape {
public:
    Circle(double r){
        radius = r;
    }
    double area() const override {
        return M_PI * radius * radius;
    }
private:
    double radius;
};
class Rectangle : public Shape {
public:
    Rectangle(double w, double h)  {
        width = w;
        height = h;
    }
    double area() const override {
        return width * height;
    }
private:
    double width;
    double height;
};
void displayArea(const Shape& shape) {
    cout << "The area of the shape is: " << shape.area() << endl;
}
int main() {
    Circle circle(7);
    Rectangle rectangle(18, 17);
    displayArea(circle);
    displayArea(rectangle);
    return 0;
}



// 20.Create an abstract base class Vehicle with a pure virtual function void start(). Derive two classes,
//  Car and Motorcycle, from Vehicle. Implement the start() function differently in each derived class. Write a
// program to create objects of both Car and Motorcycle and call their start() functions.

#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void start() const = 0;
    virtual ~Vehicle() {}
};
class Car : public Vehicle {
public:
    void start() const override {
        cout << "Car is starting." << endl;
    }
};
class Motorcycle : public Vehicle {
public:
    void start() const override {
        cout << "Motorcycle is starting." << endl;
    }
};
int main() {
    Car c;
    Motorcycle m;
    c.start();
    m.start();
    return 0;
}


// 21. WAP that defines an abstract base class Animal with a pure virtual function void speak(). 
// Create two derived classes, Dog and Cat, which implement the speak() function. Use an array of Animal 
// pointers to store instances of both Dog and Cat. Write a loop to make all animals in the array speak.

#include <iostream>
using namespace std;
class Animal {
public:
    virtual void speak() const = 0;
    virtual ~Animal() {}
};
class Dog : public Animal {
public:
    void speak() const override {
        cout << "Dog says BHOWWW" << endl;
    }
};
class Cat : public Animal {
public:
    void speak() const override {
        cout << "Cat says MEOWWW" << endl;
    }
};
int main() {
    Animal* a[4];
    a[0] = new Dog();
    a[1] = new Cat();
    a[2] = new Dog();
    a[3] = new Cat();
    for (int i = 0; i < 4; ++i) {
        a[i]->speak();
    }
    for (int i = 0; i < 4; ++i) {
        delete a[i];
    }
    return 0;
}



// 22. Create a C++ program that models a simple banking system. Implement a base class 
// Account and derived classes SavingsAccount and CheckingAccount. Use virtual functions to perform 
// operations like deposit, withdrawal, and interest calculation.
#include <iostream>
using namespace std;
class Account {
protected:
    double balance;

public:
    Account(double initialBalance) {
        balance = initialBalance;
    }

    double getBalance() const {
        return balance;
    }

    virtual void deposit() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Amount deposited." << endl;
        cout << "Current balance: " << getBalance() << endl;
    }

    virtual void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn." << endl;
            cout << "Current balance: " << getBalance() << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual void calculateInterest() = 0;

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(double initialBalance, double rate)
        : Account(initialBalance), interestRate(rate) {}

    void calculateInterest() override {
        balance += balance * interestRate;
        cout << "Interest added." << endl;
        cout << "Current balance: " << getBalance() << endl;
    }
};
class CheckingAccount : public Account {
private:
    double feePerTransaction;
public:
    CheckingAccount(double initialBalance, double fee)
        : Account(initialBalance), feePerTransaction(fee) {}
    void withdraw() override {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount + feePerTransaction <= balance) {
            balance -= (amount + feePerTransaction);
            cout << "Amount withdrawn including fee." << endl;
            cout << "Current balance: " << getBalance() << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void calculateInterest() override {
        // No interest for checking accounts
    }
};

int main() {
    SavingsAccount savings(5000, 0.05);  // Assuming a 5% interest rate
    CheckingAccount checking(2000, 2.0); // $2.00 fee per transaction
    savings.deposit();
    checking.withdraw();  // No argument needed
    savings.calculateInterest();
    checking.calculateInterest();
    cout << "Final Savings Account Balance: " << savings.getBalance() << endl;
    cout << "Final Checking Account Balance: " << checking.getBalance() << endl;
    return 0;
}



 //                                                LAB - 5



// 23. Write a function template called swapValues() that swap the values of two variables of any data type. Demonstrate swapValues() 
// on both integer and string data types. 
#include <iostream>
#include <string>
using namespace std;
template<class T>
void swapvalue(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int a = 10;
    int b = 20;
    cout << "Before swap:"<<endl <<"a = " << a << "\t b = " << b << endl;
    swapvalue(&a, &b);
    cout << "After swap:"<<endl<<" a = " << a << "\t b = " << b << endl;
    string First_Name = "Abis";
    string Last_Name = "Pokharel";
    cout << "Before swap :"<<endl<< "First_Name = " << First_Name << "\t Last_Name = " << Last_Name << endl;
    swapvalue(&First_Name, &Last_Name);
    cout << "After swap:"<<endl<< "First_Name = " << First_Name << "\t Last_Name = " << Last_Name << endl;

    return 0;
}


//  24.Write an template overload function maximum() that find the maximum of two values.Implement version for both integer and character type.
#include <iostream>
using namespace std;
template<class T>

T maximum(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int x = 30;
    int y = 40;
    cout << "Maximum of " << x << " and " << y << " is = " << maximum(x, y) << endl;

    char c1 = 'v';
    char c2 = 'k';
    cout << "Maximum of '" << c1 << "' and '" << c2 << "' is ' = " << maximum(c1, c2) << endl;

    return 0;
}

//  25. WAP to demonstrate the addition of multiple datatype using function template.
#include <iostream>
#include <string>
using namespace std;
template<class T>
void addValues(T a, T b) {
    T result = a + b;
    cout << "Result: " << result << endl;
}

int main() {
    addValues(15, 16);
    addValues(14.5, 16.4);
    string str1 = "Abis";
    string str2 = "Pokharel";
    addValues(str1, str2);

    return 0;
}

// 26. Define a class template stack that can hold element of any datatype . Implement function to push pop and display
//  element from the stack using function template.
#include <iostream>
using namespace std;

template <class T>
class Stack {
public:
    T marks[7];
    int flag = -1;
        void push(int num){
            if(flag<6){
                flag++;
                marks[flag] = num;
                
            }else{
                cout<<"Stack is Full."<<endl;
            }
        }
    void pop() {
        if (flag < 0) {
            cout << "Stack is Empty" << endl;
        }else{
        flag--; 
    }
}
    void display()  {
        cout << "Stack elements: ";
        for (int i = 0; i <= flag; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack<int> stack; 
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display(); 
    stack.pop();
    stack.display();
    return 0;
}




//                                                  LAB - 6

// 27. WAP to demonstrate try, throw and catch statement.

#include<iostream>
using namespace std;
int main()
{
    try
    {
        int a,b;
        cout << "Enter first number:";
        cin >> a;
        cout << "Enter second number:";
        cin >> b;
        if ( b == 0){
            throw runtime_error("Number can't be divisible by 2.");
        }
        double result = a / b;
        cout << "The result is:" << result << endl;
    }
    catch(runtime_error e)
    {
        cout << e.what() << endl;
    }    
    return 0;
}


// 28. WAP to accept an email address and throw an exception if it does not contain @ symbol.

#include<iostream>
using namespace std;
int main()
{
    try
    {
        string email;
        cout<< "Enter email: ";
        cin >> email;
        bool emailValid = false;
        for(int i=0; i < email.length(); i++){
            if(email[i] == '@'){
                emailValid = true;
                break;
            }
        }
        if(!emailValid){
            throw runtime_error("Email is invalid.");
        }
        cout << "Email is valid." << endl;
    }
    catch(runtime_error e)
    {
        cout<< e.what() << endl;
    }
    return 0;
}



//  29. WAP to perform arithmetic operations on two numbers and throw an exception if the dividend is zero or does not 
//  contain an operator
#include <iostream>
using namespace std;
int main() {
        double a, b;
        char op;
        cout << "Enter the first number: ";
        cin >> a;
        cout << "Enter the second number: ";
        cin >> b;
    try {
        cout << "Enter an operator : ";
        cin >> op;
        if (op != '+' && op != '-' && op != '*' && op != '/') {
            throw runtime_error("Invalid operator.");
        }
        if (op == '/' && b == 0) {
            throw runtime_error("Division by zero is not allowed.");
        }
        double result;
        switch (op) {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
        }
        cout << "The result is : " << result << endl;
    } catch (runtime_error e) {
       cout << "Exception : " << e.what() << endl;
    }
    return 0;
}


//  30. WAP to accept user name and password and throw an exception if the password 
//  has less than 6 characters or does not contain a digit.

#include<iostream>
#include<cctype>
using namespace std;
int main()
{
    try
    {
        string username, password;
        cout << "Enter username:";
        cin >> username;
        cout << "Enter password:";
        cin >> password;
        if (password.length() < 6){
            throw runtime_error("Password must be at least 6 character length.");
        }
        bool containDigit = false;
        for (int i=0; i< password.length(); i++){
            if(isdigit(password[i])){
                containDigit = true;
                break;
            }
        }
        if(!containDigit){
            throw runtime_error ("Password must contain at least one digit.");
        }
        cout << "Password is Correct." << endl;

    }
    catch(runtime_error e)
    {
        cout << e.what()<< endl;
    }
 return 0;
}



// 31. WAP that attempts to open a file named "input.txt" for reading. Use exception handling to catch and handle 
// the case when the file does not exist

#include <iostream>
#include <fstream>
using namespace std;
int main() {    
    string filename = "input.txt";
    cout<<"Filename : "<<filename<<endl;
    ifstream file(filename);
    try {
        if (!file.is_open()) {
            throw runtime_error("File does not exist or can't be opened.");
}
        cout << "File opened successfully." << endl;
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();

    } catch (const runtime_error& e) {
        cout <<"Exception : "<< e.what() << endl;
    }
    return 0;
}





// 32. Write a template function that operates on different types. Use exception handling within the 
// template function to handle exceptions specific to each data type.
#include <iostream>
using namespace std;
template <class T>
T Divide(T a, T b) {
    try {
        if (b == 0) {
            throw runtime_error("Number cannot be divisible by zero.");
        }
        return a / b;
    } catch (runtime_error e) {
        cout << "Exception : " << e.what() << endl;
        return 0;
    }
}
int main() {
    int result1 = Divide(10, 5);
    cout << "Division of integer is : " << result1 << endl; 
    int result2 = Divide(10, 0); 
    // cout << "Division of integer is : " << result2 << endl;
    double result3 = Divide(20.5, 4.5);
    cout << "Division of float datatype is : " << result3 << endl;
    return 0;
}



// //                                       LAB - 7

// 33. WAP to create file name students_records.txt and insert contents to it. 
// // CONTENT:
//             // RN   NAME    MARKS
//             // 1    RAM     30
//             // 2    SHYAM   29  
//             // 3    SITA    25

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string  content = " RN   NAME    MARKS \n"
                      " 1    RAM      30 \n"
                      " 2    SHYAM    29 \n"
                      " 3    SITA     25 \n";

    fstream file("students_records.txt", ios :: out );    

    if(!file.is_open()){
        cout << "Error opening file........" << endl;
    }

    file << content ;
    file.close();
    cout << "Content has been written in the file.......";
    return 0;
}


// 34. WAP to read contents and display in console from the file "student_records.txt".

#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream file("students_records.txt", ios :: in);
    if(file.is_open()){
        string line;
        while(getline(file, line)){
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error opening file........";
    }
    return 0;
}


 // 35. WAP to modify age of SHYAM from 29 to 22 that is available in file student_records.txt.
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main() {
    fstream file("students_records.txt", ios::in);
    if (!file.is_open()) {
        cout << "Error opening file for reading........" << endl;
        return 1;
    }
    string content = "";
    string line;
    while (getline(file, line)) {
        if (line.find("SHYAM") != string::npos) {
            line.replace(line.find("29"), 2, "22");
        }
        content += line + "\n";
    }
    file.close();
    file.open("students_records.txt", ios::out);
    if (!file.is_open()) {
        cout << "Error opening file for writing........" << endl;
        return 1;
    }

    file << content;
    file.close();

    cout << "SHYAM's age has been modified successfully!" << endl;
    return 0;
}






// 36. WAP to append the content in the file named demo.txt.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string content = "This is appended content.";
    fstream file("demo.txt", ios::app);
    if (file.is_open()) {
    file << content;
    file.close();
    cout << "Content has been appended to the file demo.txt" << endl;
    } else {
        cout << "Error opening file for writing........" << endl;
    }
  return 0;
}


// 37. WAP to read contents from file named demo.txt and print number of character available in that file.

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file("demo.txt", ios :: in);
    if(file.is_open()){
        char ch;
        int charCount = 0;
        while(file.get(ch)){
            charCount++;
        }
        file.close();
        cout << "Number of characters in the file: " << charCount << endl;
    } else {
        cout << "Error opening file........";
    }
    return 0;
}

// 38. WAP to read contents from file named demo.txt and print n.o of words and n.o of lines available in that file.

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file("demo.txt", ios :: in);
    if(file.is_open()){
        string word;
        int wordCount = 0;
        int lineCount = 0;
        while(file >> word){
            wordCount++;
            if(word[word.length() - 1] == '.'){
                lineCount++;
            }
        }
        file.close();
        cout << "Number of words in the file: " << wordCount << endl;
        cout << "Number of lines in the file: " << lineCount << endl;
    } else {
        cout << "Error opening file........";
    }
    return 0;
}


// 39. WAP to create file named file1.txt and file2.txt with some text in those file. Also merge the contents of
// those two files into the file named file3.txt.  

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file1("file1.txt", ios :: out);
    file1 << "This is the content of file1.txt.";
    file1.close();
    fstream file2("file2.txt", ios :: out);
    file2 << "This is the content of file2.txt.";
    file2.close();
    fstream file1In("file1.txt", ios :: in);
    fstream file2In("file2.txt", ios :: in);
    fstream file3Out("file3.txt", ios :: out);
    if(file1In.is_open() && file2In.is_open() && file3Out.is_open()){
        char ch;
        while(file1In.get(ch)){
            file3Out << ch;
        }
        file1In.close();

        while(file2In.get(ch)){
            file3Out << ch;
        }
        file2In.close();

        file3Out.close();
        cout << "Contents of file1.txt and file2.txt merged into file3.txt.";
    } else {
        cout << "Error opening file........";
    }
    return 0;
}

// 40. WAP to delete the record of sita from the file named students_records.txt.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream inputFile("students_records.txt");
  ofstream outputFile("updated_records.txt");

  string line;
  while (getline(inputFile, line)) {
    if (line.find("SITA") == string::npos) {
      outputFile << line << endl;
    }
  }

  inputFile.close();
  outputFile.close();
    remove("students_records.txt");
    rename("updated_records.txt", "students_records.txt"); 
  cout << "Remaining records :" << endl;
  inputFile.open("students_records.txt");
  while (getline(inputFile, line)) {
    cout << line << endl;
  }
  inputFile.close();

  cout << "Record of Sita deleted from students_records.txt" << endl;

  return 0;
}

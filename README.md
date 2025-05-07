[![CMake Build](https://github.com/WilliamLebris/CustomizeOrderManagementProgram/actions/workflows/cmake.yml/badge.svg)](https://github.com/WilliamLebris/CustomizeOrderManagementProgram/actions/workflows/cmake.yml)

Customizable Order Management System – Full Overview
A short video showing how the program run smoothly : https://youtu.be/ITQ3krNucRU 
I also made another video which is a bit longer than the previous one, if you are interested in seeing what my code is actually doing, how I wrote the code and explanation of some concept more deeply, (breaking down video)  : https://youtu.be/Y23zLWznltE

Introduction
The Customizable Order Management System is a flexible and efficient C++ program designed for businesses that manage customer orders. It can be used in retail stores, service centers, repair shops, restaurants, and more. The system allows businesses to:
✅ Set up custom fields to collect customer information
✅ Define available products and prices for easy order processing
✅ Record and manage customer orders
✅ Search for specific orders quickly
✅ Delete old or incorrect orders to maintain system efficiency
✅ Display all active orders and calculate revenue automatically
With modular design, structured data handling, and input validation, this system eliminates manual errors, improves efficiency, and ensures accurate order tracking.

Key Features & Functionalities
1. System Setup (Admin Configuration)
Before employees can use the system, the business owner/manager configures:
Customer Fields Setup (setupCustomerFields.cpp)
The admin defines what customer details should be collected (e.g., Name, Phone, Email).
Allows up to 5 fields, ensuring flexibility without overwhelming the system.
Uses getValidInt() to ensure valid inputs.
Product & Pricing Setup (setupProducts.cpp)
The admin enters available products and sets their prices.
Uses getValidInt() to limit product count and getValidDouble() to ensure proper pricing.
Prices must be $0.01 or higher to prevent incorrect entries.

💡 Why It’s Important:
Employees don’t need to memorize product names or prices.
Ensures accurate pricing and prevents manual errors.

2. Order Management (Employee Operations)
Once the system is set up, employees can use it to handle customer transactions efficiently.
Adding a New Order (addOrder.cpp)
Employees enter customer details based on the predefined fields.
They select products and quantities for the order.
Input validation ensures only valid values (0–1000) are accepted.
The total price is automatically calculated and added to revenue.
If MAX_ORDERS is reached, the system prevents new orders until old ones are deleted.
💡 Why It’s Important:
Prevents incorrect orders and missing data.
Automates price calculations, reducing mistakes.
Ensures revenue tracking is accurate and up to date.

Searching for an Order (searchOrder.cpp)
Employees can quickly find an order using a customer name or order number.
The program scans stored orders and returns matching results.
💡 Why It’s Important:
Saves time when dealing with returning customers or order corrections.
Helps businesses track past transactions.

Displaying All Orders (displayOrders.cpp)
Lists all active orders with details, including:
Date of purchase
Customer details
Products purchased
Total price
Inactive (deleted) orders are hidden, keeping the display clean.
💡 Why It’s Important:
Employees get an organized view of ongoing transactions.
Prevents confusion between active and canceled orders.

Deleting an Order (deleteOrder.cpp)
Allows employees to remove an incorrect or old order.
The selected order is marked as inactive, preventing further display.
The system adjusts revenue accordingly if an order is deleted.
💡 Why It’s Important:
Prevents clutter by removing outdated or incorrect orders.
Ensures accurate revenue tracking after order adjustments.

3. Order Structure & Data Handling
Global Variables (globalVariable.hpp)
Stores key variables used throughout the system:

int numFields, numProducts, orderCount;
double totalRevenue;
string customerFields[MAX_CUSTOMER_FIELDS];
string products[MAX_PRODUCTS];
double prices[MAX_PRODUCTS];
Order orders[MAX_ORDERS];


Defines order limits, customer fields, product lists, and revenue tracking.

Order Structure (globalVariable.hpp)
struct Order {
    string date;
    string customerInfo[MAX_CUSTOMER_FIELDS];
    int quantities[MAX_PRODUCTS];
    double totalPrice;
    bool isActive;
};
 Struct works like class but the difference is with struct, member are public by default 
Each order contains:
✅ Date of purchase
✅ Customer details (based on the admin’s setup)
✅ Product quantities
✅ Total price (calculated dynamically)
✅ isActive flag (for managing deleted orders)
💡 Why It’s Important:
Keeps all order information structured.
Allows easy access and modification of orders.

4. Input Validation Utilities
To prevent errors and ensure user-friendly data entry, the program includes validation functions:
✅ Integer Validation (getValidInt.cpp) – Ensures only valid integer inputs.
✅ Double Validation (getValidDouble.cpp) – Ensures valid floating-point values (e.g., prices).
💡 Why It’s Important:
Prevents negative prices, invalid product quantities, and incorrect field counts.
Enhances system stability and usability.

Code Efficiency & Design Choices
1. Modular Programming
Each key operation is in a separate .cpp file, making it easy to maintain and expand.
Headers (.hpp files) prevent redundant code and improve organization.
2. Input Validation & Error Handling
Ensures all inputs are within expected ranges.
Prevents incorrect or inconsistent data entries.
3. Scalability & Extensibility
New products or fields can be added without modifying core logic.
The system can be adapted for different business types, including:
✅ Retail stores (electronics, clothing, furniture, etc.)
✅ Repair shops (computer repairs, auto services, etc.)
✅ Restaurants and cafés (food ordering, table reservations, etc.)
✅ Service-based businesses (salons, tutoring centers, etc.)

Conclusion
This fully functional, well-structured Customizable Order Management System simplifies order processing for businesses by:
✔ Allowing managers to define customer fields & products
✔ Providing employees an easy way to add, search, and delete orders
✔ Automatically calculating total prices and revenue
✔ Ensuring structured data storage with modular programming
✔ Using input validation to prevent errors
With efficient design, easy scalability, and real-world applicability, this system streamlines order tracking, revenue calculation, and business operations—making it an essential tool for any business managing customer transactions. 🚀




Steps to Build and Run the Project
1. Clone the repository
   If you haven't already, clone the repository to your local machine:

bash
Copy
Edit
git clone <your-repository-url>
cd Proj1
2. Create the Build Directory
   In your terminal, navigate to the project folder and create a build directory using CMake:

bash
Copy
Edit
cmake -S . -B build
This command will generate the necessary build files in a directory called build.

3. Build the Project
   After configuring the project with CMake, build the project by running:

bash
Copy
Edit
cmake --build build
This will compile the project and generate the executable files (Proj1 and test_orders).

4. Run the Project
   To run the main project executable:

bash
Copy
Edit
./build/Proj1
This will execute the Proj1 application.

5. Run the Tests
   To run the tests (using GoogleTest), you can execute the following:

bash
Copy
Edit
./build/test_orders
This will run the unit tests and show the results in your terminal.

6. Clean Up (Optional)
   If you want to clean up the build files, you can remove the build directory:

bash
Copy
Edit
rm -rf build

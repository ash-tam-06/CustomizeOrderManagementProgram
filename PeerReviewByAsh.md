# Code Structure & CMake
Project is overall pretty organized, and 

# Modularity & Readability


# Test Coverage
There are a total of 3 test cases, which go over edge cases for 2 functions of the code and one test that just makes sure revenue is calculated correctly. I do believe there could have been more edge cases being tested, as well as testing that all parts of the code is functioning as it should be. 

# Bugs or Gaps Identified
--When asked to enter the number of products you want to put into the system, you can input a non-whole number. The program takes in the number and will use the first part of the number as your input for the number of products, then uses the rest of the decimal as the name for the product. 

--More of a logic gap: When asked for the name of a product, you can type just a space, and the program will accept that as a valid input for product name. 

--You can input any date order: i.e, the program will take in 05-06-2006 even if they ask for YYYY-MM-DD

--When adding an order, you can input an empty string for the details you want customers to add, the same for the date of the order. You can also input a non-whole number for quantities of products, same issue as before, on the number of products you are asked to input.

--When giving feedback, same issue with non-whole numbers being accepted and second part of number being used as the input for the next questions.

--When searching for order, program will not find order if case doesn't match: its case sensitive.

# Test Output & Clarity



# Architecture & Design Feedback
Something I wanted to mention about design was on how the program looked when running. Everytime you select an option from then menu that would display an order, more specifically a list of orders, it immediately shows you the menu again. Its not a problem at all, but I think it would make the program more 'friendly' if you were given a moment before the menu poped up. Maybe adding something that just tells you to type something if user is ready to go back to the menu.

# 5 New Tests
```
TEST(InputValidationTest, RejectsNonIntegerForValidInt) {
    std::istringstream input("4.5\n10\n");
    std::streambuf* orig = std::cin.rdbuf(input.rdbuf());
    int result = intValidation::getValidInt(1, 100);
    std::cin.rdbuf(orig);
    EXPECT_EQ(result, 10);
}

TEST(ProductQuantityTest, RejectsDecimalInputForQuantity) {
    std::istringstream input("3.2\n5\n");
    std::streambuf* orig = std::cin.rdbuf(input.rdbuf());
    int result = intValidation::getValidInt(0, 100);
    std::cin.rdbuf(orig);
    EXPECT_EQ(result, 5);
}

TEST(OrderSearchTest, CaseInsensitiveCustomerNameMatch) {
    std::string storedName = "John Smith";
    std::string searchInput = "john smith";
    EXPECT_EQ(deleteOrderDeclaration::toLowerCase(storedName), deleteOrderDeclaration::toLowerCase(searchInput));
}

TEST(ProductSetupTest, AcceptsSpaceAsProductName) {
    std::istringstream input("1\n \n1.99\n");  // 1 product, name = " ", price = 1.99
    std::streambuf* origCin = std::cin.rdbuf(input.rdbuf());

    setProductsDeclaration::setupProducts();

    std::cin.rdbuf(origCin);

    // Check that the product name stored is exactly a space
    EXPECT_EQ(products[0], " ");
    EXPECT_DOUBLE_EQ(prices[0], 1.99);
}

TEST(OrderSearchTest, IsCaseInsensitive) {
    // Arrange: create a mock order with mixed-case name
    Order testOrder;
    testOrder.customerInfo[0] = "Alice Johnson";
    testOrder.date = "2025-05-15";
    testOrder.totalPrice = 20.00;
    testOrder.isActive = true;
    orders[0] = testOrder;
    orderCount = 1;

    // Simulate lowercase search input (should match even though case is different)
    std::istringstream input("alice johnson\n");
    std::streambuf* origCin = std::cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    searchOrderDeclaration::searchOrder();  // function under test
    std::string output = testing::internal::GetCapturedStdout();

    std::cin.rdbuf(origCin);

    // Assert: should find the order despite case mismatch
    EXPECT_NE(output.find("Order Found"), std::string::npos) << "Order not found due to case sensitivity";
}
```

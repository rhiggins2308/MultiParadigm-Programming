// |----------------------------|
// |---- 1. Import Packages ----|
// |----------------------------|
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// |-----------------------------|
// |----- 2. Model Entities -----|
// |-----------------------------|

// 2a - Product Entity
struct Product{
    char* name;
    double price;
};

// 2b - ProductStock Entity
struct ProductStock{
    struct Product product;
    int quantity;
};

// 2c - Customer Entity
struct Customer{
    char* name;
    double budget;
    struct ProductStock shoppingList[10];
    int index;
};

// 2d - Shop Entity
struct Shop{
    double cash;
    struct ProductStock stock[20];
    int index;
};

// |-----------------------------|
// |----- 3. Define Methods -----|
// |-----------------------------|

// 3a. Create the Shop entity from shop.csv file
//      - Contains opening cash balance
//      - Contains stocked products
//      - Contains price for each product
//      - Contains stock level for each product
struct Shop createAndStockShop()
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    // open stock.csv file to read values
    fp = fopen("stock.csv", "r");
    if (fp == NULL ){
        exit(EXIT_FAILURE);
    }
    
    // parse first line of stock.csv, to import opening cash value
    getline(&line, &len, fp);
    double cashInShop = atof(line);
    struct Shop shop = {cashInShop};

    // parse remaining line items in stock.csv file
    // store in Shop struct as Productstock items
    //  - Description (Product)
    //  - Cost (Product)
    //  - Stock (ProductStock)
    while ((read = getline(&line, &len, fp)) != -1){
        char *n = strtok(line, ",");
        char *p = strtok(NULL, ",");
        char *q = strtok(NULL, ",");

        int quantity = atoi(q);
        double price = atof(p);
        char *name = malloc(sizeof(char) * 50);
        strcpy(name, n);

        struct Product product = {name, price};
        struct ProductStock stockItem = {product, quantity};
        shop.stock[shop.index++] = stockItem;
    }
    
    fclose(fp);
    return shop;
}

// 3b. Generate Menu Options for User to choose from
int menuOptions(){
    /*
    Offer Customer 2 options:
        - read in shopping list
        - search for and purchase single item
        - suggest giving customer a default budget of €20
    */
   int choice;

    printf("\nPlease Choose and Option:");
    printf("\nProcess an Order (Enter 1)");
    printf("\nPurchase a Single Item (Enter 2)\n");
    printf("\nExit (Enter 0)\n");
    scanf("%d", &choice);

    return choice;
}

// 3c. Create a Customer entity from customer.csv file
struct Customer createCustomer(){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    struct Customer custEntity = {};

    // open iostream for customer.csv file
    fp = fopen("customer.csv", "r");
    if (fp == NULL ){
        exit(EXIT_FAILURE);
    }

    // parse first line of customer.csv, to import customer's name
    getline(&line, &len, fp);
    char* custName = line;
    custEntity.name = custName;
    
    // parse second line of customer.csv, to import customer's budget
    getline(&line, &len, fp);
    double custBudget = atof(line);
    custEntity.budget = custBudget;
    
    // parse remaining line items in customer.csv file
    while ((read = getline(&line, &len, fp)) != -1){
        char *i = strtok(line, ",");
        char *q = strtok(NULL, ",");
    
        // store in Customer struct as shoppingList items
        //  - Description
        //  - Amount Required
        char *item = malloc(sizeof(char) * 50);
        strcpy(item, i);
        
        int quantity = atoi(q);
        
        //create ProductStock struct to hold each item for purchase
        struct ProductStock buyItem = {item, 0.0, quantity};
        // add each purchase item to Customers shoppingList array
        custEntity.shoppingList[custEntity.index++] = buyItem;
    }
    
    fclose(fp);
    return custEntity;
}


// 3a - Print Product Details
void printProduct(struct Product p)
{
    printf("----------------------\n");
    printf("PRODUCT NAME: %s \nPRODUCT PRICE: %.2f\n", p.name, p.price);
    printf("----------------------\n");
}

// 3b - Print Customer Details
void printCustomer(struct Customer c)
{
    printf("\nCUSTOMER NAME: %s \nCUSTOMER BUDGET: %.2f\n", c.name, c.budget);
    printf("----------------------\n");
    
    for (int i = 0; i < c.index; i++){
        printProduct(c.shoppingList[i].product);
        printf("%s HAS ORDERED %d OF THE ABOVE PRODUCT.\n", c.name, c.shoppingList[i].quantity);

        double cost = c.shoppingList[i].quantity * c.shoppingList[i].product.price;
        printf("The cost to %s will be €%.2f\n\n", c.name, cost);
    }
}

void printShop(struct Shop s){
    printf("Shop has %.2f in cash\n", s.cash);

    for (int i = 0; i < s.index; i++){
        printProduct(s.stock[i].product);
        printf("Shop has %d of the above.\n", s.stock[i].quantity);
    }
}

char findProductName(struct Shop s, char *n)
{
    int exists = 0;

    while (exists == 0){
        for (int i = 0; i < s.index; i++)
        {
            char *name = s.stock[i].product.name;
            if (strcmp(name, n) == 0){
                exists = 1;
                return exists;
            }
        }
    }
    return exists;
}

double findProductPrice(struct Shop s, char *n)
{
    int exists = 0;

    while (exists == 0){
        for (int i = 0; i < s.index; i++)
        {
            struct Product product = s.stock[i].product;
            char *name = product.name;
            if (strcmp(name, n) == 0)
            {
                return product.price;
            }
        }
    }
    return exists;
}

int findProductQty(struct Shop s, char *n)
{
    for (int i = 0; i < s.index; i++)
    {
        struct Product product = s.stock[i].product;
        char *name = product.name;
        if (strcmp(name, n) == 0)
        {
            return product.price;
        }
    }
    return -1;
}

int checkStockAmount(char *n, int q, struct Shop s){
    int stockCheck = -1;

    for(int j = 0; j < s.index; j++){
        char *name = s.stock[j].product.name;

        if (strcmp(name, n) == 0){
            if (q >= s.stock[j].quantity){
                stockCheck = 1;
                return stockCheck;
            }
            else{
                stockCheck = 0;
                return stockCheck;
            }
        }
    }

    return stockCheck;
}   

void updateShop (struct Shop shop) {           
    // complete purchase and write stock and cash updates to stock.csv
    FILE *fp = fopen ("stock.csv", "w");
    if (fp != NULL) {
        fprintf(fp, "%.2f\n", shop.cash);
        for (int i = 0; i <shop.index; i++){
            fprintf(fp, "%s, %.2f, %d\n", shop.stock[i].product.name, shop.stock[i].product.price, shop.stock[i].quantity);
        }

        fclose(fp);
    }
}

void orderSuccess(struct Shop s, struct Customer c, double tot){
    printf("\n----------\nThank you, your budget of €%.2f is sufficient to cover your order cost of €%.2f.", c.budget, tot);  
    printf("\nThank you for your custom today.\nHave a lovely day and see you again soon :-)");
    // commit stock and cash changes to shop.csv
    updateShop(s);
}

void orderFail(struct Customer c, double tot){
    printf("\n----------\nI'm sorry, unfortunately your budget of €%.2f in not sufficient to cover your total order cost of €%.2f.\nPlease reduce your shopping list and come back later.", c.budget, tot);
    // do not commit stock and cash changes to shop.csv
    // continue to exit without saving
}


void processOrder(struct Shop shop, struct Customer cust){
    double orderTotal = 0;
    // - for each line item, check that product exists in Shop stock
    // - for each line item, check that product stock in shop is sufficient
    int shopStock;

    for (int i = 0; i < cust.index; i++){
        char *name = cust.shoppingList[i].product.name;
        int qty = cust.shoppingList[i].quantity;
        double itemPrice = 0;
        double lineTotal = 0;                
                
        shopStock = checkStockAmount(name, qty, shop);
    
        if (shopStock == -1){
            printf("\n----------\nSorry, we do not stock %s here.", name);
        } else if (shopStock == 0){
            printf("\n----------\nYes, we have enough of %s in stock for your order.", name);
            // - for each in-stock line item calculate total cost and store in array
            itemPrice = findProductPrice(shop, name);
            lineTotal = qty*itemPrice;
            printf("\nCost of %d %s at €%.2f each is €%.2f", qty, name, itemPrice, lineTotal);

            // - calculate total purchase cost and confirm customer budget is sufficient to cover
            orderTotal += lineTotal;

            // - reduce customer budget by orderTotal amount
            cust.budget -= lineTotal;
            
            // increase shop cash by totalOrder amount
            shop.cash += lineTotal;
            
            // deduct purchased items from shop stock
            shop.stock[i].quantity -= qty;
            
        } else if (shopStock == 1){
            printf("\n----------\nSorry, we don't have enough of %s in stock at the moment.", name);
        }
    }

    if (cust.budget >= orderTotal){ orderSuccess(shop, cust, orderTotal); } 
    else{ orderFail(cust, orderTotal); }
}

void reduceStock(struct Shop s, char *n, int q){
    for (int i = 0; i <s.index; i++){
            if (strcmp(n, s.stock[i].product.name) == 0){
                s.stock[i].quantity -= q;
                break;
            }
    }

    updateShop(s);
}
void processGuestOrder(struct Shop shop, struct Customer cust){
    double orderTotal = 0;
    // - for each line item, check that product exists in Shop stock
    // - for each line item, check that product stock in shop is sufficient
    int shopStock;

    char *name = cust.shoppingList[0].product.name;
    int qty = cust.shoppingList[0].quantity;
    double itemPrice = 0;
    double lineTotal = 0;                
                
    shopStock = checkStockAmount(name, qty, shop);
    
    if (shopStock == -1){
        printf("\n----------\nSorry, we do not stock %s here.", name);
    } else if (shopStock == 0){
        printf("\n----------\nYes, we have enough of %s in stock for your order.", name);
        // - for each in-stock line item calculate total cost and store in array
        itemPrice = findProductPrice(shop, name);
        lineTotal = qty*itemPrice;
        printf("\nCost of %d %s at €%.2f each is €%.2f", qty, name, itemPrice, lineTotal);

        // - reduce customer budget by orderTotal amount
        cust.budget -= lineTotal;
            
        // increase shop cash by totalOrder amount
        shop.cash += lineTotal;
            
        // deduct purchased items from shop stock
        reduceStock(shop, name, qty);
            
    } else if (shopStock == 1){
        printf("\n----------\nSorry, we don't have enough of %s in stock at the moment.", name);
    }

    if (cust.budget >= lineTotal){ orderSuccess(shop, cust, lineTotal); } 
    else{ orderFail(cust, lineTotal); }
}

int main(void)
{
    // 1. Create and stock the Shop
    struct Shop shop = createAndStockShop();
    
    // 2. Offer User Options:
    int choice = menuOptions();

    // 3. Actions based on User Choice    
    if (choice == 0){
        exit;
    }
    else if (choice == 1){
        /*
        2. Create Customer from file
            - read in Customer's budget
            - read in each item in Customers order
                - Description
                - Quantity
        */
        struct Customer cust = createCustomer();
        processOrder(shop, cust);            
    }
    else if (choice == 2){
        // Set budget to €20, since user does not have an account
        struct Customer cust = {"Guest Shopper", 20.0};
        char *liveItem = malloc(30);
        int qty;
        cust.index = 0;

        printf("\nPlease type the product you wish to purchase (type 'X' to finish): ");
        // scanf("%s", liveItem);
        char temp;
        scanf("%c", &temp); 
        scanf("%[^\n]s", liveItem);

        if (strcmp(liveItem, "X") != 0){
            printf("\nHow many of %s would you like? ", liveItem);
            scanf("%d", &qty);

            cust.shoppingList[cust.index].product.name = liveItem;
            cust.shoppingList[cust.index].quantity = qty;
            printf("\n----------\nItem: %s\nQuantity: %d", cust.shoppingList[cust.index].product.name, cust.shoppingList[cust.index].quantity);
            processGuestOrder(shop, cust);
        }
    } else { printf("\nYou have entered an invalid menu option. Please try again.\n"); }
    
/*    
    // call print method for Customer details
    // nothing returned
    printCustomer(robbie);

    

    double price = findProductPrice(shop, "Coke Can");
    printf("%.2f\n", price);

    price = findProductPrice(shop, "Bread");
    printf("%.2f\n", price);

    price = findProductPrice(shop, "Spaghetti");
    printf("%.2f\n", price);

    price = findProductPrice(shop, "Tomato Sauce");
    printf("%.2f\n", price);

    price = findProductPrice(shop, "Bin Bags");
    printf("%.2f\n", price);

    // printf("The shop has %d of the product %s.\n", cokeStock.quantity, cokeStock.product.name);
    // printf("The shop has %d of the product %s.\n", breadStock.quantity, breadStock.product.name);

    
    

    // double price = findProductPrice(shop,"Coke Can");
    // printf("%.2f\n", price);

    //printf("The shop has %d of the product %s\n", cokeStock.quantity, cokeStock.product.name);

*/
    printf("\n");
    return 0;
}
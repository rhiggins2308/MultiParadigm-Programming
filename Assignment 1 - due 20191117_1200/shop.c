/* 
 ---------------------------------
 Build a simulation of a shop in C
 ---------------------------------
 Entities
    Shop
    Customer(s)
    Product(s)
    Stock

 Tasks
 ------
 1. Model the Entities
 2. Print Product Infpo
 3. Add Item to Customers List
 4. Read in Stock from a File
*/


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

struct Shop createAndStockShop(){
    struct Shop shop = {200};
    
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("stock.csv", "r");
    if (fp == NULL ){
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1){
        // printf("Retrieved line of length %zu:\n", read);
        // printf("%s IS A LINE", line);

        char *n = strtok(line, ",");
        char *p = strtok(NULL, ",");
        char *q = strtok(NULL, ",");

        char *name = malloc(sizeof(char) * 50);
        strcpy(name, n);
        double price = atof(p);
        //int quantity = atoi(q);
        
        struct Product product = {name, price};
        struct ProductStock stockItem = {product, atoi(q)};

        shop.stock[shop.index++] = stockItem;    
  
        printf("\nNAME OF PRODUCT: %s ;\nPRICE: €%.2f ;\nQUANTITY: %d\n", name, price, atoi(q));
    }

    return shop;

//     getline(&line, &len, fp);
//     double shopCash = atof(line);


//     while ((read = getline(&line, &len, fp)) != -1){
//        // printf("%s IS A LINE", line);
       



//        
//     }
}

void printShop(struct Shop s){
    printf("Shop has %.2f in cash\n", s.cash);

    for (int i = 0; i < s.index; i++){
        printProduct(s.stock[i].product);
        printf("Shop has %d of the above.\n", s.stock[i].quantity);
    }
}



// double findProductPrice(struct Shop s, char *n)
// {
//     for (int i = 0; i < s.index; i++)
//     {
//         struct Product product = s.stock[i].product;
//         char *name = product.name;
//         if (strcmp(name, n) == 0)
//         {
//             return product.price;
//         }
//     }
//     return -1;
// }

int main(void)
{
    // create Customer struct
    struct Customer robbie = {"Robbie", 100.0};
    
    // create Product struct ... 1 per product
    struct Product coke = {"Can of Coke", 1.10};
    struct Product bread = {"Bread", 0.70};
    
    // call print method for Product details
    // nothing returned
    // printProduct(coke);
    // printProduct(bread);

    // create ProductStock struct ... one per stock item
    struct ProductStock cokeStock = {coke, 20};
    struct ProductStock breadStock = {bread, 2};
    
    // add Products to Customers shopping list
    robbie.shoppingList[robbie.index++] = cokeStock;
    robbie.shoppingList[robbie.index++] = breadStock;
    
    // call print method for Customer details
    // nothing returned
    printCustomer(robbie);

    struct Shop shop = createAndStockShop();
    printShop(shop);

    // printf("The shop has %d of the product %s.\n", cokeStock.quantity, cokeStock.product.name);
    // printf("The shop has %d of the product %s.\n", breadStock.quantity, breadStock.product.name);

    
    

    // double price = findProductPrice(shop,"Coke Can");
    // printf("%.2f\n", price);

    //printf("The shop has %d of the product %s\n", cokeStock.quantity, cokeStock.product.name);

    return 0;
}
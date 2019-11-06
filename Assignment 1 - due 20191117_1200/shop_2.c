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

struct Shop createAndStockShop()
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("stock.csv", "r");
    if (fp == NULL ){
        exit(EXIT_FAILURE);
    }

    getline(&line, &len, fp);
    double cashInShop = atof(line);
    struct Shop shop = {cashInShop};


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

    return shop;
}

void printShop(struct Shop s){
    printf("Shop has %.2f in cash\n", s.cash);

    for (int i = 0; i < s.index; i++){
        printProduct(s.stock[i].product);
        printf("Shop has %d of the above.\n", s.stock[i].quantity);
    }
}

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
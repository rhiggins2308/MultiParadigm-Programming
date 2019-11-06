#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Product{
    char* name;
    double price;
};

struct ProductStock{
    struct Product product;
    int quantity;
};

struct Customer{
    char* name;
    double budget;
    struct ProductStock shoppingList[10];
    int index;
};

struct Shop{
    double cash;
    struct ProductStock stock[20];
    int index;
};

void printProduct(struct Product p){
    printf("PRODUCT NAME: %s \nPRODUCT PRICE: %.2f\n", p.name, p.price);
    printf("----------------------\n");
}

void printCustomer(struct Customer c){
    printf("CUSTOMER NAME: %s \nCUSTOMER BUDGET: %.2f\n", c.name, c.budget);
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

struct Shop createAndStockShop(){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("stock.csv", "r");
    if (fp == NULL ){
        exit(EXIT_FAILURE);
    }

    getline(&line, &len, fp);
    double shopCash = atof(line);

    struct Shop shop = {shopCash};

    while ((read = getline(&line, &len, fp)) != -1){
       // printf("%s IS A LINE", line);
       char *n = strtok(line, ",");
       char *p = strtok(NULL, ",");
       char *q = strtok(NULL, ",");
       
       char *name = malloc(sizeof(char) * 50);
       strcpy(name, n);
       double price = atof(p);
       int quantity = atoi(q);

       struct Product product = {name, price};
       struct ProductStock stockItem = {product, quantity};

       shop.stock[shop.index++] = stockItem;    
       //printf("NAME OF PRODUCT: %s ; PRICE: €%.2f ; QUANTITY: %d\n", name, price, quantity);
    }

    return shop;
}

double findProductPrice(struct Shop s, char *n)
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

int main(void)
{
    /*
    struct Customer robbie = {"Robbie", 100.0};
    printCustomer(robbie);
    
    struct Product coke = {"Coca Cola", 1.10};
    printProduct(coke);
    
    struct Product bread = {"Bread", 0.70};
    printProduct(bread);


    struct ProductStock cokeStock = {coke, 20};
    struct ProductStock breadStock = {bread, 2};

    robbie.shoppingList[robbie.index++] = cokeStock;
    robbie.shoppingList[robbie.index++] = breadStock;

    printCustomer(robbie);
    */
    struct Shop shop = createAndStockShop();
    printShop(shop);

    double price = findProductPrice(shop,"Coke Can");
    printf("%.2f\n", price);

    //printf("The shop has %d of the product %s\n", cokeStock.quantity, cokeStock.product.name);

    return 0;
}
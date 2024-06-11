#include <stdio.h>
#include <string.h>
#include <math>

#define MAX_TOYS 100

typedef struct {
    char name[50];
    char category[30];
    float supply_price;
    float sale_price;
    int quantity_sold;
} Product;

void collect(Product *p) {
    printf("Enter toy name: ");
    scanf("%s", p->name);
    printf("Enter toy category: ");
    scanf("%s", p->category);
    printf("Enter toy supply price: ");
    scanf("%f", &p->supply_price);
    printf("Enter toy sale price: ");
    scanf("%f", &p->sale_price);
    printf("Enter quantity sold: ");
    scanf("%d", &p->quantity_sold);

    float benefit = (p->sale_price - p->supply_price) * p->quantity_sold;
    printf("Benefit gained from this toy: $%.2f\n", benefit);
}

void CollectData(Product products[], int *num_products) {
    printf("How many toys do you want to add? ");
    scanf("%d", num_products);

    for (int i = 0; i < *num_products; i++) {
        printf("Toy #%d:\n", i + 1);
        collect(&products[i]);
    }
}

float benefit(Product products[], int num_products) {
    float total_benefit = 0.0;

    for (int i = 0; i < num_products; i++) {
        float benefit = (products[i].sale_price - products[i].supply_price) * products[i].quantity_sold;
        total_benefit += benefit;
         }

    return total_benefit;
}

char* mostSold(Product products[], int num_products) {
    int max_quantity = -1;
    char *most_sold_toy = "";

    for (int i = 0; i < num_products; i++) {
        if (products[i].quantity_sold > max_quantity) {
            max_quantity = products[i].quantity_sold;
            most_sold_toy = products[i].name;
        }
    }

    return most_sold_toy;
    }

char* bestProduct(Product products[], int num_products) {
    float max_benefit = -1.0;
    char *best_toy = "";

    for (int i = 0; i < num_products; i++) {
        float benefit = (products[i].sale_price - products[i].supply_price) * products[i].quantity_sold;
        if (benefit > max_benefit) {
            max_benefit = benefit;
            best_toy = products[i].name;
        }
    }

    return best_toy;
}

char* worstProduct(Product products[], int num_products) {
    float min_ratio = 1e9; // just a high value to start with
    char *worst_toy = "";
    for (int i = 0; i < num_products; i++) {
        float benefit = (products[i].sale_price - products[i].supply_price) * products[i].quantity_sold;
        float ratio = (benefit * benefit) / products[i].quantity_sold;
        if (ratio < min_ratio) {
            min_ratio = ratio;
            worst_toy = products[i].name;
        }
    }

    return worst_toy;
}

int main() {
    Product products[MAX_TOYS];
    int num_products = 0;

    CollectData(products, &num_products);

    float total_benefit = benefit(products, num_products);
    printf("Total benefit: $%.2f\n", total_benefit);

    char *most_sold_toy = mostSold(products, num_products);
    printf("Most sold toy: %s\n", most_sold_toy);

    char *best_toy = bestProduct(products, num_products);
    printf("Best toy: %s\n", best_toy);

    char *worst_toy = worstProduct(products, num_products);
    printf("Worst toy: %s\n", worst_toy);

    return 0;
}







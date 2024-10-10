#include <stdio.h>
#include <stdlib.h>


// Function declarations
void printMonthlySalesReport(double sales[]);
void printSalesSummaryReport(double sales[]);
void printSixMonthMovingAverage(double sales[]);
void printSalesReportDescending(double sales[], char *months[]);
void readSalesFromFile(double sales[], const char *filename);

int main() {
    double sales[12]; // Declare an array to hold sales data
    char *months[12] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };

    // Prompt the user to enter the filename
    char filename[100]; // Array to hold the filename
    printf("Enter the filename containing sales data: ");
    scanf("%99s", filename); // Read the filename from user input

    // Reading sales data from the file
    readSalesFromFile(sales, filename);

    // Generate the reports 
    printf("Monthly Sales Report for 2024\n");
    printMonthlySalesReport(sales);

    printf("\nSales Summary Report:\n");
    printSalesSummaryReport(sales);

    printf("\nSix-Month Moving Average Report:\n");
    printSixMonthMovingAverage(sales);

    printf("\nSales Report (Highest to Lowest):\n");
    printSalesReportDescending(sales, months);

    return 0;
}

void readSalesFromFile(double sales[], const char *filename) {
    FILE *file = fopen(filename, "r"); // Open the file for reading
    if(file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(1); // Exit the program if the file cannot be opened
    }

    for (int i = 0; i < 12; i++) {
        if (fscanf(file, "%lf", &sales[i]) != 1) {
            fprintf(stderr, "Error: Could not read sales data for month %d\n", i + 1);
            fclose(file);
            exit(1); // Exit if there's an error reading the sales data
        }
    }

    fclose(file); // Close the file after reading
}

void printMonthlySalesReport(double sales[]) {
    char *months[12] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };

    printf("Month      Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%-10s $%.2f\n", months[i], sales[i]);
    }
}

void printSalesSummaryReport(double sales[]) {
    double min = sales[0], max = sales[0], total = 0.0;
    int minMonth = 0, maxMonth = 0;

    for (int i = 0; i < 12; i++) {
        if (sales[i] < min) {
            min = sales[i];
            minMonth = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxMonth = i;
        }
        total += sales[i];
    }

    double average = total / 12; // Calculate average

    char *months[12] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };

    printf("Minimum sales: %.2f (%s)\n", min, months[minMonth]);
    printf("Maximum sales: %.2f (%s)\n", max, months[maxMonth]);
    printf("Average sales: %.2f\n", average);
}

void printSixMonthMovingAverage(double sales[]) {
    for (int i = 0; i <= 12 - 6; i++) { // Calculate moving average
        double total = 0.0;
        for (int j = i; j < i + 6; j++) {
            total += sales[j];
        }
        double average = total / 6.0;
        char *months[12] = {
            "January", "February", "March", "April", "May", "June", 
            "July", "August", "September", "October", "November", "December"
        };
        printf("%s-%s %.2f\n", months[i], months[i + 5], average);
    }
}

void printSalesReportDescending(double sales[], char *months[]) {
    double sortedSales[12];
    char *sortedMonths[12];

    // Copy sales and months into new arrays
    for (int i = 0; i < 12; i++) {
        sortedSales[i] = sales[i];
        sortedMonths[i] = months[i];
    }

    // Sort sales and months in descending order
    for (int i = 0; i < 12 - 1; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (sortedSales[i] < sortedSales[j]) {
                // Swap sales
                double tempSales = sortedSales[i];
                sortedSales[i] = sortedSales[j];
                sortedSales[j] = tempSales;

                // Swap months
                char *tempMonth = sortedMonths[i];
                sortedMonths[i] = sortedMonths[j];
                sortedMonths[j] = tempMonth;
            }
        }
    }

    // Print sorted sales and months
    printf("Month      Sales\n");
    for(int i = 0; i < 12; i++) {
        printf("%-10s $%.2f\n", sortedMonths[i], sortedSales[i]);
    }
}

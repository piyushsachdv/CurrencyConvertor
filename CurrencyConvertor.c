#include <stdio.h>

void showCurrencyList() {
    printf("1: USD (United States Dollar)\n");
    printf("2: EUR (Euro)\n");
    printf("3: GBP (British Pound)\n");
    printf("4: INR (Indian Rupee)\n");
    printf("5: JPY (Japanese Yen)\n");
    printf("6: AUD (Australian Dollar)\n");
    printf("7: CAD (Canadian Dollar)\n");
    printf("8: CNY (Chinese Yuan)\n");
    printf("9: ZAR (South African Rand)\n");
}

double getConversionRate(int fromCurrency, int toCurrency) {
    double rates[9][9] = {
        { 1.0,  0.94,  0.82,  83.22, 149.23,  1.57,  1.36,  7.31,  18.87}, 
        { 1.06, 1.0,   0.87,  88.62, 158.77,  1.67,  1.45,  7.77,  20.08}, 
        { 1.22, 1.15,  1.0,  101.47, 181.89,  1.93,  1.66,  8.96,  23.20}, 
        { 0.012, 0.011, 0.0098, 1.0,  1.79,  0.019, 0.016, 0.088, 0.23},  
        { 0.0067, 0.0063, 0.0055, 0.56, 1.0,  0.011, 0.0091, 0.049, 0.13}, 
        { 0.64,  0.60,  0.52,  53.09, 91.15,  1.0,   0.86,  4.64,  12.04}, 
        { 0.73,  0.69,  0.60,  61.76, 106.89, 1.16,  1.0,   5.40,  14.04}, 
        { 0.14,  0.13,  0.11,  11.43, 19.97,  0.22,  0.19,  1.0,   2.60},  
        { 0.053, 0.050, 0.043, 4.38,  7.93,  0.083, 0.071, 0.38,  1.0}     
    };
    
    return rates[fromCurrency - 1][toCurrency - 1];
}

int main() {
    int fromCurrency, toCurrency;
    double amount, convertedAmount, rate;

    printf("Currency Converter\n");
    printf("Choose the base currency (from):\n");
    showCurrencyList();
    printf("Enter the number corresponding to the base currency: ");
    scanf("%d", &fromCurrency);

    if (fromCurrency < 1 || fromCurrency > 9) {
        printf("Invalid currency selection.\n");
        return 1;
    }

    printf("Choose the target currency (to):\n");
    showCurrencyList();
    printf("Enter the number corresponding to the target currency: ");
    scanf("%d", &toCurrency);

    if (toCurrency < 1 || toCurrency > 9) {
        printf("Invalid currency selection.\n");
        return 1;
    }

    printf("Enter the amount to convert: ");
    scanf("%lf", &amount);
    
    if (amount < 0) {
        printf("Amount must be non-negative.\n");
        return 1;
    }

    rate = getConversionRate(fromCurrency, toCurrency);
    convertedAmount = amount * rate;

    printf("Converted Amount: %.2lf\n", convertedAmount);
    return 0;
}


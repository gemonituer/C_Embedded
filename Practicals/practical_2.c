#include <stdio.h>
#include <string.h>
#include <math.h>

#define EPSILON 1e-10

// Safe user input of a double value
double read_value(const char *prompt) {
    double value;
    char buffer[25];
    char extra;
    int success;

    do {
        printf("%s", prompt);

        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Error reading input. Please try again.\n");
            success = 0;
            continue;
        }

        if (!strchr(buffer, '\n')) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("Input too long. Please enter a shorter number.\n");
            success = 0;
            continue;
        }

        success = sscanf(buffer, " %lf %c", &value, &extra) == 1;

        if (!success) {
            printf("Invalid input. Please enter a numeric value.\n");
        }

    } while (!success);

    return value;
}

// Calculation of z1
double calc_z1(double d, double x) {
    double numerator = sin(M_PI / 2.0 + 3.0 * d);
    double denominator = 1 - sin(3.0 * x - M_PI);

    if (fabs(denominator) < EPSILON) {
        printf("\nError: denominator in z1 is too close to zero.\n");
        return NAN;
    }

    return numerator / denominator;
}

// Calculation of z2
double calc_z2(double x) {
    double angle = (5.0 * M_PI) / 4.0 + 1.5 * x;
    double tan_value = tan(angle);

    if (fabs(tan_value) < EPSILON) {
        printf("\nError: cotangent in z2 is undefined for the given input value.");
        return NAN;
    }

    return 1.0 / tan_value;
}

int main() {
    double d, x_for_z1, x_for_z2;

    // Input for z1
    printf("Calculation of z1 = sin(pi/2 + 3*d) / (1 - sin(3*x - pi))\n");
    x_for_z1 = read_value("Enter value for x: ");
    d = read_value("Enter value for d: ");

    // Input for z2
    printf("\nCalculation of z2 = ctg(5*pi/4 + 3*x/2)\n");
    x_for_z2 = read_value("Enter value for x: ");

    // Calculations
    double z1 = calc_z1(d, x_for_z1);
    double z2 = calc_z2(x_for_z2);

    // Output results
    if (!isnan(z1))
        printf("\nz1 = %.3lf\n", z1);

    if (!isnan(z2))
        printf("z2 = %.3lf\n", z2);

    return 0;
}

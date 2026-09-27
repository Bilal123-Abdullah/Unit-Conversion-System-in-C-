#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void get_user_input(double *value) {
    scanf("%lf", value);
}

void log_conversion(const char *category, double input, const char *priorunit, double output, const char *laterunit) {
    FILE *fp = fopen("conversion_log.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%s: %.4f %s = %.4f %s\n", category, input, priorunit, output, laterunit);
        fclose(fp);
    }
}

void handle_mass() {
    char *units[] = {"kg", "g", "pounds"};
    int choice;
    double value, result;
    
    printf("\n1. kg to g\n2. kg to pounds\n3. g to kg\n4. g to pounds\n5. pounds to kg\n6. pounds to g\nChoice: ");
    scanf("%d", &choice);
    printf("Enter value: ");
    get_user_input(&value);
    
    switch(choice) {
        case 1: result = value * 1000; log_conversion("Mass", value, units[0], result, units[1]); break;
        case 2: result = value * 2.20462; log_conversion("Mass", value, units[0], result, units[2]); break;
        case 3: result = value / 1000; log_conversion("Mass", value, units[1], result, units[0]); break;
        case 4: result = value * 0.00220462; log_conversion("Mass", value, units[1], result, units[2]); break;
        case 5: result = value / 2.20462; log_conversion("Mass", value, units[2], result, units[0]); break;
        case 6: result = value * 453.592; log_conversion("Mass", value, units[2], result, units[1]); break;
        default: printf("Invalid choice\n"); return;
    }

    printf("Result: %.4f\n", result);
}

void handle_length() {
    char *units[] = {"cm", "feet", "inch", "km"};
    int choice;
    double value, result;
    
    printf("\n1. cm to feet\n2. cm to inch\n3. cm to km\n4. feet to cm\n5. inch to cm\n6. km to cm\nChoice: ");
    scanf("%d", &choice);
    printf("Enter value: ");
    get_user_input(&value);
    
    switch(choice) {
        case 1: result = value / 30.48; log_conversion("Length", value, units[0], result, units[1]); break;
        case 2: result = value / 2.54; log_conversion("Length", value, units[0], result, units[2]); break;
        case 3: result = value / 100000; log_conversion("Length", value, units[0], result, units[3]); break;
        case 4: result = value * 30.48; log_conversion("Length", value, units[1], result, units[0]); break;
        case 5: result = value * 2.54; log_conversion("Length", value, units[2], result, units[0]); break;
        case 6: result = value * 100000; log_conversion("Length", value, units[3], result, units[0]); break;
        default: printf("Invalid choice\n"); return;
    }

    printf("Result: %.4f\n", result);
}

void handle_time() {
    char *units[] = {"sec", "min", "hour", "days"};
    int choice;
    double value, result;
    
    printf("\n1. sec to min\n2. sec to hour\n3. min to sec\n4. hour to min\n5. days to hour\n6. hour to days\nChoice: ");
    scanf("%d", &choice);
    printf("Enter value: ");
    get_user_input(&value);
    
    switch(choice) {
        case 1: result = value / 60; log_conversion("Time", value, units[0], result, units[1]); break;
        case 2: result = value / 3600; log_conversion("Time", value, units[0], result, units[2]); break;
        case 3: result = value * 60; log_conversion("Time", value, units[1], result, units[0]); break;
        case 4: result = value * 60; log_conversion("Time", value, units[2], result, units[1]); break;
        case 5: result = value * 24; log_conversion("Time", value, units[3], result, units[2]); break;
        case 6: result = value / 24; log_conversion("Time", value, units[2], result, units[3]); break;
        default: printf("Invalid choice\n"); return;
    }

    printf("Result: %.4f\n", result);
}

void handle_temperature() {
    char *units[] = {"F", "C", "K"};
    int choice;
    double value, result;
    
    printf("\n1. F to C\n2. F to K\n3. C to F\n4. C to K\n5. K to C\n6. K to F\nChoice: ");
    scanf("%d", &choice);
    printf("Enter value: ");
    get_user_input(&value);
    
    switch(choice) {
        case 1:
            result = (value - 32) * 5.0/9.0;
            log_conversion("Temperature", value, units[0], result, units[1]);
            break;

        case 2:
            result = (value - 32) * 5.0/9.0 + 273.15;
            log_conversion("Temperature", value, units[0], result, units[2]);
            break;

        case 3:
            result = value * 9.0/5.0 + 32;
            log_conversion("Temperature", value, units[1], result, units[0]);
            break;

        case 4:
            result = value + 273.15;
            log_conversion("Temperature", value, units[1], result, units[2]);
            break;

        case 5:
            result = value - 273.15;
            log_conversion("Temperature", value, units[2], result, units[1]);
            break;

        case 6:
            result = (value - 273.15) * 9.0/5.0 + 32;
            log_conversion("Temperature", value, units[2], result, units[0]);
            break;

        default:
            printf("Invalid choice\n");
            return;
    }

    printf("Result: %.4f\n", result);
}

void handle_speed() {
    char *units[] = {"m/s", "km/h"};
    int choice;
    double value, result;
    
    printf("\n1. m/s to km/h\n2. km/h to m/s\nChoice: ");
    scanf("%d", &choice);
    printf("Enter value: ");
    get_user_input(&value);
    
    if(choice==1) {
        result = value * 3.6;
        log_conversion("Speed", value, units[0], result, units[1]);
    }
    else if(choice==2) {
        result = value / 3.6;
        log_conversion("Speed", value, units[1], result, units[0]);
    }
    else {
        printf("Invalid choice\n");
        return;
    }

    printf("Result: %.4f\n", result);
}

void handle_volume() {
    char *units[] = {"Liters", "ml", "Gallons"};
    int choice;
    double value, result;
    
    printf("\n1. Liters to ml\n2. Liters to Gallons\n3. ml to Liters\n4. Gallons to Liters\nChoice: ");
    scanf("%d", &choice);
    printf("Enter value: ");
    get_user_input(&value);
    
    switch(choice) {
        case 1: result = value * 1000; log_conversion("Volume", value, units[0], result, units[1]); break;
        case 2: result = value * 0.264172; log_conversion("Volume", value, units[0], result, units[2]); break;
        case 3: result = value / 1000; log_conversion("Volume", value, units[1], result, units[0]); break;
        case 4: result = value / 0.264172; log_conversion("Volume", value, units[2], result, units[0]); break;
        default: printf("Invalid choice\n"); return;
    }

    printf("Result: %.4f\n", result);
}

int main() {
    char *menu[] = {"Mass", "Length", "Time", "Temperature", "Speed", "Volume"};
    int choice;
    
    do {
        printf("\n=== UNIT CONVERTER ===\n");
        printf("1. %s\n2. %s\n3. %s\n4. %s\n5. %s\n6. %s\n0. Exit\n",
               menu[0], menu[1], menu[2], menu[3], menu[4], menu[5]);

        printf("Select category: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: handle_mass(); break;
            case 2: handle_length(); break;
            case 3: handle_time(); break;
            case 4: handle_temperature(); break;
            case 5: handle_speed(); break;
            case 6: handle_volume(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }

    } while(choice!=0);
    
    return 0;
}
/*
 ============================================================================
 Name        : calcVec3.c
 Author      : dog
 Version     :
 Copyright   : gav
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    float num1, num2, * vec1, * vec2, res;
    int ftl, size, n;
    char op = '+', fc, sv, cont1, cont2, inputFile[100], outputFile[100];

    printf("Select a method (f/c): "); //we select a method of work (file / console)
    scanf(" %c", &fc);

    switch (fc) {
    case 'f': //working with files
        do {
            FILE* input, * output; //we announce the structures with which we will work
            printf("Enter name of input file: ");
            scanf(" %s", inputFile);
            printf("Enter name of output file: ");
            scanf(" %s", outputFile);
            input = fopen(inputFile, "r"); //open the file for reading
            output = fopen(outputFile, "w"); //open the file for writing
            while (feof(input) == 0) { //function that allows you to read the file to the end
                fscanf(input, " %c", &sv);
                fscanf(input, " %c", &op);

                switch (sv) { //choose to work with numbers or vectors
                case 's': { //working with numbers
                    switch (op) {
                    case '+': {
                        fscanf(input, " %f", &num1);
                        fscanf(input, " %f", &num2);
                        fprintf(output, "%f + %f = %f", num1, num2, num1 + num2);
                        break; }
                    case '-': {
                        fscanf(input, " %f", &num1);
                        fscanf(input, " %f", &num2);
                        fprintf(output, "%f - %f = %f", num1, num2, num1 - num2);
                        break; }
                    case '/': {
                        fscanf(input, " %f", &num1);
                        fscanf(input, " %f", &num2);
                        if (num2 != 0)
                            fprintf(output, "%f / %f = %f", num1, num2, num1 / num2);
                        break; }
                    case '*': {
                        fscanf(input, " %f", &num1);
                        fscanf(input, " %f", &num2);
                        fprintf(output, "%f * %f = %f", num1, num2, num1 * num2);
                        break; }
                    case '^': {
                        fscanf(input, " %f", &num1);
                        fscanf(input, " %i", &n);
                        res = 1;
                        for (int i = 0; i < n; i++)
                            res = res * num1;
                        fprintf(output, "%f ^ %i = %f", num1, n, res);
                        break; }
                    case '!': {
                        ftl = 1;
                        fscanf(input, " %i", &n);
                        if (n >= 0)
                            for (int i = n; i != 1; i--)
                                ftl = ftl * i;
                        else
                            fprintf(output, "The number must be positive!");
                        fprintf(output, "!%i = %i", n, ftl);
                        break; }
                    }
                    fprintf(output, "\n");
                    break; }

                case 'v': { //we work with vectors
                    vec1 = malloc(size * sizeof(int)); //allocate memory for vectors
                    vec2 = malloc(size * sizeof(int));

                    switch (op) {
                    case '+': {
                        fscanf(input, " %i", &size);
                        for (int i = 0; i < size; i++)
                            fscanf(input, " %f", &vec1[i]);
                        for (int i = 0; i < size; i++)
                            fscanf(input, " %f", &vec2[i]);
                        fprintf(output, "( ");
                        for (int i = 0; i < size; i++)
                            fprintf(output, "%.0f ", vec1[i]);
                        fprintf(output, ") + ( ");
                        for (int i = 0; i < size; i++)
                            fprintf(output, "%.0f ", vec2[i]);
                        fprintf(output, ") = ( ");
                        for (int i = 0; i < size; i++)
                            fprintf(output, "%.0f ", vec1[i] + vec2[i]);
                        fprintf(output, ")");
                        break; }
                    case '-': {
                        fscanf(input, " %i", &size);
                        for (int i = 0; i < size; i++)
                            fscanf(input, " %f", &vec1[i]);
                        for (int i = 0; i < size; i++)
                            fscanf(input, " %f", &vec2[i]);
                        fprintf(output, "( ");
                        for (int i = 0; i < size; i++)
                            fprintf(output, "%.0f ", vec1[i]);
                        fprintf(output, ") - ( ");
                        for (int i = 0; i < size; i++)
                            fprintf(output, "%.0f ", vec2[i]);
                        fprintf(output, ") = ( ");
                        for (int i = 0; i < size; i++)
                            fprintf(output, "%.0f ", vec1[i] - vec2[i]);
                        fprintf(output, ")");
                        break; }
                    }}
                        fprintf(output, "\n");
                        free(vec1); //free memory
                        free(vec2);
                        break;
                }
            }
            fclose(input); //close files
            fclose(output);
            break;
            printf("Continue?(y/n): ");
            scanf(" %c", &cont1);
        } while (cont1 != 'n');
        break;
    case 'c': //working with the console
        do {
            printf("Work with numbers or with vectors?(s/v): ");
            scanf(" %c", &sv);

            switch (sv) {
            case 's': { //working with numbers
                printf("Operation(+-*/^!): ");
                scanf(" %c", &op);

                switch (op) {
                case '+': {
                    printf("Enter the first value:");
                    scanf("%f", &num1);
                    printf("Enter the second value:");
                    scanf("%f", &num2);
                    printf("Result: %.2f\n",num1 + num2);
                    break; }
                case '-': {
                    printf("Enter the first value:");
                    scanf("%f", &num1);
                    printf("Enter the second value:");
                    scanf("%f", &num2);
                    printf("Result: %.2f\n",num1 - num2);
                    break; }
                case '/': {
                    printf("Enter the first value: ");
                    scanf("%f", &num1);
                    printf("Enter the second value: ");
                    scanf("%f", &num2);
                    if (num2 != 0)
                        printf("Result: %.4f\n",num1 / num2);
                    else
                        printf("You can't divide by zero.\n");
                    break; }
                case '*': {
                    printf("Enter the first value: ");
                    scanf("%f", &num1);
                    printf("Enter the second value: ");
                    scanf("%f", &num2);
                    printf("Result: %.2f\n",num1 * num2);
                    break; }
                case '^': {
                    printf("Enter the value: ");
                    scanf("%f", &num1);
                    printf("Enter the exponent(integer): ");
                    scanf("%i", &n);
                    res = 1;
                    for (int i = 0; i < n; i++)
                        res = res * num1;
                    printf("Result: %.2f\n", res);
                    break; }
                case '!': {
                    ftl = 1;
                    printf("Enter the number(integer): ");
                    scanf("%i", &n);
                    if (n >= 0)
                        for (int i = n; i != 1; i--)
                            ftl = ftl * i;
                    else
                        printf("The number must be positive!");
                    printf("Result: %i\n", ftl);
                    break; }
                }
                printf("Continue?(y/n): ");
                scanf(" %c", &cont2);
                break; }

            case 'v': { //working with vectors
                printf("Operation(+-): ");
                scanf(" %c", &op);
                vec1 = malloc(size * sizeof(int)); //allocate memory for vectors
                vec2 = malloc(size * sizeof(int));
                printf("Vector's size: ");
                scanf(" %i", &size);

                switch (op) {
                case '+': {
                    printf("Enter the first vector: ");
                    for (int i = 0; i < size; i++)
                        scanf(" %f", &vec1[i]);
                    printf("Enter the second vector: ");
                    for (int i = 0; i < size; i++)
                        scanf(" %f", &vec2[i]);
                    printf("Result: ");
                    for (int i = 0; i < size; i++)
                        printf("%.2f ", vec1[i] + vec2[i]);
                    printf("\n");
                    free(vec1); //free memory
                    free(vec2);
                    break; }
                case '-': {
                    printf("Enter the first vector: ");
                    for (int i = 0; i < size; i++)
                        scanf(" %f", &vec1[i]);
                    printf("Enter the second vector: ");
                    for (int i = 0; i < size; i++)
                        scanf(" %f", &vec2[i]);
                    printf("Result: ");
                    for (int i = 0; i < size; i++)
                        printf("%.2f ", vec1[i] - vec2[i]);
                    printf("\n");
                    free(vec1); //free memory
                    free(vec2);
                    break; }
                }}
                    printf("Continue?(y/n): ");
                    scanf(" %c", &cont2);
            }
        } while (cont2 == 'y');
    }
}

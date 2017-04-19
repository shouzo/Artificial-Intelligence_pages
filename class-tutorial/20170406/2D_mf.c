#include <stdlib.h>
#include <stdio.h>


int main(void) {
    int i = 0, j = 0;  // Set loop
    float mf[5] = {0, 0.2375, 0.475, 0.7125, 0.95};
    float X1 = 0, X2 = 0;     // Input X1, X2
    float ua1 = .0, ua2 = .0;   // for X1
    float ub1 = .0, ub2 = .0;   // for X2
    float u13 = .0, u14 = .0, u23 = .0, u24 = .0;
    char name[5][3] = {"VS", "S", "M", "L", "VL"};


    /* The entry */
    while (1) {
        /* Initial value */
        ua1 = .0, ua2 = .0;
        ub1 = .0, ub2 = .0;
        u13 = .0, u14 = .0, u23 = .0, u24 = .0;
 

        /* Key the value of x */
        printf("\n\nPlease key in the value of 'Input'\n");
        printf("X1 = ");    scanf("%f", &X1);
        printf("X2 = ");    scanf("%f", &X2);


        /* Calculate the linear μ */
        printf("\n\n****The membership function****\n");
        for (i = 0; i < 5; i++) {
            // input = mf
            if (((X1 == mf[i]))) { 
                ua1 = .0;    ua2 = 1.;
                printf("X1：μ[%s] = 1, ua1 = %.3f、ua2 = %.3f\n", name[i], ua1, ua2);
            }
            if (((X2 == mf[i]))) { 
                ub1 = .0;    ub2 = 1.;
                printf("X2：μ[%s] = 1, ub1 = %.3f、ub2 = %.3f\n", name[i], ub1, ub2);
                break;
            }


            // input bigger than the max's mf
            if ((X1 > mf[4])) { 
                ua1 = .0;   ua2 = 1.;
                printf("X1：μ[%s] = 1, ua1 = %.3f、ua2 = %.3f\n", name[4], ua1, ua2);
            }
            if ((X2 > mf[4])) { 
                ub1 = .0;   ub2 = 1.;
                printf("X2：μ[%s] = 1, ub1 = %.3f、ub2 = %.3f\n", name[4], ub1, ub2);
                break;
            }


            // input smaller than the min's mf
            if ((X1 < mf[0])) { 
                ua1 = 1.;   ua2 = .0;
                printf("X1：μ[%s] = 1, ua1 = %.3f、ua2 = %.3f\n", name[0], ua1, ua2);
            }
            if ((X2 < mf[0])) { 
                ub1 = 1.;   ub2 = .0;
                printf("X2：μ[%s] = 1, ub1 = %.3f、ub2 = %.3f\n", name[0], ub1, ub2);
                break;
            }


            // Calculate (The linear)... 
            if ((X1 > mf[i]) && (X1 < mf[i+1])) {
                printf("\n****The linear：X1****\n");
                ua1 = (1 - (mf[i] - X1) / (mf[i] - mf[i+1]));
                ua2 = (1 - (X1 - mf[i+1]) / (mf[i] - mf[i+1])); 
                printf("X1：ua1 = μ[%s] = %.3f\n", name[i], ua1);
                printf("X1：ua2 = μ[%s] = %.3f\n", name[i+1], ua2);
            }
            if ((X2 > mf[i]) && (X2 < mf[i+1])) {
                printf("\n****The linear：X2****\n");
                ub1 = (1 - (mf[i] - X2) / (mf[i] - mf[i+1]));
                ub2 = (1 - (X2 - mf[i+1]) / (mf[i] - mf[i+1])); 
                printf("X2：ub1 = μ[%s] = %.3f\n", name[i], ub1);
                printf("X2：ub2 = μ[%s] = %.3f\n", name[i+1], ub2);
                break;
            }
        }


        // Get the minimun...
        printf("\n****The minimum****\n");
        u13 = (ua1 < ub1 ? ua1 : ub1);    u14 = (ua1 < ub2 ? ua1 : ub2);
        u23 = (ua2 < ub1 ? ua2 : ub1);    u24 = (ua2 < ub2 ? ua2 : ub2);
        printf("u13 = %.3f\n", u13);  printf("u14 = %.3f\n", u14);
        printf("u23 = %.3f\n", u23);  printf("u24 = %.3f\n", u24);


        // Get the product...
        printf("\n****The product****\n");
        u13 = ua1 * ub1;    u14 = ua1 * ub2;
        u23 = ua2 * ub1;    u24 = ua2 * ub2;
        printf("u13 = %.3f\n", u13);  printf("u14 = %.3f\n", u14);
        printf("u23 = %.3f\n", u23);  printf("u24 = %.3f\n", u24);
    }
    return 0;
}

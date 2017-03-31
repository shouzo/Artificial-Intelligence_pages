#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int i = 0, j = 0;  // Set loop
    float mf[7], tmp = .0, input = .0, sa = .0, ua = .0, ub = .0;
    char name[7][3] = {"NB", "NM", "NS", "ZR", "PS", "PM", "PB"};

    /* Key the value of name */
    printf("Please define NS、NM、NB value (smaller than 0)\n");
    for (i = 0; i < 3; i++) {
        scanf("%f", &mf[i]);
    }
      
    printf("Please define PS、PM、PB value (bigger than 0)\n");
    for (i = 3; i < 6; i++) {
        scanf("%f", &mf[i]);
    }

    mf[6] = 0;  // Set the ZR value


    /* Sort the numbers */
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            if ((mf[j] > mf[i])) {
                tmp = mf[i];
                mf[i] = mf[j];
                mf[j] = tmp;
            }
       }
    }


    /* The entry */
    while(1) {
        /* Key the value of x */
        printf("\n\nPlease key in the value of 'Input'\n");
        printf("Input = ");
        scanf("%f", &input);


        /* Calculate the linear μ */
        printf("\n\n****The membership function****\n");
        for (i = 0; i < 7; i++) {
            // input = mf
            if (((input == mf[i]))) { 
                printf("μ[%s] = %.f\n", name[i], (mf[i] / mf[i]));
                break;
            }

            // input bigger than the max's mf
            else if ((input > mf[6])) { 
                printf("μ[%s] = %.f\n", name[6], (mf[6] / mf[6]));
                break;
            }

            // input smaller than the min's mf
            else if ((input < mf[0])) { 
                printf("μ[%s] = %.f\n", name[0], (mf[0] / mf[0]));
                break;
            }

            // Calculate...
            else if ((input > mf[i]) && (input < mf[i+1])) {
                /* linear area */
                printf("\n****The linear****\n");
                ua = (1 - (mf[i] - input) / (mf[i] - mf[i+1]));
                ub = (1 - (input - mf[i+1]) / (mf[i] - mf[i+1])); 
                printf("μ[%s] = %.3f\n", name[i], ua);
                printf("μ[%s] = %.3f\n", name[i+1], ub);
                
                /* non-linear area */
                printf("\n****The non-linear (S-function)****\n");
                if (input < ((mf[i] + mf[i+1]) / 2)) {
                    sa = (((input - mf[i]) / (mf[i+1] - mf[i])));
                    ua = 1 - (2 * sa * sa);
                    ub = 1 - ua;
                    printf("μ[%s] = %.3f\n", name[i], ua);
                    printf("μ[%s] = %.3f\n", name[i+1], ub);
                }

                else if ((input >= ((mf[i] + mf[i+1]) / 2)) && (input < mf[i+1])) {
                    sa = (((input - mf[i+1]) / (mf[i+1] - mf[i])));
                    ua = (2 * sa * sa);
                    ub = 1 - ua;
                    printf("μ[%s] = %.3f\n", name[i], ua);
                    printf("μ[%s] = %.3f\n", name[i+1], ub);
                }
                break;
            }
        }
    }
    return 0;
}

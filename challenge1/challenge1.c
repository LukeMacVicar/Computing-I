#include <stdio.h>

//Check if order is correct
int orderCheck(int carOrder[], int L){
    int properOrder[50] = {}; //Array to store the correct order of train cars
    int testCounter = 1; //This counter saves how many cars are correct in the test
    int testResult = 0; //variable used to store the boolean result of the test
    int swapCounter = 0; //This counter saves how many swaps were preformed
    int checkCounter = 1; //This counter saves how many correct orders we have
    
    //Create proper order to check against
    printf("Proper order of cars: ");
    for(int i = 1; i <= L; i++){
        properOrder[i] = i;
        printf("%d ", properOrder[i]);
    }
    printf("\n");
    
    //Preform tests and swaps to match proper order of cars
    //This loop will exit when the test has been passed
    while(testResult == 0){
        //This loop will run through the remaining cars until they are correct
        for(int i = checkCounter; i <= L; i++){
            int saveOrder = 0; // Variable stores the element we are working with so it doesn't get erase when we swap
            // This loop enters when you get to the next lowest number in your sequence
            if(carOrder[i]==checkCounter){
                // This will enter when you number is too high in the list
                if(i > carOrder[i]){
                    //swaps the oder of elements in the array
                    saveOrder = carOrder[i];
                    carOrder[i] = carOrder[i-1];
                    carOrder[i-1] = saveOrder;
                    swapCounter++;
                }
                // This will enter when you number is too low in the list
                else if(i < carOrder[i]){
                    //swaps the oder of elements in the array
                    saveOrder = carOrder[i];
                    carOrder[i] = carOrder[i+1];
                    carOrder[i+1] = saveOrder;
                    swapCounter++;
                }
                // This will enter when your number is in the right place
                else if(i == carOrder[i]){
                    // We count up so we no longer
                    checkCounter++;
                }
                }

            // Test if all of the train cars are in the correct place
            if(carOrder[i] == properOrder[i]){
                testCounter = 0;
                for(int i = testCounter; i <= L; i++){
                    if(carOrder[i] == properOrder[i]){
                        testCounter++;
                    }
                }
                if(testCounter >= L){
                    testResult = 1;
                    break;
                }
                else{
                    testResult = 0;
                }
            }
        }
    }
    return swapCounter;
}

//Main function
int main(int arg, char * argv[]){
    int L;
    int carOrder[50] = {};
    
    //Get input for the length of train
    printf("Enter the legnth of the train: ");
    scanf("%d", &L);
    
    //Get input for order of the cars
    for(int i = 1; i <= L; i++){
        printf("Enter order of cars one by one: ");
        scanf("%d", &(carOrder[i]));
    }
    
    // Print the order of train cars
    printf("Order of cars: ");
    for(int i = 1; i <=L; i++){
        printf("%d ",carOrder[i]);
    }
    printf("\n");
    
    // Run the orderCheck function and print output
    printf("The optimal number of swaps is: %d\n",orderCheck(carOrder,L));
    return 0;
}

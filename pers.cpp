#include <iostream>
#include <string>
#include <cstring>
#include "pers.h"

bool breakdown = false;
int version = 0; // 0 => multiplication; 1 => addition

int main(int argc, char* argv[]){
    if(argc < 2){
        std::cout << "Please enter a number" << std::endl;
        exit(EXIT_FAILURE);
    }

    unsigned long long int n = atoll(argv[1]);


    for(int i = 2; i < argc; i++){
        if(strcmp(argv[i], "-b") == 0){
            breakdown = true;
        }
        else if(strcmp(argv[i], "-v") == 0){
            if(strcmp(argv[i+1], "0") == 0){
                version = 0;
            }else if(strcmp(argv[i+1], "1") == 0){
                version = 1;
            }else{
                std::cout << "Please enter a correct version number. Correct version numbers are 0(Multiplication) and 1(Addition). Default 0";
                exit(EXIT_FAILURE);
            }
            i++;
        }
    }

    int p = pers(n, 0);

    switch (version)
    {
    case 0:
        std::cout << "Multiplicative ";
        break;
    case 1:
        std::cout << "Additive ";
        break;
    default:
        break;
    }

    std::cout << "persistance of n = " << n << ": " << p << std::endl;
    return 1;
}

/**
 * solve the persistance with recursion
*/
int pers(unsigned long long int n, int depth = 0){
    if(breakdown) std::cout << depth << ": " << n << std::endl;
    // base case
    if(n < 10){
        return depth;
    }

    unsigned long long int result = 1; 
    for(unsigned long long int i = n; i>0; i /= 10){
        if(version == 0){ // multiplication
            result *= i % 10;
        }else if(version == 1){ // addition
            result += i % 10;
        }
    }

    return pers(result, depth+1);
}
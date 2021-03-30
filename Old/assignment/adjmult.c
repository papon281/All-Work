#include<stdio.h>
#include "adjmult.h"

int largestProduct(){
    int matrix[20][20]={22,85,41,16,42,07,91,47,75,90,80,68,93,22,59,53,9,60,40,71,
                        8,79,11,77,31,90,39,50,06,11,81,82,73,99,89,16,11,86,07,20,
                        26,36,00,73,50,26,50,37,61,82,70,58,26,75,26,28,14,17,9,75,
                        42,66,96,45,98,35,94,69,73,44,37,40,24,34,21,40,39,14,97,36,
                        99,21,44,68,16,36,33,70,71,94,75,84,28,01,17,66,26,77,68,97,
                        21,84,37,04,97,06,8,14,94,32,29,37,51,31,26,86,11,67,57,41,
                        97,82,42,91,37,70,28,07,98,13,99,37,64,40,52,41,66,43,35,58,
                        99,43,78,83,66,72,96,38,60,33,60,26,64,84,49,68,52,41,36,02,
                        75,14,73,66,79,20,55,51,86,48,42,00,29,56,45,29,10,42,57,58,
                        87,29,27,80,76,22,72,76,29,35,58,70,63,03,26,94,95,88,92,18,
                        18,03,13,32,74,81,83,93,38,52,60,64,02,93,28,36,48,84,72,81,
                        85,67,23,72,50,58,50,62,17,54,66,49,49,14,70,95,38,33,54,14,
                        01,40,59,21,12,92,65,59,88,9,41,83,58,99,05,99,54,53,88,93,
                        9,22,32,85,32,19,45,32,52,29,85,16,15,40,54,57,92,43,56,14,
                        75,99,43,43,65,30,61,27,07,59,51,32,78,76,37,67,63,62,84,49,
                        05,31,34,66,78,16,77,45,81,60,36,72,83,41,27,32,68,41,23,43,
                        75,29,23,54,33,80,88,24,66,32,82,75,17,28,15,92,83,63,0,75,
                        66,78,71,98,86,66,89,14,56,47,05,77,98,67,14,8,88,13,67,13,
                        73,89,35,42,56,34,84,90,9,60,20,44,63,31,15,31,28,77,88,25,
                        25,92,05,07,13,06,45,93,64,20,07,65,33,11,48,29,91,5,48,48};

    int i, j, res = 0;
    for(i = 0; i < 20; i++){
        for(j = 0; j < 20; j++){
            int horizonal = 0;
            if(j + 3 < 20){
                horizonal = matrix[i][j] * matrix[i][j+1] * matrix[i][j+2] * matrix[i][j+3];
            }
            if(horizonal > res){
                res = horizonal;
            }

            int vertical = 0;
            if(i + 3 < 20){
                vertical = matrix[i][j] * matrix[i+1][j] * matrix[i+2][j] * matrix[i+3][j];
            }

            if(vertical > res){
                res = vertical;
            }

            int rightDow = 0;
            if(i + 3 < 20 && j+3 < 20){
                rightDow = matrix[i][j] * matrix[i+1][j+1] * matrix[i+2][j+2] * matrix[i+3][j+3];
            }
            if(rightDow > res){
                res = rightDow;
            }

            int leftDown = 0;
            if(i + 3 < 20 && j>=3){
                leftDown = matrix[i][j] * matrix[i+1][j-1] * matrix[i+2][j-2] * matrix[i+3][j-3];
            }
            if(leftDown > res){
                res = leftDown;
            }
        }
    }
    return res;
}
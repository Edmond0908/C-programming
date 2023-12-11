#include <stdio.h>
#include <stdint.h>
#define ARRAYSIZE 1000
 
typedef struct giantUnsignedInt {
    uint64_t array[ARRAYSIZE];
    int n;
} GiantUnsignedInt;
 
int numZeroBits(GiantUnsignedInt *giantNum);
 
int numZeroBits(GiantUnsignedInt *giantNum){
    int ans = 0;
    int index = (giantNum -> n) - 1;
    int tmp = 0;
    uint64_t num = giantNum -> array[index];
 
    while(index >= 0){
        for(int i = 0;i < 64;i++){
            if((num & 1) == 0) tmp++;
            else tmp = 0;
            if(ans < tmp) ans = tmp;
            num = (num>>1);
        }
        if(index != 0) num = giantNum -> array[index - 1];
        index--;
    }
    return ans;
}
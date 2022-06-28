#include <string.h>

int count = 0;
int freq[26];

void gen(){
    for (int i = 0; i < 26; i++){
        if (freq[i]){
            freq[i]--;
            count++;
            gen();
            freq[i]++;
        }
    }
}

int numTilePossibilities(char * tiles){
    int len = strlen(tiles);
    count = 0;
    for (int i = 0; i < 26; i++) freq[i] = 0;
    for (int i = 0; i < len; i++) freq[tiles[i] - 'A']++;
    gen();
    return count;
}

/*
✨ Approach

1. Count the frequency of each alphabet in tiles
2. If "freq[i] > 0", you can generate another string by appending an alphabet to the current string. (decrement "freq[i]"" by 1)
3. the number of unique strings  = # of different ways to decrement "freq[i]" so that all elements become 0

*/

// https://leetcode.com/problems/letter-tile-possibilities/
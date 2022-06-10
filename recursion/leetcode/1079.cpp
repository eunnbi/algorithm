// Letter Tile Possibilities

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
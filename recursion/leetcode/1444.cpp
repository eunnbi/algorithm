// Number of Ways of Cutting Pizza

char** pizza;
int row, col;
long long memo[51][51][11];
int contain(int startX, int startY, int endX, int endY){
    for (int i = startX; i < endX; i++){
        for (int j = startY; j < endY; j++){
            if (pizza[i][j] == 'A') return 1;
        }
    }
    return 0;
}
long long cut(int i, int j, int k){ 
    if (memo[i][j][k] != -1) return memo[i][j][k];
    if (k == 1) return contain(i, j, row, col);
   
    long long res = 0;
    
    for (int index = i + 1; index < row; index++){
        if (contain(i, j, index, col)){
            res += cut(index, j, k - 1);
        }
    }
    
    for (int index = j + 1; index < col; index++){
        if (contain(i, j, row, index)){
            res += cut(i, index, k - 1);
        }
    }
    
    return memo[i][j][k] =  res;
}

int ways(char ** _pizza, int pizzaSize, int k){
    memset(memo, -1, sizeof(memo));
    pizza = _pizza;
    row = pizzaSize;
    col = strlen(pizza[0]);
    return cut(0, 0, k) % 1000000007;
}
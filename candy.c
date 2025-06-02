int candy(int* ratings, int ratingsSize) {
    int min_tot = 0, atual = 1;
    int candysE[ratingsSize], candysD[ratingsSize];
    candysE[0] = 1;
    candysD[ratingsSize-1] = 1;
    for (int i=1; i<ratingsSize;i++)
        if (ratings[i] > ratings[i-1]) candysE[i] = atual + 1, atual++;
        else candysE[i] = atual = 1;

    atual=1;
    
    for (int i=ratingsSize-2; i>=0;i--)
        if (ratings[i] > ratings[i+1]) candysD[i] = atual + 1, atual++;
        else candysD[i] = atual = 1;

    for (int i=0;i<ratingsSize;i++) 
        if (candysE[i] > candysD[i]) min_tot += candysE[i];
        else min_tot += candysD[i];

    return min_tot;
}

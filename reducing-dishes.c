int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maxSatisfaction(int* satisfaction, int satisfactionSize) {
    qsort(satisfaction, satisfactionSize, sizeof(int), cmp);
    int i=0, sum = 0;
    while (i < satisfactionSize && satisfaction[i] < 0) i++;

    if (i == satisfactionSize) return 0;
    else if (i == 0) {
        for (int i=0;i<satisfactionSize;i++) sum += satisfaction[i] * (i+1);
    } else {
        for (int k=i; k>=0;k--) {
            int tmp_sum = 0, aux = 1;
            for (int j=k;j<satisfactionSize;j++) tmp_sum += satisfaction[j] * aux, aux++;
            if (tmp_sum > sum) sum = tmp_sum;
            else break;
        }
    }
    return sum;
}

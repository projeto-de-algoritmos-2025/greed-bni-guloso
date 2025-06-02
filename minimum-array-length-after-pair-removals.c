int minLengthAfterRemovals(int* nums, int numsSize) {
    int mid = numsSize >> 1, i = 0, pulados = 0;
    int aux  = (numsSize % 2 == 0) ? mid : mid+1;
    printf("%d\n", mid);
    while (i != mid && aux != numsSize) {
        if (nums[i] == nums[aux]) {
            while (aux != numsSize) {
                if (nums[i] != nums[aux]) break;
                aux++, pulados++;
            }
        }
        if (aux == numsSize) break;
        i++,aux++;
    }
    return (numsSize % 2 == 0) ? numsSize - (aux - mid) - i + pulados : numsSize - (aux - mid - 1) - i + pulados;
}

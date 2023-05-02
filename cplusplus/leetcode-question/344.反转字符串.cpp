
void reverseString(char* s, int sSize)
{
    int left = 0;
    int right = sSize - 1;
    while(left < right)
    {
        int temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}



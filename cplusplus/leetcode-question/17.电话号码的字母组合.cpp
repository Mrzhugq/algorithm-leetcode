char phoneMap[11][5] = {"\0", "\0", "abc\0", "def\0", "ghi\0", "jkl\0", "mno\0", "pqrs\0", "tuv\0", "wxyz\0"};


char** combinations;
int combinations_size;

char* combination;
int combination_size;

void backtrack(char *digits,int digitssize,int index)
{
	if (index == digitssize)
	{
		char* tmp = malloc(sizeof(char) * (combination_size + 1));
		strcpy(tmp,combination);
		combinations[combinations_size++] = tmp;
        return;
	}

    char digit = digits[index] - '0';
    char* letters = phoneMap[digit];
    int len = strlen(letters);
    for (int i = 0; i < len; i++)
    {
        combination[combination_size++] = letters[i];
        backtrack(digits,digitssize,index + 1);
        combination_size--;
    }
    
}

char** letterCombinations(char* digits, int* returnSize)
{
	combinations_size = combination_size = 0;
	int digitsSize = strlen(digits);
	if (digitsSize == 0)
	{
		*returnSize = 0;
		return combinations;
	}
	
	int num = 1;
	for (int i = 0; i < digitsSize; i++) 
	{
		num *= 4;
	}
	
	combinations = malloc(sizeof(char*) * num);
	combination = calloc(sizeof(char*) , (digitsSize+1));//归零
	
	backtrack(digits,digitsSize,0);
	
	*returnSize = combinations_size;
	return combinations;
}


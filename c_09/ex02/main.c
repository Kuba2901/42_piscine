#include <stdio.h>

int count_words(char *str, char *charset, int str_len);

int main()
{
    // Test 1
    char test1[] = "Hello World";
    char charset1[] = " ";
    int word_count1 = count_words(test1, charset1, sizeof(test1) - 1);
    printf("Test 1: Word count: %d\n", word_count1);

    // Test 2
    char test2[] = "One,Two,Three";
    char charset2[] = ",";
    int word_count2 = count_words(test2, charset2, sizeof(test2) - 1);
    printf("Test 2: Word count: %d\n", word_count2);

    // Test 3
    char test3[] = "NoDelimiterHere";
    char charset3[] = ",";
    int word_count3 = count_words(test3, charset3, sizeof(test3) - 1);
    printf("Test 3: Word count: %d\n", word_count3);

    // Test 4
    char test4[] = "";
    char charset4[] = " ";
    int word_count4 = count_words(test4, charset4, sizeof(test4) - 1);
    printf("Test 4: Word count: %d\n", word_count4);

    // Test 5
    char test5[] = "  ";
    char charset5[] = " ";
    int word_count5 = count_words(test5, charset5, sizeof(test5) - 1);
    printf("Test 5: Word count: %d\n", word_count5);

    // Test 6
    char test6[] = "Word1 Word2 Word3";
    char charset6[] = " ";
    int word_count6 = count_words(test6, charset6, sizeof(test6) - 1);
    printf("Test 6: Word count: %d\n", word_count6);

    // Add more tests here...

    return 0;
}

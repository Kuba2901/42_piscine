#include <stdio.h>
#include <string.h>

int is_number(char c);
int is_alpha(char c);
int is_low_case(char c);
char *ft_strcapitalize(char *str);

int main(void)
{
    // Test case 1: Mixed case input with spaces and special characters
    char test1[] = "this is a tESt, string-with_special$characters!";
    ft_strcapitalize(test1);
    printf("Test 1: %s\n", test1); // Expected: "This Is A Test, String-With_Special$Characters!"

    // Test case 2: Input with digits
    char test2[] = "123 test 456";
    ft_strcapitalize(test2);
    printf("Test 2: %s\n", test2); // Expected: "123 Test 456"

    // Test case 3: Input with already capitalized words
    char test3[] = "Hello World";
    ft_strcapitalize(test3);
    printf("Test 3: %s\n", test3); // Expected: "Hello World"

    // Test case 4: Input with single letters
    char test4[] = "a b c";
    ft_strcapitalize(test4);
    printf("Test 4: %s\n", test4); // Expected: "A B C"

    // Test case 5: Empty input
    char test5[] = "";
    ft_strcapitalize(test5);
    printf("Test 5: %s\n", test5); // Expected: ""

    // Test case 6: All uppercase input
    char test6[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    ft_strcapitalize(test6);
    printf("Test 6: %s\n", test6); // Expected: "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un"

    // Test case 7: All lowercase input
    char test7[5];
	test7[0] = '\0';
    ft_strcapitalize(test7);
    printf("Test 7: %s\n", test7); // Expected: "All Lowercase"

    return 0;
}


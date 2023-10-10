#include <stdio.h>
#include <string.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

int main()
{
    // Test cases for ft_strlcpy
    char dest[20];
    char src1[] = "Hello, World!";
    unsigned int size1 = 12;
    unsigned int result1 = ft_strlcpy(dest, src1, size1);
    printf("Test 1: ft_strlcpy: \"%s\", Return: %u\n", dest, result1);

    char src2[] = "This is a test";
    unsigned int size2 = 5;
    unsigned int result2 = ft_strlcpy(dest, src2, size2);
    printf("Test 2: ft_strlcpy: \"%s\", Return: %u\n", dest, result2);

    char src3[] = "12345";
    unsigned int size3 = 3;
    unsigned int result3 = ft_strlcpy(dest, src3, size3);
    printf("Test 3: ft_strlcpy: \"%s\", Return: %u\n", dest, result3);

    char src4[] = "";
    unsigned int size4 = 10;
    unsigned int result4 = ft_strlcpy(dest, src4, size4);
    printf("Test 4: ft_strlcpy: \"%s\", Return: %u\n", dest, result4);

    char src5[] = "OpenAI GPT-3";
    unsigned int size5 = 0;
    unsigned int result5 = ft_strlcpy(dest, src5, size5);
    printf("Test 5: ft_strlcpy: \"%s\", Return: %u\n", dest, result5);

    // Test cases for standard strlcpy
    char dest_std[20];

    unsigned int std_result1 = strlcpy(dest_std, src1, size1);
    printf("Test 1: strlcpy: \"%s\", Return: %u\n", dest_std, std_result1);

    unsigned int std_result2 = strlcpy(dest_std, src2, size2);
    printf("Test 2: strlcpy: \"%s\", Return: %u\n", dest_std, std_result2);

    unsigned int std_result3 = strlcpy(dest_std, src3, size3);
    printf("Test 3: strlcpy: \"%s\", Return: %u\n", dest_std, std_result3);

    unsigned int std_result4 = strlcpy(dest_std, src4, size4);
    printf("Test 4: strlcpy: \"%s\", Return: %u\n", dest_std, std_result4);

    unsigned int std_result5 = strlcpy(dest_std, src5, size5);
    printf("Test 5: strlcpy: \"%s\", Return: %u\n", dest_std, std_result5);

	// Test 6: NULL source
    unsigned int result6 = ft_strlcpy(dest, NULL, 10);
    printf("Test 6: ft_strlcpy (NULL source), Return: %u\n", result6);

    // Test 7: NULL destination
    unsigned int result7 = ft_strlcpy(NULL, "Hello, World!", 10);
    printf("Test 7: ft_strlcpy (NULL destination), Return: %u\n", result7);

    // Test 8: Empty source
    char src8[] = "";
    unsigned int size8 = 10;
    unsigned int result8 = ft_strlcpy(dest, src8, size8);
    printf("Test 8: ft_strlcpy (Empty source), Destination: \"%s\", Return: %u\n", dest, result8);

    // Test 9: Destination size is 0
    char src9[] = "This is a test";
    unsigned int size9 = 0;
    unsigned int result9 = ft_strlcpy(dest, src9, size9);
    printf("Test 9: ft_strlcpy (Destination size is 0), Destination: \"%s\", Return: %u\n", dest, result9);

    // Test 10: Large destination size
    char src10[] = "12345";
    unsigned int size10 = 100;
    unsigned int result10 = ft_strlcpy(dest, src10, size10);
    printf("Test 10: ft_strlcpy (Large destination size), Destination: \"%s\", Return: %u\n", dest, result10);

    // Test 11: Source string is longer than destination size
    char src11[] = "This string is longer than the destination size";
    unsigned int size11 = 10;
    unsigned int result11 = ft_strlcpy(dest, src11, size11);
    printf("Test 11: ft_strlcpy (Source string is longer), Destination: \"%s\", Return: %u\n", dest, result11);

    // Test 12: NULL destination and NULL source
    unsigned int result12 = ft_strlcpy(NULL, NULL, 10);
    printf("Test 12: ft_strlcpy (NULL destination and NULL source), Return: %u\n", result12);

    // Test 13: Destination size is 1
    char src13[] = "12345";
    unsigned int size13 = 1;
    unsigned int result13 = ft_strlcpy(dest, src13, size13);
    printf("Test 13: ft_strlcpy (Destination size is 1), Destination: \"%s\", Return: %u\n", dest, result13);

    // Test 14: Destination size is 1 and source is an empty string
    char src14[] = "";
    unsigned int size14 = 1;
    unsigned int result14 = ft_strlcpy(dest, src14, size14);
    printf("Test 14: ft_strlcpy (Destination size is 1 and empty source), Destination: \"%s\", Return: %u\n", dest, result14);

    // Test 15: NULL source and destination size is 0
    unsigned int result15 = ft_strlcpy(NULL, NULL, 0);
    printf("Test 15: ft_strlcpy (NULL source and destination size is 0), Return: %u\n", result15);

    // Test 16: Destination size is 1, source is NULL
    unsigned int result16 = ft_strlcpy(dest, NULL, 1);
    printf("Test 16: ft_strlcpy (Destination size is 1, NULL source), Destination: \"%s\", Return: %u\n", dest, result16);

    // Test 17: Destination size is 0, source is NULL
    unsigned int result17 = ft_strlcpy(dest, NULL, 0);
    printf("Test 17: ft_strlcpy (Destination size is 0, NULL source), Destination: \"%s\", Return: %u\n", dest, result17);

    // Test 18: NULL destination and empty source
    char src18[] = "";
    unsigned int result18 = ft_strlcpy(NULL, src18, 10);
    printf("Test 18: ft_strlcpy (NULL destination and empty source), Return: %u\n", result18);

    // Test 19: Large destination size and empty source
    char src19[] = "";
    unsigned int size19 = 100;
    unsigned int result19 = ft_strlcpy(dest, src19, size19);
    printf("Test 19: ft_strlcpy (Large destination size and empty source), Destination: \"%s\", Return: %u\n", dest, result19);

    // Test 20: NULL destination and large destination size
    char src20[] = "12345";
    unsigned int size20 = 100;
    unsigned int result20 = ft_strlcpy(NULL, src20, size20);
    printf("Test 20: ft_strlcpy (NULL destination and large destination size), Return: %u\n", result20);

    // Test 21: Destination size is 0, source is an empty string
    char src21[] = "";
    unsigned int size21 = 0;
    unsigned int result21 = ft_strlcpy(dest, src21, size21);
    printf("Test 21: ft_strlcpy (Destination size is 0 and empty source), Destination: \"%s\", Return: %u\n", dest, result21);

    // Test 22: Destination size is 0, source is NULL
    unsigned int result22 = ft_strlcpy(dest, NULL, 0);
    printf("Test 22: ft_strlcpy (Destination size is 0, NULL source), Destination: \"%s\", Return: %u\n", dest, result22);

    // Test 23: Large destination size and NULL source
    unsigned int size23 = 100;
    unsigned int result23 = ft_strlcpy(dest, NULL, size23);
    printf("Test 23: ft_strlcpy (Large destination size and NULL source), Return: %u\n", result23);

    // Test 24: NULL destination and source is a non-empty string
    char src24[] = "Test string";
    unsigned int result24 = ft_strlcpy(NULL, src24, 10);
    printf("Test 24: ft_strlcpy (NULL destination and non-empty source), Return: %u\n", result24);

    // Test 25: Large destination size, NULL source
    unsigned int size25 = 100;
    unsigned int result25 = ft_strlcpy(dest, NULL, size25);
    printf("Test 25: ft_strlcpy (Large destination size), Return: %u\n", result25);	
    return 0;
}


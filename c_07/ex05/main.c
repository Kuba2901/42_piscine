#include <stdio.h>
#include <stdlib.h>

char **ft_split(char *str, char *charset);

int main() {
    // Test 1: Basic splitting with a comma separator
    char *str1 = "This,is,a,test,string";
    char *charset1 = ",";
    
    // Test 2: Basic splitting with a space separator
    char *str2 = "Split this sentence by spaces";
    char *charset2 = " ";
    
    // Test 3: Empty string with a separator
    char *str3 = "";
    char *charset3 = ",";
    
    // Test 4: NULL string and NULL separator
    char *str4 = NULL;
    char *charset4 = NULL;
    
    // Test 5: Splitting with a hyphen separator
    char *str5 = "one-two-three";
    char *charset5 = "-";
    
    // Test 6: Splitting with a tab separator
    char *str6 = "Tab\tseparated\twords";
    char *charset6 = "\t";
    
    // Test 7: Single word with a comma separator
    char *str7 = "Single";
    char *charset7 = ",";
    
    // Test 8: No separator, single word
    char *str8 = "NoSeparator";
    char *charset8 = ",";
    
    // Test 9: Repeated separators with empty words
    char *str9 = "A,,,B";
    char *charset9 = ",";
    
    // Test 10: Multiple separators between words
    char *str10 = "Multiple,,,Separators,,,Between,,,Words";
    char *charset10 = ",,";
    
    // Test 11: Complex separator
    /*
	char *str11 = "Split-this-string-with-a-complex-separator";
    char *charset11 = "-with-a-";
    */

    // Test 12: Numbers separated by underscores
    char *str12 = "1_2_3_4_5";
    char *charset12 = "_";
    
    // Test 13: Words separated by colons
    char *str13 = "One:Two:Three:Four:Five";
    char *charset13 = ":";
    
    // Test 14: Empty charset
    char *str14 = "ThisShouldNotBeSplit";
    char *charset14 = "";
    
    // Test 15: Empty string and charset
    char *str15 = "";
    char *charset15 = "";
    
    // Test 16: Only separators
    char *str16 = "::::::";
    char *charset16 = ":";
    
    // Test 17: Leading and trailing separators
    char *str17 = ",,Word1,Word2,,";
    char *charset17 = ",";
    
    // Test 18: Mixed separators and spaces
    char *str18 = "A, B C ,D,E";
    char *charset18 = ", ";
    
    // Test 19: Special characters as separators
    char *str19 = "Hello!World!This!Is!A!Test";
    char *charset19 = "!";
    
    // Test 20: Complex input with multiple separators
    char *str20 = "123-abC,,DeF ,gH-456-789-ijk-lmno,pqrs-TUVW:XYZ";
    char *charset20 = ",- :";
    
    char *tests[] = {str1, str2, str3, str4, str5, str6, str7, str8, str9, str10,
		str12, str13, str14, str15, str16, str17, str18, str19, str20};
    char *charsets[] = {charset1, charset2, charset3, charset4, charset5,
                        charset6, charset7, charset8, charset9, charset10, charset12, charset13, charset14, charset15,
                        charset16, charset17, charset18, charset19, charset20};
    
    for (int i = 0; i < 20; i++) {
        char **result = ft_split(tests[i], charsets[i]);
        
        printf("Test %d: Split result:\n", i + 1);
        if (result == NULL) {
            printf("   Returned NULL (Expected result for empty or NULL input).\n");
        } else {
            for (int j = 0; result[j] != NULL; j++) {
                printf("   Word %d: %s\n", j + 1, result[j]);
                free(result[j]);
            }
            free(result);
        }
        printf("\n");
    }
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestCommonSubsequence(char * text1, char * text2);
void lcs(char *text1, char *text2);
int max (int a, int b);

int main() {

    printf("%d\n", longestCommonSubsequence("abcde", "ace"));

    printf("%d\n", longestCommonSubsequence("abc", "ace"));

    printf("%d\n", longestCommonSubsequence("dgf", "ace"));

    lcs("abcde", "ace");

    return 0;
}

int longestCommonSubsequence(char * text1, char * text2){

    int len1 = strlen(text1);
    int len2 = strlen(text2);

    if (text1 == NULL || text2 == NULL || len1 == 0 || len2 == 0) {
        return 0;
    }

    int dp[len1+1][len2+1];
    int i, j;

    for (i = 0; i < len1+1; i++) {
        for (j = 0; j < len2+1; j++ ) {
            if (i == 0||j == 0) {
                dp[i][j] = 0;
            } else if (text1[i-1] != text2[j-1]) {
                if (dp[i-1][j] >= dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                } else
                    dp[i][j] = dp[i][j-1];
            } else {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }
    return dp[len1][len2];
}

void lcs(char * text1, char * text2){

    int len1 = strlen(text1);
    int len2 = strlen(text2);

    int dp[len1+1][len2+1];
    int i, j;

    for (i = 0; i < len1+1; i++) {
        for (j = 0; j < len2+1; j++ ) {
            if (i == 0||j == 0) {
                dp[i][j] = 0;
            } else if (text1[i-1] != text2[j-1]) {
                if (dp[i-1][j] >= dp[i][j-1]) {
                } else
                    dp[i][j] = dp[i][j-1];
            } else {
                dp[i][j] = dp[i-1][j-1] + 1;
                printf("%c", text1[i-1]);
            }
        }
    }
}
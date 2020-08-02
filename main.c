#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestCommonSubsequence(char * text1, char * text2);
int lcs(char *text1, char *text2, int len1, int len2);
int max (int a, int b);

int main() {
    longestCommonSubsequence("abcde", "ace");
    return 0;
}

int longestCommonSubsequence(char * text1, char * text2){

    if (text1 == NULL || text2 == NULL || strlen(text1) == 0 || strlen(text2) == 0) {
        return 0;
    }

    return lcs(text1, text2, strlen(text1), strlen(text2));
}

int lcs(char *text1, char *text2, int len1, int len2) {

    int row = len1+1;
    int col = len2+1;

    int dp[row][col];

    int i, j;

    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++ ) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[len1][len2];
}

int max (int a, int b) {
    if (a == b) {
        return a;
    } else if (a > b) {
        return a;
    } else {
        return b;
    }
}
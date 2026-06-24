class Solution {
    static final long MOD = 1_000_000_007L;

    public int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        /*
           dp[j] = ways ending at value j for one direction

           Transition:
           next[j] = sum of dp[k] where k > m - 1 - j
        */

        long[][] trans = new long[m][m];

        for (int j = 0; j < m; j++) {
            for (int k = m - j; k < m; k++) {
                trans[j][k] = 1;
            }
        }

        long[] vec = new long[m];

        for (int i = 0; i < m; i++) {
            vec[i] = 1;
        }

        long power = n - 1L;

        while (power > 0) {
            if ((power & 1L) == 1L) {
                vec = multiplyMatrixVector(trans, vec);
            }

            power >>= 1;

            if (power > 0) {
                trans = multiplyMatrix(trans, trans);
            }
        }

        long ans = 0;

        for (long x : vec) {
            ans = (ans + x) % MOD;
        }

        // two possible patterns:
        // up-down-up...
        // down-up-down...
        ans = (2 * ans) % MOD;

        return (int) ans;
    }

    private long[] multiplyMatrixVector(long[][] mat, long[] vec) {
        int n = vec.length;
        long[] res = new long[n];

        for (int i = 0; i < n; i++) {
            long sum = 0;

            for (int j = 0; j < n; j++) {
                sum = (sum + mat[i][j] * vec[j]) % MOD;
            }

            res[i] = sum;
        }

        return res;
    }

    private long[][] multiplyMatrix(long[][] a, long[][] b) {
        int n = a.length;
        long[][] res = new long[n][n];

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (a[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }

        return res;
    }
}
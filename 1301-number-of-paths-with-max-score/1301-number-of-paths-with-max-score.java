class Solution {
    public int[] pathsWithMaxScore(List<String> board) {
        int n = board.size();
        int MOD = 1_000_000_007;

        int[][] score = new int[n][n];
        int[][] ways = new int[n][n];

        // Start from S (bottom-right)
        ways[n-1][n-1] = 1;

        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {

                if (board.get(i).charAt(j) == 'X') continue;

                if (i == n-1 && j == n-1) continue;

                int maxScore = -1;
                int count = 0;

                // check 3 directions
                int[][] dirs = {{1,0},{0,1},{1,1}};

                for (int[] d : dirs) {
                    int ni = i + d[0];
                    int nj = j + d[1];

                    if (ni < n && nj < n && ways[ni][nj] > 0) {
                        if (score[ni][nj] > maxScore) {
                            maxScore = score[ni][nj];
                            count = ways[ni][nj];
                        } else if (score[ni][nj] == maxScore) {
                            count = (count + ways[ni][nj]) % MOD;
                        }
                    }
                }

                if (count > 0) {
                    int val = board.get(i).charAt(j);
                    if (val != 'S' && val != 'E') {
                        maxScore += val - '0';
                    }
                    score[i][j] = maxScore;
                    ways[i][j] = count;
                }
            }
        }

        if (ways[0][0] == 0) return new int[]{0, 0};

        return new int[]{score[0][0], ways[0][0]};
    }
}
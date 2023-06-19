struct holder {
    int sr;
    int sc;
};

holder dummy;
queue<holder> filler;

bool isSafe(int sr, int sc, int m, int n) {
    return sr >= 0 && sr < m && sc >= 0 && sc < n;
}

bool isSame(vector<vector<int>>& image, int sr, int sc, int val) {
    return image[sr][sc] == val;
}

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int val = image[sr][sc];

        if (!isSame(image, sr, sc, color)) {
            dummy = {sr, sc};
            filler.push(dummy);
            image[sr][sc] = color;
        }

        while (!filler.empty()) {
            int r = filler.front().sr;
            int c = filler.front().sc;
            filler.pop();

            if (isSafe(r + 1, c, m, n) && isSame(image, r + 1, c, val)) {
                dummy = {r + 1, c};
                filler.push(dummy);
                image[r + 1][c] = color;
            }
            if (isSafe(r - 1, c, m, n) && isSame(image, r - 1, c, val)) {
                dummy = {r - 1, c};
                filler.push(dummy);
                image[r - 1][c] = color;
            }
            if (isSafe(r, c + 1, m, n) && isSame(image, r, c + 1, val)) {
                dummy = {r, c + 1};
                filler.push(dummy);
                image[r][c + 1] = color;
            }
            if (isSafe(r, c - 1, m, n) && isSame(image, r, c - 1, val)) {
                dummy = {r, c - 1};
                filler.push(dummy);
                image[r][c - 1] = color;
            }
        }

        return image;
    }
};

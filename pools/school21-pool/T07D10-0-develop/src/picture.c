#include <stdio.h>
#include <stdlib.h>
#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);
void output(int **a, int n, int m);

int main() {
    int picture_data[N][M];
    int *picture[N];
    transform(&picture_data[0][0], picture, N, M);

    make_picture(picture, N, M);
    output(picture, N, M);
    return 0;
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    int frame_h[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    const int tree_trunk[] = { 7, 7, 7, 7 };
    const int tree_foliage[] = { 3, 3, 3, 3 };
    int sun_data[6][5] = { { 0, 6, 6, 6, 6 },
     { 0, 0, 6, 6, 6 },
     { 0, 0, 6, 6, 6 },
     { 0, 6, 0, 0, 6 },
     { 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0 } };
    reset_picture(picture, n, m);
    int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
    int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);

    for (int i = 1; i < 5; i++) {
        for (int j = 7; j < 12; j++) {
            picture[i][j] = sun_data[i - 1][j - 7];
        }
    }
    for (int j = 0; j < length_frame_h; j++) {
        picture[j][0] = frame_h[j];
        picture[j][length_frame_w - 1] = frame_h[j];
        picture[j][length_frame_w / 2] = frame_h[j];
    }
    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
        picture[length_frame_h - 1][i] = frame_w[i];
        picture[length_frame_h / 2][i] = frame_w[i];
    }
    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
    }
    for (int j = 6; j < 10; j++) {
        picture[j - 4][3] = tree_foliage[j - 6];
        picture[j - 4][4] = tree_foliage[j - 6];
        picture[j][3] = tree_trunk[j - 6];
        picture[j][4] = tree_trunk[j - 6];
        picture[10][j - 4] = tree_trunk[j - 6];
        picture[3][j - 4] = tree_foliage[j - 6];
        picture[4][j - 4] = tree_foliage[j - 6];
    }
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}
void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}
void output(int **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int p = a[i][j];
            if (j != (m - 1)) {
                printf("%d ", p);
            } else {
                if (i != (n - 1))
                    printf("%d\n", p);
                else
                    printf("%d", p);
            }
        }
    }
}

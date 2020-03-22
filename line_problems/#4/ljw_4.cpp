#include <cstdio>
#include <cstdlib>

using namespace std;

int space[20001];
int marking[20001];

int main(void)
{
    int N;
    freopen("test.txt", "r" , stdin);
    scanf("%d", &N);

    for (int j=0;j<N;j++) {
        scanf("%d", &space[j]);
    }

    int counter = 1;

    for (int i=0;i<N;i++) {
        if (space[i] == 0) {
            marking[i] = counter++;
        }
        else {
            counter = 1;
            marking[i] = 0;
        }
    }
//
    for (int i=0; i<N; i++)
        printf("%d ", marking[i]);
    printf("\n");
//
    int max_near = -1;
    // exception case (0, N-1)
    if (space[N-1] == 0)
        max_near = marking[N-1];

    if (space[0] == 0) {
        int cnt = 1;
        while (marking[cnt] != 0) {
            cnt++;
        }

        if (max_near < marking[cnt-1]) {
            max_near = marking[cnt-1];
        }
    }

    // interval checking
    for (int i=0;i<N;i++) {
        if (marking[i] != 0) {
            int cnt = i;
            while ((marking[cnt] != 0) && (cnt < N)) {
                cnt++;
            }

//
            printf("|%d|\n", cnt); 
//
            if (max_near < marking[cnt-1]) {
                max_near = marking[cnt-1]/2 + 1;
            }
            i = cnt;
        }
    }

    printf("%d\n", max_near);

    return 0;
}

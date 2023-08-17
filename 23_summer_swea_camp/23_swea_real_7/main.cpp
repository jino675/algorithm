#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <unistd.h>

struct Result
{
    int top;
    int count;
};

void init(int C);
Result dropBlocks(int mCol, int mHeight, int mLength);

#define CMD_INIT 100
#define CMD_DROP 200
int	cnt;

static bool run()
{
    int query_num;
    scanf("%d", &query_num);

    int ans_top, ans_count;
    bool ok = false;
	cnt = 0;
    for (int q = 0; q < query_num; q++)
    {
		// printf("#%d\n", cnt + 3);
		// ++cnt;
        int query;
        scanf("%d", &query);
        if (query == CMD_INIT)
        {
            int C;
            scanf("%d", &C);
            init(C);
            ok = true;
        }
        else if (query == CMD_DROP)
        {
            int mCol, mHeight, mLength;
            scanf("%d %d %d", &mCol, &mHeight, &mLength);
            Result ret = dropBlocks(mCol, mHeight, mLength);
            scanf("%d %d", &ans_top, &ans_count);

			// printf("mCol : %d, mHeight : %d, mLength : %d, ans_top : %d, ans_cnt : %d, my_top : %d, my_cnt : %d\n\n", \
			// 			mCol, mHeight, mLength, ans_top, ans_count, ret.top, ret.count);
            if (ans_top != ret.top || ans_count != ret.count)
            {
				sleep(100);
                ok = false;
            }
        }
    }
    return ok;
}

int main()
{
    setbuf(stdout, NULL);
    // freopen("sample_input.txt", "r", stdin);
    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
    return 0;
}
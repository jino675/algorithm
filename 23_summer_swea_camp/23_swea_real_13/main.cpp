#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

extern void init();
extern void addRoom(int mID, char mWord[], int mDirLen[]);
extern void setCurrent(char mWord[]);
extern int moveDir(int mDir);
extern void changeWord(char mWord[], char mChgWord[], int mChgLen[]);

/////////////////////////////////////////////////////////////////////////

#define INIT	0
#define ADD		1
#define SET		2
#define MOVE	3
#define CHANGE	4

#define MAX_LENGTH	(11 + 1)

int	cnt;

static bool run()
{
	int cmd, ans, ret, mid;
	int dir[3];
	char mWord[MAX_LENGTH];
	char mRetWord[MAX_LENGTH];

	int Q = 0;
	bool okay = false;
	cnt = 0;
	scanf("%d", &Q);
	for (int q = 0; q < Q; ++q)
	{
		// printf("#%d\n", cnt + 3);
		// ++cnt;
		scanf("%d", &cmd);
		switch (cmd)
		{
		case INIT:
			init();
			okay = true;
			break;

		case ADD:
			scanf("%d %s %d %d %d", &mid, mWord, &dir[0], &dir[1], &dir[2]);
			addRoom(mid, mWord, dir);
			break;

		case SET:
			scanf("%s", mWord);
			setCurrent(mWord);
			break;

		case MOVE:
			scanf("%d %d", &dir[0], &ans);
			ret = moveDir(dir[0]);
			if (ret != ans) {
				printf("ans : %d, ret : %d\n", ans, ret);
				while(true){}
				okay = false;
			}
			break;

		case CHANGE:
			scanf("%s %s %d %d %d", mWord, mRetWord, &dir[0], &dir[1], &dir[2]);
			changeWord(mWord, mRetWord, dir);
			break;

		default:
			okay = false;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}
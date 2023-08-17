#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <unistd.h>
#include <string.h>

extern void init();
extern void create(int mTime, char mBranch[], char mFile[], char mData[]);
extern void edit(int mTime, char mBranch[], char mFile[], char mData[]);
extern void branch(int mTime, char mBranch[], char mChild[]);
extern void merge(int mTime, char mBranch[]);
extern int readfile(int mTime, char mBranch[], char mFile[], char retString[]);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

#define CMD_CREATE	100
#define CMD_EDIT	200
#define CMD_BRANCH	300
#define CMD_MERGE	400
#define CMD_READ	500

#define MAXN	10000
#define MAXL	11

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int cnt;
int q;

static bool run()
{
	int Q, ans;
	bool isOkey = true;

	scanf("%d", &Q);
	init();
	for (q = 1; q <= Q; ++q) {
		int cmd, len;
		char mBranch[MAXL], mChild[MAXL], mFile[MAXL], mData[MAXL], retString[MAXL];
		scanf("%d", &cmd);

		switch (cmd) {

		case CMD_CREATE:
			scanf(" %s %s %s", mBranch, mFile, mData);
			create(q, mBranch, mFile, mData);
			break;

		case CMD_EDIT:
			scanf(" %s %s %s", mBranch, mFile, mData);
			edit(q, mBranch, mFile, mData);
			break;

		case CMD_BRANCH:
			scanf(" %s %s", mBranch, mChild);
			branch(q, mBranch, mChild);
			break;

		case CMD_MERGE:
			scanf(" %s", mBranch);
			merge(q, mBranch);
			break;

		case CMD_READ:
			scanf(" %s %s", mBranch, mFile);
			len = readfile(q, mBranch, mFile, retString);

			scanf(" %d %s", &ans, mData);

			// printf("%s %s %s %d | %d %s\n", \
			// 			mBranch, mFile, mData, ans, len, retString);
			if (ans != len) {
				sleep(100);
				isOkey = false;
			}
			else if (strcmp(retString, mData) != 0) {
				sleep(100);
				isOkey = false;
			}
			break;

		default:
			isOkey = false;
		}
		// printf("#%d\n", cnt++);
	}
	return isOkey;
}

int main()
{
	setbuf(stdout, NULL);
	// freopen("temp_in.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);
	for (int tc = 1; tc <= T; tc++) {
		printf("#%d %d\n", tc, run() ? MARK : 0);
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>

int main() {
	char team[4][20];
	int goal[4][4];
	int score[4];
	int gd[4];
	int f[4];
	for (int i = 0; i < 4; i++){
		char tmp[20];
		scanf("%s", &tmp);
		strcpy(team[i], tmp);
	}
	for (int i = 0; i < 4; i++){
		scanf("%d %d %d %d", &goal[i][0], &goal[i][1], &goal[i][2], &goal[i][3]);
	}
	for (int i = 0; i < 4; i++){
		int temp_score = 0;
		for (int j = 0; j < 4; j++){
			if (i != j){
				int home_goal = goal[i][j];
				int away_goal = goal[j][i];
				if (home_goal > away_goal){
					temp_score += 3;
				}else if (home_goal == away_goal){
					temp_score += 1;
				}
				gd[i] += (home_goal - away_goal);
				f[i] += home_goal;
			}
		}
		score[i] = temp_score;
	}
	for (int tm = 0; tm < 4 - 1; tm++){
		for (int i = 0; i < 4 - tm - 1; i++){
			if (score[i] < score[i + 1]){
				int tmp = score[i];
				score[i] = score[i + 1];
				score[i + 1] = tmp;

				char tmp2[20];
				strcpy(tmp2, team[i]);
				strcpy(team[i], team[i + 1]);
				strcpy(team[i + 1], tmp2);

				int gdtmp = gd[i];
				gd[i] = gd[i + 1];
				gd[i + 1] = gdtmp;

				int ftmp = f[i];
				f[i] = f[i + 1];
				f[i + 1] = ftmp;
			}
			else if (score[i] == score[i + 1]) {
				if (gd[i] < gd[i + 1]) {
					int tmp = score[i];
					score[i] = score[i + 1];
					score[i + 1] = tmp;

					char tmp2[20];
					strcpy(tmp2, team[i]);
					strcpy(team[i], team[i + 1]);
					strcpy(team[i + 1], tmp2);

					int gdtmp = gd[i];
					gd[i] = gd[i + 1];
					gd[i + 1] = gdtmp;

					int ftmp = f[i];
					f[i] = f[i + 1];
					f[i + 1] = ftmp;

				}else if (gd[i] + gd[i + 1]){
					if (f[i] < f[i + 1]){
						int tmp = score[i];
						score[i] = score[i + 1];
						score[i + 1] = tmp;

						char tmp2[20];
						strcpy(tmp2, team[i]);
						strcpy(team[i], team[i + 1]);
						strcpy(team[i + 1], tmp2);

						int gdtmp = gd[i];
						gd[i] = gd[i + 1];
						gd[i + 1] = gdtmp;

						int ftmp = f[i];
						f[i] = f[i + 1];
						f[i + 1] = ftmp;
					}
				}
			}
		}
	}
	for (int i = 0; i < 4; i++){
		printf("%s %d\n", team[i], score[i]);
	}
	return 0;
}
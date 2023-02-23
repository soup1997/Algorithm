#include <stdio.h>
int main()
{
	int test_case, num, sum = 0;
	int i, j;
	double avg;
	int score[1000] = {0}; // 가변길이 배열을 사용할 수 없어서 대체
	int cnt = 0;
	scanf("%d", &test_case);
	for (i = 0; i < test_case; i++)
	{
		scanf("%d", &num); // 학생 수 입력
		for (j = 0; j < num; j++) //학생들의 점수를 받고 총합을 구하는 반복문
		{
			scanf("%d", &score[j]);
			sum += score[j]; // 입력받은 사람수의 점수 합산
		}
		avg = (double)sum / num;
		for (j = 0; j < num; j++) //평균을 넘는 사람들의 수를 세는 반복문
		{
			if (score[j] > avg)
			{
				cnt++;
			}
		}
		printf("%.3lf%%\n", ((double)cnt / (double)(num)) * 100.0);
		sum = 0, cnt = 0; // 출력후 전체 총합과 카운트 0으로 초기화
	}
	return 0;
}
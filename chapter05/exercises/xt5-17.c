#include <stdio.h>
int main()
{
	char i, j, k; /*是a的对手;j是b的对手;k是c的对手*/
	for (i = 'x'; i <= 'z'; i++)
		for (j = 'x'; j <= 'z'; j++)
			if (i != j)
				for (k = 'x'; k <= 'z'; k++)
					if (i != k && j != k)
						if (i != 'x' && k != 'x' && k != 'z')
							printf("A--%c\nB--%c\nC--%c\n", i, j, k);
	return 0;
}
/*
//如果A和X比 或者 C和X比 或者 C和Z比 或者 A和B比 或者 A和C比 或者 B和C比，都是不可以的；
//所以只要穷举A比赛对象，B比赛对象，C比赛对象，判断上述条件就可以了；

#include <stdio.h>

int main()
{
  int A_battle, B_battle, C_battle;
  //如果A对战的对象从“X”到“Z”
  for (A_battle = 'X'; A_battle <= 'Z'; A_battle++)
  {
	//如果B对战的对象从“X”到“Z”
	for (B_battle = 'X'; B_battle <= 'Z'; B_battle++)
	{
	  //如果C对战的对象从“X”到“Z”
	  for (C_battle = 'X'; C_battle <= 'Z'; C_battle++)
	  {
		//去除限制条件
		if (A_battle == 'X' || C_battle == 'X' || C_battle == 'Z' || B_battle == A_battle || B_battle == C_battle || A_battle == C_battle)
		{
		  continue;
		}
		printf("A对%c,B对%c,C对%c", A_battle, B_battle, C_battle);
	  }
	}
  }
  return 0;
}

*/

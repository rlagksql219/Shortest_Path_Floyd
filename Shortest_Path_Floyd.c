#include <stdio.h>
#include <stdlib.h>

#define Count_Vertice 5
#define INF 2000 // 도달할 수 없는 경우

// adjacent matrix
// i에서 j까지 바로 가는 경우
int W[Count_Vertice][Count_Vertice] = {
							{0, 10, 5, INF, INF},
							{INF, 0, 2, 1, INF},
							{INF, 3, 0, 9, 2},
							{INF, INF, INF, 0, 4},
							{7, INF, INF, 5, 0},
};


int D[Count_Vertice][Count_Vertice];	// i에서 j까지 가는 최소 거리 저장
int P[Count_Vertice][Count_Vertice];	// i에서 j까지 가는 데 거치는 최고 차수 정점을 저장 


void Floyd() {
	int i, j, k;
	for (i = 0; i < Count_Vertice; i++)	// 배열 초기화 
		for (j = 0; j < Count_Vertice; j++) {
			P[i][j] = 0;
			D[i][j] = W[i][j];
		}

	for (k = 0; k < Count_Vertice; k++)
		for (i = 0; i < Count_Vertice; i++)
			for (j = 0; j < Count_Vertice; j++)

				if (D[i][j] > D[i][k] + D[k][j]) { // k를 거칠 시 D[i][j]가 더 짧아지는 경우
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = k;
				}
}


void Path(int a, int b) {

	if (P[a][b] != 0) {	// P[a][b] = 0  "="  a에서 바로 b로 가는 것이 최단거리 

		Path(a, P[a][b]);
		printf("%d ", P[a][b]);
		Path(P[a][b], b);
	}
}


int main(int argc, char* argv[]) {
	int a, b;

	Floyd();

	printf("배열 D 출력\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			printf("%d ", D[i][j]);
		printf("\n");
	}

	printf("배열 P 출력\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			printf("%d ", P[i][j]);
		printf("\n");
	}

	printf("출발점과 도착점을 입력하세요. (0 ~ 4)\n", Count_Vertice - 1);
	scanf_s("%d %d", &a, &b);

	printf("최단거리 : %d\n", D[a][b]);

	printf("최단경로 : ");
	printf("%d ", a);	Path(a, b);

	if (D[a][b] != 0)	printf("%d", b);	// D[a][b] = 0  "="  a = b 	
	return 0;
}
/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#pragma warning (disable:4996)

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

float Answer;

// point2와 point3를 지나는 직선과 point1 사이의 최단 거리
float funcMinDistancePoint2Line(vector<float> point1, vector<float> point2, vector<float> point3) {
	float distance = 0;
	
	float delta_x, delta_y;
	delta_x = point3[0] - point2[0];
	delta_y = point3[1] - point2[1];

	float max_y, min_y, max_x, min_x;
	if (point2[1] > point3[1]) {
		max_y = point2[1];
		min_y = point3[1];
	}
	else {
		max_y = point3[1];
		min_y = point2[1];
	}
	if (point2[0] > point3[0]) {
		max_x = point2[0];
		min_x = point3[0];
	}
	else {
		max_x = point3[0];
		min_x = point2[0];
	}

	if (delta_x == 0) {
		if (point1[1] >= min_y && point1[1] <= max_y) {
			distance = point1[0] - point2[0];
		}
		if (point1[1] <= min_y) {
			distance = sqrt(powf((point1[0] - point2[0]), 2) + powf((point1[1] - min_y), 2));
		}
		if (point1[1] >= max_y) {
			distance = sqrt(powf((point1[0] - point2[0]), 2) + powf((point1[1] - max_y), 2));
		}
	}
	else if (delta_y == 0) {
		if (point1[0] >= min_x && point1[0] <= max_x) {
			distance = point1[1] - point2[1];
		}
		if (point1[0] <= min_x) {
			distance = sqrt(powf((point1[0] - min_x), 2) + powf((point1[1] - point2[1]), 2));
		}
		if (point1[1] >= max_y) {
			distance = sqrt(powf((point1[0] - max_x), 2) + powf((point1[1] - point2[1]), 2));
		}
	}
	else {
		float m, a, b, x, y;
		m = delta_y / delta_x;
		a = point2[1] - m * point2[0];
		b = point1[1] + m * point1[0];
		x = fabs(b - a) / (2.0f * m);
		y = (a + b) / 2.0f;
		if (x >= min_x && x <= max_x && y >= min_y && y <= max_y) {
			distance = sqrt(powf((point1[0] - x), 2) + powf((point1[1] - y), 2));
		}
		else {
			float dist1 = sqrt(powf((point1[0] - point2[0]), 2) + powf((point1[1] - point2[1]), 2));
			float dist2 = sqrt(powf((point1[0] - point3[0]), 2) + powf((point1[1] - point3[1]), 2));
			distance = dist1 > dist2 ? dist2 : dist1;
		}
	}

	return distance;
}

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int N, M;
		cin >> N;
		cin >> M;
		vector<vector<float> > A, B;
		vector<float> vertex;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 2; j++) {
				float temp;
				cin >> temp;
				vertex.push_back(temp);
			}
			A.push_back(vertex);
			vertex.clear();
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < 2; j++) {
				float temp;
				cin >> temp;
				vertex.push_back(temp);
			}
			B.push_back(vertex);
			vertex.clear();
		}

		vector <float> distance;
		for (int i = 0; i < N; i++) {
			int j = (i + 1) % N;
			for (int k = 0; k < M; k++) {
				float dist = funcMinDistancePoint2Line(B[k], A[i], A[j]);
				distance.push_back(dist);
			}
		}
		for (int i = 0; i < M; i++) {
			int j = (i + 1) % M;
			for (int k = 0; k < N; k++) {
				float dist = funcMinDistancePoint2Line(A[k], B[i], B[j]);
				distance.push_back(dist);
			}
		}
		for (int i = 0; i < M*N; i++) {
			cout << distance[i] << ", ";
		}
		cout << endl << endl;

		sort(distance.begin(), distance.end());
		Answer = distance[0];

		A.clear();
		B.clear();
		distance.clear();
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
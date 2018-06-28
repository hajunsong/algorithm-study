/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <math.h>

#pragma warning(disable:4996)

using namespace std;

int Answer;

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
		int R[5];
		for (int i = 0; i < 5; i++) {
			cin >> R[i];
		}
		int N;
		cin >> N;
		vector<int> pos, distance;
		for (int i = 0; i < N*2; i++) {
			int temp;
			cin >> temp;
			pos.push_back(temp);
			if (i % 2 == 0) {
				distance.push_back(sqrt(pow(pos[pos.size()-1],2) + pow(pos[pos.size()-2],2)));
			}
		}
		for (int i = 0; i < distance.size(); i++) {
			int dist = distance[i];
			if (R[0] > dist) {
				Answer += 
			}
			else if (dist > R[0] && dist < R[1]) {

			}
			else if (dist > R[1] && dist < R[2]) {

			}
			else if (dist > R[2] && dist < R[3]) {

			}
			else if (dist > R[3] && dist < R[4]) {

			}
			else {

			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
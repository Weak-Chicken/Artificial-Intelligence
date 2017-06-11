#include <Eigen\Eigen>
#include <iostream>

#include <thread>
#include <mutex>
#include <chrono>

#include "argumentation_framework_lib.h"

#define MATRIX_SIZE 40
#define MATRIX_NUMBER 5000
#define OUTPUT_TIME_STEP 1000

int another_counter(0);
std::mutex m;

void output(vector<MatrixXd> & matrices)
{
	while (matrices.size() < MATRIX_NUMBER)
	{
		cout << another_counter << "|" << matrices.size() << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(OUTPUT_TIME_STEP));
	}
	cout << another_counter << "|" << matrices.size() << endl;
}

void run(vector<MatrixXd> & matrices, int seeds)
{
	MatrixXd temp_matrix(MATRIX_SIZE, MATRIX_SIZE);
	initialization_of_random_number(seeds * 1000);
	while (matrices.size() < MATRIX_NUMBER)
	{
		temp_matrix = produce_not_self_conflict_random_01matrix(MATRIX_SIZE);
		another_counter++;
		/*if (!is_AF_self_conflict(temp_matrix))
		{
			if (is_AF_strongly_connected(temp_matrix))
			{
				matrices.push_back(temp_matrix);
				counter++;
			}
		}*/

		if (is_AF_strongly_connected(temp_matrix))
		{
			if (matrices.size() < MATRIX_NUMBER)
			{
				m.lock();
				matrices.push_back(temp_matrix);
				m.unlock();
			}

		}

	}
}

int main()
{
	vector<MatrixXd> matrices;
	clock_t start = clock();

	std::thread t1(run, std::ref(matrices), 1);
	std::thread t2(run, std::ref(matrices), 2);
	std::thread t3(run, std::ref(matrices), 3);
	std::thread t4(run, std::ref(matrices), 4);
	std::thread t5(run, std::ref(matrices), 5);
	std::thread t6(run, std::ref(matrices), 6);
	std::thread t7(run, std::ref(matrices), 7);
	std::thread t8(run, std::ref(matrices), 8);

	std::thread timer(output, std::ref(matrices));

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();

	timer.join();

	clock_t end = clock();

	cout << "Running Time:" << end - start << endl;

	/*for (int i = 0; i < MATRIX_NUMBER; i++)
	{
		cout << matrices[i] << endl;
		cout << "=========================================" << endl;
	}*/
}

//MatrixXd m(6, 6);
//m << 0, 1, 1, 1, 0, 0,
//	0, 0, 1, 0, 0, 0,
//	1, 0, 0, 1, 0, 0,
//	0, 0, 0, 0, 0, 1,
//	0, 1, 1, 0, 0, 0,
//	0, 0, 1, 0, 1, 0;

//initialization_of_random_number();

//for (int i = 0; i < 10; i++) 
//{
//	MatrixXd test = produce_not_self_conflict_random_01matrix(6);
//	if (!is_AF_self_conflict(test))
//	{
//		is_AF_strongly_connected(test);
//		cout << "===========================" << endl;
//		cout << test << endl << count_number_of_ones(test) << endl;
//	}
//}

//is_AF_strongly_connected(m);

//==============================================================================================================

//vector<MatrixXd> matrices;
//MatrixXd temp_matrix(MATRIX_SIZE, MATRIX_SIZE);
//int counter = 0;
//int another_counter = 0;

//while(counter < MATRIX_NUMBER)
//{
//	temp_matrix = produce_random_01matrix(MATRIX_SIZE);
//	another_counter++;
//	if (is_AF_strongly_connected(temp_matrix))
//	{
//		matrices.push_back(temp_matrix);
//		cout << another_counter << "|" <<counter << endl;
//		counter++;
//	}
//}

//for (int i = 0; i < MATRIX_NUMBER; i++)
//{
//	cout << matrices[i] << endl;
//}
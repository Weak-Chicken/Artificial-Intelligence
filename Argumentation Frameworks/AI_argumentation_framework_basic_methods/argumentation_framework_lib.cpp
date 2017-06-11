#include "argumentation_framework_lib.h"

void initialization_of_random_number()
{
	srand((unsigned)time(NULL));
}

MatrixXd produce_random_01matrix(int matrix_size)
{
	MatrixXd temp_matrix(matrix_size, matrix_size);
	
	for (int i = 0; i < matrix_size; i++) 
	{
		for (int j = 0; j < matrix_size; j++) 
		{
			temp_matrix(i, j) = rand() % 2;
		}
	}
	
	return temp_matrix;
}

MatrixXd produce_not_self_conflict_random_01matrix(int matrix_size)
{
	MatrixXd temp_matrix(matrix_size, matrix_size);

	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			if (i != j)
			{
				temp_matrix(i, j) = rand() % 2;
			}
			else
			{
				temp_matrix(i, j) = 0;
			}
			
		}
	}

	return temp_matrix;
}

bool is_AF_self_conflict(MatrixXd input_matrix)
{
	for (int i = 0; i < input_matrix.rows(); i++) 
	{
		if (input_matrix(i, i) == 1) {
			return true;
		}
	}

	return false;
}

bool is_AF_strongly_connected(MatrixXd input_matrix)
{
	vector<bool> status_of_nodes(input_matrix.cols());

	for (int j = 0; j < input_matrix.cols(); j++)
	{
		status_of_nodes[j] = true;
	}

	for (int i = 0; i < input_matrix.rows(); i++)
	{
		vector<int> connection_to_other_nodes;
		vector<bool> status_of_connection_to_nodes(input_matrix.cols());
		int nodes_counter = 0;

		for (int j = 0; j < input_matrix.cols(); j++)
		{
			if (input_matrix(i, j) == 1)
			{
				connection_to_other_nodes.push_back(j);
				status_of_connection_to_nodes[j] = true;
			}
		}

		while (nodes_counter < connection_to_other_nodes.size()) {
			for (int j = 0; j < input_matrix.cols(); j++)
			{
				if (input_matrix(connection_to_other_nodes[nodes_counter], j) == 1)
				{
					if (!status_of_connection_to_nodes[j])
					{
						if (i != j)
						{
							connection_to_other_nodes.push_back(j);
							status_of_connection_to_nodes[j] = true;
						}
					}
				}
			}
			nodes_counter++;
		}

		if (nodes_counter != input_matrix.rows() - 1)
		{
			status_of_nodes[i] = false;
		}
	}

	for (int j = 0; j < input_matrix.cols(); j++)
	{
		if (!status_of_nodes[j]) {
			return false;
		}
	}

	return true;
}

int count_number_of_ones(MatrixXd input_matrix)
{
	int temp_number_of_ones = 0;

	for (int i = 0; i < input_matrix.rows(); i++)
	{
		for (int j = 0; j < input_matrix.cols(); j++)
		{
			if (input_matrix(i, j) == 1)
			{
				temp_number_of_ones++;
			}
		}
	}
	return temp_number_of_ones;
}

bool too_many_ones(MatrixXd input_matrix, int maximum_number_of_ones)
{
	if (count_number_of_ones(input_matrix) > maximum_number_of_ones)
	{
		return false;
	}

	return true;
}

bool too_few_ones(MatrixXd input_matrix, int minimum_number_of_ones)
{
	if (count_number_of_ones(input_matrix) < minimum_number_of_ones)
	{
		return false;
	}

	return true;
}

bool setting_number_of_ones(MatrixXd input_matrix, int maximum_number_of_ones, int minimum_number_of_ones)
{
	if (count_number_of_ones(input_matrix) > maximum_number_of_ones && count_number_of_ones(input_matrix) < minimum_number_of_ones)
	{
		return false;
	}

	return true;
}

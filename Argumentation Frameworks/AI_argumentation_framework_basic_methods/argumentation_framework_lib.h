#pragma once

#include <Eigen\Eigen>
#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>

using Eigen::MatrixXd;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

void initialization_of_random_number();
MatrixXd produce_random_01matrix(int matrix_size);
MatrixXd produce_not_self_conflict_random_01matrix(int matrix_size);

bool is_AF_self_conflict(MatrixXd input_matrix);
bool is_AF_strongly_connected(MatrixXd input_matrix);

int count_number_of_ones(MatrixXd input_matrix);
bool too_many_ones(MatrixXd input_matrix, int maximum_number_of_ones);
bool too_few_ones(MatrixXd input_matrix, int minimum_number_of_ones);
bool setting_number_of_ones(MatrixXd input_matrix, int maximum_number_of_ones, int minimum_number_of_ones);
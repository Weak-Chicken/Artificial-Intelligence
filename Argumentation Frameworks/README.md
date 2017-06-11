# Argumentation Frameworks
Since my final year project in undergraduate stage is about argumentation framework, I made some codes used to produce random argumentation frameworks and calculate the characteristics of these AFs during the project.

However, limited by deadline of the project, many works are remained to be done. Therefore, I re-implemented my code in C++ and try to finish the works I planned to do. (Because I'm not sure whether I can upload my original code or not. I don't want to fail by uploading my codes.)(My original codes are writen in Java with the matrix library JAMA.)

In the previous Java version, the main problem was that the codes are not efficient enough. It will cost up to days to obtain a strongly-connected directed graph. By using c++ this time, I will try to use CUDA to help calculating the matrices. Meanwhile, I'll change the algorithm so that the code can be more efficient.

This C++ code needs to include the Eigen matrix library.
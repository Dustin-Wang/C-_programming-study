
#include<iostream>
#include <vector>
using namespace std;

template <typename First, typename Second>
void printvectorofpairs(std::vector< std::pair<First,Second> > vector_of_pairs)
{
  for (const auto& p : vector_of_pairs)
  		std::cout << p.first << ", " << p.second << std::endl;
  	printf("\n");
	fflush(stdout);
}



int main(){
	vector<pair<int,int>> test1;
	test1.push_back(pair<int,int>{2,3});
	printvectorofpairs(test1);


	vector<pair<double,double>> test2;
	test2.push_back(pair<double,double>{2,3.333333333333});
	printvectorofpairs(test2);
	return(0);
}
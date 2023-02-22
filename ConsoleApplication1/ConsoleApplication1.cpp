#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <thread>
#include<map>
#define  log(x) (std::cout << x << std::endl)

void print(std::vector <int> const& a);
void test(int x)
{
	log("hello from test thread");
	log(x);
}
int checkleft(std::vector<int>& blocks, int i)
{
	int res = 0;
	while (i > 0) {
		if (blocks[i - 1] > blocks[i])
		{
			res++;
		}
		else
		{
			return res;
		}
		i--;
	}
}
int checkright(std::vector<int>& blocks, int i)
{
	int res = 0;
	while (i < blocks.size()-1) {
		if (blocks[i + 1] > blocks[i])
		{
			res++;
		}
		else
		{
			return res;
		}
		i++;
	}
}
struct tree {
	int data;
	struct node* left;
	struct node* right;
};
int main()
{
	int max = 0;
	int curl = 0;
	int curr = 0;

	std::vector<int>blocks{ 3,1,3,4,5,2,6,4 };
	for (int i = 0; i < blocks.size(); i++)
	{
		curl = 0;
		curr = 0;
		if (i) {
			curl = checkleft(blocks, i);
		}
		if (i < blocks.size() - 1)
		{
			curr = checkright(blocks, i);
			i += curr;

		}
		if (curr + curl > max)
			max = curr + curl;
	}
	log(max + 1);
}


void print(std::vector <int> const& a) {
	std::cout << "The vector elements are : ";

	for (int i = 0; i < a.size(); i++)
		std::cout << a.at(i) << ' ';
}
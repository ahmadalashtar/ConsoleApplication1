#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <thread>
#include<map>

#define  log(x) (std::cout << x << std::endl)

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
bool finished = false;
void working()
{
	while (!finished)
		log("working...");
}
void print(std::vector <int> const& a) {
	std::cout << "The vector elements are : ";

	for (int i = 0; i < a.size(); i++)
		std::cout << a.at(i) << ' ';
}

int main()
{
	std::vector<int> blocks{ 1,4,5,7,4,2,3,6,8,5,2,3,5,6,7 };

}
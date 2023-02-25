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

unsigned int CodilityPerformance(std::vector<int> blocks)
{
	unsigned int front = 0;
	unsigned int back = 0;
	unsigned int max = 0;
	for (int i = 0; i < blocks.size()-1; i++)
	{
		if (blocks[i] < blocks[i + 1])
		{
			front++;
			if (max < front + back)
				max = front + back;
		}
		else if (blocks[i] > blocks[i + 1])
		{
			if (max < front + back)
				max = front + back;

			if (front) {
				front = 0;
				back=0;
			}
			back++;
			if (max < front + back)
				max = front + back;
			
		}
		else // (blocks[i] == blocks[i + 1])
		{
			back++;
			if (max < front + back)
				max = front + back;
		}
	}
	return max;
}
int main()
{
	std::vector<int> blocks1{ 1,4,5,7,4,2,3,6,8,5,2,3,5,6,7 };
	std::vector<int> blocks2{ 1,2,3,4,5,6,7,8 };
	std::vector<int> blocks3{ 8,7,6,5,4,3,2,1 };
	std::vector<int> blocks4{ 1,1,1,1,1,1,1,1,1 };
	std::vector<int> blocks5{ 1,1 };
	unsigned int result = CodilityPerformance(blocks5);
	log(result+1);

}
#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue

using namespace std;

int main ()
{
	queue<int> myqueue;
  	int myint;

  	cout << "Please enter some integers (enter 0 to end):\n";

  	do {
    		std::cin >> myint;
		myqueue.push (myint);
	} while (myint);

	cout << "myqueue contains: ";
	while (!myqueue.empty())
	{
 		std::cout << ' ' << myqueue.front();
		myqueue.pop();
	}
  	std::cout << '\n';

  	return 0;
}


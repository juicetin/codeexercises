#include <iostream>
#include <vector>
#include <string>

class Node
{
	public:
		Node(std::string name)
		{
			name_ = name;
		}

		std::vector<Node*> neighbours_;
		std::string name_;
};

class Graph
{
	public:
		Graph() {}

		std::vector<Node> nodes_;
};

int main()
{
	std::cout << "sadf" << std::endl;
}

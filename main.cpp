/*v1.5 
wha's new?
(1)从控制台读入矩阵时，判断标识符的合法性（只能包含英文字母和数字，只能以字母开头）
(2)从控制台读入矩阵时，先判断矩阵是否存在；
(3)修改已经输入的矩阵
(4)实现转置行列式 M|2
(5)修正计算后缀表达式模块内存泄漏bug！
(6)增加输出中间结果的功能 trace/notrace

*/

#include "Matrix.h"
#include "analysis.h"
#include "menu.h"

void init_for_debug()
{	
	double a1[] = { 1, 2, 5, 8,3,6 };
	double a2[] = { 4, 5, 7, 9,10,12 };
	double a3[] = { 3, 8, 6, 10 };

	Matrix m1(2, 3, a1), m2(3, 2, a2), m3(2, 2, a3);
	identifiers.emplace_back(m1, "M1");
	identifiers.emplace_back(m2, "M2");
	identifiers.emplace_back(m3, "M3");

}

int main()
{
	init_for_debug();

	std::string line;
	int stepNum = 1;

	std::cout << "In[" << stepNum << "]:= ";
	std::getline(std::cin,line);
	std::cout << std::endl;

	while (line != "quit")
	{
		if (line.empty())
			;
		else if (line == "#")
		{
			showMenu();
			++stepNum;
		}
		else if (line == "trace")
		{
			trace = true;
			++stepNum;
		}
		else if (line == "notrace")
		{
			trace = false;
			++stepNum;
		}
		else
		{
			std::cout << "Out[" << stepNum++ << "]= \n"
				<< analyze_expr(line) << std::endl;
		}
		std::cout << "In[" << stepNum << "]:= ";
		std::getline(std::cin,line);
		std::cout << std::endl;
	}
}

//add 1
//add3
//add the fourth line
//git test

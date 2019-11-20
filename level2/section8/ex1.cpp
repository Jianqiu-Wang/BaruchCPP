//Author: Jianqiu Wang
//Implements struct Article
#include <stdio.h>

//Struct Article contains 3 characteritics
struct Article
{
	int article_number;
	int quantity;
	char description[20];
};

//Prints characteritics of struct Article
void Print(Article* p_article)
{
	printf("Article number: %d\n", p_article->article_number);
	printf("Quantity      : %d\n", p_article->quantity);
	printf("Description   : %s\n", p_article->description);
}

int main()
{
	Article article = {100001, 99, "TestCase"}; // initialize an article
	Print(&article); // call by passing address of article
	return 0;
}


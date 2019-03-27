/* author: Jianqiu Wang
 * struct Article
 */
#include <stdio.h>

struct Article
{
    int article_number;
    int quantity;
    char description[20];
};

void Print(Article* p_article)
{
    printf("Article number: %d\n", p_article->article_number);
    printf("Quantity      : %d\n", p_article->quantity);
    printf("Description   : %s\n", p_article->description);
}

int main()
{
    Article article = {100001, 99, "TestCase"};
    Print(&article);
    return 0;
}


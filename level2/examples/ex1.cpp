#include <stdio.h>
union u_tag
{
	int ival;
	float fval;
};

struct value
{
	union u_tag var;
	int type; /* 0 = int, 1 = float */
}; 

void print(struct value* val);

int main()
{
	struct value variable; 
	variable.type = 0; 
	variable.var.ival = 10; 
	print(&variable);
	variable.type = 1; 
	variable.var.fval = 10.10; 
	print(&variable);
}

void print(struct value* val)
{
	if (val->type == 0)
	{
		printf("An integer value : %d\n", val->var.ival);
	}
	else
	{
		printf("A float value : %f\n", val->var.fval);
	}
}
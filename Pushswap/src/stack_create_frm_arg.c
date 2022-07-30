#include "push_swap.h"

int dublicated_check(t_list *root, t_list *tail)
{
    while(tail!=root)
    {
        if(tail->num == root->num)
            return 0;
        root=root->next;
    }
    return 1;
}

int string_checker(t_list **root, t_list **tail, char *argv)
{
    if(!add_node_to_stack(&(*root),&(*tail),ft_atol(argv)))
        return 0;
    if((*root!=*tail)&&(!dublicated_check(*root, *tail)))
        return 0;
    return 1;
}

int ft_isalnum_isspace(char *argv_sub)
{
    int flag;

    flag = 0;
    while(*argv_sub)
    {
	    if ((*argv_sub >= 48 && *argv_sub <= 57) ||(*argv_sub >= 65 && *argv_sub <= 90) 
        || (*argv_sub >= 97 && *argv_sub <= 122) || *argv_sub == ' ')
        {
		    flag = 0;
            break;
        }
	    flag = 1;
        argv_sub++;
    }
    if(flag == 1)
        return 1;
    return 0;
}

int stack_create_and_control(t_list **root, t_list **tail,char **argv)
{
    int i;
    char **argv_sub;

    i = 1;
    while(argv[i])
    {
        if(ft_isalnum_isspace(argv[i]))
        {
            if(!string_checker(root,tail,argv[i]))
                return 0;
        }
        else
        {
            return 0;
        }
        i++;
    }
    return 1;
}
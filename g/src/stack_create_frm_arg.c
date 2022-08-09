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
    if(!add_node_to_stack(&(*root),&(*tail),ft_atol(argv,*tail)))
        return 0;
    if((*root!=*tail)&&(!dublicated_check(*root, *tail)))
        return 0;
    return 1;
}

int ft_isspace_srch_all(char *argv_sub)
{
    int flag;

    flag = 1;
    while(*argv_sub)
    {
	    if (*argv_sub == ' ')
		    flag = 0;
        argv_sub++;
    }
    if(flag == 1)
        return 1;
    return 0;
}

int  stack_create_and_control(t_list **root, t_list **tail,char **argv)
{
    int i[2];
    char **argv_sub;

    i[0] = 1;
    while(argv[i[0]])
    {
        if(ft_isspace_srch_all(argv[i[0]]))
        {
            if(!string_checker(root,tail,argv[i[0]]))
                return 0;
        }
        else
        {
            i[1] = 0;
            argv_sub=ft_split(argv[i[0]],' ');
            while (argv_sub[i[1]])
            {
                if(!string_checker(root,tail,argv_sub[i[1]]))
                    return 0;
                i[1]++;
            }
        }
        i[0]++;
    }
    return 1;
}
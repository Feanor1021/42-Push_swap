#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *root;
    t_list *tail;
    t_list *root2;
    t_list *tail2;

    root=NULL;
    tail=root;
    root2=NULL;
    tail2=root2;
    if(argc == 1)
        ft_printf("Error\n");
    else
    {
        if(!stack_create_and_control(&root, &tail, argv))
        {
            ft_printf("Error\n");
            return 0;
        }
    }
    index_list(&root,&tail);
    quick_sort_stack_a(&root,&tail,&root2,&tail2);
    quick_sort_stack_b(&root,&tail,&root2,&tail2);


 /*   int pivot;
    int r_num;
    int rr_num;
    int is_size;
    print_list(root,tail);
    is_size=list_size(root,tail);
     pivot=pivot_finder(root,tail);
    r_num = find_min_r(root,tail,pivot,is_size);
    rr_num = find_min_rr(root,tail,pivot,is_size);
    printf("%d %d %d\n",r_num, rr_num, pivot);
    if (r_num<rr_num)
        r_x_times(&root,&tail,r_num);
    else if (r_num>rr_num)
        rr_x_times(&root,&tail,rr_num);
    else if (find_val_r(root,tail,r_num)>find_val_rr(root,tail,rr_num))
        rr_x_times(&root,&tail,rr_num);
    else if(find_val_r(root,tail,r_num)<find_val_rr(root,tail,rr_num))
        r_x_times(&root,&tail,r_num); 
    push_a(&root,&tail,&root2,&tail2);
        is_size=list_size(root,tail);
     pivot=pivot_finder(root,tail);
    r_num = find_min_r(root,tail,pivot,is_size);
    rr_num = find_min_rr(root,tail,pivot,is_size);
    printf("%d %d %d\n",r_num, rr_num, pivot);
    if (r_num<rr_num)
        r_x_times(&root,&tail,r_num);
    else if (r_num>rr_num)
        rr_x_times(&root,&tail,rr_num);
    else if (find_val_r(root,tail,r_num)>find_val_rr(root,tail,rr_num))
        rr_x_times(&root,&tail,rr_num);
    else if(find_val_r(root,tail,r_num)<find_val_rr(root,tail,rr_num))
        r_x_times(&root,&tail,r_num); 
        else if (find_val_r(root,tail,r_num) == find_val_rr(root,tail,rr_num))
        rr_x_times(&root,&tail,rr_num);
    push_a(&root,&tail,&root2,&tail2);
            is_size=list_size(root,tail);
     pivot=pivot_finder(root,tail);
    r_num = find_min_r(root,tail,pivot,is_size);
    rr_num = find_min_rr(root,tail,pivot,is_size);
    printf("%d %d %d\n",r_num, rr_num, pivot);
    if (r_num<rr_num)
        r_x_times(&root,&tail,r_num);
    else if (r_num>rr_num)
        rr_x_times(&root,&tail,rr_num);
    else if (find_val_r(root,tail,r_num)>find_val_rr(root,tail,rr_num))
        rr_x_times(&root,&tail,rr_num);
    else if(find_val_r(root,tail,r_num)<find_val_rr(root,tail,rr_num))
        r_x_times(&root,&tail,r_num);
    else if (find_val_r(root,tail,r_num) == find_val_rr(root,tail,rr_num))
        rr_x_times(&root,&tail,rr_num);
    push_a(&root,&tail,&root2,&tail2);

            is_size=list_size(root,tail);
     pivot=pivot_finder(root,tail);
    r_num = find_min_r(root,tail,pivot,is_size);
    rr_num = find_min_rr(root,tail,pivot,is_size);
    printf("%d %d %d\n",r_num, rr_num, pivot);
    if (r_num<rr_num)
        r_x_times(&root,&tail,r_num);
    else if (r_num>rr_num)
        rr_x_times(&root,&tail,rr_num);
    else if (find_val_r(root,tail,r_num)>find_val_rr(root,tail,rr_num))
        rr_x_times(&root,&tail,rr_num);
    else if(find_val_r(root,tail,r_num)<find_val_rr(root,tail,rr_num))
        r_x_times(&root,&tail,r_num);
    else if (find_val_r(root,tail,r_num) == find_val_rr(root,tail,rr_num))
        rr_x_times(&root,&tail,rr_num);
    push_a(&root,&tail,&root2,&tail2);

            is_size=list_size(root,tail);
     pivot=pivot_finder(root,tail);
    r_num = find_min_r(root,tail,pivot,is_size);
    rr_num = find_min_rr(root,tail,pivot,is_size);
    printf("%d %d %d\n",r_num, rr_num, pivot);
    if (r_num<rr_num)
        r_x_times(&root,&tail,r_num);
    else if (r_num>rr_num)
        rr_x_times(&root,&tail,rr_num);
    else if (find_val_r(root,tail,r_num)>find_val_rr(root,tail,rr_num))
        rr_x_times(&root,&tail,rr_num);
    else if(find_val_r(root,tail,r_num)<find_val_rr(root,tail,rr_num))
        r_x_times(&root,&tail,r_num);
    else if (find_val_r(root,tail,r_num) == find_val_rr(root,tail,rr_num))
        rr_x_times(&root,&tail,rr_num);
    push_a(&root,&tail,&root2,&tail2);

            is_size=list_size(root,tail);
     pivot=pivot_finder(root,tail);
    r_num = find_min_r(root,tail,pivot,is_size);
    rr_num = find_min_rr(root,tail,pivot,is_size);
    printf("%d %d %d\n",r_num, rr_num, pivot);
    if (r_num<rr_num)
        r_x_times(&root,&tail,r_num);
    else if (r_num>rr_num)
        rr_x_times(&root,&tail,rr_num);
    else if (find_val_r(root,tail,r_num)>find_val_rr(root,tail,rr_num))
        rr_x_times(&root,&tail,rr_num);
    else if(find_val_r(root,tail,r_num)<find_val_rr(root,tail,rr_num))
        r_x_times(&root,&tail,r_num);
    else if (find_val_r(root,tail,r_num) == find_val_rr(root,tail,rr_num))
        rr_x_times(&root,&tail,rr_num);
    push_a(&root,&tail,&root2,&tail2);

            is_size=list_size(root,tail);
     pivot=pivot_finder(root,tail);
    r_num = find_min_r(root,tail,pivot,is_size);
    rr_num = find_min_rr(root,tail,pivot,is_size);
    printf("%d %d %d\n",r_num, rr_num, pivot);
    if (r_num<rr_num)
        r_x_times(&root,&tail,r_num);
    else if (r_num>rr_num)
        rr_x_times(&root,&tail,rr_num);
    else if (find_val_r(root,tail,r_num)>find_val_rr(root,tail,rr_num))
        rr_x_times(&root,&tail,rr_num);
    else if(find_val_r(root,tail,r_num)<find_val_rr(root,tail,rr_num))
        r_x_times(&root,&tail,r_num);
    else if (find_val_r(root,tail,r_num) == find_val_rr(root,tail,rr_num))
        rr_x_times(&root,&tail,rr_num);
    push_a(&root,&tail,&root2,&tail2);

*/

    return 0;
}

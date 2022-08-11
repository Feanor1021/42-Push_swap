#include "push_swap.h"


int *find_min_path(t_list*root, t_list*tail, t_list *root2, t_list *tail2)
{
    int size[2];
    int min;
    int a[2];
    int *b;
    int i[2];

    min = INT_MAX;
    size[0]=list_size(root2,tail2);
    size[1]=list_size(root,tail);
    b=malloc(sizeof(int)*2);
    i[0] = -1;
    while(size[0]>++i[0])
    {
        i[1]=find_min_rotate(root,tail,closest_index_b(root,tail,tail2->index,size[1]),size[1]);
        if(i[0]<size[0]/2)
            a[0]=i[0];
        else
            a[0]=size[0]-i[0];
        if(i[1]<size[1]/2)
            a[1]=i[1];
        else
            a[1]=size[1]-i[1];
        if(min>(a[0]+a[1]))
        {
            min=a[0]+a[1];
            b[0]=i[0];
            b[1]=i[1];
        }
        tail2=tail2->prev;
    }
    return b;
}
void arrange_chunk_b(t_list **root, t_list **tail, t_list **root2, t_list **tail2)
{
    int pivot;
    int is_size;
    int i;

    is_size = list_size(*root,*tail);
    pivot=pivot_finder(*root,*tail);
    i = 0;
    if(is_size < 3)
    {
        if(is_size == 1)
            push_b(root,tail,root2,tail2);
        return;
    }
    while (is_size>i)
    {
        if(pivot >= (*tail)->index)
        {
            push_a(root,tail,root2,tail2);
        }
        else
            shift_up_r(root,tail,'a');
        i++;
    }
    arrange_chunk_b(root,tail,root2,tail2);
}

void sort_final(t_list **root, t_list **tail, t_list **root2, t_list **tail2)
{
    int r_num;
    int rr_num;

    r_num = find_min_rotate(*root,*tail,0,list_size(*root,*tail));
    rr_num = find_min_rrb(*root,*tail,0,list_size(*root,*tail));
    if (r_num<rr_num)
    {
        r_x_times(root,tail,r_num);
    }
    else if (r_num>=rr_num)
    {
        rr_x_times(root,tail,rr_num);
    }
}

void sort_stack(t_list **root, t_list **tail, t_list **root2, t_list **tail2)
{
    int size[2];
    int *indexes;
    
    arrange_chunk_b(root,tail,root2,tail2);
    size[0]=list_size(*root2,*tail2);
    size[1]=list_size(*root,*tail);
    while(size[0])
    {
        indexes=find_min_path(*root,*tail,*root2,*tail2);
        if (indexes[1] < (size[1]) / 2)
		    while (indexes[1]-- > 0)
			    shift_up_r(root,tail,'a');
	    else
		    while (indexes[1]++ < size[1])
			    shift_down_rr(root,tail,'a');
	    if (indexes[0] < (size[0] / 2))
		    while (indexes[0]-- > 0)
			    shift_up_r(root2,tail2,'b');
	    else
		    while (indexes[0]++ < size[0])
			    shift_down_rr(root2,tail2,'b');
        push_b(root,tail,root2,tail2);
        size[0]--;
        size[1]++;
        free(indexes);
    }
    sort_final(root,tail,root2,tail2);
}
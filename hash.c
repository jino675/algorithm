/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:27:44 by jiryu             #+#    #+#             */
/*   Updated: 2023/07/15 18:49:31 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    int              key;
    struct s_list   *next;
}   t_list;

int** findDifference(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize, int **returnColumnSizes){
    t_list  *list1;
    t_list  *list2;
    t_list  *new;
    t_list  *ptr;
    int     cnt1;
    int     cnt2;
    int     **res;
    int     idx;

    list1 = (t_list *)calloc(nums1Size, sizeof(t_list));
    list2 = (t_list *)calloc(nums2Size, sizeof(t_list));

    for (int i = 0; i < nums1Size; ++i) {
        idx = nums1[i] % nums1Size;
        new = (t_list *)malloc(sizeof(t_list));
        new->key = nums1[i];
        new->next = list1[idx].next;
        list1[idx].next = new;
    }
    for (int i = 0; i < nums2Size; ++i) {
        idx = nums2[i] % nums2Size;
        new = (t_list *)malloc(sizeof(t_list));
        new->key = nums2[i];
        new->next = list2[idx].next;
        list2[idx].next = new;
    }
    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < nums1Size; ++i) {
        idx = nums1[i] % nums2Size;
        for (ptr = list2[idx].next; ptr != NULL; ptr = ptr->next) {
            if (ptr->key == nums1[i])
                break ;
        }
        if (ptr == NULL)
            ++cnt1;
    }    
    for (int i = 0; i < nums2Size; ++i) {
        idx = nums2[i] % nums1Size;
        for (ptr = list1[idx].next; ptr != NULL; ptr = ptr->next) {
            if (ptr->key == nums2[i])
                break ;
        }
        if (ptr == NULL)
            ++cnt2;
    }
    res = (int **)calloc(2, sizeof(int *));
    if (cnt1 != 0)
        res[0] = (int *)malloc(sizeof(int) * cnt1);
    if (cnt2 != 0)
        res[1] = (int *)malloc(sizeof(int) * cnt2);
    *returnSize = cnt1 + cnt2;
    *returnColumnSizes = (int *)malloc(sizeof(int) * 2);
    (*returnColumnSizes)[0] = cnt1;
    (*returnColumnSizes)[1] = cnt2;
    if (cnt1 != 0) {
        for (int i = 0; i < nums1Size; ++i) {
            idx = nums1[i] % nums2Size;
            for (ptr = list2[idx].next; ptr != NULL; ptr = ptr->next) {
                if (ptr->key == nums1[i])
                    break ;
            }
            if (ptr == NULL)
                res[0][--cnt1] = nums1[i];
        }
    }
    if (cnt2 != 0) {
        for (int i = 0; i < nums2Size; ++i) {
            idx = nums2[i] % nums1Size;
            for (ptr = list1[idx].next; ptr != NULL; ptr = ptr->next) {
                if (ptr->key == nums2[i])
                    break ;
            }
            if (ptr == NULL)
                res[1][--cnt2] = nums2[i];
        }
    }
    return (res);
}

int	main(void)
{
	int arr1[4] = {1, 2, 3};
	int	arr2[5] = {2, 4, 6};
	int	size;
	int	**res;
	int	*sizes;
	
	res = findDifference(arr1, 4, arr2, 5, &size, &sizes);
	for (int i = 0; i < sizes[0]; ++i) {
		printf("%d ", res[0][i]);
	}
	printf("\n");
	for (int i = 0; i < sizes[1]; ++i) {
		printf("%d ", res[1][i]);
	}
	printf("\n");
}
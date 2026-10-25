#ifndef TERMINOLOGY_TAB_REORDER_H_
#define TERMINOLOGY_TAB_REORDER_H_ 1

/* Index the tab at dragged_index moves to when the pointer is at y from the
 * top of a vertical tab list: below every other tab whose midpoint is above
 * y. heights are the tab heights in list order. */
int tab_reorder_index(const int *heights, int count, int dragged_index, int y);

#endif

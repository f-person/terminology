#include "private.h"

#include "tab_reorder.h"

int
tab_reorder_index(const int *heights, int count, int dragged_index, int y)
{
   int i, top = 0, index = 0;

   for (i = 0; i < count; i++)
     {
        if ((i != dragged_index) && (top + heights[i] / 2 < y))
          index++;
        top += heights[i];
     }
   return index;
}

#if defined(BINARY_TYTEST)
#include <assert.h>
#include "unit_tests.h"

int
tytest_tab_reorder_index(void)
{
   const int same[] = { 20, 20, 20 };
   const int tall_first[] = { 40, 20 };
   const int short_first[] = { 20, 40 };
   const int one[] = { 30 };

   assert(tab_reorder_index(one, 1, 0, -50) == 0);
   assert(tab_reorder_index(one, 1, 0, 500) == 0);

   assert(tab_reorder_index(same, 3, 0, 29) == 0);
   assert(tab_reorder_index(same, 3, 0, 31) == 1);
   assert(tab_reorder_index(same, 3, 0, 51) == 2);
   assert(tab_reorder_index(same, 3, 2, 31) == 2);
   assert(tab_reorder_index(same, 3, 2, 29) == 1);
   assert(tab_reorder_index(same, 3, 2, 9) == 0);
   assert(tab_reorder_index(same, 3, 1, -5) == 0);
   assert(tab_reorder_index(same, 3, 1, 900) == 2);

   /* swapping with the tab under the pointer would swap back and forth */
   assert(tab_reorder_index(short_first, 2, 0, 25) == 0);
   assert(tab_reorder_index(short_first, 2, 0, 41) == 1);
   assert(tab_reorder_index(tall_first, 2, 1, 41) == 1);
   assert(tab_reorder_index(tall_first, 2, 1, 21) == 1);
   assert(tab_reorder_index(tall_first, 2, 1, 19) == 0);

   assert(tab_reorder_index(tall_first, 2, 0, 45) == 0);
   assert(tab_reorder_index(tall_first, 2, 0, 51) == 1);
   assert(tab_reorder_index(short_first, 2, 1, 51) == 1);
   assert(tab_reorder_index(short_first, 2, 1, 11) == 1);
   assert(tab_reorder_index(short_first, 2, 1, 9) == 0);
   return 0;
}
#endif

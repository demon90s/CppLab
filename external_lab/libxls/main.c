#include <stdio.h>
#include "include/xls.h"

int main()
{
    xlsWorkBook* book;
    xlsWorkSheet* sheet;
    xls_error_t code = LIBXLS_OK;

    book = xls_open_file("./what.xls", "UTF-8", &code);
    if (book == NULL) {
        fprintf(stderr, "open file failed: %s\n", xls_getError(code));
        return 1;
    }

    sheet = xls_getWorkSheet(book, 0);
    if ((code = xls_parseWorkSheet(sheet)) != LIBXLS_OK) {
        fprintf(stderr, "Error parsing worksheet: %s\n", xls_getError(code));
    }

    {
        int i, j;
        struct st_row_data* row;

        for (i = 0; i <= sheet->rows.lastrow; i++) {
            row = &sheet->rows.row[i];

            for (j = 0; j < sheet->rows.lastcol; j++) {
                printf("%s ", row->cells.cell[j].str);
            }

            printf("\n");
        }
    }

    xls_close_WB(book);
    xls_close_WS(sheet);

    return 0;
}

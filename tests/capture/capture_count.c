/*
 * Copyright 2021 Federico Mena Quintero
 *
 * See LICENCE for the full copyright terms.
 */

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <fsm/fsm.h>
#include <fsm/capture.h>

#include "captest.h"

int main(void)
{
        struct fsm *fsm = captest_fsm_of_string("", 0);
        assert(fsm != NULL);

        unsigned count = fsm_countcaptures(fsm);
        assert(count == 0);

        fsm_free(fsm);

        return 0;
}

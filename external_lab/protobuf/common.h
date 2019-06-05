#pragma once

#define SHM_KEY 1111
#define SHM_BLOCK_LEN 1024

struct SharedBlock
{
    int len;
    char data[SHM_BLOCK_LEN];
};

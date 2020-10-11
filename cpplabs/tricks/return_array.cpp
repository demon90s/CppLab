int arr[10];

// 传统的方法
int (*ret_arr())[10]
{
    return &arr;
}

int main()
{
    ret_arr();
}
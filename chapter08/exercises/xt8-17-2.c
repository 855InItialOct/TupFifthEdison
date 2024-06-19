int cmpStr(const char *src, const char *dst)
{
    int ret = 0;

    // 进行强制转化的原因是因为有0~255个ASCII码，而char默认有符号型，即范围为-128~127。
    while ((ret = *(unsigned char *)src - *(unsigned char *)dst) == 0 && *dst)
    {
        ++src, ++dst;
    }

    return ((-ret) < 0) - (ret < 0); // (if positive) - (if negative) generates branchless code
}

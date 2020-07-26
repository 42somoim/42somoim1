#include <iostream>

int		main(void)
{
    int         cnt;
	int			a, b;
    char        w;
	
    std::cin >> cnt;
    for(int i=0; i < cnt; i++)
    {
        std::cin >> a >> w >> b;
	    std::cout << a + b << std::endl;
    }
	return (0);
}


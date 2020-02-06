int ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int ft_nputchar(char c, int n)
{
	int i;
	
	i=0;
	while(i<n)
	{
		ft_putchar(c);
		i=i+1;
	}
}


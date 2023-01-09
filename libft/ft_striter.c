void	ft_striter(char *c, void (*f)(char *))
{
	while (*c)
	{
		(*f)(c);
		c++;
	}
}

double	ft_lerp(double first, double second, double p)
{
	if (first == second)
		return (first);
	return (first + (second - first) * p);
}

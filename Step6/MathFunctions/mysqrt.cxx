double mysqrt(double inputValue)
{
	double outputValue;

	#if defined(HAVE_LOG) && defined(HAVE_EXP)
			outputValue = exp(log(inputValue) * 0.5);
	#else // otherwise use an iterative approach
		outputValue = -inputValue * inputValue;
	#endif

	return outputValue;
}
#include <Python.h>
#include <stdio.h>

/**
 * print_python_int - prints a python integer
 * @p: pointer to python object
 */
void print_python_int(PyObject *p)
{
	ssize_t len, i, signedInt;
	unsigned long num = 0;

	setbuf(stdout, NULL);
	if (!PyLong_Check(p))
	{
		printf("Invalid Int Object\n");
		return;
	}
	len = ((PyVarObject *)p)->ob_size;
	signedInt = len < 0;
	len = signedInt ? -len : len;
	if (len > 3 || (len == 3 && ((PyLongObject *)p)->ob_digit[2] > 0xf))
	{
		printf("C unsigned long int overflow\n");
		return;
	}
	for (i = 0; i < len; i++)
	{
		int sh = PyLong_SHIFT * i;
		unsigned long sub =
			((unsigned long)((PyLongObject *)p)->ob_digit[i]) * (1UL << (sh));
		num += sub;
	}
	if (signedInt)
		printf("-");
	printf("%lu\n", num);
}

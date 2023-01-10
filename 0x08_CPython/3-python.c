#include <stdio.h>
#include <stdlib.h>
#include <Python.h>
#include <float.h>


/**
 * print_python_float - prints a python float object
 * @p: pointer to python float object
 */
void print_python_float(PyObject *p)
{
	char *str;

	setbuf(stdout, NULL);
	printf("[.] float object info\n");
	if (!p || p->ob_type != &PyFloat_Type)
	{
		printf("  [ERROR] Invalid Float Object\n");
		return;
	}
	str = PyOS_double_to_string(((PyFloatObject *)p)->ob_fval,
			'g', 16, 0, NULL);
	printf("  value: %s%s\n", str, strchr(str, '.') ? "" : ".0");
}

/**
 * print_python_bytes - prints a python bytes object
 * @p: pointer to python bytes object
 */
void print_python_bytes(PyObject *p)
{
	ssize_t len, i = 0;

	setbuf(stdout, NULL);
	printf("[.] bytes object info\n");
	if (!p || p->ob_type != &PyBytes_Type)
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	len = ((PyVarObject *)p)->ob_size;
	printf("  size: %ld\n", len);
	printf("  trying string: %s\n", ((PyBytesObject *)p)->ob_sval);
	len = len < 9 ? len + 1 : 10;
	printf("  first %ld bytes: ", len);
	for (i = 0; i < len; i++)
		printf("%02hhx%c",
			((PyBytesObject *)p)->ob_sval[i], i + 1 == len ? '\n' : ' ');

}
/**
 * print_python_list - prints a python list object
 * @p: pointer to python list object
 */
void print_python_list(PyObject *p)
{
	ssize_t len, i = 0;

	setbuf(stdout, NULL);
	printf("%s", "[*] Python list info\n");
	if (!p || p->ob_type != &PyList_Type)
	{
		printf("  [ERROR] Invalid List Object\n");
		return;
	}
	len = ((PyVarObject *)p)->ob_size;
	printf("[*] Size of the Python List = %ld\n", len);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);
	for (i = 0; i < len; i++)
	{
		PyObject *pobj = ((PyListObject *)p)->ob_item[i];

		printf("Element %ld: %s\n", i, pobj->ob_type->tp_name);
		if (pobj->ob_type == &PyBytes_Type)
			print_python_bytes(pobj);
		else if (pobj->ob_type == &PyFloat_Type)
			print_python_float(pobj);
	}
}

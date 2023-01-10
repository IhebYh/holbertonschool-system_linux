#include <stdio.h>
#include <stdlib.h>
#include <Python.h>

/**
 * print_python_bytes - prints a python bytes object
 * @p: pointer to python bytes object
 */ 
void print_python_bytes(PyObject *p)
{
	ssize_t len, i = 0;

	printf("[.] bytes object info\n");
	if (p->ob_type != &PyBytes_Type)
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
 * print_python_list - prints basic info about python lists
 * 
 * @p: pointer to python object struct
 */
void print_python_list(PyObject *p)
{
	__ssize_t len = ((PyVarObject *)p)->ob_size, i = 0;

	printf("%s", "[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", len);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);
	for (i = 0; i < len; i++)
	{
		PyObject *pobj = ((PyListObject *)p)->ob_item[i];

		printf("Element %ld: %s\n", i, pobj->ob_type->tp_name);
		if (pobj->ob_type == &PyBytes_Type)
			print_python_bytes(pobj);
	}
}

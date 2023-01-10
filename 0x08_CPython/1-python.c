#include <stdio.h>
#include <stdlib.h>
#include <object.h>

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
		printf("Element %ld: %s\n", i,
			((PyListObject *)p)->ob_item[i]->ob_type->tp_name);
}

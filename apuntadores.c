#include <stdio.h>

int main(){
	
	int a = 5;
	int b = 7;
		
	printf("a=%d\n", a); // 5
	printf("b=%d\n", b); // 5
	printf("sizeof(a)=%d\n", sizeof(a)); // 4 (bytes)
	printf("sizeof(b)=%d\n", sizeof(b)); // 4 (bytes)
	printf("dir(a)=%p\n", &a); // dir(a)
	printf("dir(b)=%p\n\n", &b); // dir(b)
	
	int * ptr = &a;
	
	printf("a=%d\n", *ptr); // valor de a
	printf("dir(a)=%p\n", ptr); // dir(a)
	printf("dir(ptr)=%p\n", &ptr); // dir(ptr)
	
	int ** dptr = &ptr;
	
	printf("a=%d\n", **dptr); // valor de a
	printf("dir(a)=%p\n", *dptr); // dir(a)
	printf("dir(ptr)=%p\n", dptr); // dir(ptr)
	printf("dir(dptr)=%p\n", &dptr); // dir(dptr)
	
	return 0;
}

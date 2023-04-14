#include <stdio.h>

int main(int argc, char *argv[]) {
	char name[256];
	
	/**
	fprintf和sprintf都是C语言中的输出函数，但是它们的作用不同。fprintf用于将输出写入到指定的文件流中，而sprintf则将输出写入到一个字符串中。具体来说，fprintf的第一个参数是文件指针，第二个参数是输出格式，后面的参数是要输出的内容；而sprintf的第一个参数是一个字符数组，第二个参数是输出格式，后面的参数是要输出的内容。需要注意的是，sprintf可能会导致缓冲区溢出，因此在使用时需要特别小心。
	**/
	sprintf(name, "Firmware/dfu/WTF.s5l all.RELEASE.dfu");
	
	const char *pName = name;
	printf("%s, size: %ld\n", pName, sizeof(name));
	printf("%s, size: %ld\n", name, sizeof(pName));
	
	return 0;
}